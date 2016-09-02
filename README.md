vitamenulib
===========

A rudimentary menu system for the Vita built on vita2dlib and C++. 
Most of the library (unless specified) will be under the MIT license.

This project is not being maintained anymore.

Features
--------
* Directonal Pad Support
* Touch Support
* Background (Colour and images)
* Multi-menu support

Documentation
-------
vitamenulib is meant to be directly incorporated into your project. No need to compile and install vitamenulib separately. 

The very first thing you need to is to use the Menu Manager, you can do easily by:
````
MenuManager * manager = new MenuManager();
````

Next create to create menu:

````
Menu * menu = new Menu(manager, x, y);
//manager is a pointer to a MenuManager object
//x, y are the co-ordinates of where to draw the Menu name
````

You can add menus by:
````
manager->addNewMenu(new Menu(...));
````
Note: There is a limitation of 10 menus for a MenuManager.


MenuManager will automatically display the first menu you added. If you want to change the displayed menu by doing:
````
manager->changeMenu(new Menu(...));
````



Thanks
------
xerpi (Thanks for answering my stupid questions on IRC)
