#include <psp2/ctrl.h>
#include <psp2/touch.h>
#include <psp2/moduleinfo.h>
#include <psp2/kernel/processmgr.h>

#include <vita2d.h>

#include "../src/menu_manager.h"
#include "../src/menu.h"
#include "../src/menu_item.h"

PSP2_MODULE_INFO(0, 0, "vita2dsample");

int main() {
	vita2d_init();

	Menu * menu = new Manu("Test");

	MenuManager * menu_manager = new MenuManager(menu);

	MenuItem * item = new MenuItem("Sample test", 100, 100);
	menu->addMenuItem(item);

	//input for both touch and joysticks
	SceCtrlData pad;
	SceTouchData touch;

	while(1) {
		clear_screen();

		//read input
		sceCtrlPeekBufferPositive(0, &pad, 1);
		sceTouchPeek(0, &touch, 1);


		menu_manager->draw();


		vita2d_end_drawing();
		vita2d_swap_buffers();
	}

	vita2d_fini();
	vita2d_free_texture(tex);

	sceKernelExitProcess(0);
	delete menu_manager;

	return 0;
}