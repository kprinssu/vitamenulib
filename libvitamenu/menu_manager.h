#ifndef _MENU_MANAGER_H
#define _MENU_MANAGER_H

#include <psp2/ctrl.h>
#include <psp2/touch.h>

#include "menu.h"

class MenuManager {
	Menu * currentMenu;
	Menu * mainMenu;

	Menu * menus[10];
	unsigned int last_pressed_button;
public:
	MenuManager(Menu * mainMenu);
	~MenuManager();
	void draw();
	void changeMenu(Menu * menu);
	void addNewMenu(Menu * menu);
	void handleTouch(SceTouchData * touch_data);
	void handleDpad(SceCtrlData * ctrl_data);

	bool buttonPressed(unsigned int x, unsigned int button);
};

#endif