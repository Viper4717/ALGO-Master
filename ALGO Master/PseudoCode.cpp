#include "Header Files/InterruptHandle.h"



PseudoCode::PseudoCode(int width, int height)
{
	if (!font.loadFromFile("Fonts/ACANBLS.ttf")) {
		cout << "Error Occured: While loading font in PsudoCode." << endl;
	}

	algorithmName.setFont(font);
	algorithmName.setCharacterSize(height / 10);
	algorithmName.setFillColor(Color(66, 164, 244));
	algorithmName.setOutlineThickness(3);
	algorithmName.setOutlineColor(Color(255, 255, 255));
	
}


PseudoCode::~PseudoCode()
{
}

void PseudoCode::loadCode(float width, float height)
{
	pseudoString.clear();
	//This part loads the code to our stream.
	if (currentState == bubble) {
		if (flag == 2) pseudoFileStream.open("Pseudo Codes/Sort_Bubble_Ascending.txt");
		else if (flag == 3) pseudoFileStream.open("Pseudo Codes/Sort_Bubble_Descending.txt");
	}
	else if (currentState == insertion) {
		if (flag == 2) pseudoFileStream.open("Pseudo Codes/Sort_Insertion_Ascending.txt");
		else if (flag == 3) pseudoFileStream.open("Pseudo Codes/Sort_Insertion_Descending.txt");
	}
	else if (currentState == selection) {
		if (flag == 2) pseudoFileStream.open("Pseudo Codes/Sort_Selection_Ascending.txt");
		else if (flag == 3) pseudoFileStream.open("Pseudo Codes/Sort_Selection_Descending.txt");
	}
	else if (currentState == binary)	pseudoFileStream.open("Pseudo Codes/Search_Binary.txt");
	else if (currentState == linear)	pseudoFileStream.open("Pseudo Codes/Search_Linear.txt");

	else if(currentState == practiceBubble)	pseudoFileStream.open("Pseudo Codes/Practice_Sort_Bubble.txt");
	else if (currentState == practiceInsertion)	pseudoFileStream.open("Pseudo Codes/Practice_Sort_Insertion.txt");
	else if (currentState == practiceSelection)	pseudoFileStream.open("Pseudo Codes/Practice_Sort_Selection.txt");

	this->width = width;
	this->height = height;
	maxLineSize = -1;
	string temp;
	int i=0;
	line = 0;
	Text tempText;
	tempText.setFont(font);
	
	if (currentState == practiceBubble || currentState == practiceInsertion || currentState == practiceSelection) {
		tempText.setCharacterSize(height * (3.0 / 180));
	}
	else
		tempText.setCharacterSize(height * (3.0 / 150));
	setPseudoColorFont(tempText);

	getline(pseudoFileStream, temp);
	algorithmName.setString(temp);
	algorithmName.setOrigin(Vector2f(algorithmName.getGlobalBounds().width / 2, algorithmName.getGlobalBounds().height / 2));
	algorithmName.setPosition(Vector2f(width / 2, height / 8));

	while (getline(pseudoFileStream, temp)) {
		int stringLineSize = temp.size();
		if (stringLineSize > maxLineSize)	maxLineSize = stringLineSize;

		tempText.setString(temp);
		pseudoString.push_back(tempText);
		pseudoString[i++].setPosition(Vector2f(width / 1.25 - 60, ((height / 2) + (line++) * 40)));
	}

	Vector2f size;
	size.x = 415;		//maxLineSize * (height * (3.0 / (150 * 2.3))) + 30;

	//showVariable BG and text position and color
	size.y = height * 4 / 150 + 10;
	showVariable = tempText;
	if (currentState == practiceBubble || currentState == practiceInsertion || currentState == practiceSelection) {
		showVariable.setCharacterSize(height * (3.0 / 150));
	}
	showVariable.setPosition(width / 1.25 - 40, height / 2 - 20 - height * 4 / 150);
	showVariableBG.setSize(size);
	showVariableBG.setPosition(width / 1.25 - 20 - 55, height / 2 - 20 - height * 4 / 150);
	showVariableBG.setFillColor(Color(50, 255, 50));
	showVariableBG.setOutlineThickness(2);
	showVariableBG.setOutlineColor(Color(0, 0, 0));

	//This part modifies the BG
	size.y = height * 4 / 150 + line * 40;
	pseudoBG.setSize(size);
	pseudoBG.setFillColor(Color(255, 255, 255));
	pseudoBG.setPosition(width / 1.25 - 20 - 55, height / 2 - 20);
	pseudoBG.setOutlineThickness(2);
	pseudoBG.setOutlineColor(Color(0, 0, 0));

	//This part modifies the marker
	size.y = height * 4 / 150;
	pseudoMarker.setSize(size);										
	setPseudoColorMarker(pseudoMarker);
	pseudoMarker.setPosition(width / 1.25 - 20 - 55, height / 2);

	pseudoFileStream.close();
}

void PseudoCode::update(int line)
{
	markerUpdate(line);
	showVariableUpdate();
}

void PseudoCode::markerUpdate(int line)
{
	Vector2f position;
	line--;
	position.x = width / 1.25 - 20 - 55; //Same as size.x in the loadCode
	position.y = (height / 2) + line * 40;	//First part is the height from where the lines started + line number multiplied by line (spacing and size = 50).
	pseudoMarker.setPosition(position);
}

void PseudoCode::showVariableUpdate()
{
	showVariable.setString(showVariableString);
}



void PseudoCode::drawCode(bool show)
{
	if (!show)	showVariable.setString(showVariableString);

	int i, l = pseudoString.size();
	window.draw(algorithmName);

	window.draw(pseudoBG);					//draw BG
	if(show)	window.draw(pseudoMarker);	//draw marker
	window.draw(showVariableBG);			//draw showVariableBG
	window.draw(showVariable);				//draw showVariable Text
	
	for (i = 0; i < l; i++)		//draw lines
	{
		window.draw(pseudoString[i]);
	}
}

