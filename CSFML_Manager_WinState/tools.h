#pragma once

#include "SFML/Graphics.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "dirent.h"
#ifndef WIN32
#include <sys/types.h>
#endif

#define TEXTURE_PATH "../Ressources/Textures/"
#define FONT_PATH "../Ressources/Fonts/"
#define MAP_PATH "../Ressources/Maps/"

#define TILE_WIDTH 32
#define TILE_HEIGHT 32

typedef struct vector4f vector4f;
struct vector4f
{
	float r;
	float g;
	float b;
	float a;
};

float sangdanslespieds;
int PVMAX;
int score;
float Corruption;
int Balles;
sfBool REALODIIING;
sfVector2f PosATH ;
sfTime sftime;
sfBool AKA;
sfClock* sfclock;
sfText* text;
int sacré;
int maudi;
int Dmg;

sfVector2f vector2f(float _x, float _y);
sfVector2i vector2i(int _x, int _y);
sfVector3f vector3f(float _x, float _y, float _z);
sfFloatRect FlRect(float _left, float _top,  float _width, float _height);
sfIntRect IntRect(int _left, int _top,  int _width, int _height);
void restartClock();
float GetTimeDelta();
sfSprite* CreateSprite(char* _path);
sfText* CreateText(char* _path);
sfBool Circle_Collision(sfVector2f _pos1, sfVector2f _pos2, float _rayon1, float _rayon2);
int iRand(int _min, int _max);
float FrameRate();
void displayFrameRate(sfRenderWindow* _window, sfText* _text);
void screenshot(sfRenderWindow* _window);

sfVector2f getMousePos(sfRenderWindow* _window, sfView* _view);