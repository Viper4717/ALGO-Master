#include "Header Files/InterruptHandle.h"

using namespace std;


Search::Search(){
	notFoundImage.loadFromFile("Images/not found.png");
	notFound.setTexture(notFoundImage);
	notFound.setOrigin(621 / 2, 362 / 2);
}


Search::~Search()
{
}

NumbersClass Search::binarySearch(NumbersClass vectorInput, int n, Texture backgroundTexture)
{
	pseudo.loadCode(window.getSize().x, window.getSize().y);

	notFound.setPosition(window.getSize().x / 2, window.getSize().y / 2);

	pause = false;
	stepForward = false;
	stepBackward = false;
	iteration = true;
	start = false;
	end = false;
	showScreen = true;
	numbersInput = vectorInput;

	int low, mid, high;
	int size = numbersInput.numbers.size();
	Sprite background(backgroundTexture);

	while (showScreen) {
		if (!pause) {
			printNotFound = false;
			found = false;
			pause = true;
			low = 0; 
			high = numbersInput.numbers.size() - 1;
			mid = -1;
			while (low <= high && !found)
			{
				pseudo.showVariableString = "low = " + to_string(low) + "   mid = " + to_string(mid) + "   high = " + to_string(high);
				pseudo.update(1);
				window.clear();
				window.draw(background);
				numbersInput.draw();
				pseudo.drawCode();
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
					if (currentState != binary) break;
					window.clear();
					window.draw(background);
					numbersInput.draw();
					pseudo.drawCode();
					buttons.buttonDraw(1, 7);
					buttons.sliderDraw();
					window.display();
				}
				if (currentState != binary) break;
				if (!pause || stepForward) {
					setBarColorCheck(numbersInput.numbers[low].numberShape);
					setBarColorCheck(numbersInput.numbers[high].numberShape);
					mid = (low + high) / 2;
					setBarColorActive(numbersInput.numbers[mid].numberShape);

					pseudo.showVariableString = "low = " + to_string(low) + "   mid = " + to_string(mid) + "   high = " + to_string(high);
					pseudo.update(2);
					window.clear();
					window.draw(background);
					numbersInput.draw();
					pseudo.drawCode();
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
						if (currentState != binary) break;
						window.clear();
						window.draw(background);
						numbersInput.draw();
						pseudo.drawCode();
						buttons.buttonDraw(1, 7);
						buttons.sliderDraw();
						window.display();
					}
					if (currentState != binary) break;
					delayTime = clock.restart().asSeconds();
					while (delayTime < 1.0f && !end) {
						while (window.pollEvent(event)) {
							interrupt.windowHandle();
							interrupt.simUpdate(pause, stepForward, stepBackward, iteration, start, end, numbersInput);
						}
						delayTime = clock.getElapsedTime().asSeconds();
						if (currentState != binary) break;
						window.clear();
						window.draw(background);
						numbersInput.draw();
						pseudo.drawCode();
						buttons.buttonDraw(1, 7);
						buttons.sliderDraw();
						window.display();
					}
					if (currentState != binary) break;

					pseudo.showVariableString = "low = " + to_string(low) + "   mid = " + to_string(mid) + "   high = " + to_string(high);
					pseudo.update(3);
					window.clear();
					window.draw(background);
					numbersInput.draw();
					pseudo.drawCode();
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
						if (currentState != binary) break;
						window.clear();
						window.draw(background);
						numbersInput.draw();
						pseudo.drawCode();
						buttons.buttonDraw(1, 7);
						buttons.sliderDraw();
						window.display();
					}
					if (currentState != binary) break;
					if (numbersInput.numbers[mid].number == n)
					{
						found = true;
						setBarColorDone(numbersInput.numbers[mid].numberShape);

						pseudo.showVariableString = "low = " + to_string(low) + "   mid = " + to_string(mid) + "   high = " + to_string(high);
						pseudo.update(4);
						window.clear();
						window.draw(background);
						numbersInput.draw();
						pseudo.drawCode();
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
							if (currentState != binary) break;
							window.clear();
							window.draw(background);
							numbersInput.draw();
							pseudo.drawCode();
							buttons.buttonDraw(1, 7);
							buttons.sliderDraw();
							window.display();
						}
						if (currentState != binary) break;
						continue;

					}
					else if (low == high) {
						low++;
						continue;
					}

					pseudo.showVariableString = "low = " + to_string(low) + "   mid = " + to_string(mid) + "   high = " + to_string(high);
					pseudo.update(5);
					window.clear();
					window.draw(background);
					numbersInput.draw();
					pseudo.drawCode();
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
						if (currentState != binary) break;
						window.clear();
						window.draw(background);
						numbersInput.draw();
						pseudo.drawCode();
						buttons.buttonDraw(1, 7);
						buttons.sliderDraw();
						window.display();
					}

					if (currentState != binary) break;
					if (n < numbersInput.numbers[mid].number)
					{
						high = mid - 1;
						if (high != -1)
						{
							setBarColorActive(numbersInput.numbers[high].numberShape);
							for (int i = mid; i < size; i++) {
								setBarColorOff(numbersInput.numbers[i].numberShape);
							}
						}
						pseudo.showVariableString = "low = " + to_string(low) + "   mid = " + to_string(mid) + "   high = " + to_string(high);
						pseudo.update(6);
						window.clear();
						window.draw(background);
						numbersInput.draw();
						pseudo.drawCode();
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
							if (currentState != binary) break;
							window.clear();
							window.draw(background);
							numbersInput.draw();
							pseudo.drawCode();
							buttons.buttonDraw(1, 7);
							buttons.sliderDraw();
							window.display();
						}
						if (currentState != binary) break;
					}

					pseudo.showVariableString = "low = " + to_string(low) + "   mid = " + to_string(mid) + "   high = " + to_string(high);
					pseudo.update(7);
					window.clear();
					window.draw(background);
					numbersInput.draw();
					pseudo.drawCode();
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
						if (currentState != binary) break;
						window.clear();
						window.draw(background);
						numbersInput.draw();
						pseudo.drawCode();
						buttons.buttonDraw(1, 7);
						buttons.sliderDraw();
						window.display();
					}
					if (currentState != binary) break;
					if (n > numbersInput.numbers[mid].number)
					{
						low = mid + 1;
						setBarColorActive(numbersInput.numbers[low].numberShape);
						for (int i = mid; i >= 0; i--) {
							setBarColorOff(numbersInput.numbers[i].numberShape);
						}

						pseudo.showVariableString = "low = " + to_string(low) + "   mid = " + to_string(mid) + "   high = " + to_string(high);
						pseudo.update(8);
						window.clear();
						window.draw(background);
						numbersInput.draw();
						pseudo.drawCode();
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
							if (currentState != binary) break;
							window.clear();
							window.draw(background);
							numbersInput.draw();
							pseudo.drawCode();
							buttons.buttonDraw(1, 7);
							buttons.sliderDraw();
							window.display();
						}
						if (currentState != binary) break;
					}

					if (start)
					{
						numbersInput = vectorInput;
						low = 0;
						high = numbersInput.numbers.size() - 1;
						start = false;
					}

					if (stepForward)
					{
						stepForward = false;
					}

					while (window.pollEvent(event))
					{
						if (event.type == Event::Closed)
						{
							interrupt.windowHandle();
							interrupt.simUpdate(pause, stepForward, stepBackward, iteration, start, end, numbersInput);
						}
					}
					if (currentState != binary) break;
					window.clear();
					window.draw(background);
					numbersInput.draw();
					pseudo.drawCode();
					buttons.buttonDraw(1, 7);
					buttons.sliderDraw();
					window.display();
				}
				while (window.pollEvent(event)) {
					interrupt.windowHandle();
					interrupt.simUpdate(pause, stepForward, stepBackward, iteration, start, end, numbersInput);
				}
				if (currentState != binary) break;
			}
		}

		if (!found)
		{

			pseudo.showVariableString = "low = " + to_string(low) + "   mid = " + to_string(mid) + "   high = " + to_string(high);
			pseudo.update(9);
			window.clear();
			window.draw(background);
			numbersInput.draw();
			pseudo.drawCode();
			buttons.buttonDraw(1, 7);
			buttons.sliderDraw();
			window.draw(notFound);
			window.display();

			clock.restart();
			delayTime = clock.restart().asSeconds();
			while (delayTime < dtDelay && !end) {
				while (window.pollEvent(event)) {
					interrupt.windowHandle();
					interrupt.simUpdate(pause, stepForward, stepBackward, iteration, start, end, numbersInput);
				}
				delayTime = clock.getElapsedTime().asSeconds();
				if (currentState != binary) break;
				window.clear();
				window.draw(background);
				numbersInput.draw();
				pseudo.drawCode();
				buttons.buttonDraw(1, 7);
				buttons.sliderDraw();
				window.draw(notFound);
				window.display();
			}
			if (currentState != binary) break;

			found = true;
			printNotFound = true;
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
			if (currentState != binary) break;
		}
		if (currentState != binary) break;
		window.clear();
		window.draw(background);
		numbersInput.draw();
		pseudo.drawCode();
		buttons.buttonDraw(1, 7);
		buttons.sliderDraw();
		if(printNotFound) window.draw(notFound);
		window.display();
	}
	//currentState = simulation;
	return numbersInput;
}

