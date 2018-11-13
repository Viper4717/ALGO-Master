#pragma once

#ifndef SORT_H
#define SORT_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include <algorithm>
#include <vector>
#include "NumbersClass.h"


using namespace sf;
using namespace std;

class Sort
{
public:
	Sort();
	~Sort();
	NumbersClass BubbleSortAscending(NumbersClass vectorInput, Texture backgroundTexture);
	NumbersClass BubbleSortDescending(NumbersClass vectorInput, Texture backgroundTexture);
	NumbersClass InsertionSortAscending(NumbersClass vectorInput, Texture backgroundTexture);
	NumbersClass InsertionSortDescending(NumbersClass vectorInput, Texture backgroundTexture);
	NumbersClass SelectionSortAscending(NumbersClass vectorInput, Texture backgroundTexture);
	NumbersClass SelectionSortDescending(NumbersClass numbersInput, Texture backgroundTexture);
private:
	Clock clock;
	bool pause;
	bool stepForward;
	bool stepBackward;
	bool iteration;
	bool start;
	bool end;
	bool showScreen;
	NumbersClass numbersInput;
	float delayTime;
};

#endif