#ifndef _MENU_ITEM_H
#define _MENU_ITEM_H

#include <string>

class MenuItem {
	int x, y;

	std::string * name;
public:
	MenuItem(char * name, int x, int y);
	~MenuItem();
	void draw();

	void handleTouch();
};

#endif