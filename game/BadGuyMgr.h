#pragma once
#include<list>
#include<iostream>
#include<ctime>
using namespace std;
#include"BadGuy.h"

class BadGuyMgr
{
private:
	list<BadGuy> badGuyList;
	Texture badGuyTexture;
	bool goleft;
	bool goright;
	bool goDown;
	int distance; //distance moved per frame aka speed
	int shooter;
	int lastShooter;
	int downDistance;

public:
	BadGuyMgr()
	{
		if (!badGuyTexture.loadFromFile("enemy.png"))
		{
			cout << "Unable to load badguy texture!" << endl;
			exit(EXIT_FAILURE);
		}
		const int DISTANCEBETWEENBGUYS = 65;
		Vector2f firstPos(50, 100);
		Vector2f distanceBtwn(DISTANCEBETWEENBGUYS, 0);
		for (int i = 0; i < 10; i++)
		{
			BadGuy newBadGuy(badGuyTexture, firstPos);
			badGuyList.push_back(newBadGuy);
			firstPos = firstPos + distanceBtwn;
		}
		goleft = false;
		goright = true;
		goDown = false;
		distance = 3;
		downDistance = 15;
		lastShooter = 0;
	}
	
/*===================================
name: draw
function: runs through list of badGuys and draws them
parameters: window of the game
=====================================*/
	void draw(RenderWindow& win)
	{
		list<BadGuy>::iterator iter;
		for (iter = badGuyList.begin(); iter != badGuyList.end(); iter++)
		{
			iter->draw(win);
		}
	}

	/*===================================
name: move
function: move all badGuys in the list (left and right and down when appropriate)
parameters: window of the game
=====================================*/
	void move(RenderWindow& win)
	{
		int counter = 0;
		// find last guy on the right
		list<BadGuy>::iterator iter;
		for (iter = badGuyList.begin(); iter != badGuyList.end(); iter++)
		{
			counter++;
		}
		iter = badGuyList.begin();
		advance(iter, counter -1);
		
		if (iter->getXPos() > 750)
		{
			goleft = true;
			goright = false;
			goDown = true;
		}
		else if (badGuyList.begin()->getXPos() < 20)
		{
			goleft = false;
			goright = true;
		}
		if (goleft)
		{
			list<BadGuy>::iterator it;
			for (it = badGuyList.begin(); it != badGuyList.end(); it++)
			{
				it->moveDistance(-distance, 0);
			}
			if (goDown)
			{
				for (it = badGuyList.begin(); it != badGuyList.end(); it++)
				{
					it->moveDistance(-distance, downDistance);
				}
				goDown = false;
			}
		}
		else if (goright)
		{
			list<BadGuy>::iterator it;
			for (it = badGuyList.begin(); it != badGuyList.end(); it++)
			{
				it->moveDistance(distance, 0);
			}
		}
	}

	/*===================================
name: isHit
function: runs through each BadGuy on the list to check for hits
parameters: list of missiles
=====================================*/
	bool isHit(list<missile>& missileList)
	{
		bool hit = false;
		// go through list of bad guys to check for hits
		list<BadGuy>::iterator iter;
		for (iter = badGuyList.begin(); iter != badGuyList.end();)
		{
			if (iter->isHit(missileList))
			{
				hit = true;
  				iter = badGuyList.erase(iter);
			}
			else
			{
				iter++;
			}
		}
		return hit;
	}
	list<BadGuy>& getList()
	{
		return badGuyList;
	}
	// changes speed of BadGuys moving left and right
	void setSpeed(int speed)
	{
		distance = speed;
	}
	bool isEmpty()
	{
		bool empty = false;

		if (badGuyList.empty())
		{
			empty = true;
		}
		return empty;
	}

	/*===================================
name: reset
function: deletes all badguys from previous state; repopulates with new bad guys; changes speed 
parameters: new speed 
=====================================*/
	void reset(int speed)
	{
		// delete all badguys from previous state
		list<BadGuy>::iterator it;
		for (it = badGuyList.begin(); it != badGuyList.end();)
		{
			it = badGuyList.erase(it);
		}

		// repopulate new bad guys and change speed/distance
		const int DISTANCEBETWEENBGUYS = 65;
		Vector2f firstPos(50, 100);
		Vector2f distanceBtwn(DISTANCEBETWEENBGUYS, 0);
		for (int i = 0; i < 10; i++)
		{
			BadGuy newBadGuy(badGuyTexture, firstPos);
			badGuyList.push_back(newBadGuy);
			firstPos = firstPos + distanceBtwn;
		}
		goleft = false;
		goright = true;
		distance = speed;
	}

	/*===================================
name: didEnemyShoot
function: randomly generates a number and assigns it to shooter if it is within bounds of number of enemies
parameters: none
returns: returns true of the number is within the number of badGuys that exists
=====================================*/
	bool didEnemyShoot()
	{
		bool enemyShot = false;
		srand(time(0));

		int maxValue = badGuyList.size() + 10;
		shooter = (rand() % maxValue);

		if (shooter > 0 && shooter < badGuyList.size())
		{
			if (shooter != lastShooter)
			{
				enemyShot = true;
				lastShooter = shooter;
			}
		}
		return enemyShot;
	}

	/*===================================
name: getShooterPos
function: finds the BadGuy who shot 
parameters: none
returns: returns position of bad guy
=====================================*/
	Vector2f getShooterPos()
	{
		Vector2f shooterPos;

		list<BadGuy>::iterator iter;
		iter = badGuyList.begin();
		advance(iter, shooter); //advance to shooter position
		shooterPos = iter->getPosition();

		return shooterPos;
	}

	/*===================================
name: isAcrossLine
function: checks if enemies have reached the ship
parameters: none
returns: returns true if enemies reach the ship
=====================================*/
	bool isAcrossLine()
	{
		bool acrossLine = false;

		list<BadGuy>::iterator it;
		it = badGuyList.begin();
		if (it->getYPos() > 400)
		{
			acrossLine = true;
		}
		return acrossLine;
	}
};