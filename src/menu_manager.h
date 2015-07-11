#ifndef _MENU_H
#define _MENU_H

#include <vector>

class MenuManager {
	Menu * currentMenu;
	Menu * mainMenu;

	std::vector<Menu *> menus;

	~MenuManager();
public:
	MenuManager(Menu * mainMenu);
	void draw();
	void changeMenu(Menu * menu);
	void addNewMenu(Menu * menu);
	void handleTouch(int x, int y);
};

#endif