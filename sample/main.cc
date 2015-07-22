#include <psp2/ctrl.h>
#include <psp2/touch.h>
#include <psp2/moduleinfo.h>
#include <psp2/kernel/processmgr.h>

#include <string>
#include <cstdio>
#include <cstdlib>
#include <vita2d.h>

#include "../libvitamenu/menu_manager.h"
#include "../libvitamenu/menu.h"
#include "../libvitamenu/menu_item.h"
#include "../libvitamenu/utils.h"

PSP2_MODULE_INFO(0, 0, "touchvitalibsample");

void log(std::string s)
{
	printf("%s%s", s.c_str(), "\n");
}

void test_function()
{
	log("I was called!");
}

int main() {
	log("Starting");
	vita2d_init();

	char menu_name[] = "Sample Menu";
	char menu_name2[] = "Sample Child Menu";
	char item1_name[] = "Item 1";
	char item2_name[] = "Item 2";
	char item3_name[] = "Item 3";

	char back_name[] = "Back";

  	char background_file[] = "cache0:/VitaDefilerClient/Documents/test.png";

  	MenuManager * manager = new MenuManager();

	Menu * menu = new Menu(manager, 100, 50);
	menu->setName(&menu_name[0]);
	menu->setBackground(&background_file[0]);

	menu->addMenuItem(new MenuItem(&item1_name[0], 100, 100, &test_function));
	menu->addMenuItem(new MenuItem(&item2_name[0], 100, 116, &test_function));
	menu->addMenuItem(new MenuItem(&item3_name[0], 100, 132, &test_function));

	Menu * secondMenu = new Menu(manager, 100, 50);
	secondMenu->setName(&menu_name2[0]);
	secondMenu->setBackground(RED);

	secondMenu->addMenuItem(new MenuItem(&item1_name[0], 100, 100, &test_function));
	secondMenu->addMenuItem(new MenuItem(&item2_name[0], 100, 116, &test_function));
	secondMenu->addMenuItem(new MenuItem(&item3_name[0], 100, 132, &test_function));
	secondMenu->setPrevMenu(menu, &back_name[0], 100, 148);

	manager->changeMenu(secondMenu);

	log("Menu loaded");

	//input for both touch and joysticks
	SceCtrlData pad;
	SceTouchData touch;

	while(1) {
		//read input
		sceCtrlPeekBufferPositive(0, &pad, 1);
		sceTouchPeek(0, &touch, 1);

		//quit when you press triangle
		if (pad.buttons & PSP2_CTRL_TRIANGLE)
		{
			break;
		}

		manager->handleDpad(&pad);

		manager->handleTouch(&touch);

		vita2d_start_drawing();
		vita2d_clear_screen();

		manager->draw();

		vita2d_end_drawing();
		vita2d_swap_buffers();
	}

	log("Stopped.\n");
	

	vita2d_fini();

	sceKernelExitProcess(0);
	delete manager;

	return 0;
}