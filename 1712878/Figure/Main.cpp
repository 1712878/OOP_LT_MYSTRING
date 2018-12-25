#include "Figure.h"

int main()
{
	/*Figure* Fig;
	Rectangle Rec(4,5);
	Square Sq(5);
	Fig = &Rec;
	cout << Fig->Area() << endl;
	Fig = &Sq;
	cout << Fig->Area() << endl;*/
	
	Figure* Figs[] = { new Rectangle(9.3,9.7), new Circle(4.5), new Ellipse(4.2, 4.7),
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
	}

	/*Rectangle Rec(4, 5);
	Square Sq(5);
	Figure* Fig;
	Fig = Cloning(&Rec);
	cout << Fig->className() << ", Area: " << Fig->Area() << endl;
	Fig = Cloning(&Sq);
	cout << Fig->className() << ", Area: " << Fig->Area() << endl;*/


	Figure* Fig = Figure::createObject("Ellipse");
	if (Fig != NULL)
	{
		cout << Fig->className() << ", Area: " << Fig->Area() << endl;
	}

	system("pause");
	return 0;
}
