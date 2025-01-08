#include <3ds.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>




int main(int argc, char* argv[])
{
	gfxInitDefault();
	consoleInit(GFX_TOP, NULL);
	printf("\x1b[1;0HCirclepad Position\n");

	// Main loop
	while (aptMainLoop())
	{
		gspWaitForVBlank();
		gfxSwapBuffers();
		hidScanInput();

		// Your code goes here
		u32 kDown = hidKeysDown();
		if (kDown & KEY_START)
			break; // break in order to return to hbmenu
		circlePosition pad;
		hidCircleRead(&pad);
		printf("\x1b[10;0HX: %05d  	Y: %05d",pad.dx, pad.dy);
	}

	gfxExit();
	return 0;
}
