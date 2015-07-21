#ifndef _MENU_MANAGER_H
#define _MENU_MANAGER_H

#include <psp2/ctrl.h>
#include <psp2/touch.h>

class Menu;

class MenuManager {
	Menu * currentMenu;
	Menu * mainMenu;

	Menu * menus[10];
	unsigned int last_pressed_button;
public:
	MenuManager();
	~MenuManager();
	void draw();
	void changeMenu(Menu * menu);
	void addNewMenu(Menu * menu);
	void handleTouch(SceTouchData * touch_data);
	void handleDpad(SceCtrlData * ctrl_data);

	bool buttonPressed(unsigned int x, unsigned int button);
};

#endif