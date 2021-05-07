#pragma once
#include "windowManager.h"
#include "tools.h"
#include "windowManager.h"
#include "Player.h"

#define VITESSE_TIRS 2.5
typedef enum TypeEnemie TypeEnemie;
enum TypeEnemie
{
	PERSO,
	MOBS,
	MOBS2,
	BOSS
};


typedef struct Tirs Tirs;
struct Tirs
{
	Tirs* TirsSuivant;
	sfSprite* TirsEnemies;
	int VieTirs;
	float VitTirs;
	sfVector2f DirectiobTirs;
	sfVector2f agles;
	float Timer;
	sfVector2f Postirs;
	sfVector2f persopos;
	sfRectangleShape* tirs;
	TypeEnemie TypeMob;
};
Tirs* debutTir;
Tirs* TempTirs;



void PrepareTir(int _HP, float _Vit, sfVector2f _Direction, sfVector2f _PosTirs);
void ajoutTirs(Tirs* _Tirs);
void DisplayTirs(sfRenderWindow* _window);
Tirs* retirTirs(Tirs* _Tirs);
void initTirs(sfRenderWindow* _window);
void updatdeTirs(sfRenderWindow* _window);
void updateVie();