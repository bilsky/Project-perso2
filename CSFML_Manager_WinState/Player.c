#include "Player.h"
#include "Tirs.h"
sfBool IsMouving = sfFalse;
sfIntRect PersoRect = { 0,0,31,60 };
sfVector2f ScalePerso = { 2.5,2.5 };
sfVector2f originePerso = { 15.5,30 };

sfBool FrameInv = sfFalse;
float doubleTouch = 0;
float Roulade = 0;
void initPlayer()
{
	sangdanslespieds = 1;
	AKA = sfFalse;
	sacré = 0;
	maudi = 0;
	Dmg = 1;
	REALODIIING = sfFalse;
	Balles = 20;
	Corruption = 0;
	Persos.perso = CreateSprite("../Ressources/Textures/Perso_et_Npc/Mc.png");
	Persos.posperso.x = 1920;
	Persos.posperso.y = 1080;
	Persos.Pvperso = PVMAX;
	sfSprite_setOrigin(Persos.perso, originePerso);
	sfSprite_setPosition(Persos.perso, Persos.posperso);
}

void updatePlayer()
{

	doubleTouch += GetTimeDelta();
	if (sfKeyboard_isKeyPressed(sfKeySpace) && doubleTouch >= 0.8 && FrameInv == sfFalse)
	{
		FrameInv = sfTrue;

		PersoRect.left = 200;
		PersoRect.top = 177;
		PersoRect.height = 57;
		PersoRect.width = 39;
		doubleTouch = 0;
	}
	if (FrameInv == sfTrue)
		Roulade += GetTimeDelta();
	if (FrameInv == sfTrue && Roulade >= 0.5)
	{
		PersoRect.left = 0;
		PersoRect.top = 0;

		PersoRect.height = 60;
		PersoRect.width = 31;

		FrameInv = sfFalse;
		Roulade = 0;
	}
	if (sfKeyboard_isKeyPressed(sfKeyA))
	{
		Persos.posperso.x -= VITESSEPERSO / sangdanslespieds * GetTimeDelta();

	}
	if (sfKeyboard_isKeyPressed(sfKeyD))
	{
		Persos.posperso.x += VITESSEPERSO / sangdanslespieds * GetTimeDelta();
	}
	if (sfKeyboard_isKeyPressed(sfKeyS))
	{
		Persos.posperso.y += VITESSEPERSO / sangdanslespieds * GetTimeDelta();
	}

	if (sfKeyboard_isKeyPressed(sfKeyZ))
	{
		Persos.posperso.y -= VITESSEPERSO / sangdanslespieds * GetTimeDelta();
	}
	TempTirs = debutTir;
	while (TempTirs != 0)
	{
		if (Circle_Collision(Persos.posperso, TempTirs->Postirs, 25, 10) && TempTirs->TypeMob == MOBS && FrameInv == sfFalse)
		{
			Persos.Pvperso -= 10;
			TempTirs->VieTirs -= 1;
			Corruption += 2;

		}

		TempTirs = TempTirs->TirsSuivant;
	}

	if (Persos.posperso.x<=120)
	{
		Persos.posperso.x =120;
	}
	if (Persos.posperso.x >= 1920 * 2-120)
	{
		Persos.posperso.x = 1920 *2-120;
	}
	if (Persos.posperso.y <= 0 + 160)
	{
		Persos.posperso.y = 0 + 160;

	}
	if (Persos.posperso.y >= 1080 * 2- 160)
	{
		Persos.posperso.y = 1080 * 2- 160;
	}

}

void DrawPlayer(sfRenderWindow* _window)
{
	sfSprite_setPosition(Persos.perso, Persos.posperso);
	sfSprite_setScale(Persos.perso, ScalePerso);
	sfSprite_setTextureRect(Persos.perso, PersoRect);
	sfRenderWindow_drawSprite(_window, Persos.perso, NULL);
}

sfView* view;

sfFloatRect rectView = { 1920,1080,1920 / 2,1080 / 2 };

sfView* getview()
{
	return view;
}

sfView* viewinit(sfRenderWindow* _window)
{
	view = sfView_create();
	sfFloatRect rectViewPort = { 0.f, 0.f, 1.0f, 1.0f };
	sfView_setViewport(view, rectViewPort);
	sfView_reset(view, rectView);
	view = sfRenderWindow_getView(_window);

	return view;

}

void updateView()
{
	ViewPos.x = Persos.posperso.x;
	ViewPos.y = Persos.posperso.y;
	if (ViewPos.x <= +1920 / 2)
	{
		ViewPos.x = 1920 / 2;
	}
	if (ViewPos.x >= 1920*1.5)
	{
		ViewPos.x = 1920 * 1.5;
	}
	if (ViewPos.y <= 1080/2)
	{
		ViewPos.y = 1080 / 2;
	}
	if (ViewPos.y >= 1080 * 1.5)
	{
		ViewPos.y = 1080 * 1.5;
	}
	sfView_setCenter(view, ViewPos);

		
	
		

}

sfRenderWindow* displayView(sfRenderWindow* _window)
{
	sfRenderWindow_setView(_window, view);
}

sfRectangleShape* BarreVie;
sfVector2f BarreVieScale = { 0,50 };
sfVector2f posBarreVie = { 0,0 };

sfRectangleShape* BarreCOR;
sfVector2f BarreCORScale = { 0,50 };
sfVector2f posBarreCOR = { 0,100 };


sfText* text;
sfVector2f PosText = { 0,0 };
char ScoreString[30] = "";
void initATH()
{
	text = CreateText("../Ressources/Fonts/Satanyc_Demoniac_St.ttf");
	sfText_setCharacterSize(text, 45);
	sfText_setColor(text, sfRed);


	score = 0;
	PVMAX = 100;
	PosATH.x = 0;
	PosATH.y = 0;
	BarreVieScale.x = Persos.Pvperso;
	BarreCORScale.x = Corruption * 10;
	BarreVie = sfRectangleShape_create();
	sfRectangleShape_setFillColor(BarreVie, sfRed);
	BarreCOR = sfRectangleShape_create();
	sfRectangleShape_setFillColor(BarreCOR, sfWhite);

}
void updateATH()
{
	sprintf(ScoreString, "Score:%d", score);
	BarreVieScale.x = Persos.Pvperso * 5;
	if (Persos.Pvperso >= PVMAX)
	{
		Persos.Pvperso = PVMAX;
	}

	BarreCORScale.x = Corruption * 5;
	sfRectangleShape_setSize(BarreVie, BarreVieScale);
	sfRectangleShape_setSize(BarreCOR, BarreCORScale);
	PosATH.y = ViewPos.y;
	PosATH.x = ViewPos.x;

	posBarreVie.y = PosATH.y - 500.0;
	posBarreVie.x = PosATH.x - 850.0;

	posBarreCOR.y = PosATH.y - 400.0;
	posBarreCOR.x = PosATH.x - 850.0;

	PosText.y = PosATH.y - 450;
	PosText.x = PosATH.x - 100;


	if (Corruption <= 0)
	{
		Corruption = 0;
	}

}

sfRenderWindow* displayATH(sfRenderWindow* _window)
{
	sfRectangleShape_setPosition(BarreVie, posBarreVie);
	sfRenderWindow_drawRectangleShape(_window, BarreVie, NULL);
	sfRectangleShape_setPosition(BarreCOR, posBarreCOR);
	sfRenderWindow_drawRectangleShape(_window, BarreCOR, NULL);
	sfText_setPosition(text, PosText);
	sfText_setString(text, ScoreString);
	sfRenderWindow_drawText(_window, text, NULL);
}