#pragma once

#ifndef Button_H
#define Button_H

#include <SFML/Graphics.hpp>

using namespace sf;
using namespace std;

class Button
{
public:
	Button(float width, float height);
	~Button();
	void buttonDraw(int itemStart, int itemEnd);
	void sliderDraw();
	int mouseCheck(Sprite *buttons, int itemStart, int itemEnd);
	//void sliderCheck(RectangleShape &slider, CircleShape &sliderButton);
	void sliderCheck();
public:
	Text buttonText[8];
	Sprite buttonSprites[8];
	Texture buttonTextures[11][2];
	RectangleShape slider;
	CircleShape sliderButton;
	CircleShape sliderButtonReflection;
	Text sliderText[2];
private:
	Font font;
	Text tempText;
};

#endif

