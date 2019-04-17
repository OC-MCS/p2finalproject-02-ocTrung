#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;

class missile
{
private:
	Sprite missileSprite;
	float Distance;
	bool isMissileInFlight;

public:
	missile(Texture& misTexture, Vector2f GoodGuyPos)
	{
		missileSprite.setTexture(misTexture);
		missileSprite.setPosition(GoodGuyPos);
		Distance = -10.0;
		isMissileInFlight = true;
	}
	void draw(RenderWindow& window)
	{
		window.draw(missileSprite);
	}
	void move()
	{
		missileSprite.move(0, Distance);
	}
	bool isOffScreen()
	{
		bool offScreen = false;

		if (missileSprite.getPosition().y < 0)
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
	/*bool isHit(list<BadGuy> badGuyList)
	{
		bool enemyHit = false;
		FloatRect missileBounds = missileSprite.getGlobalBounds();

		list<BadGuy>::iterator iter;
		for (iter = badGuyList.begin(); iter != badGuyList.end();iter++ )
		{
			FloatRect enemyBounds = iter->getEnemyBounds();

			if (missileBounds.intersects(enemyBounds))
			{
				enemyHit = true;
			}
		}
		return enemyHit;
	}*/


};