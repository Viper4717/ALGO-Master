#include "Header Files/InterruptHandle.h"



Practice::Practice()
{
}


Practice::~Practice()
{
}


void Practice::BubbleSortAscending(NumbersClass vectorInput, Texture backgroundTexture)
{
	//Intialization
	check1 = -1;
	check2 = -1;
	showScreen = true;
	start = false;
	numbersInput = vectorInput;

	Sprite background(backgroundTexture);
	float leftPosition, rightPosition;
	i = 0;
	j = 0;
	len = numbersInput.numbers.size();

	pseudo.loadCode(window.getSize().x, window.getSize().y);
	pseudo.showVariableString = "Instructions";

	dtDelay = 0.5;

	//Algorithm Loop
	while (showScreen) {
		while (1) {
			//Trigger
			while (window.pollEvent(event)) {
				interrupt.windowHandle();
				interrupt.simUpdate(start, numbersInput);
				if (event.type == Event::MouseMoved || event.type == Event::MouseButtonPressed) {
					checkBar(numbersInput.numbers, check1, check2, 0, len-i-1);
				}
			}
			if (currentState != practiceBubble) break;
			//Update
			if (check1 != -1 && check2 != -1) {
				if (check2 < check1)	swap(check1, check2);

				if (check1 == j && check2 == j+1) {
					setCorrectColor(numbersInput.numbers[check1].numberShape);
					setCorrectColor(numbersInput.numbers[check2].numberShape);

					clock.restart();
					delayTime = clock.restart().asSeconds();
					while (delayTime < dtDelay) {
						while (window.pollEvent(event)) {
							interrupt.windowHandle();
							interrupt.simUpdate(start, numbersInput);
						}
						delayTime = clock.getElapsedTime().asSeconds();
						//if (currentState != practiceBubble) break;
						window.clear();

						window.draw(background);
						numbersInput.draw();
						buttons.buttonDraw(1, 4);
						pseudo.drawCode(0);

						window.display();
					}
					//if (currentState != practiceBubble) break;
					if (numbersInput.numbers[check1].number > numbersInput.numbers[check2].number) {
						leftPosition = numbersInput.numbers[check1].position.x;
						rightPosition = numbersInput.numbers[check2].position.x;

						swap(numbersInput.numbers[check1], numbersInput.numbers[check2]);
						while (numbersInput.numbers[check1].position.x > leftPosition && numbersInput.numbers[check2].position.x < rightPosition) {

							while (window.pollEvent(event)) {
								interrupt.windowHandle();
								interrupt.simUpdate(start, numbersInput);
							}
							if (currentState != practiceBubble) break;
							numbersInput.numbers[check1].position.x -= 5.0f;
							numbersInput.numbers[check1].numberShape.setPosition(numbersInput.numbers[check1].position);
							numbersInput.numbers[check1].textPosition.x -= 5.0f;
							numbersInput.numbers[check1].value.setPosition(numbersInput.numbers[check1].textPosition);
							numbersInput.numbers[check2].position.x += 5.0f;
							numbersInput.numbers[check2].numberShape.setPosition(numbersInput.numbers[check2].position);
							numbersInput.numbers[check2].textPosition.x += 5.0f;
							numbersInput.numbers[check2].value.setPosition(numbersInput.numbers[check2].textPosition);

							window.clear();

							window.draw(background);
							numbersInput.draw();
							buttons.buttonDraw(1, 4);
							pseudo.drawCode(0);

							window.display();
						}
					}
					j++;
				}

				else {
					setWrongColor(numbersInput.numbers[check1].numberShape);
					setWrongColor(numbersInput.numbers[check2].numberShape);

					clock.restart();
					delayTime = clock.restart().asSeconds();
					while (delayTime < dtDelay) {
						while (window.pollEvent(event)) {
							interrupt.windowHandle();
							interrupt.simUpdate(start, numbersInput);
						}
						delayTime = clock.getElapsedTime().asSeconds();
						if (currentState != practiceBubble) break;
						window.clear();

						window.draw(background);
						numbersInput.draw();
						buttons.buttonDraw(1, 4);
						pseudo.drawCode(0);

						window.display();
					}
					if (currentState != practiceBubble) break;
				}

				setBarColor(numbersInput.numbers[check1].numberShape);
				setBarColor(numbersInput.numbers[check2].numberShape);
				check1 = -1;
				check2 = -1;
			}

			if (j == (len - i - 1)) {
				setBarColorDone(numbersInput.numbers[len - i - 1].numberShape);
				j = 0;
				i++;
			}

			if (i == len-1) break;
			if (currentState != practiceBubble) break;
			if (start) {
				numbersInput = vectorInput;
				start = false;
				//initialize i j check1 check2
				check1 = -1;
				check2 = -1;
				i = 0;
				j = 0;
			}
			//Draw
			window.clear();

			window.draw(background);
			numbersInput.draw();
			buttons.buttonDraw(1, 4);
			pseudo.drawCode(0);

			window.display();
		}
		if (currentState != practiceBubble) break;
	}
	//Intializing the current State
	//currentState = sorting;  //Doing only this won't work. You have to change the flag too.

	//If you want to store the sorted string you just need to recieve this NumberClass
	return;
}

