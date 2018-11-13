#include "Header Files/InterruptHandle.h"
#include <algorithm>

InterruptHandle interrupt;
PseudoCode pseudo(1914, 1040);
Event event;
RenderWindow window;
states currentState;
algoChoose currentAlgo;
taskChoose currentTask;
Sprite background;
int koytaInputDraw = 1;
int flag = 0;
int searchItem;
float speed;
vector <int> tempStorage;
Music menuMusic;
RectangleShape cursor;
float charWidth;
float spaceWidth;
Sprite sideImage;
Texture imageTextures[5][3];
Menu menu(1914, 1040);
Button buttons(1914, 1040);
bool musicPlay = 1;
bool algoPlay = 0;
int buttonReturn = -2;
int dataIndex = -1;
int dataTotalChar = -1;
int searchIndex = -1;
int searchTotalChar = -1;
float dtDelay;

InterruptHandle::InterruptHandle()
{
}

InterruptHandle::~InterruptHandle()
{
}

void InterruptHandle::windowHandle()
{
	if (event.type == Event::Closed)
	{
		//window.close();
		exit(0);
	}
}

void InterruptHandle::menuUpdate(Menu & menu, int & mouseReturn, int & buttonReturn, NumbersClass &numbersInput)   //// *** Change Done *** ////
{
	if (currentState == mainMenu) {
		if (event.type == Event::MouseMoved || Mouse::isButtonPressed(Mouse::Left)) {
			mouseReturn = menu.mouseCheck(menu.mainRect, 0, 3);
			buttonReturn = buttons.mouseCheck(buttons.buttonSprites, 0, 2);
			if (mouseReturn > -1) {
				if (mouseReturn == 0) {
					currentState = simulation;
					currentTask = simTask;
					menu.resetMenu(menu.simRect, 1, 3);
					buttons.buttonSprites[4].setTexture(buttons.buttonTextures[4][0]);
					mouseReturn = -1;
				}
				if (mouseReturn == 1) {
					currentState = method;
					currentAlgo = algoSort;
					currentTask = pracTask;
					menu.resetMenu(menu.methodRect, 2, 2);
					buttons.buttonSprites[4].setTexture(buttons.buttonTextures[10][0]);
					mouseReturn = -1;
				}
				if (mouseReturn == 2) {
					exit(0);
				}
			}
			if (buttonReturn > -1) {
				if (buttonReturn == 0) {
					loadFile(numbersInput);
				}
			}
		}
		if (event.type == Event::KeyPressed) {
			if (event.key.code == Keyboard::Up) {
				menu.moveUp(menu.mainRect, 0, 3);
			}
			if (event.key.code == Keyboard::Down) {
				menu.moveDown(menu.mainRect, 0, 3);
			}
			if (event.key.code == Keyboard::M) {
				musicUpdate();
			}
			if (event.key.code == Keyboard::L) {
				loadFile(numbersInput);
			}
			if (event.key.code == Keyboard::Return) {
				if (menu.optionPressed() == 0) {
					currentState = simulation;
					currentTask = simTask;
					menu.resetMenu(menu.simRect, 1, 3);
					buttons.buttonSprites[4].setTexture(buttons.buttonTextures[4][0]);
				}
				if (menu.optionPressed() == 1) {
					currentState = method;
					currentAlgo = algoSort;
					currentTask = pracTask;
					menu.resetMenu(menu.methodRect, 2, 2);
					buttons.buttonSprites[4].setTexture(buttons.buttonTextures[10][0]);
				}
				if (menu.optionPressed() == 2) {
					exit(0);
				}
			}
		}
	}

	else if (currentState == simulation) {
		if (event.type == Event::MouseMoved || Mouse::isButtonPressed(Mouse::Left)) {
			mouseReturn = menu.mouseCheck(menu.simRect, 1, 3);
			buttonReturn = buttons.mouseCheck(buttons.buttonSprites, 0, 2);
			if (mouseReturn == 0) {
				currentState = method;
				currentAlgo = algoSort;
				mouseReturn = -1;
				menu.resetMenu(menu.methodRect, 2, 2);
			}
			if (mouseReturn == 1) {
				currentState = input;
				cursor.setPosition(Vector2f(window.getSize().x / 12, 2 * window.getSize().y / 6));
				dataIndex = -1;
				dataTotalChar = -1;
				searchIndex = -1;
				searchTotalChar = -1;
				currentAlgo = algoSearch;
				mouseReturn = -1;
			}
			if (mouseReturn == 2) {
				exit(0);
			}
			if (buttonReturn > -1) {
				if (buttonReturn == 0) {
					loadFile(numbersInput);
				}
				if (buttonReturn == 2) {
					stateBackUpdate(menu);
				}
			}
		}
		if (event.type == Event::KeyPressed) {
			if (event.key.code == Keyboard::Up) {
				menu.moveUp(menu.simRect, 1, 3);
			}
			if (event.key.code == Keyboard::Down) {
				menu.moveDown(menu.simRect, 1, 3);
			}
			if (event.key.code == Keyboard::M) {
				musicUpdate();
			}
			if (event.key.code == Keyboard::B) {
				stateBackUpdate(menu);
			}
			if (event.key.code == Keyboard::Return) {
				if (menu.optionPressed() == 0) {
					currentState = method;
					currentAlgo = algoSort;
					menu.resetMenu(menu.methodRect, 2, 2);
				}
				if (menu.optionPressed() == 1) {
					currentState = input;
					cursor.setPosition(Vector2f(window.getSize().x / 12, 2 * window.getSize().y / 6));
					dataIndex = -1;
					dataTotalChar = -1;
					searchIndex = -1;
					searchTotalChar = -1;
					currentAlgo = algoSearch;
				}
				if (menu.optionPressed() == 2) {
					exit(0);
				}
			}
		}
	}
	else if (currentState == method) {
		if (event.type == Event::MouseMoved || Mouse::isButtonPressed(Mouse::Left)) {
			mouseReturn = menu.mouseCheck(menu.methodRect, 2, 2);
			buttonReturn = buttons.mouseCheck(buttons.buttonSprites, 0, 2);
			if (mouseReturn == 0) {
				currentState = input;
				cursor.setPosition(Vector2f(window.getSize().x / 12, 2 * window.getSize().y / 6));
				dataIndex = -1;
				dataTotalChar = -1;
				searchIndex = -1;
				searchTotalChar = -1;
				mouseReturn = -1;
			}
			if (mouseReturn == 1) {
				currentState = random;
				mouseReturn = -1;
			}
			if (buttonReturn > -1) {
				if (buttonReturn == 0) {
					loadFile(numbersInput);
				}
				if (buttonReturn == 2) {
					stateBackUpdate(menu);
				}
			}
		}
		if (event.type == Event::KeyPressed) {
			if (event.key.code == Keyboard::Up) {
				menu.moveUp(menu.methodRect, 2, 2);
			}
			if (event.key.code == Keyboard::Down) {
				menu.moveDown(menu.methodRect, 2, 2);
			}
			if (event.key.code == Keyboard::M) {
				musicUpdate();
			}
			if (event.key.code == Keyboard::B) {
				stateBackUpdate(menu);
			}
			if (event.key.code == Keyboard::Return) {
				if (menu.optionPressed() == 0) {
					currentState = input;
					cursor.setPosition(Vector2f(window.getSize().x / 12, 2 * window.getSize().y / 6));
					dataIndex = -1;
					dataTotalChar = -1;
					searchIndex = -1;
					searchTotalChar = -1;
				}
				if (menu.optionPressed() == 1) {
					currentState = random;
				}
			}
		}
	}

	else if (currentState == input) {   //// *** Change Done *** ////
		flushVector(numbersInput);
		numbersInput.resetTotalNumbers();
		buttonReturn = buttons.mouseCheck(buttons.buttonSprites, 0, 2);
		if (buttonReturn > -1) {
			if (buttonReturn == 0) {
				loadFile(numbersInput);
			}
			if (buttonReturn == 2) {
				stateBackUpdate(menu);
			}
		}
		if (koytaInputDraw > 2 && koytaInputDraw < 4) {
			cursor.setPosition(Vector2f(window.getSize().x / 12, 4 * window.getSize().y / 6));
		}
		if (Keyboard::isKeyPressed(Keyboard::Key::Right) && dataIndex < dataTotalChar) {
			if (koytaInputDraw < 3) {
				if (menu.dataLine[dataIndex + 1] == ' ') cursor.move(Vector2f(spaceWidth, 0));
				else cursor.move(Vector2f(charWidth, 0));
			}
			else cursor.move(Vector2f(charWidth, 0));
			dataIndex++;
		}
		if (Keyboard::isKeyPressed(Keyboard::Key::Left) && dataIndex > -1) {
			if (koytaInputDraw < 3) {
				if (menu.dataLine[dataIndex] == ' ') cursor.move(Vector2f((-1)*spaceWidth, 0));
				else cursor.move(Vector2f((-1)*charWidth, 0));
			}
			else cursor.move(Vector2f((-1)*charWidth, 0));
			dataIndex--;
		}
		if (event.type == Event::TextEntered && koytaInputDraw < 3) {
			if (((event.text.unicode >= '0' && event.text.unicode <='9') || event.text.unicode == 32) && cursor.getPosition().x <= window.getSize().x * 0.7253) {
				menu.dataLine.insert(menu.dataLine.begin() + (dataIndex + 1), event.text.unicode);
				menu.inputMenu[1].setString(menu.dataLine);
				dataIndex++;
				dataTotalChar++;
				koytaInputDraw = 2;
				if(event.text.unicode == 32) cursor.move(Vector2f(spaceWidth, 0));
				else cursor.move(Vector2f(charWidth, 0));
			}
			if (event.text.unicode == 8 && dataIndex > -1) {
				if (!menu.dataLine.empty()) {
					if (menu.dataLine[dataIndex] == ' ') cursor.move(Vector2f((-1)*spaceWidth, 0));
					else cursor.move(Vector2f((-1)*charWidth, 0));
					menu.dataLine.erase(menu.dataLine.begin() + dataIndex);
					dataIndex--;
					dataTotalChar--;
				}
				menu.inputMenu[1].setString(menu.dataLine);
				koytaInputDraw = 2;
			}
			if (event.text.unicode == 'm') {
				musicUpdate();
			}
			if (event.text.unicode == 'b') {
				stateBackUpdate(menu);
			}
			if (event.text.unicode == 13) {
				if (!menu.dataLine.empty()) {
					stringstream ss(menu.dataLine);
					int n, dataCount = 1;
					ss >> n;
					if (n) {
						if (currentAlgo == algoSort) {
							currentState = sorting;
							menu.resetMenu(menu.sortRect, 3, 3);
							numbersInput.PushVector(n, (float)window.getSize().y);
							dataCount++;
							while (ss >> n && dataCount <=10) {
								if (n) {
									numbersInput.PushVector(n, (float)window.getSize().y);
									dataCount++;
								}
							}
							flag = 1;
						}
						else if (currentAlgo == algoSearch) {
							koytaInputDraw = 3;
							tempStorage.clear();
							tempStorage.push_back(n);
							dataCount++;
							while (ss >> n && dataCount <= 10) {
								if (n) {
									tempStorage.push_back(n);
									dataCount++;
								}
							}
						}
					}
					else {
						menu.dataLine.erase(menu.dataLine.begin(), menu.dataLine.end());
						menu.inputMenu[1].setString(menu.dataLine);
						dataIndex = -1;
						dataTotalChar = -1;
						cursor.setPosition(Vector2f(window.getSize().x / 12, 2 * window.getSize().y / 6));
					}
				}
			}
		}
		else if(event.type == Event::TextEntered){
			if (event.text.unicode >= '0' && event.text.unicode <= '9' && cursor.getPosition().x <= window.getSize().x * 0.7253) {
				menu.searchData.insert(menu.searchData.begin() + (searchIndex + 1), event.text.unicode);
				menu.inputMenu[3].setString(menu.searchData);
				searchIndex++;
				searchTotalChar++;
				koytaInputDraw = 4;
				cursor.move(Vector2f(charWidth, 0));
			}
			if (event.text.unicode == 8 && searchIndex > -1) {
				if (!menu.searchData.empty()) {
					cursor.move(Vector2f((-1)*charWidth, 0));
					menu.searchData.erase(menu.searchData.begin() + searchIndex);
					searchIndex--;
					searchTotalChar--;
				}
				menu.inputMenu[3].setString(menu.searchData);
				koytaInputDraw = 4;
			}
			if (event.text.unicode == 'm') {
				musicUpdate();
			}
			if (event.text.unicode == 'b') {
				stateBackUpdate(menu);
			}
			if (event.text.unicode == 13) {
				if (!menu.searchData.empty()) {
					stringstream ss(menu.searchData);
					int n;
					ss >> n;
					if (n) {
						searchItem = n;
						flag = 1;
						currentState = searching;
						menu.resetMenu(menu.searchRect, 4, 2);
						sort(tempStorage.begin(), tempStorage.end());
						int size = tempStorage.size();
						for (int i = 0; i < size; i++) {
							numbersInput.PushVector(tempStorage[i], (float)window.getSize().y);
						}
					}
					else {
						menu.searchData.erase(menu.searchData.begin(), menu.searchData.end());
						menu.inputMenu[3].setString(menu.searchData);
						searchIndex = -1;
						searchTotalChar = -1;
						cursor.setPosition(Vector2f(window.getSize().x / 12, 4 * window.getSize().y / 6));
					}
				}
			}
		}
	}

	else if (currentState == random && flag == 0) {
		flushVector(numbersInput);
		numbersInput.resetTotalNumbers();
		int n = 10;
		//int n = 4;
		for (int i = 0; i < n; i++) {
			numbersInput.PushVector(rand() % 50 + 1, (float)window.getSize().y);
		}
		flag = 1;
		if (currentAlgo == algoSort) {
			currentState = sorting;
			menu.resetMenu(menu.sortRect, 3, 3);
		}
		else if (currentAlgo == algoSearch) {
			currentState = searching;
			menu.resetMenu(menu.searchRect, 4, 2);
		}
	}

	else if (currentState == sorting) {
		if (event.type == Event::MouseMoved || Mouse::isButtonPressed(Mouse::Left)) {
			mouseReturn = menu.mouseCheck(menu.sortRect, 3, 3);
			buttonReturn = buttons.mouseCheck(buttons.buttonSprites, 0, 2);
			if (mouseReturn == 0) {
				if(currentTask == simTask) currentState = bubble;
				else if (currentTask == pracTask) currentState = practiceBubble;
				mouseReturn = -1;
				menu.resetMenu(menu.asdesRect, -1, 2);
			}
			if (mouseReturn == 1) {
				if (currentTask == simTask) currentState = insertion;
				else if (currentTask == pracTask) currentState = practiceInsertion;
				mouseReturn = -1;
				menu.resetMenu(menu.asdesRect, -1, 2);
			}
			if (mouseReturn == 2) {
				if (currentTask == simTask) currentState = selection;
				else if (currentTask == pracTask) currentState = practiceSelection;
				mouseReturn = -1;
				menu.resetMenu(menu.asdesRect, -1, 2);
			}
			if (buttonReturn > -1) {
				if (buttonReturn == 0) {
					loadFile(numbersInput);
				}
				if (buttonReturn == 2) {
					stateBackUpdate(menu);
				}
			}
		}
		if (event.type == Event::KeyPressed) {
			if (event.key.code == Keyboard::Up) {
				menu.moveUp(menu.sortRect, 3, 3);
			}
			if (event.key.code == Keyboard::Down) {
				menu.moveDown(menu.sortRect, 3, 3);
			}
			if (event.key.code == Keyboard::M) {
				musicUpdate();
			}
			if (event.key.code == Keyboard::B) {
				stateBackUpdate(menu);
			}
			if (event.key.code == Keyboard::Return) {
				if (menu.optionPressed() == 0) {
					if (currentTask == simTask) currentState = bubble;
					else if (currentTask == pracTask) currentState = practiceBubble;;
					menu.resetMenu(menu.asdesRect, -1, 2);
				}
				if (menu.optionPressed() == 1) {
					if (currentTask == simTask) currentState = insertion;
					else if (currentTask == pracTask) currentState = practiceInsertion;
					menu.resetMenu(menu.asdesRect, -1, 2);
				}
				if (menu.optionPressed() == 2) {
					if (currentTask == simTask) currentState = selection;
					else if (currentTask == pracTask) currentState = practiceSelection;
					menu.resetMenu(menu.asdesRect, -1, 2);
				}
			}
		}
	}
	else if (currentState == searching) {
		if (event.type == Event::MouseMoved || Mouse::isButtonPressed(Mouse::Left)) {
			mouseReturn = menu.mouseCheck(menu.searchRect, 4, 2);
			buttonReturn = buttons.mouseCheck(buttons.buttonSprites, 0, 2);
			if (mouseReturn == 0) {
				currentState = binary;
				flag = 1;
				mouseReturn = -1;
			}
			if (mouseReturn == 1) {
				currentState = linear;
				flag = 1;
				mouseReturn = -1;
			}
			if (buttonReturn > -1) {
				if (buttonReturn == 0) {
					loadFile(numbersInput);
				}
				if (buttonReturn == 2) {
					stateBackUpdate(menu);
				}
			}
		}
		if (event.type == Event::KeyPressed) {
			if (event.key.code == Keyboard::Up) {
				menu.moveUp(menu.searchRect, 4, 2);
			}
			if (event.key.code == Keyboard::Down) {
				menu.moveDown(menu.searchRect, 4, 2);
			}
			if (event.key.code == Keyboard::M) {
				musicUpdate();
			}
			if (event.key.code == Keyboard::B) {
				stateBackUpdate(menu);
			}
			if (event.key.code == Keyboard::Return) {
				if (menu.optionPressed() == 0) {
					currentState = binary;
					flag = 1;
				}
				if (menu.optionPressed() == 1) {
					currentState = linear;
					flag = 1;
				}
			}
		}
	}

	else if (currentState == bubble || currentState == insertion || currentState || selection) {
		if (event.type == Event::MouseMoved || Mouse::isButtonPressed(Mouse::Left)) {
			mouseReturn = menu.mouseCheck(menu.asdesRect, -1, 2);
			buttonReturn = buttons.mouseCheck(buttons.buttonSprites, 0, 2);
			if (mouseReturn == 0) {
				flag = 2;
				mouseReturn = -1;
			}
			if (mouseReturn == 1) {
				flag = 3;
				mouseReturn = -1;
			}
			if (buttonReturn > -1) {
				if (buttonReturn == 0) {
					loadFile(numbersInput);
				}
				if (buttonReturn == 2) {
					stateBackUpdate(menu);
				}
			}
		}
		if (event.type == Event::KeyPressed) {
			if (event.key.code == Keyboard::Up || (event.key.code == Keyboard::Left)) {
				menu.moveUp(menu.asdesRect, -1, 2);
			}
			if (event.key.code == Keyboard::Down || (event.key.code == Keyboard::Right)) {
				menu.moveDown(menu.asdesRect, -1, 2);
			}
			if (event.key.code == Keyboard::M) {
				musicUpdate();
			}
			if (event.key.code == Keyboard::B) {
				stateBackUpdate(menu);
			}
			if (event.key.code == Keyboard::Return) {
				if (menu.optionPressed() == 0) {
					flag = 2;
				}
				if (menu.optionPressed() == 1) {
					flag = 3;
				}
			}
		}
	}
}

