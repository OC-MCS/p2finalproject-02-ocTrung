#pragma once
#include <iostream>
using namespace std;
#include <SFML/Graphics.hpp>
using namespace sf;

class GoodGuy
{
private:
	Sprite goodGuySprite;
	bool isHit;
	int lives;

public:
	GoodGuy(Texture &goodGuyTexture, RenderWindow &window)
	{
		goodGuySprite.setTexture(goodGuyTexture);
		isHit = false;
		lives = 3;

		// set initial position
		float shipX = window.getSize().x * 0.75f;
		float shipY = window.getSize().y * 0.75f;
		goodGuySprite.setPosition(shipX, shipY);

	}
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
	
};