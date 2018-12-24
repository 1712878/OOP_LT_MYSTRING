#include "myString.h"
#include "Test.h"
#include <string>
class Base
{

};
class MyIntArray :public Base
{
private:
	int *pArr;
	int size;
public:
	MyIntArray()
	{
		this->size = 0;
		this->pArr = NULL;
	}
	MyIntArray(int n)
	{
		this->size = n;
		this->pArr = new int[n];
		for (int i = 0; i < n; i++)
			this->pArr[i] = 0;
	}
	MyIntArray(const MyIntArray &p)
	{
		this->size = p.size;
		this->pArr = new int[this->size];
		for (int i = 0; i < this->size; i++)
			this->pArr[i] = p.pArr[i];
	}
	~MyIntArray()
	{
		if (this->size > 0)
		{
			this->size = 0;
			delete[] this->pArr;
			this->pArr = NULL;
		}
	}
	MyIntArray& operator =(const MyIntArray &p)
	{
		if (this != &p)
		{
			Base::operator=(p);
			delete[] this->pArr;
			this->size = p.size;
			this->pArr = new int[this->size];
			for (int i = 0; i < this->size; i++)
				this->pArr[i] = p.pArr[i];
		}
		return *this;
	}
};
class PhanSo
{
private:
	int tu, mau;
public:
	PhanSo(int t, int m)
	{
		tu = t;
		mau = m;
	}
	PhanSo operator ++()
	{
		this->tu += mau;
		return *this;
	}
	PhanSo operator ++(int)
	{
		PhanSo t = *this;
		this->tu += this->mau;
		return t;
	}
	friend ostream& operator << (ostream& out, const PhanSo &p)
	{
		out << p.tu << "/" << p.mau;
		return out;
	}
};
int main()
{
	//MemberFunctions();
	//Iterators();
	//Capacity();
	//ElementAccess();
	//Modifiers();
	//StringOperations();
	
	Base * pa = new Base();
	MyIntArray *pb = static_cast<MyIntArray*> (pa);
	system("pause");
	return 0;
}