#include <psp2/ctrl.h>
#include <psp2/touch.h>
#include <psp2/moduleinfo.h>
#include <psp2/kernel/processmgr.h>

#include <cstdio>
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
	char item1_name[] = "Item 1";
	char item2_name[] = "Item 2";
	char item3_name[] = "Item 3";

	Menu * menu = new Menu(NULL, 840, 50, BLACK, &menu_name[0]);

	MenuManager * manager = new MenuManager(menu);

//	menu->addMenuItem( new MenuItem(&item1_name[0], 100, 100, &test_function));
//	menu->addMenuItem( new MenuItem(&item2_name[0], 100, 116, &test_function));
//	menu->addMenuItem( new MenuItem(&item3_name[0], 100, 132, &test_function));


	//input for both touch and joysticks
	SceCtrlData pad;
	SceTouchData touch;

	while(1) {
		//read input
		sceCtrlPeekBufferPositive(0, &pad, 1);
		sceTouchPeek(0, &touch, 1);

		//quit when you press select
		if (pad.buttons & PSP2_CTRL_TRIANGLE)
		{
			break;
		}
		else if(pad.buttons & PSP2_CTRL_UP)
		{
			manager->handleDpad(1, false);
		}
		else if(pad.buttons & PSP2_CTRL_DOWN)
		{
			manager->handleDpad(-1, false);
		}
		else if(pad.buttons & PSP2_CTRL_CROSS)
		{
			manager->handleDpad(0, true);
		}

		if(touch.reportNum > 0)
		{
			/* Front touchscreen: 1920x1088 */
			//int x = lerp(touch.report[0].x, 1920, SCREEN_W) - w/2;
			int y = lerp(touch.report[0].y, 1088, SCREEN_H) - 16/2;

			manager->handleTouch(0, y);
		}

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