#pragma once

#ifndef Interrupt_Handle_H
#define Interrupt_Handle_H

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <Windows.h>
#include <mmsystem.h>
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include "Menu.h"
#include "NumbersClass.h"
#include "Sort.h"
#include "Search.h"
#include "PseudoCode.h"
#include "Button.h"
#include "Practice.h"

#define setBarColor(shape)    shape.setFillColor(Color(255, 255, 255))

#define setHoverColor(shape)    shape.setFillColor(Color(204, 235, 255))
#define setWrongColor(shape)    shape.setFillColor(Color(99, 0, 0))
#define setCorrectColor(shape)    shape.setFillColor(Color(0, 230, 115))

#define setTextColors(text)    text.setFillColor(Color(204, 79, 8));
#define setMenuTextColors(text)     text.setFillColor(Color(255, 255, 255, 255))
#define setBarColorDone(shape)	   shape.setFillColor(Color(60, 179, 113))
#define setBarColorActive(shape) shape.setFillColor(Color(0, 158, 255))
#define setBarColorCheck(shape)    shape.setFillColor(Color::Yellow)
#define setBarColorOff(shape)    shape.setFillColor(Color(255, 255, 255, 100))
#define setPseudoColorFont(text)    text.setFillColor(Color(14, 34, 132))
#define setPseudoColorMarker(shape)    shape.setFillColor(Color(255, 119, 0))
//#define dtDelay 0.5f

enum states {
	mainMenu, simulation, practice, quit, sorting, searching, method, input, random, bubble, insertion, selection, binary, linear, practiceBubble, practiceInsertion, practiceSelection
};

enum algoChoose {
	algoSort, algoSearch
};

enum taskChoose {
	simTask, pracTask
};

class InterruptHandle
{
public:
	InterruptHandle();
	~InterruptHandle();

	void windowHandle();
	void menuUpdate(Menu &menu, int & mouseReturn, int & buttonReturn, NumbersClass &numbersInput);
	void simUpdate(bool &pause, bool &stepForward, bool &stepBackward, bool &iteration, bool &start, bool &end, NumbersClass numbersInput);
	void simUpdate(bool &start, NumbersClass numbersInput);
	void saveFile(NumbersClass numbersInput);
	void loadFile(NumbersClass &numbersInput);
	void display(Menu &menu, NumbersClass &numbersInput, Texture backgroundTexture);
	void musicUpdate();
	void stateBackUpdate(Menu &menu);   //// *** Change Done *** ////
	void flushVector(NumbersClass & numbersInput);
};


extern InterruptHandle interrupt;
extern PseudoCode pseudo;
extern Event event;
extern RenderWindow window;
extern states currentState;
extern algoChoose currentAlgo;
extern taskChoose currentTask;
extern int koytaInputDraw;
extern int flag;
extern int searchItem;
extern vector <int> tempStorage;
extern Music menuMusic;
extern RectangleShape cursor;
extern float charWidth;
extern float spaceWidth;
extern Sprite sideImage;
extern Texture imageTextures[5][3];
extern Menu menu;
extern Button buttons;
extern bool musicPlay;
extern bool algoPlay;
extern int buttonReturn;
extern Font valueFont;
extern float dtDelay;

#endif