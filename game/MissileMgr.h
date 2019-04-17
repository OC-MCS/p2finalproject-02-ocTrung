#pragma once
#include<iostream>
#include <list>
using namespace std;

#include "Missile.h"

class MissileMgr
{
private:
	// need a list of pointers to missiles
	list<missile> missileList;
	bool missilesInFlight;

public:
	MissileMgr()
	{
	}
	void addMissile(Vector2f pos, Texture& misTexture)
	{
		missile newMissile(misTexture, pos);
		
		missileList.push_back(newMissile);
		missilesInFlight = true;
	}
	~MissileMgr()
	{
		list<missile>::iterator iter;
		for (iter = missileList.begin(); iter != missileList.end();)
		{
			iter = missileList.erase(iter);
		}
		cout << "Missile destructor ran" << endl;
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
	list<missile> getList() 
	{
		return missileList;
	}

	//void isHit(list<BadGuy> badGuyList)
	//{
	//	// go through list of missiles to check for hits
	//	list<missile>::iterator iter;
	//	for (iter = missileList.begin(); iter != missileList.end();)
	//	{
	//		if (iter->isHit(badGuyList))
	//		{
	//			iter = missileList.erase(iter);
	//			cout << "missile hit" << endl;
	//		}
	//		else
	//		{
	//			iter++;
	//		}
	//	}

	//	// we need two lists, a list of bad guys and a list of missiles
	//	// need to past a list of missiles, not a position of one missile
	//}

};