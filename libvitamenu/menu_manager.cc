#include "menu_manager.h"

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
void MenuManager::addNewMenu(Menu * menu) {
	for(int i = 0; i < 10; i++)
	{
		if(this->menus[i] == NULL)
		{
			this->menus[i] = menu;
		}
	}
}


//send the touch x and y to the current menu
void MenuManager::handleTouch(int x, int y) {
	this->currentMenu->handleTouch(x, y);
}