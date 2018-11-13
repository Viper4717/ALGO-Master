#include "Header Files/InterruptHandle.h"

using namespace sf;
using namespace std;

Sort::Sort()
{
}


Sort::~Sort()
{
}

NumbersClass Sort::BubbleSortAscending(NumbersClass vectorInput, Texture backgroundTexture)
{
	//Declaration
	pause = false;
	stepForward = false;
	stepBackward = false;
	iteration = true;
	start = false;
	end = false;
	showScreen = true;
	numbersInput = vectorInput;
	Sprite background(backgroundTexture);
	float leftPosition, rightPosition;
	int i = 0, j = 0, len;
	len = numbersInput.numbers.size();

	pseudo.loadCode(window.getSize().x, window.getSize().y);

	//Algorithm Loop
	while (showScreen) {
		if (!pause) {
			pause = true;	//The loop will be set to paused initially
			for (i = 0; i < len; i++) {

				//Pseudo Code Update
				pseudo.showVariableString = "i = " + to_string(i) + "   j = " + to_string(j);
				pseudo.update(1);
				window.clear();
				window.draw(background);
				numbersInput.draw();
				pseudo.drawCode(1);
				buttons.buttonDraw(1, 7);
				buttons.sliderDraw();
				window.display();
				clock.restart();
				delayTime = clock.restart().asSeconds();
				while (delayTime < dtDelay && !end) {
					while (window.pollEvent(event)) {
						interrupt.windowHandle();
						interrupt.simUpdate(pause, stepForward, stepBackward, iteration, start, end, numbersInput);
					}
					delayTime = clock.getElapsedTime().asSeconds();
					if (currentState != bubble) break;
					window.clear();
					window.draw(background);
					numbersInput.draw();
					pseudo.drawCode(1);
					buttons.buttonDraw(1, 7);
					buttons.sliderDraw();
					window.display();
				}
				if (currentState != bubble) break;
				for (j = 0; j < len - 1 - i; j++) {

					//Pseudo Code Update
					pseudo.showVariableString = "i = " + to_string(i) + "   j = " + to_string(j);
					pseudo.update(2);

					if (!pause || stepForward) {
						//Set Active State
						setBarColorActive(numbersInput.numbers[j].numberShape);
						setBarColorActive(numbersInput.numbers[j + 1].numberShape);
						window.clear();
						window.draw(background);
						numbersInput.draw();
						pseudo.drawCode(1);
						buttons.buttonDraw(1, 7);
						buttons.sliderDraw();
						window.display();
						clock.restart();
						delayTime = clock.restart().asSeconds();
						while (delayTime < dtDelay && !end) {
							while (window.pollEvent(event)) {
								interrupt.windowHandle();
								interrupt.simUpdate(pause, stepForward, stepBackward, iteration, start, end, numbersInput);
							}
							delayTime = clock.getElapsedTime().asSeconds();
							if (start) break;
							if (currentState != bubble) break;
							window.clear();
							window.draw(background);
							numbersInput.draw();
							pseudo.drawCode(1);
							buttons.buttonDraw(1, 7);
							buttons.sliderDraw();
							window.display();
						}
						if (start) break;
						if (currentState != bubble) break;
						//Pseudo Code Update
						pseudo.update(3);
						window.clear();
						window.draw(background);
						numbersInput.draw();
						pseudo.drawCode(1);
						buttons.buttonDraw(1, 7);
						buttons.sliderDraw();
						window.display();
						clock.restart();
						delayTime = clock.restart().asSeconds();
						while (delayTime < dtDelay && !end) {
							while (window.pollEvent(event)) {
								interrupt.windowHandle();
								interrupt.simUpdate(pause, stepForward, stepBackward, iteration, start, end, numbersInput);
							}
							delayTime = clock.getElapsedTime().asSeconds();
							if (start) break;
							if (currentState != bubble) break;
							window.clear();
							window.draw(background);
							numbersInput.draw();
							pseudo.drawCode(1);
							buttons.buttonDraw(1, 7);
							buttons.sliderDraw();
							window.display();
						}
						if (start) break;
						if (currentState != bubble) break;
						//Swap bars
						if (numbersInput.numbers[j].number > numbersInput.numbers[j + 1].number && !end) {
							leftPosition = numbersInput.numbers[j].position.x;
							rightPosition = numbersInput.numbers[j + 1].position.x;
							swap(numbersInput.numbers[j], numbersInput.numbers[j + 1]);
							while (numbersInput.numbers[j].position.x > leftPosition && numbersInput.numbers[j + 1].position.x < rightPosition) {
								while (window.pollEvent(event)) {
									interrupt.windowHandle();
									interrupt.simUpdate(pause, stepForward, stepBackward, iteration, start, end, numbersInput);
								}
								if (currentState != bubble) break;
								numbersInput.numbers[j].position.x -= 5.0f;
								numbersInput.numbers[j].numberShape.setPosition(numbersInput.numbers[j].position);
								numbersInput.numbers[j].textPosition.x -= 5.0f;
								numbersInput.numbers[j].value.setPosition(numbersInput.numbers[j].textPosition);
								numbersInput.numbers[j + 1].position.x += 5.0f;
								numbersInput.numbers[j + 1].numberShape.setPosition(numbersInput.numbers[j + 1].position);
								numbersInput.numbers[j + 1].textPosition.x += 5.0f;
								numbersInput.numbers[j + 1].value.setPosition(numbersInput.numbers[j + 1].textPosition);
								if (start) break;
								pseudo.update(4);
								window.clear();
								window.draw(background);
								numbersInput.draw();
								pseudo.drawCode(1);
								buttons.buttonDraw(1, 7);
								buttons.sliderDraw();
								window.display();
							}
						}
						if (numbersInput.numbers[j].number > numbersInput.numbers[j + 1].number && end) {
							swap(numbersInput.numbers[j], numbersInput.numbers[j + 1]);
							swap(numbersInput.numbers[j].position.x, numbersInput.numbers[j + 1].position.x);

							numbersInput.numbers[j].numberShape.setPosition(numbersInput.numbers[j].position);
							numbersInput.numbers[j + 1].numberShape.setPosition(numbersInput.numbers[j + 1].position);

							swap(numbersInput.numbers[j].textPosition.x, numbersInput.numbers[j + 1].textPosition.x);

							numbersInput.numbers[j].value.setPosition(numbersInput.numbers[j].textPosition);
							numbersInput.numbers[j + 1].value.setPosition(numbersInput.numbers[j + 1].textPosition);
						}
						setBarColor(numbersInput.numbers[j].numberShape);
						setBarColor(numbersInput.numbers[j + 1].numberShape);
						if (stepForward) {
							iteration = !iteration;
						}
						setBarColor(numbersInput.numbers[j].numberShape);
						setBarColor(numbersInput.numbers[j + 1].numberShape);
					}
					window.clear();
					window.draw(background);
					numbersInput.draw();
					pseudo.drawCode(1);
					buttons.buttonDraw(1, 7);
					buttons.sliderDraw();
					window.display();
					if (pause && !stepForward) {
						j--;
					}

					if (stepForward && iteration) {
						stepForward = !stepForward;
					}

					if (stepBackward) {
						stepBackward = !stepBackward;
					}
					while (window.pollEvent(event)) {
						interrupt.windowHandle();
						interrupt.simUpdate(pause, stepForward, stepBackward, iteration, start, end, numbersInput);
					}
					if (currentState != bubble) break;
				}
				//Set Bar Color to Found Color
				setBarColorDone(numbersInput.numbers[len - i - 1].numberShape);
				if (start) {
					numbersInput = vectorInput;
					i = -1;
					start = false;
					end = false;
				}
			}
		}
		end = false;
		pause = true;
		while (window.pollEvent(event))
		{
			interrupt.windowHandle();

			if (event.type == Event::MouseMoved || Mouse::isButtonPressed(Mouse::Left)) {
				buttonReturn = buttons.mouseCheck(buttons.buttonSprites, 1, 7);
			}

			if (buttonReturn == 4)
			{
				pause = false;
				numbersInput = vectorInput;
				buttons.buttonSprites[5].setTexture(buttons.buttonTextures[5][0]);
				algoPlay = 0;
				buttonReturn = -2;
			}

			else if (buttonReturn == 3)
			{
				interrupt.saveFile(numbersInput);
				buttonReturn = -2;
			}
			else if (buttonReturn == 2)
			{
				showScreen = false;
				interrupt.stateBackUpdate(menu);
				buttonReturn = -2;
			}

			if (event.type == Event::KeyPressed)
			{
				if (event.key.code == Keyboard::Left)
				{
					pause = false;
					numbersInput = vectorInput;
					buttons.buttonSprites[5].setTexture(buttons.buttonTextures[5][0]);
					algoPlay = 0;
				}
				else if (event.key.code == Keyboard::B)
				{
					showScreen = false;
					interrupt.stateBackUpdate(menu);
				}
				else if (event.key.code == Keyboard::M)
				{
					interrupt.musicUpdate();
				}
			}
		}
		if (currentState != bubble) break;
		window.clear();
		window.draw(background);
		numbersInput.draw();
		pseudo.drawCode(0);
		buttons.buttonDraw(1, 7);
		buttons.sliderDraw();
		window.display();
	}
	//currentState = sorting;  //Doing only this won't work. You have to change the flag too.
	return numbersInput;
}

