#include "menu_item.h"
#include "font.h"
#include "utils.h"

#include <vita2d.h>

#include <cstdio>

MenuItem::MenuItem(char * name, int x, int y, void (*on_selection_fnc)()) 
{
	this->name = new std::string(name);
	this->x = x;
	this->y = y;
	this->on_selection_fnc = on_selection_fnc;
}

MenuItem::~MenuItem() {
	delete this->name;
}

//draw the menu item
void MenuItem::draw() 
{
	font_draw_string(this->x, this->y, WHITE, this->name->c_str());
}

//do something here
void MenuItem::handleSelection()
{
	(*this->on_selection_fnc)();
}