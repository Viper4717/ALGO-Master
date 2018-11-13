#include "Header Files/InterruptHandle.h"


using namespace sf;
using namespace std;

Button::Button(float width, float height) {

	if (!font.loadFromFile("Fonts/ACANBLS.ttf")) {
		//handle error
	}

	tempText.setFont(font);
	tempText.setCharacterSize(height * 6 / 300);
	tempText.setFillColor(Color(204, 79, 8));
	tempText.setOutlineThickness(2);
	tempText.setOutlineColor(Color(0, 0, 0));

	for (int i = 0; i < 8; i++) buttonText[i] = tempText;

	buttonText[0].setString("L");
	buttonText[0].setPosition(Vector2f(width / 11.5 - 50, (height / 2) + (1 * 110) + 83 / 2 - 10));   //(Original)
	//buttonText[0].setPosition(Vector2f(width / 11.5, (height / 2) + (0.5 * 110) + 83 / 2));

	buttonText[1].setString("M");
	buttonText[1].setPosition(Vector2f(width / 11.5 - 50, (height / 2) + (2 * 110) + 83 / 2 - 10));   //(Original)
	//buttonText[1].setPosition(Vector2f(width / 11.5, (height / 2) + (1.5 * 110) + 83 / 2));

	buttonText[2].setString("B");
	buttonText[2].setPosition(Vector2f(width / 11.5 - 50, (height / 2) + (3 * 110) + 83 / 2 - 10));   //(Original)
	//buttonText[2].setPosition(Vector2f(width / 11.5, (height / 2) + (2.5 * 110) + 57 / 2));

	buttonText[3].setString("S");
	buttonText[3].setPosition(Vector2f(width / 11.5 - 50, (height / 2) + (1 * 110) + 83 / 2 - 10));   //(Original)
	//buttonText[3].setPosition(Vector2f(width / 11.5, (height / 2) + (0.5 * 110) + 83 / 2));

	buttonText[4].setString("Left");
	buttonText[4].setOrigin(buttonText[4].getGlobalBounds().width / 2, buttonText[4].getGlobalBounds().height / 2);
	buttonText[4].setPosition(Vector2f(2 * (width / 6) + 42, (height / 2) + (3 * 110) + 67));   //(Original)
	//buttonText[4].setPosition(Vector2f(2 * (width / 6) + 42, (height / 2) + (2.5 * 110) + 57));

	buttonText[5].setString("Space");
	buttonText[5].setOrigin(buttonText[5].getGlobalBounds().width / 2, buttonText[5].getGlobalBounds().height / 2);
	buttonText[5].setPosition(Vector2f(2 * (width / 6) + (1 * 95) + 42, (height / 2) + (3 * 110) + 67));   //(Original)
	//buttonText[5].setPosition(Vector2f(2 * (width / 6) + (1 * 95) + 42, (height / 2) + (2.5 * 110) + 57));

	buttonText[6].setString("Right");
	buttonText[6].setOrigin(buttonText[6].getGlobalBounds().width / 2, buttonText[6].getGlobalBounds().height / 2);
	buttonText[6].setPosition(Vector2f(2 * (width / 6) + (2 * 95) + 42, (height / 2) + (3 * 110) + 67));   //(Original)
	//buttonText[6].setPosition(Vector2f(2 * (width / 6) + (2 * 95) + 42, (height / 2) + (2.5 * 110) + 57));

	buttonText[7].setString("Down");
	buttonText[7].setOrigin(buttonText[7].getGlobalBounds().width / 2, buttonText[7].getGlobalBounds().height / 2);
	buttonText[7].setPosition(Vector2f(2 * (width / 6) + (3 * 95) + 42, (height / 2) + (3 * 110) + 67));   //(Original)
	//buttonText[7].setPosition(Vector2f(2 * (width / 6) + (3 * 95) + 42, (height / 2) + (2.5 * 110) + 57));

	buttonTextures[0][0].loadFromFile("Images/Buttons/load.png");
	buttonTextures[0][1].loadFromFile("Images/Buttons/load selected.png");
	buttonSprites[0].setTexture(buttonTextures[0][0]);
	buttonSprites[0].setPosition(Vector2f(width / 25 - 50, (height / 2) + (1 * 110)));   //(Original)
	//buttonSprites[0].setPosition(Vector2f(width / 25, (height / 2) + (0.5 * 110)));

	buttonTextures[1][0].loadFromFile("Images/Buttons/sound.png");
	buttonTextures[1][1].loadFromFile("Images/Buttons/sound selected.png");
	buttonSprites[1].setTexture(buttonTextures[1][0]);
	buttonSprites[1].setPosition(Vector2f(width / 25 - 50, (height / 2) + (2 * 110)));   //(Original)
	//buttonSprites[1].setPosition(Vector2f(width / 25, (height / 2) + (1.5 * 110)));

	buttonTextures[2][0].loadFromFile("Images/Buttons/back.png");
	buttonTextures[2][1].loadFromFile("Images/Buttons/back selected.png");
	buttonSprites[2].setTexture(buttonTextures[2][0]);
	buttonSprites[2].setPosition(Vector2f(width / 25 - 50, (height / 2) + (3 * 110)));   //(Original) 
	//buttonSprites[2].setPosition(Vector2f(width / 25, (height / 2) + (2.5 * 110)));

	buttonTextures[3][0].loadFromFile("Images/Buttons/save.png");
	buttonTextures[3][1].loadFromFile("Images/Buttons/save selected.png");
	buttonSprites[3].setTexture(buttonTextures[3][0]);
	buttonSprites[3].setPosition(Vector2f(width / 25 - 50, (height / 2) + (1 * 110)));   //(Original) 
	//buttonSprites[3].setPosition(Vector2f(width / 25, (height / 2) + (0.5 * 110)));

	buttonTextures[4][0].loadFromFile("Images/Buttons/start.png");
	buttonTextures[4][1].loadFromFile("Images/Buttons/start selected.png");
	buttonSprites[4].setTexture(buttonTextures[4][0]);
	buttonSprites[4].setPosition(Vector2f(2 * (width / 6), (height / 2) + (3 * 110)));   //(Original)
	//buttonSprites[4].setPosition(Vector2f(2 * (width / 6), (height / 2) + (2.5 * 110)));

	buttonTextures[5][0].loadFromFile("Images/Buttons/play.png");
	buttonTextures[5][1].loadFromFile("Images/Buttons/play selected.png");
	buttonSprites[5].setTexture(buttonTextures[5][0]);
	buttonSprites[5].setPosition(Vector2f(2 * (width / 6) + (1 * 95), (height / 2) + (3 * 110)));   //(Original)
	//buttonSprites[5].setPosition(Vector2f(2 * (width / 6) + (1 * 95), (height / 2) + (2.5 * 110)));

	buttonTextures[6][0].loadFromFile("Images/Buttons/forward.png");
	buttonTextures[6][1].loadFromFile("Images/Buttons/forward selected.png");
	buttonSprites[6].setTexture(buttonTextures[6][0]);
	buttonSprites[6].setPosition(Vector2f(2 * (width / 6) + (2 * 95), (height / 2) + (3 * 110)));   //(Original)
	//buttonSprites[6].setPosition(Vector2f(2 * (width / 6) + (2 * 95), (height / 2) + (2.5 * 110)));

	buttonTextures[7][0].loadFromFile("Images/Buttons/end.png");
	buttonTextures[7][1].loadFromFile("Images/Buttons/end selected.png");
	buttonSprites[7].setTexture(buttonTextures[7][0]);
	buttonSprites[7].setPosition(Vector2f(2 * (width / 6) + (3 * 95), (height / 2) + (3 * 110)));   //(Original)
	//buttonSprites[7].setPosition(Vector2f(2 * (width / 6) + (3 * 95), (height / 2) + (2.5 * 110)));

	buttonTextures[8][0].loadFromFile("Images/Buttons/mute.png");
	buttonTextures[8][1].loadFromFile("Images/Buttons/mute selected.png");

	buttonTextures[9][0].loadFromFile("Images/Buttons/pause.png");
	buttonTextures[9][1].loadFromFile("Images/Buttons/pause selected.png");

	buttonTextures[10][0].loadFromFile("Images/Buttons/reset.png");
	buttonTextures[10][1].loadFromFile("Images/Buttons/reset selected.png");

	sliderText[0] = tempText;
	sliderText[0].setCharacterSize(height * 6 / 350);
	sliderText[0].setOutlineThickness(1);
	sliderText[0].setString("Slow");
	sliderText[0].setOrigin(buttonText[6].getGlobalBounds().width / 2, buttonText[6].getGlobalBounds().height / 2);
	sliderText[0].setPosition(Vector2f(2 * (width / 6) + (6 * 95) - 60, (height / 2) + (3 * 110) + 53));   //(Original)
	//sliderText[0].setPosition(Vector2f(2 * (width / 6) + (6 * 95) - 80, (height / 2) + (2.5 * 110) + 33));

	sliderText[1] = tempText;
	sliderText[1].setCharacterSize(height * 6 / 350);
	sliderText[1].setOutlineThickness(1);
	sliderText[1].setString("Fast");
	sliderText[1].setOrigin(buttonText[6].getGlobalBounds().width / 2, buttonText[6].getGlobalBounds().height / 2);
	sliderText[1].setPosition(Vector2f(2 * (width / 6) + (6 * 95) + 90, (height / 2) + (3 * 110) + 53));   //(Original)
	//sliderText[1].setPosition(Vector2f(2 * (width / 6) + (6 * 95) + 80, (height / 2) + (2.5 * 110) + 33));

	slider.setSize(Vector2f(160.0f, 10.0f));
	slider.setOutlineThickness(2);
	slider.setOrigin(Vector2f(160/2, 5.0f));
	slider.setPosition(Vector2f(2 * (width / 6) + (6 * 95), (height / 2) + (3 * 110) + 28));   //Original
	//slider.setPosition(Vector2f(2 * (width / 6) + (6 * 95), (height / 2) + (2.5 * 110) + 28));
	slider.setOutlineColor(Color(255, 255, 255));
	slider.setFillColor(Color(0, 158, 255));  //182, 254, 202

	sliderButton.setRadius(12);
	sliderButton.setOutlineThickness(2);
	sliderButton.setOrigin(12, 12);
	sliderButton.setPosition(Vector2f(2 * (width / 6) + (6 * 95), (height / 2) + (3 * 110) + 28));   //Original
	//sliderButton.setPosition(Vector2f(2 * (width / 6) + (6 * 95), (height / 2) + (2.5 * 110) + 28));
	sliderButton.setOutlineColor(Color(255, 255, 255, 0));
	//sliderButton.setFillColor(Color(70, 252, 120));  //Dark Green
	sliderButton.setFillColor(Color(204, 79, 8));  //Dark Blue  is 48, 88, 209

	sliderButtonReflection.setRadius(2);
	sliderButtonReflection.setOrigin(1, 1);
	sliderButtonReflection.setPosition(Vector2f(2 * (width / 6) + (6 * 95) + 4, (height / 2) + (3 * 110) + 28 - 4));   //Original
	//sliderButtonReflection.setPosition(Vector2f(2 * (width / 6) + (6 * 95) + 4, (height / 2) + (2.5 * 110) + 28 - 4));
	//sliderButton.setFillColor(Color(70, 252, 120));  //Dark Green
	sliderButtonReflection.setFillColor(Color(255, 255, 255));  //Dark Blue  is 48, 88, 209
}

