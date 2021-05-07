#pragma once
#include "tools.h"


// Variables
typedef struct Window Window;
struct Window
{
	sfRenderWindow* renderWindow;
	sfBool isDone;
	sfBool isFullscreen;
	sfBool isFPSDisplayed;
	char* windowTitle;
	sfVideoMode videoMode;
	sfVector2i defaultVideoMode;
	sfEvent event;
	float keyTimer;
};



// Prototypes

// Return sfTrue when you exit program
// else return sfFalse
sfBool IsDone(Window* This);
// Return sfTrue if the game is in Fullscreen Mode
// else return sfFalse
sfBool IsFullscreen(Window* This);
// Return sfTrue if the FPS is Displayed
// else return sfFalse
sfBool isFPSDisplayed(Window* This);
// Clear the window.
void BeginDraw(Window* This); 
// Display the changes.
void EndDraw(Window* This);
// Setup the window
// const char* _Title : The name displayed in title bar
// sfVector2i _defaultVideoMode : default resolution of your Game
Window* windowSetup(const char* _Title, sfVector2i _defaultVideoMode);
// Close a window without destroy internal data
void windowDestroy(Window* This);
// Create a window with setup parameters
void windowCreate(Window* This);
// switch between fullscreen and windowed mode
void ToggleFullscreen(Window* This);
// Initialization in game loop
void windowInit(Window* This);
// Update in game loop
void windowUpdate(Window* This);
// Draw in game loop
void windowDraw(Window* This);