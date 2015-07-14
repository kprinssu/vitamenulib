#include "menu.h"
#include "font.h"
#include "utils.h"

#include <vita2d.h>
#include <cmath>

Menu::Menu(Menu * prevMenu, int x, int y, int background_colour)
	: x(x), y(y), background_colour(background_colour), current_menu_selection(0), total_menu_items(0)
{
	this->name = new std::string("");

	this->prevMenu = prevMenu;
	for(int i = 0; i < 10; i++)
	{
		this->menuItems[i] = NULL;
	}
}

Menu::Menu(Menu * prevMenu, int x, int y, int background_colour, char * name) 
	: x(x), y(y), background_colour(background_colour), current_menu_selection(0), total_menu_items(0)
{
	this->name = new std::string(name);

	this->prevMenu = prevMenu;

	for(int i = 0; i < 10; i++)
	{
		this->menuItems[i] = NULL;
	}
}

Menu::~Menu() {
	delete this->name;

	for(int i = 0; i < this->total_menu_items; i++)
	{
		delete this->menuItems[i];
	}
}

//draws the menu and the items
void Menu::draw() {
	vita2d_set_clear_color(this->background_colour);

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

//
void Menu::handleTouch(int x, int y)
{
	//TODO: Find the correct menu item
	for(int i = 0; i < this->total_menu_items; i++)
	{
		MenuItem * item = this->menuItems[i];

		if((x >= item->getX()) 
			&& (x <= (item->getX() + item->getNameLength()))
			&& (y >= item->getY())
			&& (y <= item->getY())) //16 is the height of the font
		{
			this->current_menu_selection = i;
			this->menuItems[i]->handleSelection();
			break;
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