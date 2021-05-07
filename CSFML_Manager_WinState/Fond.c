#include "Fond.h"
sfSprite* Background;
sfSprite* BackgroundMenu;
void initFond()
{
	
	Background = CreateSprite("../Ressources/Textures/BackGroundProvisoir1.jpg");
}

void updatefond()
{

}

void DiplayFond(sfRenderWindow* _window)
{
	sfRenderWindow_drawSprite(_window, Background, NULL);
}
void initfondMenu()
{
	BackgroundMenu = CreateSprite("../Ressources/Textures/BackGroundProvisoirMenu1.jpg");
}
void displayfondMenu(sfRenderWindow* _window)
{
	sfRenderWindow_drawSprite(_window, BackgroundMenu, NULL);
}


