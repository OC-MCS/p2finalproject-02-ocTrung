#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
using namespace std;
using namespace sf;

void die(string msg);

class Hud
{
private:
	int intLives;
	int intScore;

public:
	Hud(RenderWindow& win)
	{

	}

	void draw(RenderWindow& win)
	{
		Font font;
		if (!font.loadFromFile("C:\\Windows\\Fonts\\arial.ttf"))
			die("couldn't load font");

		// title 'Lives'
		Text livesTitle("Lives", font, 20);
		livesTitle.setPosition(30, 25);
		win.draw(livesTitle);

		// displays actual number of lives
		Text lives(to_string(intLives), font, 20);
		lives.setPosition(100, 25);
		win.draw(lives);

		// title 'Score'
		Text scoreTitle("Score", font, 20);
		scoreTitle.setPosition(400, 25);
		win.draw(scoreTitle);

		// displays actual number of aliens hit
		Text score(to_string(intScore), font, 20);
		score.setPosition(500, 25);
		win.draw(score);

	}

	void update(int lives, int score)
	{
		intLives = lives;
		intScore = score;
	}
};



void die(string msg)
{
	cout << msg << endl;
	exit(-1);
}