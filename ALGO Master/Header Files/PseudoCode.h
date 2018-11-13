#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include <string>
#include <fstream>

using namespace std;
using namespace sf;

class PseudoCode
{
public:
	PseudoCode(int width, int height);
	~PseudoCode();
	void loadCode(float width, float height);

	void update(int line);
	void markerUpdate(int line);
	void showVariableUpdate();

	void drawCode(bool show = 1);
public:
	vector	<Text>	pseudoString;
	Text showVariable;
	string showVariableString;
private:
	fstream pseudoFileStream;
	RectangleShape showVariableBG;
	RectangleShape pseudoBG;
	RectangleShape pseudoMarker;
	Text algorithmName;
	int maxLineSize;
	Font font;
	int line;
	float width, height;
};

