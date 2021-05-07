#pragma once
#include "tools.h"
#include "windowManager.h"

typedef enum State State;
enum State
{
	RTNULL = -1,
	ALL,
	INTRO,
	MENU,
	GAME,
	END
};


static State state = MENU;

static sfBool onePass = sfFalse;
static sfBool isPaused = sfFalse;
static sfBool isOption = sfFalse;

// Init according to the current state 
void stateInit(Window* _window);
// Update according to the current state 
void stateUpdate(Window* _window);
// Display according to the current state 
void stateDisplay(Window* _window);
// Deinit according to the current state 
void stateDeinit(Window* _window);
// switch between states
void changeState(Window* _window, State _state);