void InterruptHandle::simUpdate(bool & pause, bool & stepForward, bool & stepBackward, bool & iteration, bool & start, bool & end, NumbersClass numbersInput)
{
	if (event.type == Event::MouseMoved || Mouse::isButtonPressed(Mouse::Left)) {
		buttonReturn = buttons.mouseCheck(buttons.buttonSprites, 1, 7);
		buttons.sliderCheck();
	}
	//cout << buttonReturn << endl;
	if (buttonReturn == 5) {
		pause = !pause;
		algoPlay = !algoPlay;
		buttonReturn = -2;
	}
	else if (buttonReturn == 6)
	{
		stepForward = !stepForward;
		iteration = !iteration;
		buttonReturn = -2;
	}
	else if (buttonReturn == 4)
	{
		start = true;
		buttonReturn = -2;
	}
	else if (buttonReturn == 7)
	{
		end = true;
		buttonReturn = -2;
	}
	else if (buttonReturn == 3)
	{
		saveFile(numbersInput);
		buttonReturn = -2;
	}
	else if (buttonReturn == 2)
	{
		stateBackUpdate(menu);
		buttonReturn = -2;
	}
	if (event.type == Event::KeyPressed)
	{
		if (event.key.code == Keyboard::Space) {
			pause = !pause;
			algoPlay = !algoPlay;
			if (algoPlay) {
				buttons.buttonSprites[5].setTexture(buttons.buttonTextures[9][0]);
			}
			else {
				buttons.buttonSprites[5].setTexture(buttons.buttonTextures[5][0]);
			}
		}
		else if (event.key.code == Keyboard::Right)
		{
			stepForward = !stepForward;
			iteration = !iteration;
		}
		else if (event.key.code == Keyboard::Left)
		{
			start = true;
		}
		else if (event.key.code == Keyboard::Down)
		{
			end = true;
		}
		else if (event.key.code == Keyboard::S)
		{
			saveFile(numbersInput);
		}
		else if (event.key.code == Keyboard::B)
		{
			stateBackUpdate(menu);
		}
		else if (event.key.code == Keyboard::M)
		{
			musicUpdate();
		}
	}
}

