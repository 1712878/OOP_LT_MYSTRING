#include "myString.h"
int m_strlen(const char *s)
{
	int i = 0;
	while (s[i] != '\0')
		i++;
	return i;
}
int m_strcmp(const char *s1, const char* s2)
{
	// 1 if s1>s2, -1 if s1<s2, 0 if s1=s2
	int n1 = m_strlen(s1), n2 = m_strlen(s2);
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
void m_strcpy(char* dest, const char* src)
{
	int nSrc = m_strlen(src);
	for (int i = 0; i < nSrc; i++)
		dest[i] = src[i];
	dest[nSrc] = '\0';
}
void m_strncpy(char* dest, const char* src, int n)
{
	int nSrc = m_strlen(src);
	if (n > nSrc)
		n = nSrc;
	for (int i = 0; i < n; i++)
		dest[i] = src[i];
	dest[n] = '\0';
}
void m_strncpy(char* dest, const char* src, int pos, int len)
{
	int nSrc = m_strlen(src);
	if (pos + len > nSrc)
		len = nSrc - pos;
	m_strncpy(dest, src + pos, len);
}

MyString operator+(const MyString & lhs, const MyString & rhs)
{
	MyString result;
	result.m_size = lhs.m_size + rhs.m_size;
	result.m_reserved_size = result.m_size + _DEFAULT_SIZE;
	result.m_str = new char[result.m_reserved_size + 1];
	m_strcpy(result.m_str, lhs.m_str);
	m_strcpy(result.m_str+lhs.m_size, rhs.m_str);
	return result;
}

//Member functions/Constructors
MyString::MyString()
{
	this->m_size = 0;
	this->m_reserved_size = _DEFAULT_SIZE;
	this->m_str = new char[this->m_reserved_size + 1];
	this->m_str[0] = '\0';
}

MyString::MyString(const MyString &str)
{
	this->m_size = str.m_size;
	this->m_reserved_size = str.m_reserved_size;
	this->m_str = new char[this->m_reserved_size + 1];
	m_strcpy(this->m_str, str.m_str);
}

MyString::MyString(const MyString &str, size_t pos, size_t len)
{
	if (len == npos)
	{
		this->m_size = str.m_size - pos;
		this->m_reserved_size = this->m_size + _DEFAULT_SIZE;
		this->m_str = new char[this->m_reserved_size + 1];
		m_strncpy(this->m_str, str.m_str, pos);
	}
	else
	{
		this->m_size = len;
		this->m_reserved_size = len + _DEFAULT_SIZE;
		this->m_str = new char[this->m_reserved_size + 1];
		m_strncpy(this->m_str, str.m_str, pos, len);
	}
}

MyString::MyString(const char* s)
{
	this->m_size = m_strlen(s);
	this->m_reserved_size = this->m_size + _DEFAULT_SIZE;
	this->m_str = new char[this->m_reserved_size + 1];
	m_strcpy(this->m_str, s);
}

MyString::MyString(const char* s, size_t n)
{
	int l = m_strlen(s);
	this->m_size = (l <= n)*l + (l > n)*n;
	this->m_reserved_size = this->m_size + _DEFAULT_SIZE;
	this->m_str = new char[this->m_reserved_size + 1];
	m_strncpy(this->m_str, s, this->m_size);
}

MyString::MyString(size_t n, char c)
{
	this->m_size = n;
	this->m_reserved_size = n + _DEFAULT_SIZE;
	this->m_str = new char[this->m_reserved_size + 1];
	for (int i = 0; i < n; i++)
		this->m_str[i] = c;
	this->m_str[n] = '\0';
}

//Member functions/Destructor
MyString::~MyString()
{
	delete[] this->m_str;
	this->m_str = NULL;
	this->m_size = 0;
	this->m_reserved_size = 0;
}

//Member functions/Operator =
MyString & MyString::operator=(const MyString & str)
{
	this->m_size = str.m_size;
	this->m_reserved_size = str.m_reserved_size;
	this->m_str = new char[this->m_reserved_size + 1];
	m_strcpy(this->m_str, str.m_str);
	return *this;
}

MyString & MyString::operator=(const char* s)
{
	this->m_size = m_strlen(s);
	this->m_reserved_size = this->m_size + _DEFAULT_SIZE;
	this->m_str = new char[this->m_reserved_size + 1];
	m_strcpy(this->m_str, s);
	return *this;
}

MyString & MyString::operator=(char c)
{
	this->m_size = 1;
	this->m_reserved_size = 1 + _DEFAULT_SIZE;
	this->m_str = new char[this->m_reserved_size + 1];
	this->m_str[0] = c;
	this->m_str[1] = '\0';
	return *this;
}

//Iterators/begin
MyString::iterator MyString::begin()
{
	return this->m_str;
}

MyString::const_iterator MyString::begin() const
{
	return this->m_str;
}

MyString::iterator MyString::end()
{
	return this->m_str + this->m_size;
}

MyString::const_iterator MyString::end() const
{
	return this->m_str + this->m_size;
}

MyString::reverse_iterator MyString::rbegin()
{
	return this->m_str + this->m_size-1;
}

MyString::const_reverse_iterator MyString::rbegin() const
{
	return const_reverse_iterator();
}

MyString::reverse_iterator MyString::rend()
{
	return this->m_str - 1;
}

MyString::const_reverse_iterator MyString::rend() const
{
	return const_reverse_iterator();
}

size_t MyString::size() const
{
	return this->m_size;
}

size_t MyString::length() const
{
	return this->m_size;
}

size_t MyString::max_size() const
{
	return  _MAX_SIZE;
}

void MyString::resize(size_t n)
{
	if (n > this->m_size)
	{
		if (n > this->m_reserved_size)
		{
			this->m_reserved_size = n;
			char* s = new char[n];
			m_strcpy(s, this->m_str);
	
		}
	}
}

void MyString::resize(size_t n, char c)
{
}

