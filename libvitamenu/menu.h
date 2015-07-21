#ifndef _MENU_H
#define _MENU_H

#include "menu_item.h"

#include <vita2d.h>
#include <string>

class Menu {
	Menu * prevMenu;

	std::string * name;
	
	MenuItem * menuItems[11];

	int x, y;
	int background_colour;
	int current_menu_selection;
	int total_menu_items;

	vita2d_texture * backgroundTexture;

public:
	Menu(Menu * prevMenu, int x, int y);
	~Menu();

	void draw();
	void addMenuItem(MenuItem * item);

	void handleTouch(int x, int y);
	void handleDpad(int up_down, bool selected);
	void setName(char * name);
	void setBackground(char * path);
	void setBackground(int backgroundColour);
};

#endif