void InterruptHandle::simUpdate(bool & start, NumbersClass numbersInput){
	if (event.type == Event::MouseMoved || Mouse::isButtonPressed(Mouse::Left)) {
		buttonReturn = buttons.mouseCheck(buttons.buttonSprites, 1, 4);
	}
	if (buttonReturn == 4)
	{
		start = true;
		buttonReturn = -2;
	}
	else if (buttonReturn == 3)
	{
		saveFile(numbersInput);
		buttonReturn = -2;
	}
	else if (buttonReturn == 2)
	{
		stateBackUpdate(menu);
		buttonReturn = -2;
	}
	if (event.type == Event::KeyPressed)
	{
		if (event.key.code == Keyboard::Left)
		{
			start = true;
		}
		else if (event.key.code == Keyboard::S)
		{
			saveFile(numbersInput);
		}
		else if (event.key.code == Keyboard::B)
		{
			stateBackUpdate(menu);
		}
		else if (event.key.code == Keyboard::M)
		{
			musicUpdate();
		}
	}
}

void InterruptHandle::saveFile(NumbersClass numbersInput)
{
	fstream saveFile;
	saveFile.open("Save/Last Saved.txt", fstream::in | fstream::out | fstream::trunc);
	saveFile << currentState << endl;
	saveFile << currentAlgo << endl;
	saveFile << currentTask << endl;
	saveFile << numbersInput.numbers.size() << endl;
	for (int i = 0; i < numbersInput.numbers.size(); i++) {
		saveFile << numbersInput.numbers[i].number << endl;
	}
	saveFile.close();
}

