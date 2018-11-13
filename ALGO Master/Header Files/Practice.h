#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include <algorithm>
#include <vector>
#include "NumbersClass.h"


class Practice
{
public:
	Practice();
	~Practice();
	void BubbleSortAscending(NumbersClass vectorInput, Texture backgroundTexture);
	void InsertionSortAscending(NumbersClass vectorInput, Texture backgroundTexture);
	void SelectionSortAscending(NumbersClass vectorInput, Texture backgroundTexture);
	void checkBar(vector <NumberInfo> & numbersInput, int & check1, int & check2, int start, int end);

private:
	Clock clock;
	float delayTime;
	bool start;
	bool showScreen;
	bool loopEnded;
	int check1, check2;
	int i, j;
	int len;

	NumbersClass numbersInput;
};