NumbersClass Search::linearSearch(NumbersClass vectorInput, int n, Texture backgroundTexture)
{
	pseudo.loadCode(window.getSize().x, window.getSize().y);

	notFound.setPosition(window.getSize().x / 2, window.getSize().y / 2);

	pause = false;
	stepForward = false;
	stepBackward = false;
	iteration = true;
	start = false;
	end = false;
	showScreen = true;
	found = false;
	numbersInput = vectorInput;

	Sprite background(backgroundTexture);
	int length = numbersInput.numbers.size();
	int i;
	while (showScreen)
	{
		if (!pause)
		{
			cout << "1" << endl;
			pause = true;
			found = false;
			printNotFound = false;

			for (i = 0; i < length; i++)
			{
				cout << "2" << endl;
				if (!pause || i != 0) setBarColorActive(numbersInput.numbers[i].numberShape);

				pseudo.showVariableString = "i = " + to_string(i);
				pseudo.update(1);
				window.clear();
				window.draw(background);
				numbersInput.draw();
				pseudo.drawCode();
				buttons.buttonDraw(1, 7);
				buttons.sliderDraw();
				window.display();

				if (!pause || stepForward)
				{
					clock.restart();
					delayTime = clock.restart().asSeconds();
					while (delayTime < dtDelay && !end) {
						while (window.pollEvent(event)) {
							interrupt.windowHandle();
							interrupt.simUpdate(pause, stepForward, stepBackward, iteration, start, end, numbersInput);
						}
						delayTime = clock.getElapsedTime().asSeconds();
						if (currentState != linear) break;
						window.clear();
						window.draw(background);
						numbersInput.draw();
						pseudo.drawCode();
						buttons.buttonDraw(1, 7);
						buttons.sliderDraw();
						window.display();
					}
					if (currentState != linear) break;
					if (start && !pause) {
						numbersInput = vectorInput;
						i = -1;
						start = false;
						end = false;
						continue;
					}

					if (!pause || stepForward)
					{
						pseudo.showVariableString = "i = " + to_string(i);
						pseudo.update(2);
						window.clear();
						window.draw(background);
						numbersInput.draw();
						pseudo.drawCode();
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
							if (currentState != linear) break;
							window.clear();
							window.draw(background);
							numbersInput.draw();
							pseudo.drawCode();
							buttons.buttonDraw(1, 7);
							buttons.sliderDraw();
							window.display();
						}
						if (currentState != linear) break;
						if (numbersInput.numbers[i].number == n)
						{
							found = true;

							setBarColorDone(numbersInput.numbers[i].numberShape);

							pseudo.showVariableString = "i = " + to_string(i);
							pseudo.update(3);
							window.clear();
							window.draw(background);
							numbersInput.draw();
							pseudo.drawCode();
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
								if (currentState != linear) break;
								window.clear();
								window.draw(background);
								numbersInput.draw();
								pseudo.drawCode();
								buttons.buttonDraw(1, 7);
								buttons.sliderDraw();
								window.display();
							}
							if (currentState != linear) break;
							pseudo.showVariableString = "i = " + to_string(i);
							pseudo.update(4);
							window.clear();
							window.draw(background);
							numbersInput.draw();
							pseudo.drawCode();
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
								if (currentState != linear) break;
								window.clear();
								window.draw(background);
								numbersInput.draw();
								pseudo.drawCode();
								buttons.buttonDraw(1, 7);
								buttons.sliderDraw();
								window.display();
							}
							if (currentState != linear) break;
							break;
						}
					}

					if (!pause || stepForward) setBarColor(numbersInput.numbers[i].numberShape);
				}

				if (pause && !stepForward)	i--;

				if (stepForward)
				{
					stepForward = false;
				}

				while (window.pollEvent(event))
				{
					interrupt.windowHandle();
					interrupt.simUpdate(pause, stepForward, stepBackward, iteration, start, end, numbersInput);
				}
				if (currentState != linear) break;
				if (start && !pause) {
					numbersInput = vectorInput;
					i = -1;
					start = false;
					end = false;
				}

				window.clear();
				window.draw(background);
				numbersInput.draw();
				pseudo.drawCode();
				buttons.buttonDraw(1, 7);
				buttons.sliderDraw();
				window.display();
			}
		}

		if (!found)
		{
			//print not found;
			pseudo.showVariableString = "i = " + to_string(i);
			pseudo.update(5);
			window.clear();
			window.draw(background);
			numbersInput.draw();
			pseudo.drawCode();
			buttons.buttonDraw(1, 7);
			buttons.sliderDraw();
			window.draw(notFound);
			window.display();

			clock.restart();
			delayTime = clock.restart().asSeconds();
			while (delayTime < dtDelay && !end) {
				while (window.pollEvent(event)) {
					interrupt.windowHandle();
					interrupt.simUpdate(pause, stepForward, stepBackward, iteration, start, end, numbersInput);
				}
				delayTime = clock.getElapsedTime().asSeconds();
				if (currentState != linear) break;
				window.clear();
				window.draw(background);
				numbersInput.draw();
				pseudo.drawCode();
				buttons.buttonDraw(1, 7);
				buttons.sliderDraw();
				window.draw(notFound);
				window.display();
			}
			if (currentState != linear) break;
			found = true;
			printNotFound = true;
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
		if (currentState != linear) break;
		window.clear();
		window.draw(background);
		numbersInput.draw();
		pseudo.drawCode();
		buttons.buttonDraw(1, 7);
		buttons.sliderDraw();
		if (printNotFound) window.draw(notFound);
		window.display();
	}
	//currentState = simulation;
	return numbersInput;
}
