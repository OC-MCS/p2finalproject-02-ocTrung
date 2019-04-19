#pragma once
//#include <iostream>
//using namespace std;
#include <SFML/Graphics.hpp>
using namespace sf;

class BadGuy
{
private:
	Sprite badGuySprite;
public:
	BadGuy(Texture &text, Vector2f pos)
	{
		badGuySprite.setTexture(text);
		badGuySprite.setPosition(pos);
	}
	void draw(RenderWindow& win)
	{
		win.draw(badGuySprite);
	}
	Vector2f getPosition()
	{
		return badGuySprite.getPosition();
	}
	void setPosition(Vector2f pos)
	{
		badGuySprite.setPosition(pos);
	}
	void moveDistance(float x, float y)
	{
		badGuySprite.move(x, y);
	}
	int getXPos()
	{
		return badGuySprite.getPosition().x;
	}
	int getYPos()
	{
		return badGuySprite.getPosition().y;
	}
	FloatRect getEnemyBounds()
	{
		return badGuySprite.getGlobalBounds();
	}
/*===================================
name: isHit
function: runs through list of missiles and returns true if any intersect with BadGuy
parameters: list of missiles
=====================================*/
	bool isHit(list<missile>& missileList)
	{
		bool enemyHit = false;
		FloatRect enemyBounds = badGuySprite.getGlobalBounds();

		list<missile>::iterator iter;
		for (iter = missileList.begin(); iter != missileList.end();)
		{
			FloatRect missileBounds = iter->getGlobalBounds();

			if (missileBounds.intersects(enemyBounds))
			{
				enemyHit = true;
				iter = missileList.erase(iter);
			}
			else
			{
				iter++;
			}
		}
		return enemyHit;
	}
};