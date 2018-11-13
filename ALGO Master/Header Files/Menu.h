#pragma once

#ifndef MENU_H
#define MENU_H

#include <SFML/Graphics.hpp>
#include <string>
#define MAX_ITEMS 3

using namespace sf;
using namespace std;

class Menu {
public:
	Menu(float width, float height);
	~Menu();
	void simulationMenu(float width, float height);
	void practiceMenu(float width, float height);
	void sortingMenu(float width, float height);
	void searchingMenu(float width, float height);
	void methodChoosingMenu(float width, float height);
	void inputingMenu(float width, float height);
	void asdesingMenu(float width, float height);
	void mainDraw();
	void simDraw();
	void pracDraw();
	void sortDraw();
	void searchDraw();
	void methodDraw();
	void inputDraw(int koyta);
	void asdesDraw();
	void resetMenu(RectangleShape *shape, int index, int koytaItem);   //// *** Change Done *** ////
	void moveUp(RectangleShape *shape, int index, int koytaItem);
	void moveDown(RectangleShape *shape, int index, int koytaItem);
	int mouseCheck(RectangleShape *shape, int index, int koytaItem);
	int optionPressed() {
		return selectedItemIndex;
	}
public:
	Text mainMenu[MAX_ITEMS], head, simMenu[MAX_ITEMS], sortMenu[MAX_ITEMS], searchMenu[2], methodMenu[2], inputMenu[4], asdesHead, asdesMenu[2];
	RectangleShape mainRect[MAX_ITEMS], simRect[MAX_ITEMS], sortRect[MAX_ITEMS], searchRect[2], methodRect[2], asdesRect[2];
	int selectedItemIndex, lastItemIndex;
	string dataLine, searchData;
private:
	Font font, fonthead;
	Text tempText;
	RectangleShape tempRect, inputRect[2];
};

extern RenderWindow window;

#endif