void InterruptHandle::loadFile(NumbersClass &numbersInput)
{
	flushVector(numbersInput);
	numbersInput.resetTotalNumbers();

	int height = window.getSize().y;
	int n;
	int size;

	fstream loadFile;
	loadFile.open("Save/Last Saved.txt");

	loadFile >> n;
	if (n == 0)			currentState = mainMenu;
	else if (n == 1)	currentState = simulation;
	else if (n == 2)	currentState = practice;
	else if (n == 3)	currentState = quit;
	else if (n == 4)	currentState = sorting;
	else if (n == 5)	currentState = searching;
	else if (n == 6)	currentState = method;
	else if (n == 7)	currentState = input;
	else if (n == 8)	currentState = random;
	else if (n == 9)	currentState = bubble, flag = 1;
	else if (n == 10)	currentState = insertion, flag = 1;
	else if (n == 11)	currentState = selection, flag = 1;
	else if (n == 12)	currentState = binary, flag = 1;
	else if (n == 13)	currentState = linear, flag = 1;
	else if (n == 14)	currentState = practiceBubble, flag = 1;
	else if (n == 15)	currentState = practiceInsertion, flag = 1;
	else if (n == 16)	currentState = practiceSelection, flag = 1;

	loadFile >> n;
	currentAlgo = n ? algoSearch : algoSort;

	loadFile >> n;
	currentTask = n ? pracTask : simTask;
	cout << currentTask;

	loadFile >> size;

	for (int i = 0; i < size; i++) {
		loadFile >> n;
		cout << n << endl;
		numbersInput.PushVector(n, height);
	}

	loadFile.close();
}

