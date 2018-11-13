#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include "Header Files/Menu.h"
#include "Header Files/NumbersClass.h"
#include "Header Files/Sort.h"
#include "Header Files/InterruptHandle.h"
#include "Header Files/Search.h"

using namespace sf;
using namespace std;


int main() {
	srand(time(NULL));
	Vector2u resolution;
	resolution.x = VideoMode::getDesktopMode().width;
	resolution.y = VideoMode::getDesktopMode().height;
	

	window.create(VideoMode(1914, 1040), "ALGO Master", Style::Default);
	//window.create(VideoMode(resolution.x, resolution.y), "ALGO Master", Style::Fullscreen);
	window.setPosition(Vector2i(-7, 0));
	window.setVerticalSyncEnabled(true);

	Texture loadingTexture;
	if (!loadingTexture.loadFromFile("Images/Loading Screen.png")) {
		//handle error;
	}
	Sprite loadingScreen;
	loadingScreen.setTexture(loadingTexture);
	window.clear();
	window.draw(loadingScreen);
	window.display();
	
	int mouseReturn = -2;
	flag = 0;
	koytaInputDraw = 1;
	//int dataSetLength = 0;

	currentState = mainMenu;
	currentAlgo = algoSort;
	currentTask = simTask;

	NumbersClass numbersInput;

	Sort sort;
	Search search;
	Practice practice;

	Clock cursorClock;
	bool blink = true;
	float cursorDelayTime;

	Texture backgroundTexture;
	if (!backgroundTexture.loadFromFile("Images/blue.png")) {
		//handle error;
	}

	sideImage.setPosition(window.getSize().x / 8, window.getSize().y / 2.5);

	//// Loading Textures ////

	imageTextures[0][0].loadFromFile("Images/simulation.png");
	imageTextures[0][1].loadFromFile("Images/practice.png");
	imageTextures[0][2].loadFromFile("Images/quit.png");
	imageTextures[1][0].loadFromFile("Images/sort.png");
	imageTextures[1][1].loadFromFile("Images/search.png");
	imageTextures[1][2].loadFromFile("Images/quit.png");
	imageTextures[2][0].loadFromFile("Images/input.png");
	imageTextures[2][1].loadFromFile("Images/random.png");
	imageTextures[3][0].loadFromFile("Images/bubble.png");
	imageTextures[3][1].loadFromFile("Images/insertion.png");
	imageTextures[3][2].loadFromFile("Images/selection.png");
	imageTextures[4][0].loadFromFile("Images/binary.png");
	imageTextures[4][1].loadFromFile("Images/linear.png");


	//// Loading finished ////

	sideImage.setTexture(imageTextures[0][0]);
	
	if (!menuMusic.openFromFile("Music/opening.wav")) {
		//handle error;
	}
	menuMusic.play();
	menuMusic.setLoop(true);

	Text garbage;
	Font tempFont;

	if (!tempFont.loadFromFile("Fonts/ACANBLS.ttf")) {
		//handle error
	}
	garbage.setFont(tempFont);
	garbage.setCharacterSize((window.getSize().y * 6) / 150);
	garbage.setOutlineThickness(2);
	garbage.setString("98 9");
	//garbage.setPosition(Vector2f(window.getSize().x / 8, window.getSize().y / 8));
	charWidth = (garbage.findCharacterPos(1).x - garbage.findCharacterPos(0).x);
	spaceWidth = (garbage.findCharacterPos(3).x - garbage.findCharacterPos(2).x);

	while (window.isOpen()) {
		if (cursorClock.getElapsedTime().asSeconds() > 0.5) {
			cursorClock.restart();
			blink = !blink;
			if (blink) cursor.setFillColor(Color(0, 0, 0));
			else cursor.setFillColor(Color(0, 0, 0, 0));
		}
		while (window.pollEvent(event)) {
			interrupt.windowHandle();
			interrupt.menuUpdate(menu, mouseReturn, buttonReturn, numbersInput);
		}
		if (currentState == bubble){
			if (flag == 2) sort.BubbleSortAscending(numbersInput, backgroundTexture);
			else if (flag == 3) sort.BubbleSortDescending(numbersInput, backgroundTexture);
			buttons.buttonSprites[5].setTexture(buttons.buttonTextures[5][0]);
			algoPlay = 0;
		}
		else if (currentState == insertion) {
			if (flag == 2) sort.InsertionSortAscending(numbersInput, backgroundTexture);
			else if (flag == 3) sort.InsertionSortDescending(numbersInput, backgroundTexture);
			buttons.buttonSprites[5].setTexture(buttons.buttonTextures[5][0]);
			algoPlay = 0;
		}
		else if (currentState == selection){
			if (flag == 2) sort.SelectionSortAscending(numbersInput, backgroundTexture);
			else if (flag == 3) sort.SelectionSortDescending(numbersInput, backgroundTexture);
			buttons.buttonSprites[5].setTexture(buttons.buttonTextures[5][0]);
			algoPlay = 0;
		}
		else if (currentState == binary && flag == 1) {
			search.binarySearch(numbersInput, searchItem, backgroundTexture);
			buttons.buttonSprites[5].setTexture(buttons.buttonTextures[5][0]);
			algoPlay = 0;
		}
		else if (currentState == linear && flag == 1) {
			search.linearSearch(numbersInput, searchItem, backgroundTexture);
			buttons.buttonSprites[5].setTexture(buttons.buttonTextures[5][0]);
			algoPlay = 0;
		}
		else if (currentState == practiceBubble && flag == 1) {
			practice.BubbleSortAscending(numbersInput, backgroundTexture);
		}
		else if (currentState == practiceInsertion && flag == 1) {
			practice.InsertionSortAscending(numbersInput, backgroundTexture);
		}
		else if (currentState == practiceSelection && flag == 1) {
			practice.SelectionSortAscending(numbersInput, backgroundTexture);
		}
		window.clear();
		interrupt.display(menu, numbersInput, backgroundTexture);
		window.display();
	}
	return 0;
}