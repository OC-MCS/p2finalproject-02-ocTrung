#pragma once
#include "BadGuyMgr.h"
#include "GoodGuy.h"
#include "MissileMgr.h"
#include "Hud.h"

class Game
{
private:
	GoodGuy goodGuy;
	MissileMgr missileMgr;
	BadGuyMgr badGuyMgr;
	Hud hud;
	int score;
	int lives;
	Sprite background;
	
public:
	// what happens when the game starts?
	// draw background
	// draw scores and lives
	// create ship
	// create missile mgr
	// create aliens
	// draw everything

	// create game elements & set score and lives
	Game(Texture& goodTexture,  Texture& badTexture, Texture& starsTexture, RenderWindow& window) : goodGuy(goodTexture, window), badGuyMgr(badTexture), hud(window)
	{
		background.setTexture(starsTexture);
		// The texture file is 640x480, so scale it up a little to cover 800x600 window
		background.setScale(1.5, 1.5);

		score = 0;
		lives = 3;
		
	}

	void drawGameElements(RenderWindow& win)
	{
		win.draw(background);
		hud.draw(win);

		goodGuy.move();
		goodGuy.draw(win);

		badGuyMgr.move(win);
		badGuyMgr.draw(win);

		if (missileMgr.areMissilesInFlight())
		{
			// ***code goes here to handle a missile in flight
			// don't forget to turn the flag off when the missile goes off screen!

			missileMgr.move();
			missileMgr.draw(win);
			checkHits();

		}

	}

	Vector2f getGoodGuyPos()
	{
		return goodGuy.getPosition();
	}

	void addMissile(Texture& texture)
	{
		Vector2f curGoodGuyPos = goodGuy.getPosition();

		missileMgr.addMissile(curGoodGuyPos, texture);
	}

	void checkHits()
	{
		badGuyMgr.isHit(missileMgr.getList());
		//missileMgr.isHit(badGuyMgr.getList());
	}

};