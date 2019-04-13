#pragma once
#include<list>
#include<iostream>
using namespace std;
#include"BadGuy.h"

class BadGuyMgr
{
private:
	list<BadGuy*> badGuyList;
	bool goleft;
	bool goright;

public:
	BadGuyMgr(Texture& text)
	{
		Vector2f firstPos(50, 50);
		Vector2f distance(50, 0);
		for (int i = 0; i < 10; i++)
		{
			BadGuy* newBadGuy;
			newBadGuy = new BadGuy(text, firstPos);
			badGuyList.push_back(newBadGuy);
			firstPos = firstPos + distance;
		}
		goleft = false;
		goright = true;
	}
	~BadGuyMgr()
	{
		list<BadGuy*>::iterator iter;
		for (iter = badGuyList.begin(); iter != badGuyList.end();)
		{
			iter = badGuyList.erase(iter);
		}
		cout << "badGuyList destructor ran" << endl;
	}
	void draw(RenderWindow& win)
	{
		list<BadGuy*>::iterator iter;
		for (iter = badGuyList.begin(); iter != badGuyList.end(); iter++)
		{
			(*iter)->draw(win);
		}
	}
	void move(RenderWindow& win)
	{
		const float DISTANCE = 3.0;
		
		int sizeOfRow = 10; // number of bad guys in a row
		list<BadGuy*>::iterator iter;
		iter = badGuyList.begin();
		advance(iter, 9); // find the left most bad guy 
		
		if ((*iter)->getXPos() > 775)
		{
			goleft = true;
			goright = false;
		}
		else if ((*iter)->getXPos() < 450)
		{
			goleft = false;
			goright = true;
		}
		if (goleft)
		{
			list<BadGuy*>::iterator it;
			for (it = badGuyList.begin(); it != badGuyList.end(); it++)
			{
				(*it)->moveDistance(-DISTANCE, 0);
			}
		}
		else if (goright)
		{
			list<BadGuy*>::iterator it;
			for (it = badGuyList.begin(); it != badGuyList.end(); it++)
			{
				(*it)->moveDistance(DISTANCE, 0);
			}
		}
	}
};