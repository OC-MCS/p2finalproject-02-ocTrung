#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;

class missile
{
private:
	Sprite missileSprite;
	float distance;
	bool isMissileInFlight;

public:
	missile(Texture& misTexture, Vector2f GoodGuyPos)
	{
		missileSprite.setTexture(misTexture);
		missileSprite.setPosition(GoodGuyPos);
		distance = -10.0;
		isMissileInFlight = true;
	}
	void draw(RenderWindow& window)
	{
		window.draw(missileSprite);
	}
	void move()
	{
		missileSprite.move(0, distance);
	}
	bool isOffScreen()
	{
		bool offScreen = false;

		if (missileSprite.getPosition().y < 0 || missileSprite.getPosition().y > 800)
		{
			offScreen = true;
		}

		return offScreen;
	}
	int getYPosition()
	{
		return missileSprite.getPosition().y;
	}
	FloatRect getGlobalBounds()
	{
		return missileSprite.getGlobalBounds();
	}
	void setSpeedandDirection(float speed)
	{
		distance = speed;
	}

};