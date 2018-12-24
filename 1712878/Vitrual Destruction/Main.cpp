#include <iostream>
using namespace std;

class Point
{
	int x, y;
public:
	Point(int xo = 0, int yo = 0)
	{
		this->x = xo;
		this->y = yo;
	}
	friend class RECT;
};

class Polygon
{
protected:
	int nVer;
	Point* Vers;
public:
	Polygon(int n = 0)
	{
		Vers = NULL;
		nVer = 0;
		if (n > 0)
		{
			nVer = n;
			Vers = new Point[nVer];
		}
	}
	int nVertice()
	{
		return this->nVer;
	}
	virtual ~Polygon()
	{
		if (this->nVer > 0)
		{
			this->nVer = 0;
			delete[] this->Vers;
			this->Vers = NULL;
		}
	}
};

class RECT : public Polygon
{
	Point P, Q;
	char *Buffer;
public:
	Point Center()
	{
		Point I;
		I.x = (P.x + Q.x) / 2;
		I.y = (P.y + Q.y) / 2;
		return I;
	}
	RECT(Point A, Point B)
	{
		this->nVer = 4;
		this->P = A;
		this->Q = B;
		int dx = P.x - Q.x, dy = P.y - Q.y;
		long BufferSize = dx * (long)dy;
		if (BufferSize < 0)
			BufferSize = -BufferSize;
		Buffer = new char[BufferSize];
	}
	virtual ~RECT()
	{
		if (Buffer != NULL)
		{
			delete[] Buffer;
			Buffer = NULL;
		}
	}
};

int main()
{
	Point A(4, 5);
	Point B(-3, 11);
	Polygon *pg = new RECT(Point(4, 5), Point(-3, 11));
	cout << pg->nVertice() << endl;
	delete pg;
	
	system("pause");
	return 0;
}