NumbersClass Sort::BubbleSortDescending(NumbersClass vectorInput, Texture backgroundTexture)
{
	//Declaration
	pause = false;
	stepForward = false;
	stepBackward = false;
	iteration = true;
	start = false;
	end = false;
	showScreen = true;
	numbersInput = vectorInput;
	Sprite background(backgroundTexture);
	float leftPosition, rightPosition;
	int i = 0, j = 0, len;
	len = numbersInput.numbers.size();

	pseudo.loadCode(window.getSize().x, window.getSize().y);

	//Algorithm Loop
	while (showScreen) {
		if (!pause) {
			pause = true;	//The loop will be set to paused initially
			for (i = 0; i < len; i++) {

				//Pseudo Code Update
				pseudo.showVariableString = "i = " + to_string(i) + "   j = " + to_string(j);
				pseudo.update(1);
				window.clear();
				window.draw(background);
				numbersInput.draw();
				pseudo.drawCode(1);
				buttons.buttonDraw(1, 7);
				buttons.sliderDraw();
				window.display();
				clock.restart();
				delayTime = clock.restart().asSeconds();
				while (delayTime < dtDelay && !end) {
					while (window.pollEvent(event)) {
						interrupt.windowHandle();
						interrupt.simUpdate(pause, stepForward, stepBackward, iteration, start, end, numbersInput);
					}
					delayTime = clock.getElapsedTime().asSeconds();
					if (currentState != bubble) break;
					window.clear();
					window.draw(background);
					numbersInput.draw();
					pseudo.drawCode(1);
					buttons.buttonDraw(1, 7);
					buttons.sliderDraw();
					window.display();
				}
				if (currentState != bubble) break;
				for (j = 0; j < len - 1 - i; j++) {

					//Pseudo Code Update
					pseudo.showVariableString = "i = " + to_string(i) + "   j = " + to_string(j);
					pseudo.update(2);

					if (!pause || stepForward) {
						//Set Active State
						setBarColorActive(numbersInput.numbers[j].numberShape);
						setBarColorActive(numbersInput.numbers[j + 1].numberShape);
						window.clear();
						window.draw(background);
						numbersInput.draw();
						pseudo.drawCode(1);
						buttons.buttonDraw(1, 7);
						buttons.sliderDraw();
						window.display();
						clock.restart();
						delayTime = clock.restart().asSeconds();
						while (delayTime < dtDelay && !end) {
							while (window.pollEvent(event)) {
								interrupt.windowHandle();
								interrupt.simUpdate(pause, stepForward, stepBackward, iteration, start, end, numbersInput);
							}
							delayTime = clock.getElapsedTime().asSeconds();
							if (start) break;
							if (currentState != bubble) break;
							window.clear();
							window.draw(background);
							numbersInput.draw();
							pseudo.drawCode(1);
							buttons.buttonDraw(1, 7);
							buttons.sliderDraw();
							window.display();
						}
						if (start) break;
						if (currentState != bubble) break;
						//Pseudo Code Update
						pseudo.update(3);
						window.clear();
						window.draw(background);
						numbersInput.draw();
						pseudo.drawCode(1);
						buttons.buttonDraw(1, 7);
						buttons.sliderDraw();
						window.display();
						clock.restart();
						delayTime = clock.restart().asSeconds();
						while (delayTime < dtDelay && !end) {
							while (window.pollEvent(event)) {
								interrupt.windowHandle();
								interrupt.simUpdate(pause, stepForward, stepBackward, iteration, start, end, numbersInput);
							}
							delayTime = clock.getElapsedTime().asSeconds();
							if (start) break;
							if (currentState != bubble) break;
							window.clear();
							window.draw(background);
							numbersInput.draw();
							pseudo.drawCode(1);
							buttons.buttonDraw(1, 7);
							buttons.sliderDraw();
							window.display();
						}
						if (start) break;
						if (currentState != bubble) break;
						//Swap bars
						if (numbersInput.numbers[j].number < numbersInput.numbers[j + 1].number && !end) {
							leftPosition = numbersInput.numbers[j].position.x;
							rightPosition = numbersInput.numbers[j + 1].position.x;
							swap(numbersInput.numbers[j], numbersInput.numbers[j + 1]);
							while (numbersInput.numbers[j].position.x > leftPosition && numbersInput.numbers[j + 1].position.x < rightPosition) {
								while (window.pollEvent(event)) {
									interrupt.windowHandle();
									interrupt.simUpdate(pause, stepForward, stepBackward, iteration, start, end, numbersInput);
								}
								if (currentState != bubble) break;
								numbersInput.numbers[j].position.x -= 5.0f;
								numbersInput.numbers[j].numberShape.setPosition(numbersInput.numbers[j].position);
								numbersInput.numbers[j].textPosition.x -= 5.0f;
								numbersInput.numbers[j].value.setPosition(numbersInput.numbers[j].textPosition);
								numbersInput.numbers[j + 1].position.x += 5.0f;
								numbersInput.numbers[j + 1].numberShape.setPosition(numbersInput.numbers[j + 1].position);
								numbersInput.numbers[j + 1].textPosition.x += 5.0f;
								numbersInput.numbers[j + 1].value.setPosition(numbersInput.numbers[j + 1].textPosition);
								if (start) break;
								pseudo.update(4);
								window.clear();
								window.draw(background);
								numbersInput.draw();
								pseudo.drawCode(1);
								buttons.buttonDraw(1, 7);
								buttons.sliderDraw();
								window.display();
							}
						}
						if (numbersInput.numbers[j].number < numbersInput.numbers[j + 1].number && end) {
							swap(numbersInput.numbers[j], numbersInput.numbers[j + 1]);
							swap(numbersInput.numbers[j].position.x, numbersInput.numbers[j + 1].position.x);

							numbersInput.numbers[j].numberShape.setPosition(numbersInput.numbers[j].position);
							numbersInput.numbers[j + 1].numberShape.setPosition(numbersInput.numbers[j + 1].position);

							swap(numbersInput.numbers[j].textPosition.x, numbersInput.numbers[j + 1].textPosition.x);

							numbersInput.numbers[j].value.setPosition(numbersInput.numbers[j].textPosition);
							numbersInput.numbers[j + 1].value.setPosition(numbersInput.numbers[j + 1].textPosition);
						}
						setBarColor(numbersInput.numbers[j].numberShape);
						setBarColor(numbersInput.numbers[j + 1].numberShape);
						if (stepForward) {
							iteration = !iteration;
						}
						setBarColor(numbersInput.numbers[j].numberShape);
						setBarColor(numbersInput.numbers[j + 1].numberShape);
					}
					window.clear();
					window.draw(background);
					numbersInput.draw();
					pseudo.drawCode(1);
					buttons.buttonDraw(1, 7);
					buttons.sliderDraw();
					window.display();
					if (pause && !stepForward) {
						j--;
					}

					if (stepForward && iteration) {
						stepForward = !stepForward;
					}

					if (stepBackward) {
						stepBackward = !stepBackward;
					}
					while (window.pollEvent(event)) {
						interrupt.windowHandle();
						interrupt.simUpdate(pause, stepForward, stepBackward, iteration, start, end, numbersInput);
					}
					if (currentState != bubble) break;
				}
				//Set Bar Color to Found Color
				setBarColorDone(numbersInput.numbers[len - i - 1].numberShape);
				if (start) {
					numbersInput = vectorInput;
					i = -1;
					start = false;
					end = false;
				}
			}
		}
		end = false;
		pause = true;
		while (window.pollEvent(event))
		{
			interrupt.windowHandle();

			if (event.type == Event::MouseMoved || Mouse::isButtonPressed(Mouse::Left)) {
				buttonReturn = buttons.mouseCheck(buttons.buttonSprites, 1, 7);
			}

			if (buttonReturn == 4)
			{
				pause = false;
				numbersInput = vectorInput;
				buttons.buttonSprites[5].setTexture(buttons.buttonTextures[5][0]);
				algoPlay = 0;
				buttonReturn = -2;
			}

			else if (buttonReturn == 3)
			{
				interrupt.saveFile(numbersInput);
				buttonReturn = -2;
			}
			else if (buttonReturn == 2)
			{
				showScreen = false;
				interrupt.stateBackUpdate(menu);
				buttonReturn = -2;
			}

			if (event.type == Event::KeyPressed)
			{
				if (event.key.code == Keyboard::Left)
				{
					pause = false;
					numbersInput = vectorInput;
					buttons.buttonSprites[5].setTexture(buttons.buttonTextures[5][0]);
					algoPlay = 0;
				}
				else if (event.key.code == Keyboard::B)
				{
					showScreen = false;
					interrupt.stateBackUpdate(menu);
				}
				else if (event.key.code == Keyboard::M)
				{
					interrupt.musicUpdate();
				}
			}
		}
		if (currentState != bubble) break;
		window.clear();
		window.draw(background);
		numbersInput.draw();
		pseudo.drawCode(0);
		buttons.buttonDraw(1, 7);
		buttons.sliderDraw();
		window.display();
	}
	//currentState = sorting;  //Doing only this won't work. You have to change the flag too.
	return numbersInput;
}

