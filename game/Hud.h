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
	/*Text lives;
	Text score;
	RectangleShape gameArea;
	Text livesTitle;*/
	//Text scoreTitle;
	int intLives;
	int intScore;

public:
	Hud(RenderWindow& win)
	{
	/*	Vector2f gameAreaPos(0, 0);
		gameArea.setPosition(gameAreaPos);
		gameArea.setOutlineColor(Color::White);
		gameArea.setOutlineThickness(2);
		gameArea.setSize(Vector2f(800, 600));
		gameArea.setFillColor(Color::Transparent);*/

		intLives = 3;
		intScore = 0;
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

	void subtractLife()
	{
		intLives--;
	}

	void addToScore()
	{
		intScore++;
	}
};

void die(string msg)
{
	cout << msg << endl;
	exit(-1);
}