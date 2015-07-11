#ifndef _MENU_MANAGER_H
#define _MENU_MANAGER_H

#include "menu.h"

class MenuManager {
	Menu * currentMenu;
	Menu * mainMenu;

	std::vector<Menu *> menus;
public:
	MenuManager(Menu * mainMenu);
	~MenuManager();
	void draw();
	void changeMenu(Menu * menu);
	void addNewMenu(Menu * menu);
	void handleTouch(int x, int y);
};

#endif