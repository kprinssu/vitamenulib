#include "menu_item.h"
#include <vita2d.h>

MenuItem::MenuItemMenuItem(char * name, int x, int y) 
{
	this->name = new std::string(name);
	this->x = x;
	this->y = y;
}

MenuItem::~MenuItem() {
	delete this->name;
}

void MenuItem::draw() 
{

}

void MenuItem::handleTouch()
{
	
}