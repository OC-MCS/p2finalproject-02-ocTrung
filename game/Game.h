#pragma once
#include "BadGuyMgr.h"
#include "GoodGuy.h"
#include "MissileMgr.h"
#include "Hud.h"

enum GameState { STARTSCREEN,LEVEL1,LEVEL2,GAMELOST,GAMEWON };

class Game
{
private:
	GoodGuy goodGuy;
	MissileMgr missileMgr;
	MissileMgr enemyMissileMgr;
	BadGuyMgr badGuyMgr;
	Hud hud;
	int score;
	int lives;
	Sprite background;
	bool runGame;
	GameState gameState;
	Texture starsTexture;
	
public:
	// create game elements & set score and lives
	Game(RenderWindow& window) : goodGuy(window), hud(window)
	{
		if (!starsTexture.loadFromFile("stars.jpg"))
		{
			cout << "Unable to load stars texture!" << endl;
			exit(EXIT_FAILURE);
		}

		background.setTexture(starsTexture);
		// The texture file is 640x480, so scale it up a little to cover 800x600 window
		background.setScale(1.5, 1.5);

		score = 0;
		lives = 3;
		runGame = false;
		gameState = STARTSCREEN;

		enemyMissileMgr.setSpeed(4.0);
	}

	bool drawGameElements(RenderWindow& win)
	{
		win.draw(background);
		hud.update(lives, score);
		hud.draw(win);

		goodGuy.move();
		goodGuy.draw(win);

		badGuyMgr.move(win);
		badGuyMgr.draw(win);

		if (badGuyMgr.didEnemyShoot())
		{
			Vector2f shooterPos;
			shooterPos = badGuyMgr.getShooterPos();
			enemyMissileMgr.addMissile(shooterPos);
		}
		if (enemyMissileMgr.areMissilesInFlight())
		{
			enemyMissileMgr.move();
			enemyMissileMgr.draw(win);
			// check hit here
			if (goodGuy.isHit(enemyMissileMgr.getList()))
			{
				cout << "youve been hit" << endl;
				lives--;
				if (lives > 0)
				{
					setGameState(gameState);
				}
				else 
				{
					setGameState(GAMELOST);
				}
			}
		}
		if (missileMgr.areMissilesInFlight())
		{
			missileMgr.move();
			missileMgr.draw(win);
			if (badGuyMgr.isHit(missileMgr.getList()))
			{
				score++;
			}
		}
		if (!isLevelCleared() && badGuyMgr.isAcrossLine())
		{
			setGameState(gameState);

			lives--;
			if (lives == 0)
				gameState = GAMELOST;
		}

		return isLevelCleared();
	}

	Vector2f getGoodGuyPos()
	{
		return goodGuy.getPosition();
	}

	void addMissile()
	{
		Vector2f curGoodGuyPos = goodGuy.getPosition();
		missileMgr.addMissile(curGoodGuyPos);
	}

	void setRunGame(bool run)
	{
		runGame = run;
	}

	bool isStartBtnPressed()
	{
		return runGame;
	}

	bool isLevelCleared()
	{
		bool levelCleared = false;
		if (badGuyMgr.isEmpty())
		{
			levelCleared = true;
		}
		return levelCleared;
	}

	GameState getGameState()
	{
		return gameState;
	}

	void setGameState(GameState state)
	{
		gameState = state;

		if (gameState == LEVEL2)
		{
			int newSpeed = 4;
			badGuyMgr.reset(newSpeed);
		}
		else if (gameState == LEVEL1 || gameState == STARTSCREEN || gameState == GAMELOST)
		{
			int defaultSpeed = 3;
			badGuyMgr.reset(defaultSpeed);

			if (gameState == GAMELOST)
			{
				lives = 3;
				score = 0;
			}

		}
	}
	int getLivesCounter()
	{
		return lives;
	}
	int getScore()
	{
		return score;
	}
};