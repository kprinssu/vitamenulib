#include "menu_item.h"
#include "font.h"
#include "utils.h"

#include <vita2d.h>

MenuItem::MenuItem(char * name, int x, int y, void (*on_selection_fnc)()) 
{
	this->x = x;
	this->y = y;

	this->name = new std::string(name);
	this->on_selection_fnc = on_selection_fnc;

	this->draw_colour = WHITE;
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

	font_draw_string(this->x, this->y, this->draw_colour, output_name.c_str());
}

//chnage the name
void MenuItem::setName(char * name)
{
	delete this->name;
	this->name = new std::string(name);
}

//calls a void function only
// this function handles touch
bool MenuItem::handleSelection(int x, int y)
{
	int length = this->x + (FONT_DRAW_W * this->name->length());
	int height = this->y + FONT_DRAW_H;
	if((x >= this->x)
		&& (x <= length)
		&& (y >= this->y)
		&& (y <= height)) //16 is the height of the font
	{
		(*this->on_selection_fnc)();
			
		return true;
	}

	return false;
}

//normal selection
bool MenuItem::handleSelection()
{
	(*this->on_selection_fnc)();

	return true;
}

//set the drawColour (default white)
void MenuItem::setDrawColour(int drawColour = WHITE)
{
	this->draw_colour = drawColour;
}