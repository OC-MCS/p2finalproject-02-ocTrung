#pragma once
#include <iostream>
using namespace std;
#include <SFML/Graphics.hpp>
using namespace sf;

class GoodGuy
{
private:
	Sprite goodGuySprite;
	Texture shipTexture;

public:
	GoodGuy(RenderWindow &window)
	{
		if (!shipTexture.loadFromFile("ship.png"))
		{
			cout << "Unable to load ship texture!" << endl;
			exit(EXIT_FAILURE);
		}
		goodGuySprite.setTexture(shipTexture);

		// set initial position
		float shipX = window.getSize().x * 0.75f;
		float shipY = window.getSize().y * 0.75f;
		goodGuySprite.setPosition(shipX, shipY);

	}

	/*===================================
name: move
function: moves goodGuy according to user input
parameters: none
returns: none
=====================================*/
	void move()
	{
		const float DISTANCE = 5.0;

		if (Keyboard::isKeyPressed(Keyboard::Left))
		{
			// left arrow is pressed: move our ship left 5 pixels
			// 2nd parm is y direction. We don't want to move up/down, so it's zero.
			goodGuySprite.move(-DISTANCE, 0);
		}
		else if (Keyboard::isKeyPressed(Keyboard::Right))
		{
			// right arrow is pressed: move our ship right 5 pixels
			goodGuySprite.move(DISTANCE, 0);
		}
	}
	void draw(RenderWindow& win)
	{
		win.draw(goodGuySprite);
	}
	Vector2f getPosition()
	{
		return goodGuySprite.getPosition();
	}

	/*===================================
name: isHit
function: runs through list of missiles to check if any intersect with GoodGuy
parameters: list of missiles
returns: returns true if any missiles intersect with good guy
=====================================*/
	bool isHit(list<missile>& enemyMissileList)
	{
		bool goodGuyHit = false;
		FloatRect goodGuyBounds = goodGuySprite.getGlobalBounds();

		list<missile>::iterator iter;
		for (iter = enemyMissileList.begin(); iter != enemyMissileList.end();)
		{
			FloatRect missileBounds = iter->getGlobalBounds();

			if (missileBounds.intersects(goodGuyBounds))
			{
				goodGuyHit = true;
				iter = enemyMissileList.erase(iter);
			}
			else
			{
				iter++;
			}
		}
		return goodGuyHit;
	}

};