void Practice::InsertionSortAscending(NumbersClass vectorInput, Texture backgroundTexture)
{
	//////////1 22 24 11 :: Problem in the last check\\\\\\\\\\\\\\
	//Intialization
	int height = window.getSize().y;
	bool up = false;
	int tempCheck1;
	check1 = -1;
	check2 = -1;
	showScreen = true;
	loopEnded = false;

	numbersInput = vectorInput;

	dtDelay = 0.5;

	Sprite background(backgroundTexture);
	float leftPosition, rightPosition, liftRange, defaultHeight;
	i = 1;
	j = 0;
	int k = 1;
	len = numbersInput.numbers.size();
	liftRange = window.getSize().y / 2;

	pseudo.loadCode(window.getSize().x, window.getSize().y);
	pseudo.showVariableString = "Instructions";

	while (showScreen) {
		while (!loopEnded) {
			//Trigger
			while (window.pollEvent(event)) {
				interrupt.windowHandle();
				interrupt.simUpdate(start, numbersInput);
				if (event.type == Event::MouseMoved || event.type == Event::MouseButtonPressed) {
					checkBar(numbersInput.numbers, check1, check2, 0, len - 1);
				}
			}
			if (currentState != practiceInsertion) break;
			//Update

			//Lift Bar
			if (check1 != -1 && check2 == -1 && !up) {

				up = !up;
				tempCheck1 = check1;
				defaultHeight = numbersInput.numbers[check1].position.y;

				while (numbersInput.numbers[check1].position.y + numbersInput.numbers[check1].shapeSize.y > liftRange) {
					numbersInput.numbers[check1].position.y -= 5.0f;
					numbersInput.numbers[check1].numberShape.setPosition(numbersInput.numbers[check1].position);
					numbersInput.numbers[check1].textPosition.y -= 5.0f;
					numbersInput.numbers[check1].value.setPosition(numbersInput.numbers[check1].textPosition);

					window.clear();

					window.draw(background);
					numbersInput.draw();
					buttons.buttonDraw(1, 4);
					pseudo.drawCode(0);

					window.display();

					while (window.pollEvent(event)) {
						interrupt.windowHandle();
						interrupt.simUpdate(start, numbersInput);
					}
					if (currentState != practiceInsertion) break;
					if (start) {
						break;
					}
				}
			}

			if (check1 != -1 && check2 != -1 && up && !start) {

				if (check1 == i && check2 == j)
				{
					setCorrectColor(numbersInput.numbers[check1].numberShape);
					setCorrectColor(numbersInput.numbers[check2].numberShape);

					clock.restart();
					delayTime = clock.restart().asSeconds();
					while (delayTime < dtDelay) {

						while (window.pollEvent(event)) {
							interrupt.windowHandle();
							interrupt.simUpdate(start, numbersInput);
						}

						delayTime = clock.getElapsedTime().asSeconds();
						if (currentState != practiceInsertion) break;
						window.clear();

						window.draw(background);
						numbersInput.draw();
						buttons.buttonDraw(1, 4);
						pseudo.drawCode(0);

						window.display();
					}

					if (numbersInput.numbers[check2].number > numbersInput.numbers[check1].number) {

						leftPosition = numbersInput.numbers[check2].position.x;
						rightPosition = numbersInput.numbers[check1].position.x;
						swap(numbersInput.numbers[check2], numbersInput.numbers[check1]);
						while (numbersInput.numbers[check2].position.x > leftPosition && numbersInput.numbers[check1].position.x < rightPosition) {
							numbersInput.numbers[check2].position.x -= 5.0f;
							numbersInput.numbers[check2].numberShape.setPosition(numbersInput.numbers[check2].position);
							numbersInput.numbers[check2].textPosition.x -= 5.0f;
							numbersInput.numbers[check2].value.setPosition(numbersInput.numbers[check2].textPosition);
							numbersInput.numbers[check1].position.x += 5.0f;
							numbersInput.numbers[check1].numberShape.setPosition(numbersInput.numbers[check1].position);
							numbersInput.numbers[check1].textPosition.x += 5.0f;
							numbersInput.numbers[check1].value.setPosition(numbersInput.numbers[check1].textPosition);

							window.clear();

							window.draw(background);
							numbersInput.draw();
							buttons.buttonDraw(1, 4);
							pseudo.drawCode(0);

							window.display();

							while (window.pollEvent(event)) {
								interrupt.windowHandle();
								interrupt.simUpdate(start, numbersInput);
							}
							if (currentState != practiceInsertion) break;
							if (start) {
								break;
							}
						}
						setBarColorActive(numbersInput.numbers[check2].numberShape);
						setBarColor(numbersInput.numbers[check1].numberShape);
						check1 = check2;
						tempCheck1 = check1;
						i--;
						j--;
						check2 = -1;
					}

					else {
						setBarColorActive(numbersInput.numbers[check1].numberShape);
						setBarColor(numbersInput.numbers[check2].numberShape);

						check1 = -1;
						check2 = -1;

						k++;
						i = k;
						j = i - 1;
					}
				}

				else {
					setWrongColor(numbersInput.numbers[check1].numberShape);
					setWrongColor(numbersInput.numbers[check2].numberShape);

					clock.restart();
					delayTime = clock.restart().asSeconds();
					while (delayTime < dtDelay) {
						while (window.pollEvent(event)) {
							interrupt.windowHandle();
							interrupt.simUpdate(start, numbersInput);
						}
						delayTime = clock.getElapsedTime().asSeconds();
						if (currentState != practiceInsertion) break;
						window.clear();

						window.draw(background);
						numbersInput.draw();
						buttons.buttonDraw(1, 4);
						pseudo.drawCode(0);

						window.display();
					}
					if (currentState != practiceInsertion) break;
					setBarColorActive(numbersInput.numbers[check1].numberShape);
					setBarColor(numbersInput.numbers[check2].numberShape);
					check2 = -1;
				}
			}

			if (((check1 == -1 && check2 == -1) || check1 != i || check1 == 0) && up && !start) {
				up = !up;
				if (check1 != i && check1 != -1) {
					setWrongColor(numbersInput.numbers[check1].numberShape);
					clock.restart();
					delayTime = clock.restart().asSeconds();
					while (delayTime < dtDelay) {
						while (window.pollEvent(event)) {
							interrupt.windowHandle();
							interrupt.simUpdate(start, numbersInput);
						}
						delayTime = clock.getElapsedTime().asSeconds();
						if (currentState != practiceInsertion) break;
						window.clear();

						window.draw(background);
						numbersInput.draw();
						buttons.buttonDraw(1, 4);
						pseudo.drawCode(0);

						window.display();
					}
					if (currentState != practiceInsertion) break;
					check1 = -1;
					check2 = -1;
				}

				if (check1 == 0) {
					k++;
					i = k;
					j = i - 1;
					check1 = -1;
					//setBarColor(numbersInput.numbers[check2].numberShape);
				}

				setBarColorActive(numbersInput.numbers[tempCheck1].numberShape);

				while (numbersInput.numbers[tempCheck1].position.y < defaultHeight) {
					numbersInput.numbers[tempCheck1].position.y += 5.0f;
					numbersInput.numbers[tempCheck1].numberShape.setPosition(numbersInput.numbers[tempCheck1].position);
					numbersInput.numbers[tempCheck1].textPosition.y += 5.0f;
					numbersInput.numbers[tempCheck1].value.setPosition(numbersInput.numbers[tempCheck1].textPosition);

					window.clear();

					window.draw(background);
					numbersInput.draw();
					buttons.buttonDraw(1, 4);
					pseudo.drawCode(0);

					window.display();

					while (window.pollEvent(event)) {
						interrupt.windowHandle();
						interrupt.simUpdate(start, numbersInput);
					}
					if (currentState != practiceInsertion) break;
					if (start) {
						break;
					}
				}

				if(!start) setBarColor(numbersInput.numbers[tempCheck1].numberShape);
			}

			if (i == len) {
				for (int temp = 0; temp < numbersInput.numbers.size(); temp++) {
					setBarColorDone(numbersInput.numbers[temp].numberShape);
				}
				loopEnded = true;
			}
			if (start) {
				numbersInput = vectorInput;
				start = false;
				//initialize i j check1 check2
				check1 = -1;
				check2 = -1;
				i = 1;
				j = 0;
				k = 1;
				up = false;
				tempCheck1 = -1;
				loopEnded = false;
			}
			//Draw
			window.clear();

			window.draw(background);
			numbersInput.draw();
			buttons.buttonDraw(1, 4);
			pseudo.drawCode(0);

			window.display();
		}

		while (window.pollEvent(event)) {
			interrupt.windowHandle();
			interrupt.simUpdate(start, numbersInput);
		}
		if (currentState != practiceInsertion) break;
		if (start) {
			numbersInput = vectorInput;
			start = false;
			//initialize i j check1 check2
			check1 = -1;
			check2 = -1;
			i = 1;
			j = 0;
			k = 1;
			up = false;
			tempCheck1 = -1;
			loopEnded = false;
		}
		window.clear();

		window.draw(background);
		numbersInput.draw();
		buttons.buttonDraw(1, 4);
		pseudo.drawCode(0);

		window.display();
	}
	//Intializing the current State
	//currentState = sorting;  //Doing only this won't work. You have to change the flag too.

	//If you want to store the sorted string you just need to recieve this NumberClass
	return;
}

