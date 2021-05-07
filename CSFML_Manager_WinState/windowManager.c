#include "windowManager.h"
#include "stateManager.h"

sfBool IsDone(Window* This)
{
	return This->isDone;
}

sfBool IsFullscreen(Window* This)
{
	return This->isFullscreen;
}

sfBool isFPSDisplayed(Window* This)
{
	return This->isFPSDisplayed;
}

void BeginDraw(Window* This)
{
	sfRenderWindow_clear(This->renderWindow, sfBlack);
}

void EndDraw(Window* This)
{
	sfRenderWindow_display(This->renderWindow);
}

Window* windowSetup(const char* _Title, sfVector2i _defaultVideoMode)
{
	Window* This = malloc(sizeof(Window));
	if (This != NULL)
	{
		This->windowTitle = malloc(strlen(_Title) * sizeof(char));
		if (This->windowTitle != NULL)
			strcpy(This->windowTitle, _Title);
		else 
			printf("Allocation pour Title de la window echoue");
		This->isFullscreen = sfFalse;
		This->isDone = sfFalse;
		This->videoMode = sfVideoMode_getDesktopMode();
		This->defaultVideoMode = _defaultVideoMode;
		This->isFPSDisplayed = sfFalse;
		This->keyTimer = 0.0f;
		windowCreate(This);
	}
	else printf("Allocation pour la window echoue");

	sfclock = sfClock_create();
	text = CreateText(FONT_PATH"Ginger Soda.ttf");

	return This;
}

void windowDestroy(Window* This)
{
	sfRenderWindow_close(This->renderWindow);
}

void windowCreate(Window* This)
{
	sfWindowStyle style = (This->isFullscreen ? sfFullscreen : sfDefaultStyle);

	This->renderWindow = sfRenderWindow_create(This->videoMode, This->windowTitle, style, NULL);
}

void ToggleFullscreen(Window* This)
{
	This->isFullscreen = !This->isFullscreen;
	windowDestroy(This);
	windowCreate(This);
}

void ToggleFPSDisplay(Window* This)
{
	This->isFPSDisplayed = !This->isFPSDisplayed;
}

void windowInit(Window* This)
{
	stateInit(This);
}

void windowUpdate(Window* This)
{
	restartClock();
	This->keyTimer += GetTimeDelta();
	
	while (sfRenderWindow_pollEvent(This->renderWindow, &This->event))
	{
		if (This->event.type == sfEvtClosed)
			This->isDone = sfTrue;
		
	}
	if (sfKeyboard_isKeyPressed(sfKeyF11) == sfTrue && This->keyTimer > 0.2)
	{
		ToggleFullscreen(This);
		This->keyTimer = 0.0f;
	}
	if (sfKeyboard_isKeyPressed(sfKeyF10) == sfTrue && This->keyTimer > 0.2)
	{
		screenshot(This->renderWindow);
		This->keyTimer = 0.0f;
	}
	if (sfKeyboard_isKeyPressed(sfKeyF9) == sfTrue && This->keyTimer > 0.2)
	{
		ToggleFPSDisplay(This);
		This->keyTimer = 0.0f;
	}

	stateUpdate(This);
}

void windowDraw(Window* This)
{
	if (isFPSDisplayed(This))
	{
		displayFrameRate(This->renderWindow, text);
	}
	stateDisplay(This);
}