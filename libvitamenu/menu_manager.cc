#include "menu_manager.h"
#include "utils.h"

MenuManager::~MenuManager() {
	for(int i = 0; i < 10; i++)
	{
		delete this->menus[i];
	}
}

MenuManager::MenuManager(Menu * mainMenu) {
	this->mainMenu = mainMenu;
	this->currentMenu = mainMenu;

	for(int i = 0; i < 10; i++)
	{
		this->menus[i] = NULL;
	}

	this->addNewMenu(mainMenu);
	this->last_pressed_button = 0;
}

//make the current menu draw itself
void MenuManager::draw() {
	this->currentMenu->draw();
}

//changes the current menu
// Menu * should be in the menus vector
void MenuManager::changeMenu(Menu * menu)
{
	this->currentMenu = menu;
}

//add new menu to the manager
void MenuManager::addNewMenu(Menu * menu) 
{
	for(int i = 0; i < 10; i++)
	{
		if(this->menus[i] == NULL)
		{
			this->menus[i] = menu;
		}
	}
}

//send the touch x and y to the current menu
void MenuManager::handleTouch(SceTouchData * touch_data) 
{
	if(touch_data->reportNum == 0)
	{
		return;
	}

	int x = VITA_SCREEN_NORMALIZE(touch_data->report[0].x, VITA_TOUCH_H, VITA_SCREEN_W);
	int y = VITA_SCREEN_NORMALIZE(touch_data->report[0].y, VITA_TOUCH_W, VITA_SCREEN_H);

	this->currentMenu->handleTouch(x, y);
}

//send the directional pad input to menu
void MenuManager::handleDpad(SceCtrlData * ctrl_data)
{
	if(this->buttonPressed(ctrl_data->buttons, PSP2_CTRL_UP))
	{
		this->currentMenu->handleDpad(-1, false);
	}
	else if(this->buttonPressed(ctrl_data->buttons, PSP2_CTRL_DOWN))
	{
		this->currentMenu->handleDpad(1, false);
	}
	else if(this->buttonPressed(ctrl_data->buttons, PSP2_CTRL_CROSS))
	{
		this->currentMenu->handleDpad(0, true);
	}

	this->last_pressed_button = ctrl_data->buttons;
}

//check if a button was pressed
bool MenuManager::buttonPressed(unsigned int x, unsigned int button)
{
	return (((this->last_pressed_button & button) == 0)
			 		&& ((x & button) == button));
}