Button::~Button() {
	
}

void Button::buttonDraw(int itemStart, int itemEnd){
	for (int i = itemStart; i <= itemEnd; i++) {
		window.draw(buttonSprites[i]);
		window.draw(buttonText[i]);
	}
}

void Button::sliderDraw(){
	window.draw(slider);
	window.draw(sliderButton);
	window.draw(sliderButtonReflection);
	for (int i = 0; i < 2; i++) window.draw(sliderText[i]);
}

int Button::mouseCheck(Sprite *buttons, int itemStart, int itemEnd){
	for (int i = itemStart; i <= itemEnd; i++) {
		IntRect rect(buttons[i].getPosition().x, buttons[i].getPosition().y, buttons[i].getGlobalBounds().width, buttons[i].getGlobalBounds().height);
		if (i == 1) {
			if (rect.contains(Mouse::getPosition(window))) {
				if (musicPlay) {
					buttons[i].setTexture(buttonTextures[i][1]);
				}
				else {
					buttons[i].setTexture(buttonTextures[8][1]);
				}
				if (event.type == Event::MouseButtonPressed) {
					if (musicPlay) {
						buttons[i].setTexture(buttonTextures[8][1]);
						menuMusic.setVolume(0);
						musicPlay = 0;
					}
					else {
						buttons[i].setTexture(buttonTextures[i][1]);
						menuMusic.setVolume(100);
						musicPlay = 1;
					}
				}
				return -1;
			}
			else {
				if (musicPlay) {
					buttons[i].setTexture(buttonTextures[i][0]);
				}
				else {
					buttons[i].setTexture(buttonTextures[8][0]);
				}
			}
		}
		else if (i == 5) {
			if (rect.contains(Mouse::getPosition(window))) {
				if (algoPlay) {
					buttons[i].setTexture(buttonTextures[9][1]);
				}
				else {
					buttons[i].setTexture(buttonTextures[i][1]);
				}
				if (event.type == Event::MouseButtonPressed) {
					if (algoPlay) {
						buttons[i].setTexture(buttonTextures[i][1]);
					}
					else {
						buttons[i].setTexture(buttonTextures[9][1]);
					}
					return i;
				}
				return -1;
			}
			else {
				if (algoPlay) {
					buttons[i].setTexture(buttonTextures[9][0]);
				}
				else {
					buttons[i].setTexture(buttonTextures[i][0]);
				}
			}
		}
		else{
			if (rect.contains(Mouse::getPosition(window))) {
				if (currentTask == pracTask && i == 4) {
					buttons[i].setTexture(buttonTextures[10][1]);
					if (Mouse::isButtonPressed(Mouse::Left)) return i;
					return -1;
				}
				else{
					buttons[i].setTexture(buttonTextures[i][1]);
					if (Mouse::isButtonPressed(Mouse::Left)) return i;
					return -1;
				}
			}
			else {
				if (currentTask == pracTask && i == 4) {
					buttons[i].setTexture(buttonTextures[10][0]);
				}
				else {
					buttons[i].setTexture(buttonTextures[i][0]);
				}
			}
		}
	}
	return -2;
}

