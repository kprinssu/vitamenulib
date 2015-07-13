#ifndef _MENU_H
#define _MENU_H

#include "menu_item.h"
#include <string>
class Menu {
	Menu * prevMenu;

	std::string * name;
	
	MenuItem * menuItems[10];

	int x, y;
	int background_colour;
	int current_menu_selection;
	int total_menu_items;
public:
	Menu(Menu * prevMenu, int x, int y, int background_colour);
	Menu(Menu * prevMenu, int x, int y, int background_colour, char * name);
	~Menu();

	void draw();
	void addMenuItem(MenuItem * item);

	void handleTouch(int y);
	void handleDpad(int up_down, bool selected);
};

#endif