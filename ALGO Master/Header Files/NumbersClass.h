#pragma once

#ifndef NUMBER_CLASS_H
#define NUMBER_CLASS_H

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <vector>
#include <iostream>
#include <string>

using namespace sf;
using namespace std;

extern RenderWindow window;

class NumberInfo {		//This class is created to contain individual information of data
public:
	RectangleShape numberShape;	//The shape of number
	Vector2f position;			//The position of shape
	Vector2f shapeSize;			//The size of shape
	int number;					//The value of the number
	Text value;
	Vector2f textPosition;

	//Logical Operator Overloading
	bool operator<(NumberInfo a);
	bool operator<=(NumberInfo a);
	bool operator>(NumberInfo a);
	bool operator>=(NumberInfo a);
	bool operator==(NumberInfo a);
};

extern RenderWindow window;
extern float speed;

class NumbersClass
{
public:
	vector <NumberInfo> numbers;		//Main data structure where numbers will be saved

public:
	NumbersClass();
	~NumbersClass();
	void draw();	//Function to draw the numbers
	void PushVector(int number, float height);		//Function to input numbers in the vector/data structure
	void PopVector(int number);			//Function to delete numbers in the vector/data structure
	void resetTotalNumbers();
	//void Swap(NumberInfo a, NumberInfo b);
	/*
	There's a bug in the PopVector it'll delete the first number which will match with given number.
	This bug might be fixed by using iterator/ position of a vector rather than the number it self.
	*/

private:
	NumberInfo temp;
	vector<NumberInfo>::iterator searchNumber = numbers.begin();

	int totalNumbers = 0;
	Font valueFont;
	Vector2u resolution;
	//float screenHeight = (resolution.y*5) / 12;			//The screen height where the simulation will be shown
	//float screenWidth = (resolution.x*4) / 5;		//The screen width where the simulation will be shown
	float screenHeight;
	float screenWidth;
	Vector2f screenPosition;			//The position of the screen where simulation will be shown
};
#endif

