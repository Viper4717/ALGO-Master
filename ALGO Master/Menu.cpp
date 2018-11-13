#include "Header Files/InterruptHandle.h"


using namespace sf;
using namespace std;

Menu::Menu(float width, float height) {

	if (!fonthead.loadFromFile("Fonts/ACANBLS.ttf")) {
		//handle error
	}

	head.setFont(fonthead);
	head.setCharacterSize(height * 6 / 30);
	head.setFillColor(Color(66,164,244));
	head.setString("ALGO Master");
	head.setPosition(Vector2f(width / 8, height / 8));
	head.setOutlineThickness(3);
	head.setOutlineColor(Color(255,255,255));

	tempText.setFont(font);
	tempText.setCharacterSize(height * 6 / 150);
	tempText.setFillColor(Color(255, 255, 255, 255));
	tempText.setOutlineThickness(2);
	tempText.setOutlineColor(Color(0, 0, 0));
	
	tempRect.setFillColor(Color(66, 244, 167, 80));
	tempRect.setOutlineThickness(3);
	tempRect.setOutlineColor(Color(255, 255, 255, 0));

	if (!font.loadFromFile("Fonts/ACANBLS.ttf")) {
		//handle error
	}
	mainMenu[0] = tempText;
	mainMenu[0].setString("Simulation");
	mainMenu[0].setOrigin(mainMenu[0].getGlobalBounds().width / 2, mainMenu[0].getGlobalBounds().height / 2);
	mainMenu[0].setPosition(Vector2f(width / 1.3, ((height / 2) / (MAX_ITEMS + 1) * 1) + (height / 2)));
	mainRect[0] = tempRect;
	mainRect[0].setSize(Vector2f(width*0.1324, mainMenu[0].getGlobalBounds().height + 20)); //180
	mainRect[0].setOrigin((width*0.1324)/2.0, (mainMenu[0].getGlobalBounds().height / 2+20)/2);
	mainRect[0].setPosition(Vector2f(width / 1.3, ((height / 2) / (MAX_ITEMS + 1) * 1) + (height / 2)));
	mainRect[0].setFillColor(Color(66,244,167));
	mainRect[0].setOutlineColor(Color(255, 255, 255));

	mainMenu[1] = tempText;
	mainMenu[1].setString("Practice");
	mainMenu[1].setOrigin(mainMenu[1].getGlobalBounds().width / 2, mainMenu[1].getGlobalBounds().height / 2);
	mainMenu[1].setPosition(Vector2f(width / 1.3, ((height / 2) / (MAX_ITEMS + 1) * 2) + (height / 2)));
	mainRect[1] = tempRect;
	mainRect[1].setSize(Vector2f(width*0.1324, mainMenu[0].getGlobalBounds().height + 20));
	mainRect[1].setOrigin((width*0.1324) / 2.0, (mainMenu[0].getGlobalBounds().height / 2 + 20) / 2);
	mainRect[1].setPosition(Vector2f(width / 1.3, ((height / 2) / (MAX_ITEMS + 1) * 2) + (height / 2)));

	mainMenu[2] = tempText;
	mainMenu[2].setString("Quit");
	mainMenu[2].setOrigin(mainMenu[2].getGlobalBounds().width / 2, mainMenu[2].getGlobalBounds().height / 2);
	mainMenu[2].setPosition(Vector2f(width / 1.3, ((height / 2) / (MAX_ITEMS + 1) * 3) + (height / 2)));
	mainRect[2] = tempRect;
	mainRect[2].setSize(Vector2f(width*0.1324, mainMenu[0].getGlobalBounds().height + 20));
	mainRect[2].setOrigin((width*0.1324) / 2.0, (mainMenu[0].getGlobalBounds().height / 2 + 20) / 2);
	mainRect[2].setPosition(Vector2f(width / 1.3, ((height / 2) / (MAX_ITEMS + 1) * 3) + (height / 2)));

	selectedItemIndex = 0;
	lastItemIndex = 0;

	Menu::simulationMenu(width, height);
	Menu::practiceMenu(width, height);
	Menu::sortingMenu(width, height);
	Menu::searchingMenu(width, height);
	Menu::inputingMenu(width, height);
	Menu::methodChoosingMenu(width, height);
	Menu::asdesingMenu(width, height);
}

