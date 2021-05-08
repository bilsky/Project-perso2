#pragma once
#include "windowManager.h"
#include "tools.h"
#include "windowManager.h"
#include "Tirs.h"
#include "stateManager.h"
#define VITESSEPERSO 700
typedef struct Perso Perso;
sfVector2f ViewPos;
struct Perso
{

	sfSprite* perso;
	sfVector2f posperso;
	sfVector2f vitperso;
	sfVector2f sizeperso;
	sfColor Colorsperso;
	int Pvperso;
	float angle3;
};
Perso Persos;
void initPlayer();
void updatePlayer();
void DrawPlayer(sfRenderWindow* _window);
sfView* viewinit(sfRenderWindow* _window);
void updateView();
sfRenderWindow* displayView(sfRenderWindow* _window);
sfView* getview();
void initATH();
void updateATH();
sfRenderWindow* displayATH(sfRenderWindow* _window);