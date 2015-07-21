#include "menu.h"
#include "font.h"
#include "utils.h"

#include "menu_manager.h"

#include <cstdio>

//does nothing, ignore this
//hackish fix for back menu item
void menu_item_empty() {}

Menu::Menu(MenuManager * manager, int x, int y)
	: x(x), y(y), background_colour(BLACK), current_menu_selection(0), total_menu_items(0), manager(manager)
{
	printf("%d %d%s", x, this->x, "\n");

	this->name = new std::string("");
	this->backgroundTexture = NULL;
	this->prevMenu = NULL;
	
	//11 menu items since we need to account for back menu item
	for(int i = 0; i < 11; i++)
	{
		this->menuItems[i] = NULL;
	}
}

Menu::~Menu() {
	delete this->name;

	vita2d_free_texture(this->backgroundTexture); //make sure to free the memory allocated to the test background

	for(int i = 0; i < this->total_menu_items; i++)
	{
		delete this->menuItems[i];
	}

	delete this->menuItems[10]; //back button
}

//closes the menu
void Menu::closeMenu()
{
	this->manager->changeMenu(this->prevMenu);
}

//draws the menu and the items
void Menu::draw() {

	if(!this->backgroundTexture)
	{
		vita2d_set_clear_color(this->background_colour);
	}
	else
	{
		vita2d_draw_texture(this->backgroundTexture, 0, 0);
	}

	for(int i = 0; i < this->total_menu_items; i++)
	{
		this->menuItems[i]->draw(this->current_menu_selection == i);
	}

	if(this->prevMenu)
	{
		this->menuItems[10]->draw(this->current_menu_selection == 10);
	}
}

//adds a menu to the menu
void Menu::addMenuItem(MenuItem * item) {

	//we can only have 10 menu items for now
	if(this->total_menu_items >= 9)
	{
		return;
	}

	this->menuItems[total_menu_items] = item;
	this->total_menu_items++;
}

// handles the touch and sends to the correct menu item
void Menu::handleTouch(int x, int y)
{
	for(int i = 0; i < this->total_menu_items; i++)
	{
		if(this->menuItems[i]->handleSelection(x, y))
		{
			this->current_menu_selection = i;
			break;
		}
	}

	if(this->prevMenu)
	{
		if(this->menuItems[10]->handleSelection(x, y))
		{
			this->closeMenu();
		}
	}
}

// handles the dpad movement
// int up_down is either 1 or -1
// 1 is up, -1 is down
void Menu::handleDpad(int up_down, bool selected)
{
	if(selected)
	{
		//back button
		if(this->current_menu_selection == 11)
		{
			this->closeMenu();
			return;
		}
		else if(this->menuItems[this->current_menu_selection])
		{

			this->menuItems[this->current_menu_selection]->handleSelection();
		}
		
		return;
	}
	else if(up_down != 1 && up_down != -1)
	{
		return;
	}

	this->current_menu_selection += up_down;


	//boundary checks
	if(this->current_menu_selection < 0)
	{
		this->current_menu_selection = 10; // (total_menu_items - 1);	
	}
	else if(this->current_menu_selection >= 11)
	{
		this->current_menu_selection = 0;
	}
	else if(this->current_menu_selection >= this->total_menu_items
	 && this->current_menu_selection < 11)
	{
		if(up_down == 1)
		{
			this->current_menu_selection =  0;
		}
		else
		{
			this->current_menu_selection =  this->total_menu_items - 1;
		}
	}
}

//sets the name of the menu
void Menu::setName(char * name)
{
	delete this->name;

	this->name = new std::string(name);
}

//sets the previous menu
void Menu::setPrevMenu(Menu * prevMenu, char * name, int x, int y)
{
	//tidying up afterselves
	if(this->prevMenu)
	{
		delete this->menuItems[10];
		this->menuItems[10] = NULL;	
	}

	this->prevMenu = prevMenu;

	if(this->prevMenu)
	{
		this->menuItems[10] = new MenuItem(name, x, y, &menu_item_empty);
	}
}

//changes the background by loading an image
void Menu::setBackground(char * path)
{
	vita2d_free_texture(this->backgroundTexture); //make sure to free the memory allocated to the test background

	this->backgroundTexture = vita2d_load_PNG_file(path); //assuming path is correct!
}

//changes the background by loading an image
void Menu::setBackground(int backgroundColour = BLACK)
{
	if(this->backgroundTexture)
	{
		vita2d_free_texture(this->backgroundTexture); //make sure to free the memory allocated to the test background
		this->backgroundTexture = NULL;
	}

	this->background_colour = backgroundColour;
}