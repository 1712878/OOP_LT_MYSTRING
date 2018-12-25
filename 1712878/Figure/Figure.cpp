#include "Figure.h"
vector<Figure*> Figure::sampleObjects;

void Figure::addSample(Figure * pFig)
{
	if (pFig == NULL)
		return;
	int pos = sampleObjects.size();
	while (--pos >= 0)
	{
		Figure* Obj = sampleObjects[pos];
		if (strcmp(pFig->className(), Obj->className()) == 0)
			break;
	}
	if (pos < 0)
		sampleObjects.push_back(pFig);
}

Figure * Figure::createObject(const char * clsName)
{
	if (clsName == NULL)
		return NULL;
	int pos = sampleObjects.size();
	while (--pos >= 0)
	{
		Figure* Obj = sampleObjects[pos];
		if (Obj == NULL)
			continue;
		if (strcmp(clsName, Obj->className()) == 0)
			break;
	}
	if (pos >= 0)
		return sampleObjects[pos]->Clone();
	else
		return NULL;
}

Rectangle::Rectangle(float wight, float height)
{
	this->wight = wight;
	this->height = height;
	addSample(this);
}

const char * Rectangle::className()
{
	return "Rectangle";
}

Figure * Rectangle::Clone()
{
	return new Rectangle(*this);
}

void Rectangle::Input(istream & inDev)
{
	inDev >> this->wight >> this->height;
}

float Rectangle::Area()
{
	return this->wight * this->height;
}

Square::Square(float a)
{
	this->height = this->wight = a;
	addSample(this);
	//Square(float a = 0):Rectangle(a,a){}
	//Square(float a = 0){ Rectangle(a,a); }
}

const char * Square::className()
{
	return "Square";
}

Figure * Square::Clone()
{
	return new Square(*this);
}

void Square::Input(istream & inDev)
{
	inDev >> this->wight;
	this->height = this->wight;
}

Ellipse::Ellipse(float Ra, float Rb)
{
	this->Ra = Ra;
	this->Rb = Rb;
	addSample(this);
}

const char * Ellipse::className()
{
	return "Ellipse";
}

Figure * Ellipse::Clone()
{
	return new Ellipse(*this);
}

void Ellipse::Input(istream & inDev)
{
	inDev >> this->Ra >> this->Rb;
}

float Ellipse::Area()
{
	return PI * this->Ra * this->Rb;
}

Circle::Circle(float R) :Ellipse(R, R)
{
	addSample(this);
}

const char * Circle::className()
{
	return "Circle";
}

Figure * Circle::Clone()
{
	return new Circle(*this);
}

void Circle::Input(istream & inDev)
{
	inDev >> this->Ra;
	this->Ra = this->Rb;
}

Triangle::Triangle(float basesize, float height)
{
	this->basesize = basesize;
	this->height = height;
	addSample(this);
}

const char * Triangle::className()
{
	return "Triangle";
}

Figure * Triangle::Clone()
{
	return new Triangle(*this);
}

void Triangle::Input(istream & inDev)
{
	inDev >> this->basesize >> this->height;
}

float Triangle::Area()
{
	return 0.5*this->basesize*this->height;
}

Figure * FigMaxArea(Figure * Figs[], int nFig)
{
	Figure* FigMax = NULL;
	if (nFig > 0)
	{
		FigMax = Figs[0];
		for (int i = 0; i < nFig; i++)
		{
			if (FigMax->Area() < Figs[i]->Area())
				FigMax = Figs[i];
		}
	}
	return FigMax;
}

Figure * Cloning(Figure * pFig)
{
	if (pFig == NULL)
		return NULL;
	return pFig->Clone();
}
