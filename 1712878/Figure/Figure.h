#ifndef __FIGURE_H__
#define __FIGURE_H__

#include <iostream>
#include <vector>
using namespace std;
const float PI = 3.14;

class Figure
{
	static vector<Figure*> sampleObjects;
protected:
	static void addSample(Figure* pFig);
public:
	virtual const char* className() = 0;
	virtual Figure* Clone() = 0;
	static Figure* createObject(const char* clsName);
	virtual void Input(istream& inDev) = 0;
	virtual float Area() = 0;
};

class Rectangle : public Figure
{
protected:
	float wight, height;
public:
	Rectangle(float wight = 0, float height = 0);
	virtual const char* className();
	virtual Figure* Clone();
	virtual void Input(istream& inDev);
	virtual float Area();
};

class Square : public Rectangle
{
public:
	Square(float a = 0);
	virtual const char* className();
	virtual Figure* Clone();
	virtual void Input(istream& inDev);
};

class Ellipse :public Figure
{
protected:
	float Ra, Rb;
public:
	Ellipse(float Ra = 0, float Rb = 0);
	virtual const char* className();
	virtual Figure* Clone();
	virtual void Input(istream& inDev);
	virtual float Area();
};

class Circle :public Ellipse
{
public:
	Circle(float R = 0);
	virtual const char* className();
	virtual Figure* Clone();
	virtual void Input(istream& inDev);
};

class Triangle :public Figure
{
private:
	float basesize, height;
public:
	Triangle(float basesize, float height);
	virtual const char* className();
	virtual Figure* Clone();
	virtual void Input(istream& inDev);
	virtual float Area();
};

Figure* FigMaxArea(Figure* Figs[], int nFig);

Figure* Cloning(Figure* pFig);

#endif // !__FIGURE_H__

