#ifndef _MENU_H
#define _MENU_H

#include "menu_item.h"
#include <string>

class Menu {
	Menu * prevMenu;

	std::string * name;
	
	MenuItem * menuItems[10];

	int background_colour;
public:
	Menu(Menu * prevMenu);
	Menu(Menu * prevMenu, char * name);
	~Menu();

	void draw();
	void addMenuItem(MenuItem * item);
	void removeMenuItem(int x);

	void handleTouch(int x, int y);
};

#endif