#pragma once
#include<iostream>
#include <list>
using namespace std;

#include "Missile.h"

class MissileMgr
{
private:
	list<missile> missileList;
	bool missilesInFlight;
	Texture missileTexture;
	float speed;

public:
	MissileMgr()
	{
		if (!missileTexture.loadFromFile("missile.png"))
		{
			cout << "Unable to load missile texture!" << endl;
			exit(EXIT_FAILURE);
		}
		speed = -10.0;
	}
	void addMissile(Vector2f pos)
	{
		missile newMissile(missileTexture, pos);
		newMissile.setSpeedandDirection(speed);
		missileList.push_back(newMissile);
		missilesInFlight = true;
	}
	
	void draw(RenderWindow &win)
	{
		list<missile>::iterator iter;
		for (iter = missileList.begin(); iter != missileList.end(); iter++)
		{
			iter->draw(win);
		}
	}
	void move()
	{
		list<missile>::iterator iter;
		for (iter = missileList.begin(); iter != missileList.end(); iter++)
		{
			iter->move();
		}
	}
	bool areMissilesInFlight()
	{
		// check each missiles position to see if it is off the screen
		list<missile>::iterator iter;
		for (iter = missileList.begin(); iter != missileList.end(); )
		{
			if (iter->isOffScreen())
			{
				iter = missileList.erase(iter);
			}
			else
			{
				iter++;
			}
		}
		if (missileList.empty())
		{
			missilesInFlight = false;
		}
		return missilesInFlight;
	
	}
	list<missile>& getList() 
	{
		return missileList;
	}
	void setSpeed(int speedInput)
	{
		speed = speedInput;
	}
};