void Button::sliderCheck() {
	IntRect rect(sliderButton.getPosition().x - 12, sliderButton.getPosition().y - 12, sliderButton.getGlobalBounds().width, sliderButton.getGlobalBounds().height);
	if (rect.contains(Mouse::getPosition(window))) {
		sliderButton.setFillColor(Color(118, 10, 226));
		sliderButton.setOutlineColor(Color(255, 255, 255));
		if (Mouse::isButtonPressed(Mouse::Left)) {
			if (Mouse::getPosition(window).x < slider.getPosition().x + 80 && Mouse::getPosition(window).x > slider.getPosition().x - 80) {
				sliderButton.setPosition(Vector2f(Mouse::getPosition(window).x, (window.getSize().y / 2) + (3 * 110) + 28)); //Original
				//sliderButton.setPosition(Vector2f(Mouse::getPosition(window).x, (window.getSize().y / 2) + (2.5 * 110) + 28));
				sliderButtonReflection.setPosition(Vector2f(Mouse::getPosition(window).x + 4, (window.getSize().y / 2) + (3 * 110) + 28 - 4)); //Original
				//sliderButtonReflection.setPosition(Vector2f(Mouse::getPosition(window).x + 4, (window.getSize().y / 2) + (2.5 * 110) + 28 - 4));
			}
		}
	}
	else {
		sliderButton.setFillColor(Color(204, 79, 8));  //Magenta
		sliderButton.setOutlineColor(Color(255, 255, 255, 0));
	}
	dtDelay = 2 - ((sliderButton.getPosition().x - (slider.getPosition().x - 80)) / 80);
	//cout << dtDelay << endl;
}


