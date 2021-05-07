#include "Mobs.h"
#include "Tirs.h"
#include "Player.h"

sfSprite* mobs;
sfVector2f posMob = { 0,0 };
sfVector2f dirMob = { 0,0 };
sfVector2f scaleMob = {0.30,0.30 };
sfVector2f oroginemob = { 640/2,640 / 2 };

sfSprite* bos;
sfVector2f posbos = { 0,0 };
sfVector2f dirbos = { 0,0 };
sfVector2f scalebos = { 0.5,0.5 };
sfVector2f oroginebos = { 640 / 2,640 / 2 };
float timer = 0;


void PrepareMOb(sfSprite* _enemies, int _HP, float _Vit, sfVector2f _Direction, sfVector2f _PosMob)
{
	Mob* TempMob = (Mob*)calloc(1, sizeof(Mob));
	TempMob->Enemies= _enemies;
	TempMob->VieMob = _HP;
	TempMob->VitMob = _Vit;
	TempMob->DirectioMob = _Direction;
	TempMob->PosMob.x = rand() % 1920*2;
	TempMob->PosMob.y = rand() % 1080*2;
	TempMob->timermob = 0;
	ajoutMob(TempMob);
}

void ajoutMob(Mob* _Mob)
{
	_Mob->MobsSuivant = debutMob;
	debutMob = _Mob;
}

Mob* retirMob(Mob* _Mob)
{
	if (_Mob == debutMob)
	{
		Mob* TempMob = _Mob->MobsSuivant;
		debutMob = TempMob;
		free(_Mob);
		return	TempMob;
	}
	else
	{
		Mob* TempMob = debutMob;
		while (TempMob->MobsSuivant != _Mob)
		{
			TempMob = TempMob->MobsSuivant;
		}
		TempMob->MobsSuivant = _Mob->MobsSuivant;
		free(_Mob);
		return TempMob->MobsSuivant;
	}
}
sfSprite* Bible;
sfVector2f BiblePos;
sfVector2f OrigineBible = { 125 / 2,136 / 2 };
sfVector2f ScaleBible = { 1,1 };

sfSprite* Coeur;
sfVector2f CoeurPos;
sfVector2f OrigineCoeur = { 121 / 2,111 / 2 };
sfVector2f ScaleCoeur = { 1,1 };

sfSprite* Argent;
sfVector2f ArgentPos;
sfVector2f OrigineArgent = { 54/ 2,73 / 2 };
sfVector2f ScaleArgent = { 1,1 };

sfSprite* Graal;
sfVector2f GraalPos;
sfVector2f OrigineGraal = { 151 / 2,138 / 2 };
sfVector2f ScaleGraal = { 1,1 };

sfSprite* Dieu;
sfVector2f DieuPos;
sfVector2f OrigineDieu = { 86 / 2,46 / 2 };
sfVector2f ScaleDieu = { 1,1 };

sfSprite* AK;
sfVector2f AKPos;
sfVector2f OrigineAK = { 512 / 4,313 / 4 };
sfVector2f ScaleAK = { 1,1 };


sfSprite* BLASPHEMOUSLIFE;
sfVector2f BLASPHEMOUSLIFEPos;
sfVector2f OrigineBLASPHEMOUSLIFE = { 85 / 2,89 / 2 };
sfVector2f ScaleBLASPHEMOUSLIFE = { 1,1 };

sfSprite* Tete;
sfVector2f TetePos;
sfVector2f OrigineTete = { 88 / 2,83 / 2 };
sfVector2f ScaleTete = { 1,1 };

sfSprite* Blood;
sfVector2f BloodPos;
sfVector2f OrigineBlood = { 103 / 2,115 / 2 };
sfVector2f ScaleBlood = { 1,1 };