NumbersClass Sort::InsertionSortAscending(NumbersClass vectorInput, Texture backgroundTexture)
{
	//Declaration
	int height = window.getSize().y;
	bool up = false;
	pause = false;
	stepForward = false;
	stepBackward = false;
	iteration = true;
	start = false;
	end = false;
	showScreen = true;
	numbersInput = vectorInput;

	Sprite background(backgroundTexture);
	float leftPosition, rightPosition, liftRange, defaultHeight;
	int i = 1, j = 0, len;
	len = numbersInput.numbers.size();
	pseudo.loadCode(window.getSize().x, window.getSize().y);
	liftRange = window.getSize().y / 2;

	pseudo.showVariableString = "i = " + to_string(i) + "   j = " + to_string(j);
	pseudo.update(1);

	//Algorithm Loop
	while (showScreen) {
		if (!pause) {
			pause = true;
			for (i = 1, j = 0; i < len; i++) {
				if ((!pause || stepForward) && !up) {
					setBarColorActive(numbersInput.numbers[i].numberShape);
					pseudo.showVariableString = "i = " + to_string(i) + "   j = " + to_string(j);
					pseudo.update(1);
					window.clear();
					window.draw(background);
					numbersInput.draw();
					pseudo.drawCode(1);
					buttons.buttonDraw(1, 7);
					buttons.sliderDraw();
					window.display();
					defaultHeight = numbersInput.numbers[i].position.y;
					if (!end) {
						while (numbersInput.numbers[i].position.y + numbersInput.numbers[i].shapeSize.y > liftRange) {
							while (window.pollEvent(event)) {
								interrupt.windowHandle();
								interrupt.simUpdate(pause, stepForward, stepBackward, iteration, start, end, numbersInput);
							}
							if (start && !pause)	break;
							if (currentState != insertion) break;

							numbersInput.numbers[i].position.y -= 5.0f;
							numbersInput.numbers[i].numberShape.setPosition(numbersInput.numbers[i].position);
							numbersInput.numbers[i].textPosition.y -= 5.0f;
							numbersInput.numbers[i].value.setPosition(numbersInput.numbers[i].textPosition);
							window.clear();
							window.draw(background);
							numbersInput.draw();
							pseudo.drawCode(1);
							buttons.buttonDraw(1, 7);
							buttons.sliderDraw();
							window.display();
						}
						if (currentState != insertion) break;
					}
					else if (end) {
						numbersInput.numbers[i].position.y = liftRange - numbersInput.numbers[i].shapeSize.y;
						numbersInput.numbers[i].numberShape.setPosition(numbersInput.numbers[i].position);
						numbersInput.numbers[i].textPosition.y = liftRange - height * 6 / 200;
						numbersInput.numbers[i].value.setPosition(numbersInput.numbers[i].textPosition);
						window.clear();
						window.draw(background);
						numbersInput.draw();
						pseudo.drawCode(1);
						buttons.buttonDraw(1, 7);
						buttons.sliderDraw();
						window.display();
					}
					up = true;
					clock.restart();
					delayTime = clock.restart().asSeconds();
					while (delayTime < dtDelay && !end) {
						while (window.pollEvent(event)) {
							interrupt.windowHandle();
							interrupt.simUpdate(pause, stepForward, stepBackward, iteration, start, end, numbersInput);
						}
						delayTime = clock.getElapsedTime().asSeconds();
						if (currentState != insertion) break;
						if (start && !pause)	break;
						window.clear();
						window.draw(background);
						numbersInput.draw();
						pseudo.drawCode(1);
						buttons.buttonDraw(1, 7);
						buttons.sliderDraw();
						window.display();
					}
					if (currentState != insertion) break;
				}

				j = i - 1;
				if ((!pause || stepForward) && up && !start) {
					for (j = i - 1; j >= 0 && (numbersInput.numbers[j] > numbersInput.numbers[j + 1] || (pause && !stepForward)); j--)
					{
						if (!iteration)	iteration = !iteration;
						if (!pause || stepForward) {
							setBarColorActive(numbersInput.numbers[j].numberShape);
							pseudo.showVariableString = "i = " + to_string(i) + "   j = " + to_string(j);
							pseudo.update(2);
							window.clear();
							window.draw(background);
							numbersInput.draw();
							pseudo.drawCode(1);
							buttons.buttonDraw(1, 7);
							buttons.sliderDraw();
							window.display();
							clock.restart();
							delayTime = clock.restart().asSeconds();
							while (delayTime < dtDelay && !end) {
								while (window.pollEvent(event)) {
									interrupt.windowHandle();
									interrupt.simUpdate(pause, stepForward, stepBackward, iteration, start, end, numbersInput);
								}

								delayTime = clock.getElapsedTime().asSeconds();
								if (start && !pause)	break;
								if (currentState != insertion) break;
								window.clear();
								window.draw(background);
								numbersInput.draw();
								pseudo.drawCode(1);
								buttons.buttonDraw(1, 7);
								buttons.sliderDraw();
								window.display();
							}
							if (start && !pause)	break;
							if (currentState != insertion) break;
							pseudo.showVariableString = "i = " + to_string(i) + "   j = " + to_string(j);
							pseudo.update(3);
							leftPosition = numbersInput.numbers[j].position.x;
							rightPosition = numbersInput.numbers[j + 1].position.x;
							swap(numbersInput.numbers[j], numbersInput.numbers[j + 1]);
							if (!end) {
								while (numbersInput.numbers[j].position.x > leftPosition && numbersInput.numbers[j + 1].position.x < rightPosition) {
									while (window.pollEvent(event)) {
										interrupt.windowHandle();
										interrupt.simUpdate(pause, stepForward, stepBackward, iteration, start, end, numbersInput);
									}
									if (start && !pause) break;
									if (currentState != insertion) break;
									numbersInput.numbers[j].position.x -= 5.0f;
									numbersInput.numbers[j].numberShape.setPosition(numbersInput.numbers[j].position);
									numbersInput.numbers[j].textPosition.x -= 5.0f;
									numbersInput.numbers[j].value.setPosition(numbersInput.numbers[j].textPosition);
									numbersInput.numbers[j + 1].position.x += 5.0f;
									numbersInput.numbers[j + 1].numberShape.setPosition(numbersInput.numbers[j + 1].position);
									numbersInput.numbers[j + 1].textPosition.x += 5.0f;
									numbersInput.numbers[j + 1].value.setPosition(numbersInput.numbers[j + 1].textPosition);
									window.clear();
									window.draw(background);
									numbersInput.draw();
									pseudo.drawCode(1);
									buttons.buttonDraw(1, 7);
									buttons.sliderDraw();
									window.display();
								}
							}
							else if (end) {
								numbersInput.numbers[j].position.x = leftPosition;
								numbersInput.numbers[j].numberShape.setPosition(numbersInput.numbers[j].position);
								numbersInput.numbers[j].textPosition.x = leftPosition + numbersInput.numbers[j].shapeSize.x / 2 - height * 6 / 300;
								numbersInput.numbers[j].value.setPosition(numbersInput.numbers[j].textPosition);
								numbersInput.numbers[j + 1].position.x = rightPosition;
								numbersInput.numbers[j + 1].numberShape.setPosition(numbersInput.numbers[j + 1].position);
								numbersInput.numbers[j + 1].textPosition.x = rightPosition + numbersInput.numbers[j + 1].shapeSize.x / 2 - height * 6 / 300;;
								numbersInput.numbers[j + 1].value.setPosition(numbersInput.numbers[j + 1].textPosition);
								window.clear();
								window.draw(background);
								numbersInput.draw();
								pseudo.drawCode(1);
								buttons.buttonDraw(1, 7);
								buttons.sliderDraw();
								window.display();
							}
							setBarColor(numbersInput.numbers[j + 1].numberShape);
						}

						while (window.pollEvent(event)) {
							interrupt.windowHandle();
							interrupt.simUpdate(pause, stepForward, stepBackward, iteration, start, end, numbersInput);
						}
						if (start && !pause) break;
						if (currentState != insertion) break;
						if (iteration && stepForward) {
							if (j - 1 >= 0)
							{
								if (numbersInput.numbers[j - 1] > numbersInput.numbers[j])
								{
									stepForward = !stepForward;
								}
							}
							else {
								j--;
								break;
							}
						}

						if (pause && !stepForward) {
							j++;
						}

						/*if (iteration && stepForward && j - 1 >= 0)
							if (numbersInput.numbers[j - 1] > numbersInput.numbers[j])*/

					}
				}
				window.clear();
				window.draw(background);
				numbersInput.draw();
				pseudo.drawCode(1);
				buttons.buttonDraw(1, 7);
				buttons.sliderDraw();
				window.display();
				if ((!pause || stepForward) && up) {
					if (!end) {
						while (numbersInput.numbers[j + 1].position.y < defaultHeight) {
							numbersInput.numbers[j + 1].position.y += 5.0f;
							numbersInput.numbers[j + 1].numberShape.setPosition(numbersInput.numbers[j + 1].position);
							numbersInput.numbers[j + 1].textPosition.y += 5.0f;
							numbersInput.numbers[j + 1].value.setPosition(numbersInput.numbers[j + 1].textPosition);
							window.clear();
							window.draw(background);
							numbersInput.draw();
							pseudo.drawCode(1);
							buttons.buttonDraw(1, 7);
							buttons.sliderDraw();
							window.display();

							while (window.pollEvent(event)) {
								interrupt.windowHandle();
								interrupt.simUpdate(pause, stepForward, stepBackward, iteration, start, end, numbersInput);
							}
							if (start && !pause) break;
							if (currentState != insertion) break;
						}
					}
					else if (end) {
						numbersInput.numbers[j + 1].position.y = defaultHeight;
						numbersInput.numbers[j + 1].numberShape.setPosition(numbersInput.numbers[j + 1].position);
						numbersInput.numbers[j + 1].textPosition.y = defaultHeight + numbersInput.numbers[j + 1].shapeSize.y - height * 6 / 200;
						numbersInput.numbers[j + 1].value.setPosition(numbersInput.numbers[j + 1].textPosition);
					}
					setBarColor(numbersInput.numbers[j + 1].numberShape);
					up = false;
				}
				if (pause) {
					i--;
					while (window.pollEvent(event)) {
						interrupt.windowHandle();
						interrupt.simUpdate(pause, stepForward, stepBackward, iteration, start, end, numbersInput);
					}
					if (!up && (!pause || stepForward) && i != 0)	i++;	//If the bar is down it means the comparison is done. So, move on to the next one.
					//if (stepForward)	stepForward = !stepForward;
					if (currentState != insertion) break;
				}
				if (start && !pause) {
					numbersInput = vectorInput;
					i = 0;
					j = 0;
					start = false;
					end = false;
				}
			}
			window.clear();
			window.draw(background);
			numbersInput.draw();
			pseudo.drawCode(1);
			buttons.buttonDraw(1, 7);
			buttons.sliderDraw();
			window.display();
			for (i = 0; i < len; i++) {
				setBarColorDone(numbersInput.numbers[i].numberShape);
			}
		}

		end = false;
		pause = true;
		while (window.pollEvent(event))
		{
			interrupt.windowHandle();

			if (event.type == Event::MouseMoved || Mouse::isButtonPressed(Mouse::Left)) {
				buttonReturn = buttons.mouseCheck(buttons.buttonSprites, 1, 7);
			}

			if (buttonReturn == 4)
			{
				pause = false;
				numbersInput = vectorInput;
				buttons.buttonSprites[5].setTexture(buttons.buttonTextures[5][0]);
				algoPlay = 0;
				buttonReturn = -2;
			}

			else if (buttonReturn == 3)
			{
				interrupt.saveFile(numbersInput);
				buttonReturn = -2;
			}
			else if (buttonReturn == 2)
			{
				showScreen = false;
				interrupt.stateBackUpdate(menu);
				buttonReturn = -2;
			}

			if (event.type == Event::KeyPressed)
			{
				if (event.key.code == Keyboard::Left)
				{
					pause = false;
					numbersInput = vectorInput;
					buttons.buttonSprites[5].setTexture(buttons.buttonTextures[5][0]);
					algoPlay = 0;
				}
				else if (event.key.code == Keyboard::B)
				{
					showScreen = false;
					interrupt.stateBackUpdate(menu);
				}
				else if (event.key.code == Keyboard::M)
				{
					interrupt.musicUpdate();
				}
			}
		}
		if (currentState != insertion) break;
		window.clear();
		window.draw(background);
		numbersInput.draw();
		pseudo.drawCode(0);
		buttons.buttonDraw(1, 7);
		buttons.sliderDraw();
		window.display();
	}
	//currentState = sorting;  //Doing only this won't work. You have to change the flag too.
	return numbersInput;
}

