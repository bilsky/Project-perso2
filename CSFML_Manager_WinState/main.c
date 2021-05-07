#include "windowManager.h"

int main(int argc, char** argv)
{
// Supprime la console en mode release
#ifndef _DEBUG
	FreeConsole();
#endif 

	// Video mode par defaut
	sfVector2i defaultVideoMode = { 1920,1080 };
	// Création de la fenêtre
	Window* mainWindow = windowSetup("CSFML Window & State Manager", defaultVideoMode);

	// Boucle de jeu
	while (!IsDone(mainWindow))
	{
		windowInit(mainWindow);

		windowUpdate(mainWindow);

		BeginDraw(mainWindow);
			windowDraw(mainWindow);
		EndDraw(mainWindow);
	}
	return 0;
}
