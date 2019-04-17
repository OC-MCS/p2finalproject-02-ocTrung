#pragma once
#include<list>
#include<iostream>
using namespace std;
#include"BadGuy.h"

class BadGuyMgr
{
private:
	list<BadGuy> badGuyList;
	bool goleft;
	bool goright;

public:
	BadGuyMgr(Texture& text)
	{
		const int DISTANCEBETWEENBGUYS = 65;
		Vector2f firstPos(50, 100);
		Vector2f distance(DISTANCEBETWEENBGUYS, 0);
		for (int i = 0; i < 10; i++)
		{
			BadGuy newBadGuy(text, firstPos);
			badGuyList.push_back(newBadGuy);
			firstPos = firstPos + distance;
		}
		goleft = false;
		goright = true;
	}
	/*~BadGuyMgr()
	{
		list<BadGuy>::iterator iter;
		for (iter = badGuyList.begin(); iter != badGuyList.end();)
		{
			iter = badGuyList.erase(iter);
		}
		cout << "badGuyList destructor ran" << endl;
	}*/
	void draw(RenderWindow& win)
	{
		list<BadGuy>::iterator iter;
		for (iter = badGuyList.begin(); iter != badGuyList.end(); iter++)
		{
			iter->draw(win);
		}
	}
	void move(RenderWindow& win)
	{
		const float DISTANCE = 3.0;
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
		}
		else if (iter->getXPos() < 590)
		{
			goleft = false;
			goright = true;
		}
		if (goleft)
		{
			list<BadGuy>::iterator it;
			for (it = badGuyList.begin(); it != badGuyList.end(); it++)
			{
				it->moveDistance(-DISTANCE, 0);
			}
		}
		else if (goright)
		{
			list<BadGuy>::iterator it;
			for (it = badGuyList.begin(); it != badGuyList.end(); it++)
			{
				it->moveDistance(DISTANCE, 0);
			}
		}
	}

	void isHit(list<missile> missileList)
	{
		// go through list of missiles to check for hits
		list<BadGuy>::iterator iter;
		for (iter = badGuyList.begin(); iter != badGuyList.end();)
		{
			if (iter->isHit(missileList))
			{
				iter = badGuyList.erase(iter);
				cout << "missile hit" << endl;
			}
			else
			{
				iter++;
			}
		}

		// we need two lists, a list of bad guys and a list of missiles
		// need to past a list of missiles, not a position of one missile
	}
	list<BadGuy> getList()
	{
		return badGuyList;
	}
};