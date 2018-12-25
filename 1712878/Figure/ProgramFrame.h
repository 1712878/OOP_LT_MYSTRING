#ifndef __PROGRAMFRAME_H__
#define __PROGRAMFRAME_H__

#include <iostream>
#include "Figure.h"
using namespace std;

class ProgramFrame
{
protected:
	virtual void StartMessage(ostream &outDev);
	virtual void Input(istream &inDev) = 0;
	virtual bool ValidData() = 0;
	virtual void ErrorMessage(ostream &outDev);
	virtual void Output(ostream &outDev) = 0;
	virtual void Processing() {};
	virtual bool AskToContinue(istream &inDev, ostream &outDev);
public:
	void Run(istream &inDev, ostream &outDev);
};

class FigureTest :public ProgramFrame
{
	Figure *mFig;
public:
	FigureTest(Figure* pFig);
	virtual void Input(istream &inDev);
	virtual void Output(ostream &outDev);
	virtual bool ValidData();
	virtual void StartMessage(ostream &outDev);
};
#endif // !__PROGRAMFRAME_H__

