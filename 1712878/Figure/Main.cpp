#include <iostream>
using namespace std;
const float PI = 3.14;

class Figure
{
public:
	virtual void Input(istream& inDev) = 0;
	virtual float Area() = 0;
};

class Rectangle : public Figure
{
protected :
	float wight, height;
public:
	Rectangle(float wight = 0, float height = 0)
	{
		this->wight = wight;
		this->height = height;
	}
	virtual void Input(istream& inDev)
	{
		inDev >> this->wight >> this->height;
	}
	virtual float Area()
	{
		return this->wight * this->height;
	}
};

class Square : public Rectangle
{
public:
	Square(float a = 0)
	{
		this->height = this->wight = a;
		//Square(float a = 0):Rectangle(a,a){}
		//Square(float a = 0){ Rectangle(a,a); }
	}
	virtual void Input(istream& inDev)
	{
		inDev >> this->wight;
		this->height = this->wight;
	}
};

class Ellipse :public Figure
{
protected:
	float Ra, Rb;
public:
	Ellipse(float Ra = 0, float Rb = 0)
	{
		this->Ra = Ra;
		this->Rb = Rb;
	}
	virtual void Input(istream& inDev)
	{
		inDev >> this->Ra >> this->Rb;
	}
	virtual float Area()
	{
		return PI * this->Ra * this->Rb;
	}
};

class Circle :public Ellipse
{
public:
	Circle(float R = 0) :Ellipse(R, R) {}
	virtual void Input(istream& inDev)
	{
		inDev >> this->Ra;
		this->Ra = this->Rb;
	}
};

class Triangle :public Figure
{
private:
	float basesize, height;
public:
	Triangle(float basesize, float height)
	{
		this->basesize = basesize;
		this->height = height;
	}
	virtual void Input(istream& inDev)
	{
		inDev >> this->basesize >> this->height;
	}
	virtual float Area()
	{
		return 0.5*this->basesize*this->height;
	}
};

Figure* FigMaxArea(Figure* Figs[], int nFig)
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

int main()

{
	//Figure *Fig;
	//Rectangle Rec(4,5);
	//Square Sq(5);
	//Fig = &Rec;
	//cout << Fig->Area() << endl;
	//Fig = &Sq;
	//cout << Fig->Area() << endl;
	
	Figure* Figs[] = { new Rectangle(9.3,9.7), new Circle(4.5), new Ellipse(4.2, 4.7),
					   new Square(9.5), new Triangle(10.7, 6.4), new Ellipse(3.7,7.8) };
	int nFig = sizeof(Figs) / sizeof(Figure*);
	Figure *aFig = FigMaxArea(Figs, nFig);
	if (aFig != NULL)
	{
		cout << aFig->Area() << endl;
	}
	system("pause");
	return 0;
}