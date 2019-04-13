#pragma once
//#include <iostream>
//using namespace std;
#include <SFML/Graphics.hpp>
using namespace sf;

class BadGuy
{
private:
	Sprite badGuySprite;
	bool isHit;
public:
	BadGuy(Texture &text, Vector2f pos)
	{
		badGuySprite.setTexture(text);
		isHit = false;
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
};