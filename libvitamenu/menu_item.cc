#include "menu_item.h"
#include "font.h"
#include "utils.h"

#include <vita2d.h>

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
void MenuItem::draw(bool selected) 
{
	std::string output_name = "";

	if(selected)
	{
		//cannot make '> ' a global const, gcc seems to dislike it
		output_name += "> ";
	}
	
	output_name += *this->name;

	font_draw_string(this->x, this->y, WHITE, output_name.c_str());
}

//do something here
void MenuItem::handleSelection()
{
	(*this->on_selection_fnc)();
}