Menu::~Menu() {
}

void Menu::simulationMenu(float width, float height) {
	if (!font.loadFromFile("Fonts/ACANBLS.ttf")) {
		//handle error
	}
	simMenu[0] = tempText;
	simMenu[0].setString("Sort");
	simMenu[0].setOrigin(simMenu[0].getGlobalBounds().width / 2, simMenu[0].getGlobalBounds().height / 2);
	simMenu[0].setPosition(Vector2f(width / 1.3, ((height / 2) / (MAX_ITEMS + 1) * 1) + (height / 2)));
	simRect[0] = tempRect;
	simRect[0].setSize(Vector2f(width*0.08824, simMenu[0].getGlobalBounds().height + 20)); //120
	simRect[0].setOrigin((width*0.08824) / 2.0, (simMenu[0].getGlobalBounds().height / 2 + 20) / 2);
	simRect[0].setPosition(Vector2f(width / 1.3, ((height / 2) / (MAX_ITEMS + 1) * 1) + (height / 2)));
	simRect[0].setFillColor(Color(66, 244, 167));
	simRect[0].setOutlineColor(Color(255, 255, 255));

	simMenu[1] = tempText;
	simMenu[1].setString("Search");
	simMenu[1].setOrigin(simMenu[1].getGlobalBounds().width / 2, simMenu[1].getGlobalBounds().height / 2);
	simMenu[1].setPosition(Vector2f(width / 1.3, ((height / 2) / (MAX_ITEMS + 1) * 2) + (height / 2)));
	simRect[1] = tempRect;
	simRect[1].setSize(Vector2f(width*0.08824, simMenu[0].getGlobalBounds().height + 20));
	simRect[1].setOrigin((width*0.08824) / 2.0, (simMenu[0].getGlobalBounds().height / 2 + 20) / 2);
	simRect[1].setPosition(Vector2f(width / 1.3, ((height / 2) / (MAX_ITEMS + 1) * 2) + (height / 2)));

	simMenu[2] = tempText;
	simMenu[2].setString("Quit");
	simMenu[2].setOrigin(simMenu[2].getGlobalBounds().width / 2, simMenu[2].getGlobalBounds().height / 2);
	simMenu[2].setPosition(Vector2f(width / 1.3, ((height / 2) / (MAX_ITEMS + 1) * 3) + (height / 2)));
	simRect[2] = tempRect;
	simRect[2].setSize(Vector2f(width*0.08824, simMenu[0].getGlobalBounds().height + 20));
	simRect[2].setOrigin((width*0.08824) / 2.0, (simMenu[0].getGlobalBounds().height / 2 + 20) / 2);
	simRect[2].setPosition(Vector2f(width / 1.3, ((height / 2) / (MAX_ITEMS + 1) * 3) + (height / 2)));

	selectedItemIndex = 0;
	lastItemIndex = 0;
}

void Menu::practiceMenu(float width, float height) {

}