NumbersClass Sort::InsertionSortDescending(NumbersClass vectorInput, Texture backgroundTexture)
{
	//Declaration
	int height = window.getSize().y;
	bool up = false;
	pause = false;
	stepForward = false;
	stepBackward = false;
	iteration = true;
	start = false;
	end = false;
	showScreen = true;
	numbersInput = vectorInput;

	Sprite background(backgroundTexture);
	float leftPosition, rightPosition, liftRange, defaultHeight;
	int i = 1, j = 0, len;
	len = numbersInput.numbers.size();
	pseudo.loadCode(window.getSize().x, window.getSize().y);
	liftRange = window.getSize().y / 2;

	pseudo.showVariableString = "i = " + to_string(i) + "   j = " + to_string(j);
	pseudo.update(1);

	//Algorithm Loop
	while (showScreen) {
		if (!pause) {
			pause = true;
			for (i = 1, j = 0; i < len; i++) {
				if ((!pause || stepForward) && !up) {
					setBarColorActive(numbersInput.numbers[i].numberShape);
					pseudo.showVariableString = "i = " + to_string(i) + "   j = " + to_string(j);
					pseudo.update(1);
					window.clear();
					window.draw(background);
					numbersInput.draw();
					pseudo.drawCode(1);
					buttons.buttonDraw(1, 7);
					buttons.sliderDraw();
					window.display();
					defaultHeight = numbersInput.numbers[i].position.y;
					if (!end) {
						while (numbersInput.numbers[i].position.y + numbersInput.numbers[i].shapeSize.y > liftRange) {
							while (window.pollEvent(event)) {
								interrupt.windowHandle();
								interrupt.simUpdate(pause, stepForward, stepBackward, iteration, start, end, numbersInput);
							}
							if (start && !pause)	break;
							if (currentState != insertion) break;

							numbersInput.numbers[i].position.y -= 5.0f;
							numbersInput.numbers[i].numberShape.setPosition(numbersInput.numbers[i].position);
							numbersInput.numbers[i].textPosition.y -= 5.0f;
							numbersInput.numbers[i].value.setPosition(numbersInput.numbers[i].textPosition);
							window.clear();
							window.draw(background);
							numbersInput.draw();
							pseudo.drawCode(1);
							buttons.buttonDraw(1, 7);
							buttons.sliderDraw();
							window.display();
						}
						if (currentState != insertion) break;
					}
					else if (end) {
						numbersInput.numbers[i].position.y = liftRange - numbersInput.numbers[i].shapeSize.y;
						numbersInput.numbers[i].numberShape.setPosition(numbersInput.numbers[i].position);
						numbersInput.numbers[i].textPosition.y = liftRange - height * 6 / 200;
						numbersInput.numbers[i].value.setPosition(numbersInput.numbers[i].textPosition);
						window.clear();
						window.draw(background);
						numbersInput.draw();
						pseudo.drawCode(1);
						buttons.buttonDraw(1, 7);
						buttons.sliderDraw();
						window.display();
					}
					up = true;
					clock.restart();
					delayTime = clock.restart().asSeconds();
					while (delayTime < dtDelay && !end) {
						while (window.pollEvent(event)) {
							interrupt.windowHandle();
							interrupt.simUpdate(pause, stepForward, stepBackward, iteration, start, end, numbersInput);
						}
						delayTime = clock.getElapsedTime().asSeconds();
						if (currentState != insertion) break;
						if (start && !pause)	break;
						window.clear();
						window.draw(background);
						numbersInput.draw();
						pseudo.drawCode(1);
						buttons.buttonDraw(1, 7);
						buttons.sliderDraw();
						window.display();
					}
					if (currentState != insertion) break;
				}

				j = i - 1;
				if ((!pause || stepForward) && up && !start) {
					for (j = i - 1; j >= 0 && (numbersInput.numbers[j] < numbersInput.numbers[j + 1] || (pause && !stepForward)); j--)
					{
						if (!iteration)	iteration = !iteration;
						if (!pause || stepForward) {
							setBarColorActive(numbersInput.numbers[j].numberShape);
							pseudo.showVariableString = "i = " + to_string(i) + "   j = " + to_string(j);
							pseudo.update(2);
							window.clear();
							window.draw(background);
							numbersInput.draw();
							pseudo.drawCode(1);
							buttons.buttonDraw(1, 7);
							buttons.sliderDraw();
							window.display();
							clock.restart();
							delayTime = clock.restart().asSeconds();
							while (delayTime < dtDelay && !end) {
								while (window.pollEvent(event)) {
									interrupt.windowHandle();
									interrupt.simUpdate(pause, stepForward, stepBackward, iteration, start, end, numbersInput);
								}

								delayTime = clock.getElapsedTime().asSeconds();
								if (start && !pause)	break;
								if (currentState != insertion) break;
								window.clear();
								window.draw(background);
								numbersInput.draw();
								pseudo.drawCode(1);
								buttons.buttonDraw(1, 7);
								buttons.sliderDraw();
								window.display();
							}
							if (start && !pause)	break;
							if (currentState != insertion) break;
							pseudo.showVariableString = "i = " + to_string(i) + "   j = " + to_string(j);
							pseudo.update(3);
							leftPosition = numbersInput.numbers[j].position.x;
							rightPosition = numbersInput.numbers[j + 1].position.x;
							swap(numbersInput.numbers[j], numbersInput.numbers[j + 1]);
							if (!end) {
								while (numbersInput.numbers[j].position.x > leftPosition && numbersInput.numbers[j + 1].position.x < rightPosition) {
									while (window.pollEvent(event)) {
										interrupt.windowHandle();
										interrupt.simUpdate(pause, stepForward, stepBackward, iteration, start, end, numbersInput);
									}
									if (start && !pause) break;
									if (currentState != insertion) break;
									numbersInput.numbers[j].position.x -= 5.0f;
									numbersInput.numbers[j].numberShape.setPosition(numbersInput.numbers[j].position);
									numbersInput.numbers[j].textPosition.x -= 5.0f;
									numbersInput.numbers[j].value.setPosition(numbersInput.numbers[j].textPosition);
									numbersInput.numbers[j + 1].position.x += 5.0f;
									numbersInput.numbers[j + 1].numberShape.setPosition(numbersInput.numbers[j + 1].position);
									numbersInput.numbers[j + 1].textPosition.x += 5.0f;
									numbersInput.numbers[j + 1].value.setPosition(numbersInput.numbers[j + 1].textPosition);
									window.clear();
									window.draw(background);
									numbersInput.draw();
									pseudo.drawCode(1);
									buttons.buttonDraw(1, 7);
									buttons.sliderDraw();
									window.display();
								}
							}
							else if (end) {
								numbersInput.numbers[j].position.x = leftPosition;
								numbersInput.numbers[j].numberShape.setPosition(numbersInput.numbers[j].position);
								numbersInput.numbers[j].textPosition.x = leftPosition + numbersInput.numbers[j].shapeSize.x / 2 - height * 6 / 300;
								numbersInput.numbers[j].value.setPosition(numbersInput.numbers[j].textPosition);
								numbersInput.numbers[j + 1].position.x = rightPosition;
								numbersInput.numbers[j + 1].numberShape.setPosition(numbersInput.numbers[j + 1].position);
								numbersInput.numbers[j + 1].textPosition.x = rightPosition + numbersInput.numbers[j + 1].shapeSize.x / 2 - height * 6 / 300;;
								numbersInput.numbers[j + 1].value.setPosition(numbersInput.numbers[j + 1].textPosition);
								window.clear();
								window.draw(background);
								numbersInput.draw();
								pseudo.drawCode(1);
								buttons.buttonDraw(1, 7);
								buttons.sliderDraw();
								window.display();
							}
							setBarColor(numbersInput.numbers[j + 1].numberShape);
						}

						while (window.pollEvent(event)) {
							interrupt.windowHandle();
							interrupt.simUpdate(pause, stepForward, stepBackward, iteration, start, end, numbersInput);
						}
						if (start && !pause) break;
						if (currentState != insertion) break;
						if (iteration && stepForward) {
							if (j - 1 >= 0)
							{
								if (numbersInput.numbers[j - 1] < numbersInput.numbers[j])
								{
									stepForward = !stepForward;
								}
							}
							else {
								j--;
								break;
							}
						}

						if (pause && !stepForward) {
							j++;
						}

						/*if (iteration && stepForward && j - 1 >= 0)
							if (numbersInput.numbers[j - 1] > numbersInput.numbers[j])*/

					}
				}
				window.clear();
				window.draw(background);
				numbersInput.draw();
				pseudo.drawCode(1);
				buttons.buttonDraw(1, 7);
				buttons.sliderDraw();
				window.display();
				if ((!pause || stepForward) && up) {
					if (!end) {
						while (numbersInput.numbers[j + 1].position.y < defaultHeight) {
							numbersInput.numbers[j + 1].position.y += 5.0f;
							numbersInput.numbers[j + 1].numberShape.setPosition(numbersInput.numbers[j + 1].position);
							numbersInput.numbers[j + 1].textPosition.y += 5.0f;
							numbersInput.numbers[j + 1].value.setPosition(numbersInput.numbers[j + 1].textPosition);
							window.clear();
							window.draw(background);
							numbersInput.draw();
							pseudo.drawCode(1);
							buttons.buttonDraw(1, 7);
							buttons.sliderDraw();
							window.display();

							while (window.pollEvent(event)) {
								interrupt.windowHandle();
								interrupt.simUpdate(pause, stepForward, stepBackward, iteration, start, end, numbersInput);
							}
							if (start && !pause) break;
							if (currentState != insertion) break;
						}
					}
					else if (end) {
						numbersInput.numbers[j + 1].position.y = defaultHeight;
						numbersInput.numbers[j + 1].numberShape.setPosition(numbersInput.numbers[j + 1].position);
						numbersInput.numbers[j + 1].textPosition.y = defaultHeight + numbersInput.numbers[j + 1].shapeSize.y - height * 6 / 200;
						numbersInput.numbers[j + 1].value.setPosition(numbersInput.numbers[j + 1].textPosition);
					}
					setBarColor(numbersInput.numbers[j + 1].numberShape);
					up = false;
				}
				if (pause) {
					i--;
					while (window.pollEvent(event)) {
						interrupt.windowHandle();
						interrupt.simUpdate(pause, stepForward, stepBackward, iteration, start, end, numbersInput);
					}
					if (!up && (!pause || stepForward) && i != 0)	i++;	//If the bar is down it means the comparison is done. So, move on to the next one.
					//if (stepForward)	stepForward = !stepForward;
					if (currentState != insertion) break;
				}
				if (start && !pause) {
					numbersInput = vectorInput;
					i = 0;
					j = 0;
					start = false;
					end = false;
				}
			}
			window.clear();
			window.draw(background);
			numbersInput.draw();
			pseudo.drawCode(1);
			buttons.buttonDraw(1, 7);
			buttons.sliderDraw();
			window.display();
			for (i = 0; i < len; i++) {
				setBarColorDone(numbersInput.numbers[i].numberShape);
			}
		}

		end = false;
		pause = true;
		while (window.pollEvent(event))
		{
			interrupt.windowHandle();

			if (event.type == Event::MouseMoved || Mouse::isButtonPressed(Mouse::Left)) {
				buttonReturn = buttons.mouseCheck(buttons.buttonSprites, 1, 7);
			}

			if (buttonReturn == 4)
			{
				pause = false;
				numbersInput = vectorInput;
				buttons.buttonSprites[5].setTexture(buttons.buttonTextures[5][0]);
				algoPlay = 0;
				buttonReturn = -2;
			}

			else if (buttonReturn == 3)
			{
				interrupt.saveFile(numbersInput);
				buttonReturn = -2;
			}
			else if (buttonReturn == 2)
			{
				showScreen = false;
				interrupt.stateBackUpdate(menu);
				buttonReturn = -2;
			}

			if (event.type == Event::KeyPressed)
			{
				if (event.key.code == Keyboard::Left)
				{
					pause = false;
					numbersInput = vectorInput;
					buttons.buttonSprites[5].setTexture(buttons.buttonTextures[5][0]);
					algoPlay = 0;
				}
				else if (event.key.code == Keyboard::B)
				{
					showScreen = false;
					interrupt.stateBackUpdate(menu);
				}
				else if (event.key.code == Keyboard::M)
				{
					interrupt.musicUpdate();
				}
			}
		}
		if (currentState != insertion) break;
		window.clear();
		window.draw(background);
		numbersInput.draw();
		pseudo.drawCode(0);
		buttons.buttonDraw(1, 7);
		buttons.sliderDraw();
		window.display();
	}
	//currentState = sorting;  //Doing only this won't work. You have to change the flag too.
	return numbersInput;
}

