#include "menu_manager.h"

MenuManager::~MenuManager() {
	for(std::vector<Menu *>::iterator it = this->menus.begin(); it != this->menus.end(); ++it) {
		delete *it;
	}
}

MenuManager::MenuManager(Menu * mainMenu) {
	this->mainMenu = mainMenu;
	this->currentMenu = mainMenu;

	this->menus.push_back(mainMenu);
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
void addNewMenu(Menu * menu) {
	this->menus.push_back(menu);
}


//send the touch x and y to the current menu
void handleTouch(int x, int y) {
	this->currentMenu=>handleTouch(x, y);
}