void InterruptHandle::flushVector(NumbersClass & numbersInput)
{
	numbersInput.numbers.erase(numbersInput.numbers.begin(), numbersInput.numbers.end());
	//cout << "Eije Mama" << endl;
}

void InterruptHandle::musicUpdate() {
	if (musicPlay) {
		buttons.buttonSprites[1].setTexture(buttons.buttonTextures[8][0]);
		menuMusic.setVolume(0);
		musicPlay = 0;
	}
	else {
		buttons.buttonSprites[1].setTexture(buttons.buttonTextures[1][0]);
		menuMusic.setVolume(100);
		musicPlay = 1;
	}
}

void InterruptHandle::stateBackUpdate(Menu &menu) {    //// *** Change Done *** ////
	menu.selectedItemIndex = 0;
	menu.lastItemIndex = 0;
	if (currentState == sorting || currentState == searching || currentState == input) {
		menu.dataLine.erase(menu.dataLine.begin(), menu.dataLine.end());
		menu.searchData.erase(menu.searchData.begin(), menu.searchData.end());
		menu.inputMenu[3].setString(menu.dataLine);
		menu.inputMenu[3].setString(menu.searchData);
		koytaInputDraw = 1;
		dataIndex = -1;
		dataTotalChar = -1;
		searchIndex = -1;
		searchTotalChar = -1;
		flag = 0;
		cursor.setPosition(Vector2f(window.getSize().x / 15, 2 * window.getSize().y / 6));
	}
	if (currentState == mainMenu) exit(0);
	else if (currentState == simulation || currentState == practice) {
		currentState = mainMenu;
		menu.resetMenu(menu.mainRect, 0, 3);
	}
	else if (currentState == sorting) {
		currentState = method;
		menu.resetMenu(menu.methodRect, 2, 2);
	}
	else if (currentState == searching) {
		currentState = simulation;
		menu.resetMenu(menu.simRect, 1, 3);
	}
	else if (currentState == method) {
		if (currentTask == simTask) {
			currentState = simulation;
			menu.resetMenu(menu.simRect, 1, 3);
		}
		else if (currentTask == pracTask) {
			currentState = mainMenu;
			menu.resetMenu(menu.mainRect, 0, 3);
		}
	}
	else if (currentState == input) {
		if (currentAlgo == algoSearch) {
			currentState = simulation;
			currentAlgo = algoSort;
			menu.resetMenu(menu.simRect, 1, 3);
		}
		else if (currentAlgo == algoSort) {
			currentState = method;
			menu.resetMenu(menu.methodRect, 2, 2);
		}
	}
	else if (currentState == bubble || currentState == insertion || currentState == selection || currentState || binary || currentState == linear) {
		if (algoPlay) {
			buttons.buttonSprites[5].setTexture(buttons.buttonTextures[5][0]);
			//algoPlay = 0;
		}
		else{
			buttons.buttonSprites[5].setTexture(buttons.buttonTextures[9][0]);
			//algoPlay = 1;
		}
		if (currentAlgo == algoSort) {
			currentState = sorting;
			menu.resetMenu(menu.sortRect, 3, 3);
			flag = 1;
		}
		else if (currentAlgo == algoSearch) {
			currentState = searching;
			menu.resetMenu(menu.searchRect, 4, 3);
			flag = 1;
		}
	}
	else if (currentState == practiceBubble || currentState == practiceInsertion || currentState == practiceSelection) {
		currentState = sorting;
		menu.resetMenu(menu.sortRect, 3, 3);
		flag = 1;
	}
}