void Practice::SelectionSortAscending(NumbersClass vectorInput, Texture backgroundTexture)
{
	//Intialization
	check1 = -1;
	check2 = -1;
	showScreen = true;

	numbersInput = vectorInput;

	Sprite background(backgroundTexture);
	float leftPosition, rightPosition;
	i = 0, j = 1;
	int len = numbersInput.numbers.size();
	dtDelay = 0.5;

	//Loading Pseudo Code
	pseudo.loadCode(window.getSize().x, window.getSize().y);
	pseudo.showVariableString = "Instructions";

	//Algorithm Loop
	while (showScreen) {
		while (1) {
			//Trigger
			while (window.pollEvent(event)) {
				interrupt.windowHandle();
				interrupt.simUpdate(start, numbersInput);
				if (event.type == Event::MouseMoved || event.type == Event::MouseButtonPressed) {
					checkBar(numbersInput.numbers, check1, check2, i, len-1);
				}
			}
			if (currentState != practiceSelection) break;
			//Update
			if (check2 != -1 && check2 != -1) {
				if (check2 < check1)	swap(check1, check2);

				if (check1 == i && check2 == j) {
					setCorrectColor(numbersInput.numbers[check1].numberShape);
					setCorrectColor(numbersInput.numbers[check2].numberShape);

					clock.restart();
					delayTime = clock.restart().asSeconds();
					while (delayTime < dtDelay) {
						while (window.pollEvent(event)) {
							interrupt.windowHandle();
							interrupt.simUpdate(start, numbersInput);
						}
						delayTime = clock.getElapsedTime().asSeconds();
						if (currentState != practiceSelection) break;
						window.clear();

						window.draw(background);
						numbersInput.draw();
						buttons.buttonDraw(1, 4);
						pseudo.drawCode(0);

						window.display();
					}
					if (currentState != practiceSelection) break;
					if (numbersInput.numbers[check1].number > numbersInput.numbers[check2].number) {
						leftPosition = numbersInput.numbers[check1].position.x;
						rightPosition = numbersInput.numbers[check2].position.x;

						swap(numbersInput.numbers[check1], numbersInput.numbers[check2]);
						while (numbersInput.numbers[check1].position.x > leftPosition && numbersInput.numbers[check2].position.x < rightPosition) {

							while (window.pollEvent(event)) {
								interrupt.windowHandle();
								interrupt.simUpdate(start, numbersInput);
							}
							if (currentState != practiceSelection) break;
							numbersInput.numbers[check1].position.x -= 5.0f;
							numbersInput.numbers[check1].numberShape.setPosition(numbersInput.numbers[check1].position);
							numbersInput.numbers[check1].textPosition.x -= 5.0f;
							numbersInput.numbers[check1].value.setPosition(numbersInput.numbers[check1].textPosition);
							numbersInput.numbers[check2].position.x += 5.0f;
							numbersInput.numbers[check2].numberShape.setPosition(numbersInput.numbers[check2].position);
							numbersInput.numbers[check2].textPosition.x += 5.0f;
							numbersInput.numbers[check2].value.setPosition(numbersInput.numbers[check2].textPosition);

							window.clear();

							window.draw(background);
							numbersInput.draw();
							buttons.buttonDraw(1, 4);
							pseudo.drawCode(0);

							window.display();
						}
					}
					j++;
				}

				else {
					setWrongColor(numbersInput.numbers[check1].numberShape);
					setWrongColor(numbersInput.numbers[check2].numberShape);

					clock.restart();
					delayTime = clock.restart().asSeconds();
					while (delayTime < dtDelay) {
						while (window.pollEvent(event)) {
							interrupt.windowHandle();
							interrupt.simUpdate(start, numbersInput);
						}
						delayTime = clock.getElapsedTime().asSeconds();
						if (currentState != practiceSelection) break;
						window.clear();

						window.draw(background);
						numbersInput.draw();
						buttons.buttonDraw(1, 4);
						pseudo.drawCode(0);

						window.display();
					}
					if (currentState != practiceSelection) break;
				}

				check1 = -1;
				check2 = -1;
			}

			if (j == len) {
				setBarColorDone(numbersInput.numbers[i].numberShape);
				i++;
				j = i + 1;
			}

			if (i == len - 1) {
				break;
			}
			if (start) {
				numbersInput = vectorInput;
				start = false;
				//initialize i j check1 check2
				check1 = -1;
				check2 = -1;
				i = 0;
				j = 1;
			}
			//Draw
			window.clear();

			window.draw(background);
			numbersInput.draw();
			buttons.buttonDraw(1, 4);
			pseudo.drawCode(0);

			window.display();
		}
		if (currentState != practiceSelection) break;
		//Draw
		window.clear();

		window.draw(background);
		numbersInput.draw();
		buttons.buttonDraw(1, 4);
		pseudo.drawCode(0);

		window.display();
	}

	//Intializing the current State
	//currentState = sorting;  //Doing only this won't work. You have to change the flag too.

	//If you want to store the sorted string you just need to recieve this NumberClass
	return;
}


void Practice::checkBar(vector<NumberInfo> & numbersInput, int & check1, int & check2, int start, int end)
{
	for (int k = start; k <= end; k++) {
		//temp
		IntRect rect(numbersInput[k].numberShape.getPosition().x, numbersInput[k].numberShape.getPosition().y, numbersInput[k].numberShape.getGlobalBounds().width, numbersInput[k].numberShape.getGlobalBounds().height);

		//If rect contains mouse change it's color to active state. Else make both bar colors white.
		if (rect.contains(Mouse::getPosition(window))) {
			if (k != check1 && k != check2)  setHoverColor(numbersInput[k].numberShape);
			if (Mouse::isButtonPressed(Mouse::Left)) {
				setBarColorActive(numbersInput[k].numberShape);
				if (check1 == -1)       check1 = k;
				else if (check1 != k)    check2 = k;
				return;
			}
		}
		else if (k != check1 && k != check2) {
			setBarColor(numbersInput[k].numberShape);
		}
	}

	if (Mouse::isButtonPressed(Mouse::Left)) {
		if (check1 != -1)   setBarColor(numbersInput[check1].numberShape);
		if (check2 != -1)   setBarColor(numbersInput[check2].numberShape);
		check1 = -1;
		check2 = -1;
	}
}