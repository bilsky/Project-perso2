#include "Tirs.h"
#include "Player.h"
#include "Mobs.h"
sfRectangleShape* tirs;
sfVector2f sizetirs = { 15,15};
sfVector2f posTirs = { 0,0 };
sfVector2f posMouse = { 0,0 };

float timerTirs = 0;
float reload = 0;
	void PrepareTir(int _HP, float _Vit, sfVector2f _Direction, sfVector2f _PosTirs, TypeEnemie _TypeMob)
	{
		Tirs* TempTirsF = (Tirs*)calloc(1, sizeof(Tirs));
		TempTirsF->VieTirs = _HP;
		TempTirsF->VitTirs = _Vit;
		TempTirsF->DirectiobTirs = _Direction;
		TempTirsF->Postirs = _PosTirs;
		TempTirsF->TypeMob = _TypeMob;
		if (TempTirsF->DirectiobTirs.y < TempTirsF->Postirs.y)
		{
			TempTirsF->VitTirs = acos((TempTirsF->Postirs.x - TempTirsF->DirectiobTirs.x) / sqrt((TempTirsF->Postirs.x - TempTirsF->DirectiobTirs.x) * (TempTirsF->Postirs.x - TempTirsF->DirectiobTirs.x)

				+ (TempTirsF->Postirs.y - TempTirsF->DirectiobTirs.y) * (TempTirsF->Postirs.y - TempTirsF->DirectiobTirs.y)));
		}
		if (TempTirsF->DirectiobTirs.y > TempTirsF->Postirs.y)
		{
			TempTirsF->VitTirs = -acos((TempTirsF->Postirs.x - TempTirsF->DirectiobTirs.x) / sqrt((TempTirsF->Postirs.x - TempTirsF->DirectiobTirs.x) * (TempTirsF->Postirs.x - TempTirsF->DirectiobTirs.x)

				+ (TempTirsF->Postirs.y - TempTirsF->DirectiobTirs.y) * (TempTirsF->Postirs.y - TempTirsF->DirectiobTirs.y)));
		}
	
		if (!AKA)
		{
			TempTirsF->agles.x = -1000.0f * cos(TempTirsF->VitTirs) + iRand(-50, 50);
			TempTirsF->agles.y = -1000.0f * sin(TempTirsF->VitTirs) + iRand(-50, 50);
		}
		else if (AKA)
		{
			TempTirsF->agles.x = -1000.0f * cos(TempTirsF->VitTirs) + iRand(-120, 120);
			TempTirsF->agles.y = -1000.0f * sin(TempTirsF->VitTirs) + iRand(-120, 120);
		}
	

		ajoutTirs(TempTirsF);
	}

	void ajoutTirs(Tirs* _Tirs)
	{
		_Tirs->TirsSuivant = debutTir;
		debutTir = _Tirs;
	}

	Tirs* retirTirs(Tirs* _Tirs)
	{
		if (_Tirs == debutTir)
		{
			Tirs* TempTirsF = _Tirs->TirsSuivant;
			debutTir = TempTirsF;
			free(_Tirs);
			return	TempTirsF;
		}
		else
		{
			Tirs* TempTirsF = debutTir;
			while (TempTirsF->TirsSuivant != _Tirs)
			{
				TempTirsF = TempTirsF->TirsSuivant;
			}
			TempTirsF->TirsSuivant = _Tirs->TirsSuivant;
			free(_Tirs);
			return TempTirsF->TirsSuivant;
		}
		//TempTirs = debutTir;
		//while (TempTirs != 0)
		//{
		//	if (Persos.Pvperso <= 0)
		//	{
		//		TempTirs = retirMob(TempTirs);
		//	}
		//	else TempTirs = TempTirs->TirsSuivant;
		//}
	}
sfSprite* Chargeur;
sfIntRect ChargeurRect = { 0,0,800,227 };
sfVector2f ScaleChargeur = { 0.5,0.5 };
sfVector2f PosChargeur;

void initTirs(sfRenderWindow* _window)
{
	ChargeurRect.height = 227;
	ChargeurRect.left = 0;
	ChargeurRect.top = 0;
	ChargeurRect.width = 800;
	PosChargeur.y = PosATH.y +400.0;
	PosChargeur.x = PosATH.x - 850.0;
	Chargeur = CreateSprite("../Ressources/Textures/Balles_deGlockForReal.png");
	sfSprite_setScale(Chargeur, ScaleChargeur);

	tirs = sfRectangleShape_create();
	posMouse.x = (float)getMousePos(_window,getview()).x;
	posMouse.y = (float)getMousePos(_window, getview()).y;
	sfRectangleShape_setSize(tirs, sizetirs);

}



