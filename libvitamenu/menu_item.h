#ifndef _MENU_ITEM_H
#define _MENU_ITEM_H

#include <string>

class MenuItem {
	int x, y, draw_colour;

	std::string * name;
	void (*on_selection_fnc)();
public:
	MenuItem(char * name, int x, int y, void (*on_selection_fnc)());
	~MenuItem();
	void draw(bool selected);

	bool handleSelection(int x, int y);
	bool handleSelection();
	void setDrawColour(int drawColour);
	void setName(char * name);

	int getNameLength();
};

#endif