NumbersClass Sort::SelectionSortAscending(NumbersClass vectorInput, Texture backgroundTexture) {
	//Declaration
	pause = false;
	stepForward = false;
	stepBackward = false;
	iteration = true;
	start = false;
	end = false;
	showScreen = true;
	numbersInput = vectorInput;

	pseudo.loadCode(window.getSize().x, window.getSize().y);
	Sprite background(backgroundTexture);
	float leftPosition, rightPosition;
	int i, j, len;
	len = numbersInput.numbers.size();

	//Algorithm Loop
	while (showScreen) {
		if (!pause) {
			pause = true;
			for (i = 0, j = 1; i <= len - 2; i++) {
				setBarColorActive(numbersInput.numbers[i].numberShape);

				pseudo.showVariableString = "i = " + to_string(i) + "   j = " + to_string(j);
				pseudo.update(1);
				window.clear();
				window.draw(background);
				numbersInput.draw();
				pseudo.drawCode(1);
				buttons.buttonDraw(1, 7);
				buttons.sliderDraw();
				window.display();

				clock.restart();
				delayTime = clock.restart().asSeconds();
				while (delayTime < dtDelay && !end) {
					while (window.pollEvent(event)) {
						interrupt.windowHandle();
						interrupt.simUpdate(pause, stepForward, stepBackward, iteration, start, end, numbersInput);
					}
					delayTime = clock.getElapsedTime().asSeconds();
					if (currentState != selection) break;
					window.clear();
					window.draw(background);
					numbersInput.draw();
					pseudo.drawCode(1);
					buttons.buttonDraw(1, 7);
					buttons.sliderDraw();
					window.display();
				}
				if (currentState != selection) break;
				if (!pause || stepForward) {
					for (j = i + 1; j < len; j++) {
						setBarColorActive(numbersInput.numbers[j].numberShape);
						if (!pause || stepForward) {
							//this is for j update
							if (!iteration)	iteration = !iteration;

							pseudo.showVariableString = "i = " + to_string(i) + "   j = " + to_string(j);
							pseudo.update(2);
							window.clear();
							window.draw(background);
							numbersInput.draw();
							pseudo.drawCode(1);
							buttons.buttonDraw(1, 7);
							buttons.sliderDraw();
							window.display();

							while (window.pollEvent(event)) {
								interrupt.windowHandle();
								interrupt.simUpdate(pause, stepForward, stepBackward, iteration, start, end, numbersInput);
							}
							if (currentState != selection) break;
							clock.restart();
							delayTime = clock.restart().asSeconds();
							while (delayTime < dtDelay && !end) {
								while (window.pollEvent(event)) {
									interrupt.windowHandle();
									interrupt.simUpdate(pause, stepForward, stepBackward, iteration, start, end, numbersInput);
									if (start && !pause)	break;
								}
								delayTime = clock.getElapsedTime().asSeconds();
								if (currentState != selection) break;
								window.clear();
								window.draw(background);
								numbersInput.draw();
								pseudo.drawCode(1);
								buttons.buttonDraw(1, 7);
								buttons.sliderDraw();
								window.display();
							}
							if (currentState != selection) break;
							//this for the comparison check
							pseudo.showVariableString = "i = " + to_string(i) + "   j = " + to_string(j);
							pseudo.update(3);
							window.clear();
							window.draw(background);
							numbersInput.draw();
							pseudo.drawCode(1);
							buttons.buttonDraw(1, 7);
							buttons.sliderDraw();
							window.display();

							clock.restart();
							delayTime = clock.restart().asSeconds();
							while (delayTime < dtDelay && !end) {
								while (window.pollEvent(event)) {
									interrupt.windowHandle();
									interrupt.simUpdate(pause, stepForward, stepBackward, iteration, start, end, numbersInput);
									if (start && !pause)	break;
								}
								delayTime = clock.getElapsedTime().asSeconds();
								if (currentState != selection) break;
								window.clear();
								window.draw(background);
								numbersInput.draw();
								pseudo.drawCode(1);
								buttons.buttonDraw(1, 7);
								buttons.sliderDraw();
								window.display();
							}
							if (currentState != selection) break;

							if (numbersInput.numbers[i].number > numbersInput.numbers[j].number) {
								leftPosition = numbersInput.numbers[i].position.x;
								rightPosition = numbersInput.numbers[j].position.x;
								swap(numbersInput.numbers[i], numbersInput.numbers[j]);
								if (!end) {
									while (numbersInput.numbers[i].position.x > leftPosition && numbersInput.numbers[j].position.x < rightPosition) {
										while (window.pollEvent(event)) {
											interrupt.windowHandle();
											interrupt.simUpdate(pause, stepForward, stepBackward, iteration, start, end, numbersInput);
											if (pause && !stepForward)	continue;
											if (start && !pause)	break;
										}
										if (currentState != selection) break;
										numbersInput.numbers[i].position.x -= 5.0f;
										numbersInput.numbers[i].numberShape.setPosition(numbersInput.numbers[i].position);
										numbersInput.numbers[i].textPosition.x -= 5.0f;
										numbersInput.numbers[i].value.setPosition(numbersInput.numbers[i].textPosition);
										numbersInput.numbers[j].position.x += 5.0f;
										numbersInput.numbers[j].numberShape.setPosition(numbersInput.numbers[j].position);
										numbersInput.numbers[j].textPosition.x += 5.0f;
										numbersInput.numbers[j].value.setPosition(numbersInput.numbers[j].textPosition);

										pseudo.showVariableString = "i = " + to_string(i) + "   j = " + to_string(j);
										pseudo.update(4);
										window.clear();
										window.draw(background);
										numbersInput.draw();
										pseudo.drawCode(1);
										buttons.buttonDraw(1, 7);
										buttons.sliderDraw();
										window.display();
									}
								}
								else if (end)
								{
									swap(numbersInput.numbers[j].position.x, numbersInput.numbers[i].position.x);

									numbersInput.numbers[j].numberShape.setPosition(numbersInput.numbers[j].position);
									numbersInput.numbers[i].numberShape.setPosition(numbersInput.numbers[i].position);

									swap(numbersInput.numbers[j].textPosition.x, numbersInput.numbers[i].textPosition.x);

									numbersInput.numbers[j].value.setPosition(numbersInput.numbers[j].textPosition);
									numbersInput.numbers[i].value.setPosition(numbersInput.numbers[i].textPosition);
									if (start && !pause)	break;
									pseudo.showVariableString = "i = " + to_string(i) + "   j = " + to_string(j);
									pseudo.update(4);
									window.clear();
									window.draw(background);
									numbersInput.draw();
									pseudo.drawCode(1);
									buttons.buttonDraw(1, 7);
									buttons.sliderDraw();
									window.display();
								}
							}
						}

						if (pause) {
							while (window.pollEvent(event)) {
								interrupt.windowHandle();
								interrupt.simUpdate(pause, stepForward, stepBackward, iteration, start, end, numbersInput);
							}
							if (iteration && stepForward)	stepForward = !stepForward;
							if (pause && !stepForward) j--;
						}
						if (currentState != selection) break;
						if (!pause || stepForward)	setBarColor(numbersInput.numbers[j].numberShape);

						window.clear();
						window.draw(background);
						numbersInput.draw();
						pseudo.drawCode(1);
						buttons.buttonDraw(1, 7);
						buttons.sliderDraw();
						window.display();

						if (start && !pause) {
							break;
						}
					}
				}
				if (pause) {
					while (window.pollEvent(event)) {
						interrupt.windowHandle();
						interrupt.simUpdate(pause, stepForward, stepBackward, iteration, start, end, numbersInput);
					}
					if (currentState != selection) break;
					if (iteration && stepForward)	stepForward = !stepForward;
					if (pause && !stepForward) i--;
				}
				if (i != -1) setBarColorDone(numbersInput.numbers[i].numberShape);
				if (start && !pause) {
					numbersInput = vectorInput;
					i = -1;
					j = 1;
					start = false;
					end = false;
				}
				if (i + 2 == len)	setBarColorDone(numbersInput.numbers[i + 1].numberShape);
				window.clear();
				window.draw(background);
				numbersInput.draw();
				pseudo.drawCode(1);
				buttons.buttonDraw(1, 7);
				buttons.sliderDraw();
				window.display();
			}
		}
		end = false;
		pause = true;
		while (window.pollEvent(event))
		{
			interrupt.windowHandle();

			if (event.type == Event::MouseMoved || Mouse::isButtonPressed(Mouse::Left)) {
				buttonReturn = buttons.mouseCheck(buttons.buttonSprites, 1, 7);
			}

			if (buttonReturn == 4)
			{
				pause = false;
				numbersInput = vectorInput;
				buttons.buttonSprites[5].setTexture(buttons.buttonTextures[5][0]);
				algoPlay = 0;
				buttonReturn = -2;
			}

			else if (buttonReturn == 3)
			{
				interrupt.saveFile(numbersInput);
				buttonReturn = -2;
			}
			else if (buttonReturn == 2)
			{
				showScreen = false;
				interrupt.stateBackUpdate(menu);
				buttonReturn = -2;
			}

			if (event.type == Event::KeyPressed)
			{
				if (event.key.code == Keyboard::Left)
				{
					pause = false;
					numbersInput = vectorInput;
					buttons.buttonSprites[5].setTexture(buttons.buttonTextures[5][0]);
					algoPlay = 0;
				}
				else if (event.key.code == Keyboard::B)
				{
					showScreen = false;
					interrupt.stateBackUpdate(menu);
				}
				else if (event.key.code == Keyboard::M)
				{
					interrupt.musicUpdate();
				}
			}
		}
		if (currentState != selection) break;
		window.clear();
		window.draw(background);
		numbersInput.draw();
		pseudo.drawCode(0);
		buttons.buttonDraw(1, 7);
		buttons.sliderDraw();
		window.display();
	}
	//currentState = sorting;
	return numbersInput;
}

