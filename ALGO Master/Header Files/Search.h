#pragma once

#ifndef Search_H
#define Search_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include <algorithm>
#include <vector>
#include "NumbersClass.h"

class Search
{
public:
	NumbersClass binarySearch(NumbersClass vectorInput, int n, Texture backgroundTexture);
	NumbersClass linearSearch(NumbersClass vectorInput, int n, Texture backgroundTexture);
	Search();
	~Search();
private:
	Texture notFoundImage;
	Sprite notFound;
	Clock clock;
	bool pause;
	bool stepForward;
	bool stepBackward;
	bool iteration;
	bool start;
	bool end;
	bool showScreen;
	bool found;
	NumbersClass numbersInput;
	int step;
	bool printNotFound;
	float delayTime;
};

#endif