void Menu::sortingMenu(float width, float height) {
	if (!font.loadFromFile("Fonts/ACANBLS.ttf")) {
		//handle error
	}
	sortMenu[0] = tempText;
	sortMenu[0].setString("Bubble Sort");
	sortMenu[0].setOrigin(sortMenu[0].getGlobalBounds().width / 2, sortMenu[0].getGlobalBounds().height / 2);
	sortMenu[0].setPosition(Vector2f(width / 1.3, ((height / 2) / (MAX_ITEMS + 1) * 1) + (height / 2)));
	sortRect[0] = tempRect;
	sortRect[0].setSize(Vector2f(width*0.16177, sortMenu[0].getGlobalBounds().height + 20)); //220
	sortRect[0].setOrigin((width*0.16177) / 2.0, (sortMenu[0].getGlobalBounds().height / 2 + 20) / 2);
	sortRect[0].setPosition(Vector2f(width / 1.3, ((height / 2) / (MAX_ITEMS + 1) * 1) + (height / 2)));
	sortRect[0].setFillColor(Color(66, 244, 167));
	sortRect[0].setOutlineColor(Color(255, 255, 255));

	sortMenu[1] = tempText;
	sortMenu[1].setString("Insertion Sort");
	sortMenu[1].setOrigin(sortMenu[1].getGlobalBounds().width / 2, sortMenu[1].getGlobalBounds().height / 2);
	sortMenu[1].setPosition(Vector2f(width / 1.3, ((height / 2) / (MAX_ITEMS + 1) * 2) + (height / 2)));
	sortRect[1] = tempRect;
	sortRect[1].setSize(Vector2f(width*0.16177, sortMenu[0].getGlobalBounds().height + 20));
	sortRect[1].setOrigin((width*0.16177) / 2.0, (sortMenu[0].getGlobalBounds().height / 2 + 20) / 2);
	sortRect[1].setPosition(Vector2f(width / 1.3, ((height / 2) / (MAX_ITEMS + 1) * 2) + (height / 2)));

	sortMenu[2] = tempText;
	sortMenu[2].setString("Selection Sort");
	sortMenu[2].setOrigin(sortMenu[2].getGlobalBounds().width / 2, sortMenu[2].getGlobalBounds().height / 2);
	sortMenu[2].setPosition(Vector2f(width / 1.3, ((height / 2) / (MAX_ITEMS + 1) * 3) + (height / 2)));
	sortRect[2] = tempRect;
	sortRect[2].setSize(Vector2f(width*0.16177, sortMenu[0].getGlobalBounds().height + 20));
	sortRect[2].setOrigin((width*0.16177) / 2.0, (sortMenu[0].getGlobalBounds().height / 2 + 20) / 2);
	sortRect[2].setPosition(Vector2f(width / 1.3, ((height / 2) / (MAX_ITEMS + 1) * 3) + (height / 2)));

	selectedItemIndex = 0;
	lastItemIndex = 0;
}

void Menu::searchingMenu(float width, float height) {
	if (!font.loadFromFile("Fonts/ACANBLS.ttf")) {
		//handle error
	}
	searchMenu[0] = tempText;
	searchMenu[0].setString("Binary Search");
	searchMenu[0].setOrigin(searchMenu[0].getGlobalBounds().width / 2, searchMenu[0].getGlobalBounds().height / 2);
	searchMenu[0].setPosition(Vector2f(width / 1.3, ((height / 2) / (MAX_ITEMS + 1) * 1) + (height / 2)));
	searchRect[0] = tempRect;
	searchRect[0].setSize(Vector2f(width*0.17442, searchMenu[0].getGlobalBounds().height + 20)); //210
	searchRect[0].setOrigin((width*0.17442) / 2.0, (searchMenu[0].getGlobalBounds().height / 2 + 20) / 2);
	searchRect[0].setPosition(Vector2f(width / 1.3, ((height / 2) / (MAX_ITEMS + 1) * 1) + (height / 2)));
	searchRect[0].setFillColor(Color(66, 244, 167));
	searchRect[0].setOutlineColor(Color(255, 255, 255));

	searchMenu[1] = tempText;
	searchMenu[1].setString("Linear Search");
	searchMenu[1].setOrigin(searchMenu[1].getGlobalBounds().width / 2, searchMenu[1].getGlobalBounds().height / 2);
	searchMenu[1].setPosition(Vector2f(width / 1.3, ((height / 2) / (MAX_ITEMS + 1) * 2) + (height / 2)));
	searchRect[1] = tempRect;
	searchRect[1].setSize(Vector2f(width*0.17442, searchMenu[0].getGlobalBounds().height + 20));
	searchRect[1].setOrigin((width*0.17442) / 2.0, (searchMenu[0].getGlobalBounds().height / 2 + 20) / 2);
	searchRect[1].setPosition(Vector2f(width / 1.3, ((height / 2) / (MAX_ITEMS + 1) * 2) + (height / 2)));

	selectedItemIndex = 0;
	lastItemIndex = 0;
}

