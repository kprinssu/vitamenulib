#include "menu.h"
#include "font.h"
#include "utils.h"

Menu::Menu(Menu * prevMenu, int x, int y)
	: x(x), y(y), background_colour(BLACK), current_menu_selection(0), total_menu_items(0)
{
	this->name = new std::string("");
	this->backgroundTexture = NULL;
	
	this->prevMenu = prevMenu;

	//11 menu items since we need to account for back menu item
	for(int i = 0; i < 11; i++)
	{
		this->menuItems[i] = NULL;
	}

	if(this->prevMenu)
	{
		//TODO: Actually implement the back button
		//this->menuItems[11] = new MenuItem
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

	font_draw_string(this->x, this->y, WHITE, this->name->c_str());

	for(int i = 0; i < this->total_menu_items; i++)
	{
		this->menuItems[i]->draw(this->current_menu_selection == i);
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
		this->menuItems[11]->handleSelection(x, y);
	}
}

// handles the dpad movement
// int up_down is either 1 or -1
// 1 is up, -1 is down
void Menu::handleDpad(int up_down, bool selected)
{
	if(selected)
	{
		this->menuItems[this->current_menu_selection]->handleSelection();
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
		this->current_menu_selection = (total_menu_items - 1);	
	}
	else if(this->current_menu_selection >= this->total_menu_items)
	{
		this->current_menu_selection = 0;
	}
}

//sets the name of the menu
void Menu::setName(char * name)
{
	delete this->name;

	this->name = new std::string(name);
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