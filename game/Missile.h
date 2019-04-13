#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;

class missile
{
private:
	Sprite missileSprite;
	float Speed;
	bool isMissileInFlight;

public:
	missile(Texture& misTexture, Vector2f GoodGuyPos)
	{
		missileSprite.setTexture(misTexture);
		missileSprite.setPosition(GoodGuyPos);
		Speed = -10.0;
		isMissileInFlight = false;
	}
	void draw(RenderWindow& window)
	{
		window.draw(missileSprite);
		isMissileInFlight = true;
	}
	void move()
	{
		missileSprite.move(0, Speed);
	}
	bool isInFlight()
	{
		return isMissileInFlight;
	}
	int getYPosition()
	{
		return missileSprite.getPosition().y;
	}

};