#include "Header Files/InterruptHandle.h"


using namespace sf;
using namespace std;

NumbersClass::NumbersClass()
{
	screenPosition.x = window.getSize().x / 10;  //192
	screenPosition.y = (window.getSize().y * 5) / 12;  //220 //*11 / 54
	screenWidth = 1093;
	screenHeight = 320;
	//cout << resolution.y << endl;
}

NumbersClass::~NumbersClass()
{
}


void NumbersClass::draw()
{
	for (vector<NumberInfo>::iterator i = numbers.begin(); i < numbers.end(); i++)
	{
		window.draw(i->numberShape);
		window.draw(i->value);
	}
}

void NumbersClass::PushVector(int number, float height)
{
	//string line;
	//cout << resolution.y << " " << screenHeight << " " << screenWidth <<  endl;
	valueFont.loadFromFile("Fonts/ACANBLS.ttf");
	temp.number = number;
	totalNumbers++;
	temp.value.setFont(valueFont);
	temp.value.setCharacterSize(height * 6 / 200);
	temp.value.setFillColor(Color(204, 79, 8));
	temp.value.setString(to_string(number));
	temp.shapeSize.x = 75;
	temp.shapeSize.y = (5 * temp.number);
	temp.numberShape.setSize(Vector2f(temp.shapeSize));
	temp.textPosition.x = temp.shapeSize.x*totalNumbers + screenPosition.x + 5 * (totalNumbers - 1) + temp.shapeSize.x / 2 - height * 6 / 300;
	temp.textPosition.y = (screenPosition.y + screenHeight - height * 6 / 200);
	temp.value.setPosition(Vector2f(temp.textPosition));
	temp.position.x = temp.shapeSize.x*totalNumbers + screenPosition.x + 5 * (totalNumbers - 1);
	temp.position.y = (screenPosition.y + screenHeight - temp.shapeSize.y);
	temp.numberShape.setPosition(Vector2f(temp.position));
	numbers.push_back(temp);
}

void NumbersClass::PopVector(int number)
{
	for (searchNumber = numbers.begin(); searchNumber < numbers.end(); searchNumber++)
	{
		if (number == searchNumber->number)
		{
			numbers.erase(searchNumber);
			searchNumber = numbers.begin();
			break;
		}
	}
}

void NumbersClass::resetTotalNumbers()
{
	totalNumbers = 0;
}

bool NumberInfo::operator<(NumberInfo a)
{
	if (number < a.number)	return true;
	return false;
}

bool NumberInfo::operator<=(NumberInfo a)
{
	if (number <= a.number)	return true;
	return false;
}

bool NumberInfo::operator>(NumberInfo a)
{
	if (number > a.number)	return true;
	return false;
}

bool NumberInfo::operator>=(NumberInfo a)
{
	if (number >= a.number)	return true;
	return false;
}

bool NumberInfo::operator==(NumberInfo a)
{
	if (number == a.number)	return true;
	return false;
}
