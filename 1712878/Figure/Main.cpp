#include <iostream>
#include <vector>
using namespace std;
const float PI = 3.14;

class Figure
{
	static vector<Figure*> sampleObjects;
protected:
	static void addSample(Figure* pFig)
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
public:
	virtual const char* className() = 0;
	virtual Figure* Clone() = 0;
	virtual Figure* createObject(const char* clsName)
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
		addSample(this);
	}
	virtual const char* className()
	{
		return "Rectangle";
	}
	virtual Figure* Clone()
	{
		return new Rectangle(*this);
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
		addSample(this);
		//Square(float a = 0):Rectangle(a,a){}
		//Square(float a = 0){ Rectangle(a,a); }
	}
	virtual const char* className()
	{
		return "Square";
	}
	virtual Figure* Clone()
	{
		return new Square(*this);
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
		addSample(this);
	}
	virtual const char* className()
	{
		return "Ellipse";
	}
	virtual Figure* Clone()
	{
		return new Ellipse(*this);
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
	Circle(float R = 0) :Ellipse(R, R) 
	{
		addSample(this);
	}
	virtual const char* className()
	{
		return "Circle";
	}
	virtual Figure* Clone()
	{
		return new Circle(*this);
	}
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
		addSample(this);
	}
	virtual const char* className()
	{
		return "Triangle";
	}
	virtual Figure* Clone()
	{
		return new Triangle(*this);
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

Figure* Cloning(Figure* pFig)
{
	if (pFig == NULL)
		return NULL;
	return pFig->Clone();
}

int main()
{
	/*Figure* Fig;
	Rectangle Rec(4,5);
	Square Sq(5);
	Fig = &Rec;
	cout << Fig->Area() << endl;
	Fig = &Sq;
	cout << Fig->Area() << endl;*/
	
	/*Figure* Figs[] = { new Rectangle(9.3,9.7), new Circle(4.5), new Ellipse(4.2, 4.7),
					   new Square(9.5), new Triangle(10.7, 6.4), new Ellipse(3.7,7.8) };
	int nFig = sizeof(Figs) / sizeof(Figure*);
	cout << "nFig = " << nFig << endl;
	for (int i = 0; i < nFig; i++)
	{
		cout << i + 1 << ". ";
		cout << Figs[i]->className() << ", Area: " << Figs[i]->Area() << endl;
	}
	Figure *aFig = FigMaxArea(Figs, nFig);
	if (aFig != NULL)
	{
		cout << "Area max is figure " << aFig->className() << ", Area= ";
		cout << aFig->Area() << endl;
	}*/

	/*Rectangle Rec(4, 5);
	Square Sq(5);
	Figure* Fig;
	Fig = Cloning(&Rec);
	cout << Fig->className() << ", Area: " << Fig->Area() << endl; // Fig is cloning Rec
	Fig = Cloning(&Sq);
	cout << Fig->className() << ", Area: " << Fig->Area() << endl; // Fig is cloning Sq*/

	
	system("pause");
	return 0;
}