void updatdeTirs(sfRenderWindow* _window)
{
	timerTirs += GetTimeDelta();
	if (AKA)
	{
		timerTirs += GetTimeDelta();
	}
	posMouse.x = (float)getMousePos(_window, getview()).x;
	posMouse.y = (float)getMousePos(_window, getview()).y;
	
	if (sfMouse_isButtonPressed(sfMouseLeft) && timerTirs >= 0.2&&Balles>0&& REALODIIING == sfFalse)
	{
		PrepareTir(1, 5.0, posMouse, Persos.posperso,PERSO);
		Balles -= 1;
		ChargeurRect.left += 40;
		timerTirs = 0;
		
	}
	if (Balles<=0|| sfMouse_isButtonPressed(sfMouseRight))
	{
		REALODIIING = sfTrue;
	}
	if (REALODIIING)
	{
		reload += GetTimeDelta();
		
	}
	if (reload >=0.2&& Balles<20)
	{
		ChargeurRect.left -= 40;
		Balles += 1;
		reload = 0;
	}
	else if (reload >= 1.5)
	{
		Balles = 20;
		reload = 0;
		REALODIIING = sfFalse;
		
	}
	TempTirs = debutTir;
	while (TempTirs != 0)
	{
		if (TempTirs->TypeMob==MOBS)
		{
			TempTirs->Postirs.x += TempTirs->agles.x * GetTimeDelta() * VITESSE_TIRS/2;
			TempTirs->Postirs.y += TempTirs->agles.y * GetTimeDelta() * VITESSE_TIRS/2;
		}
		else if (TempTirs->TypeMob == PERSO)
		{
			TempTirs->Postirs.x += TempTirs->agles.x * GetTimeDelta() * VITESSE_TIRS ;
			TempTirs->Postirs.y += TempTirs->agles.y * GetTimeDelta() * VITESSE_TIRS ;
		}

		// LES PROJECTILS DE GROS CANNONS A ENNERGIE PLASMA
		/*	TempTirs->Postirs.x += TempTirs->VitTirs * GetTimeDelta()*(TempTirs->DirectiobTirs.x- TempTirs->Postirs.x);
			TempTirs->Postirs.y += TempTirs->VitTirs * GetTimeDelta()*(TempTirs->DirectiobTirs.y - TempTirs->Postirs.y);*/
		TempTirs->Timer += GetTimeDelta();


		TempTirs = TempTirs->TirsSuivant;
		
	}

	TempTirs = debutTir;
	while (TempTirs != 0)
	{
		if (TempTirs->Postirs.x >= 2000*2 || TempTirs->Postirs.x <= -80*2 || TempTirs->Postirs.y >= 1100*2 || TempTirs->Postirs.y <= -80*2)
		{
			TempTirs->VieTirs -= 1;
			
		}
		if (TempTirs->VieTirs <= 0)
		{
			TempTirs = retirTirs(TempTirs);
		}
		else
			TempTirs = TempTirs->TirsSuivant;
	}

	PosChargeur.y = PosATH.y + 400.0;
	PosChargeur.x = PosATH.x -850.0;
}

void DisplayTirs(sfRenderWindow* _window)
{
	TempTirs = debutTir;
	while (TempTirs != 0)
	{
		if (TempTirs->TypeMob == MOBS)
		{
			sfRectangleShape_setFillColor(tirs, sfRed);
		}
		else if (TempTirs->TypeMob == PERSO)
		{
			sfRectangleShape_setFillColor(tirs, sfYellow);
		}
		sfRectangleShape_setRotation(tirs, TempTirs->VitTirs);
		sfRectangleShape_setPosition(tirs, TempTirs->Postirs);
		sfRenderWindow_drawRectangleShape(_window, tirs, NULL);
		
		TempTirs = TempTirs->TirsSuivant;
	}
	sfSprite_setTextureRect(Chargeur, ChargeurRect);
	sfSprite_setPosition(Chargeur, PosChargeur);
	sfRenderWindow_drawSprite(_window, Chargeur, NULL);
}

void updateVie()
{
	
}