void Menu::methodChoosingMenu(float width, float height) {
	if (!font.loadFromFile("Fonts/ACANBLS.ttf")) {
		//handle error
	}
	methodMenu[0] = tempText;
	methodMenu[0].setString("Input My Data");
	methodMenu[0].setOrigin(methodMenu[0].getGlobalBounds().width / 2, methodMenu[0].getGlobalBounds().height / 2);
	methodMenu[0].setPosition(Vector2f(width / 1.3, ((height / 2) / (MAX_ITEMS + 1) * 1) + (height / 2)));
	methodRect[0] = tempRect;
	methodRect[0].setSize(Vector2f(width*0.16912, methodMenu[0].getGlobalBounds().height + 20)); //230
	methodRect[0].setOrigin((width*0.16912) / 2.0, (methodMenu[0].getGlobalBounds().height / 2 + 20) / 2);
	methodRect[0].setPosition(Vector2f(width / 1.3, ((height / 2) / (MAX_ITEMS + 1) * 1) + (height / 2)));
	methodRect[0].setFillColor(Color(66, 244, 167));
	methodRect[0].setOutlineColor(Color(255, 255, 255));

	methodMenu[1] = tempText;
	methodMenu[1].setString("Random Data");
	methodMenu[1].setOrigin(methodMenu[1].getGlobalBounds().width / 2, methodMenu[1].getGlobalBounds().height / 2);
	methodMenu[1].setPosition(Vector2f(width / 1.3, ((height / 2) / (MAX_ITEMS + 1) * 2) + (height / 2)));
	methodRect[1] = tempRect;
	methodRect[1].setSize(Vector2f(width*0.16912, methodMenu[0].getGlobalBounds().height + 20));
	methodRect[1].setOrigin((width*0.16912) / 2.0, (methodMenu[0].getGlobalBounds().height / 2 + 20) / 2);
	methodRect[1].setPosition(Vector2f(width / 1.3, ((height / 2) / (MAX_ITEMS + 1) * 2) + (height / 2)));

	selectedItemIndex = 0;
	lastItemIndex = 0;
}

void Menu::inputingMenu(float width, float height) {
	if (!font.loadFromFile("Fonts/ACANBLS.ttf")) {
		//handle error
	}

	cursor.setSize(Vector2f((width*2)/(width),height * 6 / 120));
	cursor.setPosition(Vector2f(width / 12, 2 * height / 6));
	cursor.setFillColor(Color(0, 0, 0));

	inputRect[0].setFillColor(Color(255, 255, 255));
	inputRect[0].setOutlineThickness(3);
	inputRect[0].setOutlineColor(Color(204, 79, 8));
	inputRect[0].setSize(Vector2f(width*0.7353, height * 6 / 90));
	inputRect[0].setPosition(Vector2f(width / 15, ((2 * height) / 6)-(height*0.007195)));

	inputRect[1].setFillColor(Color(255, 255, 255));
	inputRect[1].setOutlineThickness(3);
	//inputRect[1].setOutlineColor(Color(66, 113, 244));
	inputRect[1].setOutlineColor(Color(204, 79, 8));
	inputRect[1].setSize(Vector2f(width*0.7353, height * 6 / 90));
	inputRect[1].setPosition(Vector2f(width / 15, ((4 * height) / 6)- (height*0.007195)));

	inputMenu[0] = tempText;
	inputMenu[0].setString("Enter positive numbers, space separated (Max 10)");
	inputMenu[0].setPosition(Vector2f(width / 12, height / 6));

	inputMenu[1] = tempText;
	inputMenu[1].setPosition(Vector2f(width / 12, 2 * height / 6));
	inputMenu[1].setFillColor(Color(204, 79, 8));

	inputMenu[2] = tempText;
	inputMenu[2].setString("Enter a number to search");
	inputMenu[2].setPosition(Vector2f(width / 12, 3 * height / 6));

	inputMenu[3] = tempText;
	inputMenu[3].setPosition(Vector2f(width / 12, 4 * height / 6));
	inputMenu[3].setFillColor(Color(204, 79, 8));

	selectedItemIndex = 0;
	lastItemIndex = 0;
}

