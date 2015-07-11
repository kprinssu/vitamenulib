#include "menu.h"
#include "font.h"
#include "utils.h"

#include <vita2d.h>

Menu::Menu(Menu * prevMenu) {
	this->name = new std::string("");

	this->prevMenu = prevMenu;

	for(int i = 0; i < 10; i++)
	{
		this->menuItems[i] = NULL;
	}
}

Menu::Menu(Menu * prevMenu, char * name) {
	this->name = new std::string(name);

	this->prevMenu = prevMenu;

	for(int i = 0; i < 10; i++)
	{
		this->menuItems[i] = NULL;
	}
}

Menu::~Menu() {
	delete this->name;

	for(int i = 0; i < 10; i++)
	{
		delete this->menuItems[i];
	}
}

//draws the menu and the items
void Menu::draw() {
	vita2d_set_clear_color(BLACK);

	font_draw_string(840, 200, WHITE, this->name->c_str());

	for(int i = 0; i < 10; i++)
	{
		if(this->menuItems[i] == NULL)
		{
			break;
		}

		this->menuItems[i]->draw();
	}
}

//adds a menu to the menu
void Menu::addMenuItem(MenuItem * item) {
	for(int i = 0; i < 10; i++)
	{
		if(this->menuItems[i] == NULL)
		{
			this->menuItems[i] = item;
		}
	}
}

//remove an item from the menu
//x is the index of the menu item, 0 <= x < n
void Menu::removeMenuItem(int x) {
	this->menuItems[x] = NULL;
}

//
void Menu::handleTouch(int x , int y)
{
	//TODO: Find the correct menu item
}