int timerBoss = 0;
void initMob()
{
	mobs = CreateSprite("../Ressources/Textures/Perso_et_NPc/mob.png");
	bos = CreateSprite("../Ressources/Textures/Perso_et_NPc/Boss.png");
}
float timerMobsSpawn = 0;
void UpdateMob()
{
	Mob* TempMob = debutMob;
	timer += GetTimeDelta();
	timerMobsSpawn += GetTimeDelta();
	if (timerMobsSpawn >= 3)
	{
		PrepareMOb(mobs, 4, 5.0, posMob, dirMob);
		timerMobsSpawn = 0;
		timerBoss += 1;
	}
	else if (timerBoss >= 15)
	{
		PrepareMOb(bos, 4, 5.0, posMob, dirMob);

		timerBoss = 0;
	}

	TempMob = debutMob;
	while (TempMob != 0)
	{
		TempMob->timermob += GetTimeDelta();
		if (TempMob->timermob >= 1)
		{
			PrepareTir(1, 5.0, Persos.posperso, TempMob->PosMob, MOBS);
			TempMob->timermob = 0;
			
		}
		
		
		TempMob = TempMob->MobsSuivant;
	}
	TempTirs = debutTir;
	while (TempTirs != 0)
	{
		TempMob = debutMob;
		while (TempMob != 0)
		{
			if (Circle_Collision(TempMob->PosMob, TempTirs->Postirs, 35, 10) && TempTirs->TypeMob == PERSO)
			{
				TempMob->VieMob -= 1*Dmg;
				TempTirs->VieTirs -= 1;
				Corruption += 1;
			}
			TempMob = TempMob->MobsSuivant;
		}
		TempTirs = TempTirs->TirsSuivant;
	}
	TempMob = debutMob;
	while (TempMob != 0)
	{
		if (TempMob->VieMob <= 0)
		{	
			Preparebonus(Bible, TempMob->PosMob.x, TempMob->PosMob.y, iRand(0, 15));
			
			TempMob = retirMob(TempMob);
			score += 100;

		}
		else
			TempMob = TempMob->MobsSuivant;
	}	
	TempMob = debutMob;
	while (TempMob != 0)
	{
		if (Persos.Pvperso <= 0)
		{
		
			TempMob = retirMob(TempMob);
		}
		else
		TempMob = TempMob->MobsSuivant;
	}
}
void displayMob(sfRenderWindow* _window)
{
	Mob* TempMob = debutMob;
	while (TempMob != 0)
	{
		if (TempMob->Enemies==mobs)
		{
			sfSprite_setOrigin(mobs, oroginemob);
			sfSprite_setScale(mobs, scaleMob);
			sfSprite_setPosition(mobs, TempMob->PosMob);
			sfRenderWindow_drawSprite(_window, mobs, NULL);
		}
		else if (TempMob->Enemies == bos)
		{
			sfSprite_setOrigin(bos, oroginemob);
			sfSprite_setScale(bos, scalebos);
			sfSprite_setPosition(bos, TempMob->PosMob);
			sfRenderWindow_drawSprite(_window, bos, NULL);
		}
		TempMob = TempMob->MobsSuivant;
	}

	
}


void Preparebonus(sfSprite* _bonus, float _posx, float _posy, int _typebonus)
{
	bonus* tempbonus = (bonus*)calloc(1, sizeof(bonus));
	
	tempbonus->Pv = 1;
	tempbonus->ScaleBible.x = 1;
	tempbonus->ScaleBible.y = 1;
	tempbonus->TimerBible = 0;
	tempbonus->Bibleanim = sfTrue;
	tempbonus->Pos.x = _posx;
	tempbonus->Pos.y = _posy;
	tempbonus->TypeBonus = _typebonus;
	if (tempbonus->TypeBonus ==0)
	{
		tempbonus->Spritebonus = Bible;
	}
	else if (tempbonus->TypeBonus>=1&& tempbonus->TypeBonus<=3)
	{
		tempbonus->Spritebonus = Coeur;
	}
	else if (tempbonus->TypeBonus ==4)
	{
		tempbonus->Spritebonus = Argent;
	}
	else if (tempbonus->TypeBonus>4&&tempbonus->TypeBonus <=6)
	{
		tempbonus->Spritebonus = Graal;
	}
	else if (tempbonus->TypeBonus ==7)
	{
		tempbonus->Spritebonus = Dieu;
	}
	else if (tempbonus->TypeBonus == 8)
	{
		tempbonus->Spritebonus = AK;
	}
	else if (tempbonus->TypeBonus == 9)
	{
		tempbonus->Spritebonus = BLASPHEMOUSLIFE;
	}
	else if (tempbonus->TypeBonus ==10)
	{
		tempbonus->Spritebonus = Tete;
	}
	else if (tempbonus->TypeBonus == 11)
	{
		tempbonus->Spritebonus = Blood;
	}
	
		ajoutBonus(tempbonus);
	
}

void ajoutBonus(bonus* _bonus)
{
	_bonus->bonusSuivant = debutbonus;
	debutbonus = _bonus;
}

bonus* retirBonus(bonus* _bonus)
{
	if (_bonus == debutbonus)
	{
		bonus* tempbonus = _bonus->bonusSuivant;
		debutbonus = tempbonus;
		free(_bonus);
		return	tempbonus;
	}
	else
	{
		bonus* tempbonus = debutbonus;
		while (tempbonus->bonusSuivant != _bonus)
		{
			tempbonus = tempbonus->bonusSuivant;
		}
		tempbonus->bonusSuivant = _bonus->bonusSuivant;
		free(_bonus);
		return tempbonus->bonusSuivant;
	}
}