void Menu::asdesingMenu(float width, float height){
	
	asdesHead = tempText;
	asdesHead.setString("Choose Ascending/Descending");
	asdesHead.setOrigin(asdesHead.getGlobalBounds().width / 2, asdesHead.getGlobalBounds().height / 2);
	asdesHead.setPosition(Vector2f(width / 2, height / 2));

	asdesMenu[0] = tempText;
	asdesMenu[0].setString("Ascending");
	asdesMenu[0].setOrigin(asdesMenu[0].getGlobalBounds().width / 2, asdesMenu[0].getGlobalBounds().height / 2);
	asdesMenu[0].setPosition(Vector2f(width / 2 - asdesHead.getGlobalBounds().width / 4, height / 2 + 100));
	asdesRect[0] = tempRect;
	asdesRect[0].setSize(Vector2f(width*0.1287, asdesMenu[0].getGlobalBounds().height + 20)); //175
	asdesRect[0].setOrigin((width*0.1287) / 2.0, (asdesMenu[0].getGlobalBounds().height / 2 + 20) / 2);
	asdesRect[0].setPosition(Vector2f(width / 2 - asdesHead.getGlobalBounds().width / 4, height / 2 + 100));
	asdesRect[0].setFillColor(Color(66, 244, 167));
	asdesRect[0].setOutlineColor(Color(255, 255, 255));

	asdesMenu[1] = tempText;
	asdesMenu[1].setString("Descending");
	asdesMenu[1].setOrigin(asdesMenu[1].getGlobalBounds().width / 2, asdesMenu[1].getGlobalBounds().height / 2);
	asdesMenu[1].setPosition(Vector2f(width / 2 + asdesHead.getGlobalBounds().width / 4, height / 2 + 100));
	asdesRect[1] = tempRect;
	asdesRect[1].setSize(Vector2f(width*0.1287, asdesMenu[0].getGlobalBounds().height + 20)); //175
	asdesRect[1].setOrigin((width*0.1287) / 2.0, (asdesMenu[0].getGlobalBounds().height / 2 + 20) / 2);
	asdesRect[1].setPosition(Vector2f(width / 2 + asdesHead.getGlobalBounds().width / 4, height / 2 + 100));
}

void Menu::mainDraw() {
	window.draw(head);
	for (int i = 0; i < MAX_ITEMS; i++) {
		window.draw(mainRect[i]);
		window.draw(mainMenu[i]);
	}
}

void Menu::simDraw() {
	window.draw(head);
	for (int i = 0; i < MAX_ITEMS; i++) {
		window.draw(simRect[i]);
		window.draw(simMenu[i]);
	}
}

void Menu::sortDraw() {
	window.draw(head);
	for (int i = 0; i < MAX_ITEMS; i++) {
		window.draw(sortRect[i]);
		window.draw(sortMenu[i]);
	}
}

void Menu::pracDraw() {

}

void Menu::searchDraw() {
	window.draw(head);
	for (int i = 0; i < 2; i++) {
		window.draw(searchRect[i]);
		window.draw(searchMenu[i]);
	}
}

void Menu::methodDraw() {
	window.draw(head);
	for (int i = 0; i < 2; i++) {
		window.draw(methodRect[i]);
		window.draw(methodMenu[i]);
	}
}

void Menu::inputDraw(int koyta) {
	if (koyta < 3) window.draw(inputRect[0]);
	else {
		window.draw(inputRect[0]);
		window.draw(inputRect[1]);
	}
	for (int i = 0; i < koyta; i++) {
		window.draw(inputMenu[i]);
		window.draw(cursor);
	}
}

