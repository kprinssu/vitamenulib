#ifndef _MENU_ITEM_H
#define _MENU_ITEM_H

#include <string>

class MenuItem {
	int x, y;

	std::string * name;
	void (*on_selection_fnc)();
public:
	MenuItem(char * name, int x, int y, void (*on_selection_fnc)());
	~MenuItem();
	void draw(bool selected);

	void handleSelection();

	int getX();
	int getY();
	int getNameLength();
};

#endif