sfBool dieuouicmoi = sfFalse;
float recoveriDieu;

void initbonus()
{
	recoveriDieu = 0;
	Bible = CreateSprite("../Ressources/Textures/Items/Bible.png");
	Coeur = CreateSprite("../Ressources/Textures/Items/HPUP.png");
	Argent= CreateSprite("../Ressources/Textures/Items/SilverBullet.png");
	Graal = CreateSprite("../Ressources/Textures/Items/HollyGraa.lpng.png");
	AK= CreateSprite("../Ressources/Textures/Items/Ak47.png");
	Dieu= CreateSprite("../Ressources/Textures/Items/auréole.png"); 
	BLASPHEMOUSLIFE= CreateSprite("../Ressources/Textures/Items/Balsphemeunmax.png");
	Tete = CreateSprite("../Ressources/Textures/Items/TeteDeAnimal.png");
	Blood = CreateSprite("../Ressources/Textures/Items/sang.png");

}

void updateBonus()
{
	tempbonus = debutbonus;
	while (tempbonus != 0)
	{
		tempbonus->TimerBible += GetTimeDelta();
		if (tempbonus->ScaleBible.y <=1.2 && tempbonus->Bibleanim == sfTrue)
		{
			tempbonus->ScaleBible.x += 1*GetTimeDelta();
			tempbonus->ScaleBible.y +=1* GetTimeDelta();
		}
		else
		{
			tempbonus->Bibleanim = sfFalse;
		}
		
		if (tempbonus->ScaleBible.x >=0.7 && tempbonus->Bibleanim == sfFalse)
		{
			tempbonus->ScaleBible.x -= 1 * GetTimeDelta();
			tempbonus->ScaleBible.y -= 1 * GetTimeDelta();
		}
		else
		{
			tempbonus->Bibleanim = sfTrue;
		}
		
		if (Circle_Collision(Persos.posperso, tempbonus->Pos, 35, 35) && tempbonus->Spritebonus == Bible)
		{
			tempbonus = retirBonus(tempbonus);
			Corruption /=2;
			sacré += 1;

		}
		else if (Circle_Collision(Persos.posperso, tempbonus->Pos, 35, 35)&&Persos.Pvperso<PVMAX  && tempbonus->Spritebonus == Coeur)
		{
			tempbonus = retirBonus(tempbonus);
			Persos.Pvperso += 25;
		}
		else if (Circle_Collision(Persos.posperso, tempbonus->Pos, 35, 35) && tempbonus->Spritebonus == Argent)
		{
			tempbonus = retirBonus(tempbonus);
			Dmg += sacré;
		}
		else if (Circle_Collision(Persos.posperso, tempbonus->Pos, 35, 35) && tempbonus->Spritebonus == Graal)
		{
			tempbonus = retirBonus(tempbonus);
			Corruption -= 20;
			Dmg += 1;
			sacré += 1;
		}
		else if (Circle_Collision(Persos.posperso, tempbonus->Pos, 35, 35) && tempbonus->Spritebonus == Dieu)
		{
			tempbonus = retirBonus(tempbonus);
			sacré += 1;
			dieuouicmoi = sfTrue;
		}
		else if (Circle_Collision(Persos.posperso, tempbonus->Pos, 35, 35) && tempbonus->Spritebonus == AK)
		{
			tempbonus = retirBonus(tempbonus);
			sacré += 1;
			AKA = sfTrue;
		}
		else if (Circle_Collision(Persos.posperso, tempbonus->Pos, 35, 35) && tempbonus->Spritebonus == BLASPHEMOUSLIFE)
		{
			tempbonus = retirBonus(tempbonus);
			maudi += 5;
			Dmg += 1;
			Corruption += 25;
			Persos.Pvperso += 50;
			PVMAX += 50;
		}
		else if (Circle_Collision(Persos.posperso, tempbonus->Pos, 35, 35) && tempbonus->Spritebonus == Tete)
		{
			tempbonus = retirBonus(tempbonus);
			maudi += 15;
			Dmg += maudi/3;
			Corruption += 25;
			PVMAX -= 35;
		}
		else if (Circle_Collision(Persos.posperso, tempbonus->Pos, 35, 35) && tempbonus->Spritebonus == Blood)
		{
			tempbonus = retirBonus(tempbonus);
			maudi += 15;
			Corruption += 15;
			PVMAX -=25;
			sangdanslespieds += 0.15;
		}
		
		else
			tempbonus = tempbonus->bonusSuivant;
	}
	if (dieuouicmoi)
	{
		recoveriDieu += GetTimeDelta();
	}
	if (recoveriDieu>=1)
	{
		Persos.Pvperso += 0.5 * sacré;
		recoveriDieu = 0;
	}
	
}