void InterruptHandle::display(Menu &menu, NumbersClass &numbersInput, Texture backgroundTexture)
{
	background.setTexture(backgroundTexture);
	if (currentState == mainMenu) {
		window.draw(background);
		window.draw(sideImage);
		buttons.buttonDraw(0, 1);
		menu.mainDraw();
	}
	else if (currentState == simulation) {
		window.draw(background);
		window.draw(sideImage);
		buttons.buttonDraw(0, 2);
		menu.simDraw();
	}
	else if (currentState == method) {
		window.draw(background);
		window.draw(sideImage);
		buttons.buttonDraw(0, 2);
		menu.methodDraw();
	}
	else if (currentState == input) {
		window.draw(background);
		buttons.buttonDraw(0, 2);
		menu.inputDraw(koytaInputDraw);
	}
	else if (currentState == random) {
		window.draw(background);
	}
	else if (currentState == sorting) {
		window.draw(background);
		window.draw(sideImage);
		buttons.buttonDraw(0, 2);
		menu.sortDraw();
	}
	else if (currentState == searching) {
		window.draw(background);
		window.draw(sideImage);
		buttons.buttonDraw(0, 2);
		menu.searchDraw();
	}
	else if (currentState == bubble || currentState == selection || currentState == insertion || currentState == binary || currentState == linear) {
		window.draw(background);
		numbersInput.draw();
		menu.asdesDraw();
		buttons.buttonDraw(1, 7);
	}
}