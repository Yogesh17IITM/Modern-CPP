/*
* TOPIC: Virtual Functions, Multiple Inheritance
*/

#include<iostream>
using namespace std;

class Circle
{
public:
	virtual void getArea()
	{
		cout << "Circle::getArea()" << endl;
	}
};

class Rectangle
{
public:
	virtual void getArea()
	{
		cout << "Rectangle::getArea()" << endl;
	}
};

// Multiple Inheritence
class Shape : public Circle, public Rectangle
{};

// Builder class for shape
Circle *ShapeBuilder()
{
	return new Shape();
}

int main()
{
	Circle* pCircle = ShapeBuilder();
	if (pCircle)
		pCircle->getArea();

	Rectangle* pRect = (Rectangle*)pCircle;
	if (pRect)
		pRect->getArea();	// Here "Circle::getArea()" will be printed. Since it has the address of circle.

	pRect++;	// contains addr of Shape instance which has two pointers, one for Circle and other for Rect.
	if (pRect)
		pRect->getArea();	// Here "Rectangle::getArea()" will be printed. Since the pointer is incremented.

	// pRect++; -> It will throw compilation error as there is no further pointers.

	Rectangle* pRect1 = (Shape*)pCircle;
	if (pRect)
		pRect->getArea();	// Here "Rectangle::getArea()" will be printed as we have incremented the pointer earlier.

	Rectangle* pRect2 = dynamic_cast<Shape*>(pCircle); 
	if (pRect)
		pRect->getArea();	// Here "Rectangle::getArea()" will be printed as we have incremented the pointer earlier.

	return 0;
}