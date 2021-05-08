#include "stateManager.h"
#include "Player.h"
#include "Fond.h"
#include "Mobs.h"
void stateInit(Window* _window)
{
	static sfBool firstload = sfFalse;
	if (!firstload)
	{

		firstload = sfTrue;
	}
	if (!onePass)
	{
		onePass = sfTrue;
		if (state == INTRO)
		{

		}
		if (state == MENU)
		{
			viewinit(_window->renderWindow);
			initPlayer();
			initfondMenu();
		}
		if (state == GAME)
		{
			viewinit(_window->renderWindow);
			initATH();
			initbonus();
			
			initFond();
			initPlayer();
			initTirs(_window->renderWindow);
			 initMob();
		}
		if (state == END)
		{

		}
	}
}

void stateUpdate(Window* _window)
{
	if (state == INTRO)
	{

	}
	if (state == MENU)
	{
		updatefond();
		updateView();
		updatePlayer();
		if (sfKeyboard_isKeyPressed(sfKeyEnter))
		{
			changeState(_window,GAME);
		}
	}
	if (state == GAME)
	{
		
		updateBonus();
		updatePlayer();
		updateVie();
		UpdateMob();
		updateView();
		updateATH();
		updatdeTirs(_window->renderWindow);
		if (Persos.Pvperso <= 0)
		{	
		changeState(_window, MENU);
		printf("GameOver\n");
		}
			
		
		
	}
	if (state == END)
	{

	}
}

void stateDisplay(Window* _window)
{
	if (state == INTRO)
	{

	}
	if (state == MENU)
	{
		displayfondMenu(_window->renderWindow);
	
	}
	if (state == GAME)
	{
		displayView(_window->renderWindow);
		DiplayFond(_window->renderWindow);
		DrawPlayer(_window->renderWindow);
		displayMob(_window->renderWindow);
		DisplayTirs(_window->renderWindow);
		displayBonus(_window->renderWindow);
		displayATH(_window->renderWindow);
	}
	if (state == END)
	{

	}
}

void stateDeinit(Window* _window)
{
	if (state == INTRO)
	{

	}
	if (state == MENU)
	{
	
	}
	if (state == GAME)
	{
		
	}
	if (state == END)
	{

	}
}

void changeState(Window* _window, State _state)
{
	stateDeinit(_window);
	state = _state;
	onePass = sfFalse;
	stateInit(_window);
}