NumbersClass Sort::SelectionSortDescending(NumbersClass vectorInput, Texture backgroundTexture) {
	//Declaration
	pause = false;
	stepForward = false;
	stepBackward = false;
	iteration = true;
	start = false;
	end = false;
	showScreen = true;
	numbersInput = vectorInput;

	pseudo.loadCode(window.getSize().x, window.getSize().y);
	Sprite background(backgroundTexture);
	float leftPosition, rightPosition;
	int i, j, len;
	len = numbersInput.numbers.size();

	//Algorithm Loop
	while (showScreen) {
		if (!pause) {
			pause = true;
			for (i = 0, j = 1; i <= len - 2; i++) {
				setBarColorActive(numbersInput.numbers[i].numberShape);

				pseudo.showVariableString = "i = " + to_string(i) + "   j = " + to_string(j);
				pseudo.update(1);
				window.clear();
				window.draw(background);
				numbersInput.draw();
				pseudo.drawCode(1);
				buttons.buttonDraw(1, 7);
				buttons.sliderDraw();
				window.display();

				clock.restart();
				delayTime = clock.restart().asSeconds();
				while (delayTime < dtDelay && !end) {
					while (window.pollEvent(event)) {
						interrupt.windowHandle();
						interrupt.simUpdate(pause, stepForward, stepBackward, iteration, start, end, numbersInput);
					}
					delayTime = clock.getElapsedTime().asSeconds();
					if (currentState != selection) break;
					window.clear();
					window.draw(background);
					numbersInput.draw();
					pseudo.drawCode(1);
					buttons.buttonDraw(1, 7);
					buttons.sliderDraw();
					window.display();
				}
				if (currentState != selection) break;
				if (!pause || stepForward) {
					for (j = i + 1; j < len; j++) {
						setBarColorActive(numbersInput.numbers[j].numberShape);
						if (!pause || stepForward) {
							//this is for j update
							if (!iteration)	iteration = !iteration;

							pseudo.showVariableString = "i = " + to_string(i) + "   j = " + to_string(j);
							pseudo.update(2);
							window.clear();
							window.draw(background);
							numbersInput.draw();
							pseudo.drawCode(1);
							buttons.buttonDraw(1, 7);
							buttons.sliderDraw();
							window.display();

							while (window.pollEvent(event)) {
								interrupt.windowHandle();
								interrupt.simUpdate(pause, stepForward, stepBackward, iteration, start, end, numbersInput);
							}
							if (currentState != selection) break;
							clock.restart();
							delayTime = clock.restart().asSeconds();
							while (delayTime < dtDelay && !end) {
								while (window.pollEvent(event)) {
									interrupt.windowHandle();
									interrupt.simUpdate(pause, stepForward, stepBackward, iteration, start, end, numbersInput);
									if (start && !pause)	break;
								}
								delayTime = clock.getElapsedTime().asSeconds();
								if (currentState != selection) break;
								window.clear();
								window.draw(background);
								numbersInput.draw();
								pseudo.drawCode(1);
								buttons.buttonDraw(1, 7);
								buttons.sliderDraw();
								window.display();
							}
							if (currentState != selection) break;
							//this for the comparison check
							pseudo.showVariableString = "i = " + to_string(i) + "   j = " + to_string(j);
							pseudo.update(3);
							window.clear();
							window.draw(background);
							numbersInput.draw();
							pseudo.drawCode(1);
							buttons.buttonDraw(1, 7);
							buttons.sliderDraw();
							window.display();

							clock.restart();
							delayTime = clock.restart().asSeconds();
							while (delayTime < dtDelay && !end) {
								while (window.pollEvent(event)) {
									interrupt.windowHandle();
									interrupt.simUpdate(pause, stepForward, stepBackward, iteration, start, end, numbersInput);
									if (start && !pause)	break;
								}
								delayTime = clock.getElapsedTime().asSeconds();
								if (currentState != selection) break;
								window.clear();
								window.draw(background);
								numbersInput.draw();
								pseudo.drawCode(1);
								buttons.buttonDraw(1, 7);
								buttons.sliderDraw();
								window.display();
							}
							if (currentState != selection) break;

							if (numbersInput.numbers[i].number < numbersInput.numbers[j].number) {
								leftPosition = numbersInput.numbers[i].position.x;
								rightPosition = numbersInput.numbers[j].position.x;
								swap(numbersInput.numbers[i], numbersInput.numbers[j]);
								if (!end) {
									while (numbersInput.numbers[i].position.x > leftPosition && numbersInput.numbers[j].position.x < rightPosition) {
										while (window.pollEvent(event)) {
											interrupt.windowHandle();
											interrupt.simUpdate(pause, stepForward, stepBackward, iteration, start, end, numbersInput);
											if (pause && !stepForward)	continue;
											if (start && !pause)	break;
										}
										if (currentState != selection) break;
										numbersInput.numbers[i].position.x -= 5.0f;
										numbersInput.numbers[i].numberShape.setPosition(numbersInput.numbers[i].position);
										numbersInput.numbers[i].textPosition.x -= 5.0f;
										numbersInput.numbers[i].value.setPosition(numbersInput.numbers[i].textPosition);
										numbersInput.numbers[j].position.x += 5.0f;
										numbersInput.numbers[j].numberShape.setPosition(numbersInput.numbers[j].position);
										numbersInput.numbers[j].textPosition.x += 5.0f;
										numbersInput.numbers[j].value.setPosition(numbersInput.numbers[j].textPosition);

										pseudo.showVariableString = "i = " + to_string(i) + "   j = " + to_string(j);
										pseudo.update(4);
										window.clear();
										window.draw(background);
										numbersInput.draw();
										pseudo.drawCode(1);
										buttons.buttonDraw(1, 7);
										buttons.sliderDraw();
										window.display();
									}
								}
								else if (end)
								{
									swap(numbersInput.numbers[j].position.x, numbersInput.numbers[i].position.x);

									numbersInput.numbers[j].numberShape.setPosition(numbersInput.numbers[j].position);
									numbersInput.numbers[i].numberShape.setPosition(numbersInput.numbers[i].position);

									swap(numbersInput.numbers[j].textPosition.x, numbersInput.numbers[i].textPosition.x);

									numbersInput.numbers[j].value.setPosition(numbersInput.numbers[j].textPosition);
									numbersInput.numbers[i].value.setPosition(numbersInput.numbers[i].textPosition);
									if (start && !pause)	break;
									pseudo.showVariableString = "i = " + to_string(i) + "   j = " + to_string(j);
									pseudo.update(4);
									window.clear();
									window.draw(background);
									numbersInput.draw();
									pseudo.drawCode(1);
									buttons.buttonDraw(1, 7);
									buttons.sliderDraw();
									window.display();
								}
							}
						}

						if (pause) {
							while (window.pollEvent(event)) {
								interrupt.windowHandle();
								interrupt.simUpdate(pause, stepForward, stepBackward, iteration, start, end, numbersInput);
							}
							if (iteration && stepForward)	stepForward = !stepForward;
							if (pause && !stepForward) j--;
						}
						if (currentState != selection) break;
						if (!pause || stepForward)	setBarColor(numbersInput.numbers[j].numberShape);

						window.clear();
						window.draw(background);
						numbersInput.draw();
						pseudo.drawCode(1);
						buttons.buttonDraw(1, 7);
						buttons.sliderDraw();
						window.display();

						if (start && !pause)	break;
					}
				}
				if (pause) {
					while (window.pollEvent(event)) {
						interrupt.windowHandle();
						interrupt.simUpdate(pause, stepForward, stepBackward, iteration, start, end, numbersInput);
					}
					if (currentState != selection) break;
					if (iteration && stepForward)	stepForward = !stepForward;
					if (pause && !stepForward) i--;
				}
				if (i != -1) setBarColorDone(numbersInput.numbers[i].numberShape);
				if (start && !pause) {
					numbersInput = vectorInput;
					i = -1;
					j = 1;
					start = false;
					end = false;
				}
				if (i + 2 == len)	setBarColorDone(numbersInput.numbers[i + 1].numberShape);
				window.clear();
				window.draw(background);
				numbersInput.draw();
				pseudo.drawCode(1);
				buttons.buttonDraw(1, 7);
				buttons.sliderDraw();
				window.display();
			}
		}
		end = false;
		pause = true;
		while (window.pollEvent(event))
		{
			interrupt.windowHandle();

			if (event.type == Event::MouseMoved || Mouse::isButtonPressed(Mouse::Left)) {
				buttonReturn = buttons.mouseCheck(buttons.buttonSprites, 1, 7);
			}

			if (buttonReturn == 4)
			{
				pause = false;
				numbersInput = vectorInput;
				buttons.buttonSprites[5].setTexture(buttons.buttonTextures[5][0]);
				algoPlay = 0;
				buttonReturn = -2;
			}

			else if (buttonReturn == 3)
			{
				interrupt.saveFile(numbersInput);
				buttonReturn = -2;
			}
			else if (buttonReturn == 2)
			{
				showScreen = false;
				interrupt.stateBackUpdate(menu);
				buttonReturn = -2;
			}

			if (event.type == Event::KeyPressed)
			{
				if (event.key.code == Keyboard::Left)
				{
					pause = false;
					numbersInput = vectorInput;
					buttons.buttonSprites[5].setTexture(buttons.buttonTextures[5][0]);
					algoPlay = 0;
				}
				else if (event.key.code == Keyboard::B)
				{
					showScreen = false;
					interrupt.stateBackUpdate(menu);
				}
				else if (event.key.code == Keyboard::M)
				{
					interrupt.musicUpdate();
				}
			}
		}
		if (currentState != selection) break;
		window.clear();
		window.draw(background);
		numbersInput.draw();
		pseudo.drawCode(0);
		buttons.buttonDraw(1, 7);
		buttons.sliderDraw();
		window.display();
	}
	//currentState = sorting;
	return numbersInput;
}