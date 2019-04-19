#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;
using namespace sf;

#include "Game.h"

class Menu
{
private:
	RectangleShape startBackground;
	RectangleShape startBtn;
	Text btnText;
	Font font;
	Text title;

public:
	Menu()
	{
		Vector2f backgroundPos(0, 0);
		startBackground.setPosition(backgroundPos);
		startBackground.setOutlineColor(Color::White);
		startBackground.setOutlineThickness(2);
		startBackground.setSize(Vector2f(800, 600));
		startBackground.setFillColor(Color::Black);

		if (!font.loadFromFile("C:\\Windows\\Fonts\\arial.ttf"))
			die("couldn't load font");

		title.setString("Title");
		title.setFont(font);
		title.setCharacterSize(50);
		title.setPosition(330, 80);
		title.setFillColor(Color::Green);

		btnText.setString("Start");
		btnText.setFont(font);
		btnText.setCharacterSize(20);
		btnText.setPosition(365, 290);
		btnText.setFillColor(Color::Black);

		Vector2f startBtnPos(350, 285);
		startBtn.setPosition(startBtnPos);
		startBtn.setOutlineColor(Color::Transparent);
		startBtn.setOutlineThickness(2);
		startBtn.setSize(Vector2f(110, 65));
		startBtn.setFillColor(Color::Magenta);	
	}
	void draw(RenderWindow& win)
	{
		win.draw(startBackground);
		win.draw(title);
		win.draw(startBtn);
		win.draw(btnText);
	}
	bool isStartButtonPressed(Vector2f mouse)
	{
		bool isBtnPressed = false;
		if (startBtn.getGlobalBounds().contains(mouse))
		{
			isBtnPressed = true;
		}
		return isBtnPressed;
	}
	void setBtnText(String text)
	{
		btnText.setString(text);

	}
	void setTitle(string newTitle)
	{
		title.setString(newTitle);
	}

};