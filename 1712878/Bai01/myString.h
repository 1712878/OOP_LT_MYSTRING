#ifndef __MY_STRING_H__
#define __MY_STRING_H__

#include <iostream>
#include <fstream>
using namespace std;

int m_strlen(const char *s);
int m_strcmp(const char *s1, const char* s2);
void m_strcpy(char* dest, const char* src);
void m_strncpy(char* dest, const char* src, int n);
void m_strncpy(char* dest, const char* src, int pos, int len);
const int _DEFAULT_SIZE = 4;
const size_t _MAX_LENGTH = 1024;
const int npos = -1;
class MyString
{
private:
	char *m_str;
	int m_size;
	int m_reserved_size;
public:
	//Member functions
	MyString();
	MyString(const MyString& str);
	MyString(const MyString& str, size_t pos, size_t len);
	MyString(const char* s);
	MyString(const char* s, size_t n);
	MyString(size_t n, char c);

	~MyString();

	MyString& operator= (const MyString& str);
	MyString& operator= (const char* s);
	MyString& operator= (char c);

	//Iterators
	typedef char* iterator;
	typedef const char* const_iterator;
	iterator begin();
	const_iterator begin() const;
	iterator end();
	const_iterator end() const;

	typedef char* reverse_iterator;
	typedef const char* const_reverse_iterator;
	reverse_iterator rbegin();
	const_reverse_iterator rbegin() const;
	reverse_iterator rend();
	const_reverse_iterator rend() const;
	//.............

	//Capacity:
	size_t size() const;
	size_t length() const;
	size_t max_size() const;
	void resize(size_t n);
	void resize(size_t n, char c);
	size_t capacity() const;
	//void reserve(size_t n = 0);
	void clear();
	bool empty() const;
	void shrink_to_fit();


	//Element access:
	char& operator[] (size_t pos);
	const char& operator[] (size_t pos) const;
	char& at(size_t pos);
	const char& at(size_t pos) const;
	char& back();
	const char& back() const;
	char& front();
	const char& front() const;

	friend MyString operator+ (const MyString& lhs, const MyString& rhs);
	friend istream& operator >> (istream& inDev, MyString& mstr)
	{
		char* s= new char[_MAX_LENGTH];
		inDev >> s;
		mstr = s;
		delete[] s;
		return inDev;
	}
	friend ostream& operator << (ostream& outDev, MyString& mstr)
	{
		outDev << mstr.m_str;
		return outDev;
	}
};

#endif