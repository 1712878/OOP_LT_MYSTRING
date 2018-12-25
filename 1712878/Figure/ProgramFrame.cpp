#include "ProgramFrame.h"

void ProgramFrame::StartMessage(ostream & outDev)
{
	outDev << "Welcome, entering data: ";
}

void ProgramFrame::ErrorMessage(ostream & outDev)
{
	outDev << "Input data error!" << endl;
}

bool ProgramFrame::AskToContinue(istream & inDev, ostream & outDev)
{
	char ch;
	outDev << "Press 'Y' to continue, other key to stop...";
	inDev >> ch;
	return (ch == 'y' || ch == 'Y');
}

void ProgramFrame::Run(istream & inDev, ostream & outDev)
{
	bool ToContinue;
	do
	{
		StartMessage(outDev);
		Input(inDev);
		if (!ValidData())
		{
			ErrorMessage(outDev);
			continue;
		}
		Processing();
		Output(outDev);
		ToContinue = AskToContinue(inDev, outDev);
	} while (ToContinue);
}

FigureTest::FigureTest(Figure * pFig)
{
	mFig = pFig;
}

void FigureTest::Input(istream & inDev)
{
	if (mFig != NULL)
		mFig->Input(inDev);
}

void FigureTest::Output(ostream & outDev)
{
	if (mFig == NULL)
		return;
	outDev << mFig->className() << ", Area: " << mFig->Area() << endl;
}

bool FigureTest::ValidData()
{
	if (mFig == NULL)
		return false;
	return mFig->IsValid();
}

void FigureTest::StartMessage(ostream & outDev)
{
	if (mFig != NULL)
		outDev << "Entering data for " << mFig->className() << ": ";
}