void displayBonus(sfRenderWindow* _window)
{

	tempbonus = debutbonus;
	while (tempbonus != 0)
	{
		if (tempbonus->Spritebonus == Bible)
		{
			
			sfSprite_setOrigin(tempbonus->Spritebonus, OrigineBible);
			sfSprite_setPosition(tempbonus->Spritebonus, tempbonus->Pos);
			sfSprite_setScale(tempbonus->Spritebonus, tempbonus->ScaleBible);
			sfRenderWindow_drawSprite(_window, tempbonus->Spritebonus, NULL);

		}
		if (tempbonus->Spritebonus == Coeur)
		{
			
			sfSprite_setOrigin(tempbonus->Spritebonus, OrigineCoeur);
			sfSprite_setPosition(tempbonus->Spritebonus, tempbonus->Pos);
			sfSprite_setScale(tempbonus->Spritebonus, tempbonus->ScaleBible);
			sfRenderWindow_drawSprite(_window, tempbonus->Spritebonus, NULL);
		}
		if (tempbonus->Spritebonus == Argent)
		{
			sfSprite_setOrigin(tempbonus->Spritebonus, OrigineArgent);
			sfSprite_setPosition(tempbonus->Spritebonus, tempbonus->Pos);
			sfSprite_setScale(tempbonus->Spritebonus, tempbonus->ScaleBible);
			sfRenderWindow_drawSprite(_window, tempbonus->Spritebonus, NULL);
		}
		if (tempbonus->Spritebonus == Graal)
		{
			sfSprite_setOrigin(tempbonus->Spritebonus, OrigineGraal);
			sfSprite_setPosition(tempbonus->Spritebonus, tempbonus->Pos);
			sfSprite_setScale(tempbonus->Spritebonus, tempbonus->ScaleBible);
			sfRenderWindow_drawSprite(_window, tempbonus->Spritebonus, NULL);
		}
		if (tempbonus->Spritebonus == Dieu)
		{
			sfSprite_setOrigin(tempbonus->Spritebonus, OrigineDieu);
			sfSprite_setPosition(tempbonus->Spritebonus, tempbonus->Pos);
			sfSprite_setScale(tempbonus->Spritebonus, tempbonus->ScaleBible);
			sfRenderWindow_drawSprite(_window, tempbonus->Spritebonus, NULL);
		}
		if (tempbonus->Spritebonus == AK)
		{
			sfSprite_setOrigin(tempbonus->Spritebonus, OrigineAK);
			sfSprite_setPosition(tempbonus->Spritebonus, tempbonus->Pos);
			sfSprite_setScale(tempbonus->Spritebonus, tempbonus->ScaleBible);
			sfRenderWindow_drawSprite(_window, tempbonus->Spritebonus, NULL);
		}
		if (tempbonus->Spritebonus == BLASPHEMOUSLIFE)
		{
			sfSprite_setOrigin(tempbonus->Spritebonus, OrigineBLASPHEMOUSLIFE);
			sfSprite_setPosition(tempbonus->Spritebonus, tempbonus->Pos);
			sfSprite_setScale(tempbonus->Spritebonus, tempbonus->ScaleBible);
			sfRenderWindow_drawSprite(_window, tempbonus->Spritebonus, NULL);
		}
		if (tempbonus->Spritebonus == Tete)
		{
			sfSprite_setOrigin(tempbonus->Spritebonus, OrigineTete);
			sfSprite_setPosition(tempbonus->Spritebonus, tempbonus->Pos);
			sfSprite_setScale(tempbonus->Spritebonus, tempbonus->ScaleBible);
			sfRenderWindow_drawSprite(_window, tempbonus->Spritebonus, NULL);
		}
		if (tempbonus->Spritebonus == Blood)
		{
			sfSprite_setOrigin(tempbonus->Spritebonus, OrigineBlood);
			sfSprite_setPosition(tempbonus->Spritebonus, tempbonus->Pos);
			sfSprite_setScale(tempbonus->Spritebonus, tempbonus->ScaleBible);
			sfRenderWindow_drawSprite(_window, tempbonus->Spritebonus, NULL);
		}
		tempbonus = tempbonus->bonusSuivant;
	}
}