#include "menu.h"

Menu::Menu(Menu * prevMenu) {
	this->name = new std::string("");
	this->prevMenu = prevMenu;
}

Menu::Menu(Menu * prevMenu, char * name) {
	this->name = new std::string(name);
	this->prevMenu = prevMenu;
}

Menu::~Menu() {
	delete this->name;

	for(std::vector<MenuItem>::iterator it = this->menuItems.begin(); it != this->menuItems.end(); ++it) {
		delete *it;
	}
}

//draws the menu and the items
void Menu::draw() {

}

//adds a menu to the menu
void Menu::addMenuItem(MenuItem * item) {
	this->menuItems.push_back(item);
}

//remove an item from the menu
//x is the index of the menu item, 0 <= x < n
void Menu::removeMenuItem(int x) {
	this->menuItems.erase(this->menuItems.begin() + x);
}