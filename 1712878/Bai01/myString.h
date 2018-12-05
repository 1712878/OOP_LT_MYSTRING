#ifndef __MY_STRING_H__
#define __MY_STRING_H__

#include <iostream>
#include <fstream>
using namespace std;

int mstrlen(const char *s);
int mstrcmp(const char *s1, const char* s2);
void mstrcpy(char* dest, const char* src);
void mstrncpy(char* dest, const char* src, int n);
void mstrncpy(char* dest, const char* src, int pos, int len);
const int _DEFAULT_SIZE = 4;
class MyString
{
private:
	char *m_str;
	int m_size;
	int m_reserved_size;
public:
	//Constructors
	MyString();
	MyString(const MyString& mstr);
	MyString(const MyString& mstr, int pos, int len);
	MyString(const char* s);
	MyString(const char* s, int n);
	MyString(int n, char c);

	//Destructor
	~MyString();

	friend istream& operator >> (istream& inDev, MyString& mstr)
	{
		inDev >> mstr.m_str;
		return inDev;
	}
	friend ostream& operator << (ostream& outDev, MyString& mstr)
	{
		outDev << mstr.m_str;
		return outDev;
	}
};

#endif

