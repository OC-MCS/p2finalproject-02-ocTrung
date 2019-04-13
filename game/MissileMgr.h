#pragma once
#include<iostream>
#include <list>
using namespace std;

#include "Missile.h"

class MissileMgr
{
private:
	// need a list of pointers to missiles
	list<missile*> missileList;
	bool missilesInFlight;

public:
	MissileMgr()
	{
	}
	void addMissile(Vector2f pos, Texture& misTexture)
	{
		missile* newMissile;
		newMissile = new missile(misTexture, pos);
		
		missileList.push_back(newMissile);
		missilesInFlight = true;
	}
	~MissileMgr()
	{
		list<missile*>::iterator iter;
		for (iter = missileList.begin(); iter != missileList.end();)
		{
			iter = missileList.erase(iter);
		}
		cout << "Missile destructor ran" << endl;
	}
	void draw(RenderWindow &win)
	{
		list<missile*>::iterator iter;
		for (iter = missileList.begin(); iter != missileList.end(); iter++)
		{
			(*iter)->draw(win);
		}
	}
	void move()
	{
		list<missile*>::iterator iter;
		for (iter = missileList.begin(); iter != missileList.end(); iter++)
		{
			(*iter)->move();
		}
	}
	bool areMissilesInFlight()
	{
		// check each missiles position to see if it is off the screen
		list<missile*>::iterator iter;
		for (iter = missileList.begin(); iter != missileList.end();)
		{
			if ((*iter)->getYPosition() < 30)
			{
				iter = missileList.erase(iter);
				cout << "missile erased" << endl;
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
};