#pragma once

#include "Menu.h"
#include "Hud.h"

class GameUI
{
private:
	Menu startScreen;
	Menu gameWonScreen;
	Menu gameLostScreen;
	Game *gamePtr;
	bool levelCleared;
	bool startBtnPressed;

public:
	GameUI(Game *game, RenderWindow& win)
	{
		gamePtr = game;
		levelCleared = false;
		startBtnPressed = false;
		gameWonScreen.setBtnText("RESTART?");
		gameWonScreen.setTitle("You Won!");
		startScreen.setTitle("Aliens!");
		gameLostScreen.setTitle("Game Over");
		startScreen.setBtnText("I want to shoot something now");
		gameLostScreen.setBtnText("RESTART?");
	}

	/*===================================
name: handleMouseUp
function: checks if menu button is pressed
parameters: mouse position
returns: none
=====================================*/
	void handleMouseUp(Vector2f mouse)
	{
		if (startScreen.isStartButtonPressed(mouse))
		{
			startBtnPressed = true;
		}
	}

	/*===================================
name: draw
function: checks gamestate and draws the appropriate things
parameters: renderwindow
returns: none
=====================================*/
	void draw(RenderWindow& window)
	{
		// new code using gamestates
		if (startBtnPressed && (gamePtr->getGameState() == STARTSCREEN || gamePtr->getGameState() == GAMEWON || gamePtr->getGameState() == GAMELOST))
		{
			gamePtr->setGameState(LEVEL1);
			startBtnPressed = false; // resetting flag
		}
		else if (gamePtr->getGameState() == STARTSCREEN)
		{
			startScreen.draw(window);
		}
		else if (gamePtr->getGameState() == GAMEWON)
		{
			gameWonScreen.draw(window);
			gamePtr->setLives(3);
			gamePtr->setScore(0);
		}
		else if (gamePtr->getGameState() == LEVEL1 && !levelCleared)
		{
			levelCleared = gamePtr->drawGameElements(window);
		}
		else if (gamePtr->getGameState() == LEVEL1 && levelCleared)
		{
			gamePtr->setGameState(LEVEL2);
			levelCleared = false; //resetting the flag
		}
		else if (gamePtr->getGameState() == LEVEL2 && !levelCleared)
		{
			levelCleared = gamePtr->drawGameElements(window);
		}
		else if (gamePtr->getGameState() == LEVEL2 && levelCleared)
		{
			gamePtr->setGameState(GAMEWON);
			levelCleared = false; //resetting flag
		}
		else if (gamePtr->getGameState() == GAMELOST)
		{
			gameLostScreen.draw(window);
		}
	}


};