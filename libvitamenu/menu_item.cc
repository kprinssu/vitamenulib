#include "menu_item.h"
#include "font.h"
#include "utils.h"

#include <vita2d.h>
#include <stdio.h>

MenuItem::MenuItem(char * name, int x, int y) 
{
	this->name = new std::string(name);
	this->x = x;
	this->y = y;
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
void MenuItem::handleTouch()
{
	printf("I was called!");	
}