void Menu::asdesDraw(){
	window.draw(asdesHead);
	for (int i = 0; i < 2; i++) {
		window.draw(asdesRect[i]);
		window.draw(asdesMenu[i]);
	}
}

void Menu::moveUp(RectangleShape *shape, int index, int koytaItem) {
	if (selectedItemIndex > 0) {
		shape[selectedItemIndex].setFillColor(Color(66, 244, 167, 80));
		shape[selectedItemIndex].setOutlineColor(Color(255, 255, 255, 0));
		selectedItemIndex--;
		shape[selectedItemIndex].setFillColor(Color(66, 244, 167));
		shape[selectedItemIndex].setOutlineColor(Color(255, 255, 255));
		if (index > -1) sideImage.setTexture(imageTextures[index][selectedItemIndex]);
	}
	else {
		shape[selectedItemIndex].setFillColor(Color(66, 244, 167, 80));
		shape[selectedItemIndex].setOutlineColor(Color(255, 255, 255, 0));
		selectedItemIndex = koytaItem - 1;
		shape[selectedItemIndex].setFillColor(Color(66, 244, 167));
		shape[selectedItemIndex].setOutlineColor(Color(255, 255, 255));
		if (index > -1) sideImage.setTexture(imageTextures[index][selectedItemIndex]);
	}
}

void Menu::moveDown(RectangleShape *shape, int index, int koytaItem) {
	if (selectedItemIndex < koytaItem - 1) {
		shape[selectedItemIndex].setFillColor(Color(66, 244, 167, 80));
		shape[selectedItemIndex].setOutlineColor(Color(255, 255, 255, 0));
		selectedItemIndex++;
		shape[selectedItemIndex].setFillColor(Color(66, 244, 167));
		shape[selectedItemIndex].setOutlineColor(Color(255, 255, 255));
		if (index > -1) sideImage.setTexture(imageTextures[index][selectedItemIndex]);
	}
	else {
		shape[selectedItemIndex].setFillColor(Color(66, 244, 167, 80));
		shape[selectedItemIndex].setOutlineColor(Color(255, 255, 255, 0));
		selectedItemIndex = 0;
		shape[selectedItemIndex].setFillColor(Color(66, 244, 167));
		shape[selectedItemIndex].setOutlineColor(Color(255, 255, 255));
		if (index > -1) sideImage.setTexture(imageTextures[index][selectedItemIndex]);
	}
}

int Menu::mouseCheck(RectangleShape *shape, int index, int koytaItem) {
	for (int i = 0; i < koytaItem; i++) {
		IntRect rect(shape[i].getPosition().x-(shape[i].getGlobalBounds().width)/2, shape[i].getPosition().y-(shape[i].getGlobalBounds().height)/2, shape[i].getGlobalBounds().width, shape[i].getGlobalBounds().height);
		if (rect.contains(Mouse::getPosition(window))) {
			lastItemIndex = selectedItemIndex;
			shape[selectedItemIndex].setFillColor(Color(66, 244, 167, 80));
			shape[selectedItemIndex].setOutlineColor(Color(255, 255, 255, 0));
			selectedItemIndex = i;
			shape[selectedItemIndex].setFillColor(Color(66, 244, 167));
			shape[selectedItemIndex].setOutlineColor(Color(255, 255, 255));
			if (index > -1) sideImage.setTexture(imageTextures[index][selectedItemIndex]);
			if (Mouse::isButtonPressed(Mouse::Left)) return selectedItemIndex;
			return -1;
		}
	}
	return -2;
}

void Menu::resetMenu(RectangleShape *shape, int index, int koytaItem) {    //// *** Change Done *** ////
	selectedItemIndex = 0;
	lastItemIndex = 0;
	shape[0].setFillColor(Color(66, 244, 167));
	shape[0].setOutlineColor(Color(255, 255, 255));
	if(index > -1) sideImage.setTexture(imageTextures[index][0]);
	for (int i = 1; i < koytaItem; i++) {
		shape[i].setFillColor(Color(66, 244, 167, 80));
		shape[i].setOutlineColor(Color(255, 255, 255, 0));
	}
}