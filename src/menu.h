#ifndef _MENU_H
#define _MENU_H

#include <string>
#include <vector>
#include "menu_item.h"

class Menu {
	Menu * prevMenu;

	std::string * name;
	std::vector<MenuItem *> menuItems;

	int background_colour = 0x000000;

	~Menu();
public:
	Menu(Menu * prevMenu);
	Menu(Menu * prevMenu, char * name);

	void draw();
	void addMenuItem(MenuItem * item);
	void removeMenuItem(int x);

	void handleTouch(int x, int y);
};

#endif