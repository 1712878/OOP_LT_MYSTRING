#include "myString.h"
int mstrlen(const char *s)
{
	int i = 0;
	while (s[i] != '\0')
		i++;
	return i;
}
int mstrcmp(const char *s1, const char* s2)
{
	// 1 if s1>s2, -1 if s1<s2, 0 if s1=s2
	int n1 = mstrlen(s1), n2 = mstrlen(s2);
	int n = (n1 > n2)*n2 + (n2 >= n1)*n1;
	//compare  n element a like
	for (int i = 0; i < n; i++)
	{
		if (s1[i] > s2[i])
			return 1;
		else if (s1[i] > s2[i])
			return -1;
	}
	// length(s1 >s2)
	if (n < n1)
		return 1;
	// length(s2 >s1)
	if (n < n2)
		return -1;
	// s1=s2
	return 0;
}
void mstrcpy(char* dest, const char* src)
{
	int nSrc = mstrlen(src);
	for (int i = 0; i < nSrc; i++)
		dest[i] = src[i];
	dest[nSrc] = '\0';
}

void mstrncpy(char* dest, const char* src, int n)
{
	int nSrc = mstrlen(src);
	if (n > nSrc)
		n = nSrc;
	for (int i = 0; i < n; i++)
		dest[i] = src[i];
	dest[n] = '\0';
}
void mstrncpy(char* dest, const char* src, int pos, int len)
{
	int nSrc = mstrlen(src);
	if (pos + len > nSrc)
		len = nSrc - pos;
	mstrncpy(dest, src + pos, len);
}

//Constructors
MyString::MyString()
{
	this->m_size = 0;
	this->m_reserved_size = _DEFAULT_SIZE;
	this->m_str = new char[_DEFAULT_SIZE];
	this->m_str[0] = '\0';
}

MyString::MyString(const MyString &mstr)
{
	this->m_size = mstr.m_size;
	this->m_reserved_size = mstr.m_reserved_size;
	this->m_str = new char[m_size + 1];
	mstrcpy(this->m_str, mstr.m_str);
}

MyString::MyString(const MyString &mstr, int pos, int len)
{
	this->m_size = len;
	this->m_reserved_size = len + _DEFAULT_SIZE;
	this->m_str = new char[this->m_size + 1];
	mstrncpy(this->m_str, mstr.m_str, pos, len);
}

MyString::MyString(const char* s)
{
	this->m_size = mstrlen(s);
	this->m_reserved_size = this->m_size + _DEFAULT_SIZE;
	this->m_str = new char[this->m_size + 1];
	mstrcpy(this->m_str, s);
}

MyString::MyString(const char* s, int n)
{
	int l = mstrlen(s);
	this->m_size = (l <= n)*l + (l > n)*n;
	this->m_reserved_size = this->m_size + _DEFAULT_SIZE;
	this->m_str = new char[this->m_size + 1];
	mstrncpy(this->m_str, s, this->m_size);
}

MyString::MyString(int n, char c)
{
	this->m_size = n;
	this->m_reserved_size = n + _DEFAULT_SIZE;
	this->m_str = new char[this->m_size + 1];
	for (int i = 0; i < n; i++)
		this->m_str[i] = c;
	this->m_str[n] = '\0';
}

//Destructor
MyString::~MyString()
{
	delete[] this->m_str;
	this->m_str = NULL;
	this->m_size = 0;
	this->m_reserved_size = 0;
}
