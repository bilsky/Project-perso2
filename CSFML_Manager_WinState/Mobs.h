#pragma once
#include "windowManager.h"
#include "tools.h"
#include "windowManager.h"


typedef struct Mob Mob;
struct Mob
{
	Mob* MobsSuivant;
	sfSprite*Enemies;
	int VieMob;
	float VitMob;
	sfVector2f DirectioMob;
	float Timer;
	sfVector2f PosMob;
	 float timermob;

};
Mob* debutMob;
void PrepareMOb(sfSprite* _enemies, int _HP, float _Vit, sfVector2f _Direction, sfVector2f _PosMob);
void ajoutMob(Mob* _Mob);
Mob* retirMob(Mob* _Mob);
void initMob();
void UpdateMob();
void displayMob(sfRenderWindow* _window);

typedef struct bonus bonus;
struct bonus
{
	bonus* bonusSuivant;
	sfSprite* Spritebonus;
	sfVector2f Origine;
	sfVector2f Pos;
	float Pv;
	float TimerBible;
	sfBool Bibleanim;
	sfVector2f ScaleBible;
	int RNG;
	int TypeBonus;
	float chance;
};
bonus* debutbonus;
bonus* tempbonus;

void ajoutBonus(bonus* _bonus);
void Preparebonus(sfSprite* _bonus, float _posx, float _posy, int _typebonus);
void initbonus();
void updateBonus();
void displayBonus(sfRenderWindow* _window);
