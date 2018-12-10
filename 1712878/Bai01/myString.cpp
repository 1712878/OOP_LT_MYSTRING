#include "myString.h"
int Min(int a, int b)
{
	return (a < b)*a + (a >= b)*b;
}
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
	int n = Min(n1, n2);
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
int m_strncmp(const char *s1, const char* s2, int n)
{
	int n1 = m_strlen(s1), n2 = m_strlen(s2);
	int min = Min(n1, n2);
	min = Min(min, n);
	for (int i = 0; i < min; i++)
	{
		if (s1[i] > s2[i])
			return 1;
		else if (s2[i] > s1[i])
			return -1;
	}
	if (min <= n1 && min <= n2)
		return 0;
	if (min < n1)
		return 1;
	if (min < n2)
		return -1;
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
	if (pos < nSrc)
	{
		if (pos + len > nSrc)
			len = nSrc - pos;
		m_strncpy(dest, src + pos, len);
	}
	else
		m_strcpy(dest, "");
}

MyString operator+(const MyString & lhs, const MyString & rhs)
{
	MyString result;
	result.m_size = lhs.m_size + rhs.m_size;
	result.m_reserved_size = result.m_size + _DEFAULT_SIZE;
	result.m_str = new char[result.m_reserved_size + 1];
	m_strcpy(result.m_str, lhs.m_str);
	m_strcpy(result.m_str + lhs.m_size, rhs.m_str);
	return result;
}

MyString operator+(const char * lhs, const MyString & rhs)
{
	return MyString();
}

MyString operator+(const MyString & lhs, char rhs)
{
	return MyString();
}

MyString operator+(char lhs, const MyString & rhs)
{
	return MyString();
}

//Member functions
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
		m_strcpy(this->m_str, str.m_str + pos);
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

MyString::~MyString()
{
	delete[] this->m_str;
	this->m_str = NULL;
	this->m_size = 0;
	this->m_reserved_size = 0;
}

MyString & MyString::operator=(const MyString & str)
{
	if(this->m_str)
		delete[] this->m_str;
	this->m_size = str.m_size;
	this->m_reserved_size = str.m_reserved_size;
	this->m_str = new char[this->m_reserved_size + 1];
	m_strcpy(this->m_str, str.m_str);
	return *this;
}

MyString & MyString::operator=(const char* s)
{
	if (this->m_str)
		delete[] this->m_str;
	this->m_size = m_strlen(s);
	this->m_reserved_size = this->m_size + _DEFAULT_SIZE;
	this->m_str = new char[this->m_reserved_size + 1];
	m_strcpy(this->m_str, s);
	return *this;
}

MyString & MyString::operator=(char c)
{
	if (this->m_str)
		delete[] this->m_str;
	this->m_size = 1;
	this->m_reserved_size = 1 + _DEFAULT_SIZE;
	this->m_str = new char[this->m_reserved_size + 1];
	this->m_str[0] = c;
	this->m_str[1] = '\0';
	return *this;
}

//Iterators
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

//Capacity:
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
	return pow(2, 8*sizeof(size_t)-1) - 1;
}

void MyString::resize(size_t n)
{
	if (n > this->m_size)
	{
		if (n > this->m_reserved_size)
		{
			this->m_reserved_size = n + _DEFAULT_SIZE;
			this->m_str = (char*)realloc(this->m_str, (this->m_reserved_size + 1) * sizeof(char));
		}
		MyString temp(n-this->m_size, ' ');
		m_strcpy(this->m_str + this->m_size, temp.m_str);
		this->m_size = n;
	}
	else
	{
		this->m_size = n;
		m_strncpy(this->m_str, this->m_str, n);
	}
}

void MyString::resize(size_t n, char c)
{
	if (n > this->m_size)
	{
		if (n > this->m_reserved_size)
		{
			this->m_reserved_size = n + _DEFAULT_SIZE;
			this->m_str = (char*)realloc(this->m_str, (this->m_reserved_size + 1) * sizeof(char));
		}
		MyString temp(n - this->m_size, c);
		m_strcpy(this->m_str + this->m_size, temp.m_str);
		this->m_size = n;
	}
	else
	{
		this->m_size = n;
		m_strncpy(this->m_str, this->m_str, n);
	}
}

size_t MyString::capacity() const
{
	return this->m_reserved_size;
}

void MyString::clear()
{
	delete[] this->m_str;
	this->m_str = NULL;
	this->m_size = 0;
	this->m_reserved_size = 0;
}

bool MyString::empty() const
{
	return this->m_size == 0;
}

void MyString::shrink_to_fit()
{
	this->m_str = (char*)realloc(this->m_str, (this->m_size + 1) * sizeof(char));
	this->m_reserved_size = this->m_size;
}

//Element access:
char & MyString::operator[](size_t pos)
{
	return this->m_str[pos];
}

const char & MyString::operator[](size_t pos) const
{
	return this->m_str[pos];
}

char & MyString::at(size_t pos)
{
	return this->m_str[pos];
}

const char & MyString::at(size_t pos) const
{
	return this->m_str[pos];
}

char & MyString::back()
{
	return this->m_str[this->m_size-1];
}

const char & MyString::back() const
{
	return this->m_str[this->m_size - 1];
}

char & MyString::front()
{
	return this->m_str[0];
}

const char & MyString::front() const
{
	return this->m_str[0];
}

//Modifiers
MyString & MyString::operator+=(const MyString & str)
{
	int n = this->m_size;
	this->m_size += str.m_size;
	if (this->m_size > this->m_reserved_size)
	{
		this->m_reserved_size = this->m_size + _DEFAULT_SIZE;
		this->m_str = (char*)realloc(this->m_str, (this->m_reserved_size + 1)*(sizeof(char)));
	}
	m_strcpy(this->m_str + n, str.m_str);
	return *this;
}

MyString & MyString::operator+=(const char * s)
{
	int n = this->m_size;
	this->m_size += m_strlen(s);
	if (this->m_size > this->m_reserved_size)
	{
		this->m_reserved_size = this->m_size + _DEFAULT_SIZE;
		this->m_str = (char*)realloc(this->m_str, (this->m_reserved_size + 1)*(sizeof(char)));
	}
	m_strcpy(this->m_str + n, s);
	return *this;
}

MyString & MyString::operator+=(char c)
{
	int n = this->m_size;
	this->m_size++;
	if (this->m_size > this->m_reserved_size)
	{
		this->m_reserved_size = this->m_size + _DEFAULT_SIZE;
		this->m_str = (char*)realloc(this->m_str, (this->m_reserved_size + 1)*(sizeof(char)));
	}
	this->m_str[n] = c;
	this->m_str[this->m_size] = '\0';
	return *this;
}

MyString & MyString::append(const MyString & str)
{
	*this += str;
	return *this;
}

MyString & MyString::append(const MyString & str, size_t subpos, size_t sublen)
{
	int n = this->m_size;
	this->m_size += sublen;
	if (this->m_size > this->m_reserved_size)
	{
		this->m_reserved_size = this->m_size + _DEFAULT_SIZE;
		this->m_str = (char*)realloc(this->m_str, (this->m_reserved_size + 1)*(sizeof(char)));
	}
	m_strncpy(this->m_str + n, str.m_str, subpos, sublen);
	return *this;
}

MyString & MyString::append(const char * s)
{
	*this += s;
	return *this;
}

MyString & MyString::append(const char * s, size_t n)
{
	char *temp = new char[n + 1];
	m_strncpy(temp, s, n);
	*this += temp;
	delete[] temp;
	return *this;
}

MyString & MyString::append(size_t n, char c)
{
	MyString temp(n, c);
	*this += temp;
	return *this;
}

void MyString::push_back(char c)
{
	*this += c;
}

MyString & MyString::assign(const MyString & str)
{
	*this = str;
	return *this;
}

MyString & MyString::assign(const MyString & str, size_t subpos, size_t sublen)
{
	MyString temp(str, subpos, sublen);
	*this = temp;
	return *this;
}

MyString & MyString::assign(const char * s)
{
	*this = s;
	return *this;
}

MyString & MyString::assign(const char * s, size_t n)
{
	MyString temp(s, n);
	*this = temp;
	return *this;
}

MyString & MyString::assign(size_t n, char c)
{
	MyString temp(n,c);
	*this = temp;
	return *this;
}

MyString & MyString::insert(size_t pos, const MyString & str)
{
	if (pos > this->m_size)
		pos = this->m_size;
	if (pos < this->m_size)
	{
		if (this->m_size + str.m_size > this->m_reserved_size)
		{
			this->m_reserved_size = this->m_size + str.m_size + _DEFAULT_SIZE;
			this->m_str = (char*)realloc(this->m_str, (this->m_reserved_size + 1) * sizeof(char));
		}
		char *temp = new char[this->m_size - pos + 1];
		m_strncpy(temp, this->m_str + pos, this->m_size - pos);
		m_strcpy(this->m_str + pos, str.m_str);
		m_strcpy(this->m_str + pos + str.m_size, temp);
		this->m_size += str.m_size;
		delete[] temp;
	}
	else
		m_strcpy(this->m_str + pos, str.m_str);
	return *this;
}

MyString & MyString::insert(size_t pos, const MyString & str, size_t subpos, size_t sublen)
{
	MyString temp(str, subpos, sublen);
	this->insert(pos, temp);
	return *this;
}

MyString & MyString::insert(size_t pos, const char * s)
{
	MyString temp(s);
	this->insert(pos, temp);
	return *this;
}

MyString & MyString::insert(size_t pos, const char * s, size_t n)
{
	MyString temp(s, n);
	this->insert(pos, temp);
	return *this;
}

MyString & MyString::insert(size_t pos, size_t n, char c)
{
	MyString temp(n,c);
	this->insert(pos, temp);
	return *this;
}

MyString & MyString::erase(size_t pos, size_t len)
{
	if (len == npos)
	{
		len = this->m_size - pos;
	}
	m_strcpy(this->m_str + pos, this->m_str + pos + len);
	this->m_size = this->m_size - len;
	return *this;
}

MyString & MyString::replace(size_t pos, size_t len, const MyString & str)
{
	this->erase(pos, len);
	this->insert(pos, str);
	return *this;
}

MyString & MyString::replace(size_t pos, size_t len, const MyString & str, size_t subpos, size_t sublen)
{
	MyString temp(str, subpos, sublen);
	this->replace(pos, len, temp);
	return *this;
}

MyString & MyString::replace(size_t pos, size_t len, const char * s)
{
	MyString temp(s);
	this->replace(pos, len, temp);
	return *this;
}

MyString & MyString::replace(size_t pos, size_t len, const char * s, size_t n)
{
	MyString temp(s, n);
	this->replace(pos, len, temp);
	return *this;
}

MyString & MyString::replace(size_t pos, size_t len, size_t n, char c)
{
	MyString temp(n, c);
	this->replace(pos, len, temp);
	return *this;
}

void MyString::swap(MyString & str)
{
	MyString temp = str;
	str = *this;
	*this = temp;
}

void MyString::pop_back()
{
	m_strncpy(this->m_str, this->m_str, this->m_size - 1);
}

//String operations:
const char * MyString::c_str() const
{
	return this->m_str;
}

const char * MyString::data() const
{
	return this->m_str;
}

size_t MyString::copy(char * s, size_t len, size_t pos) const
{
	m_strncpy(s, this->m_str, pos, len);
	return this->m_size;
}

size_t MyString::find(const MyString & str, size_t pos) const
{
	const char *p = this->m_str + pos;
	size_t len = m_strlen(p);
	while (*p != NULL)
	{
		if (len >= str.m_size)
		{
			if (m_strncmp(p, str.m_str,str.m_size) == 0)
				return this->m_size - len;
		}
		p++;
		len--;
	}
	return -1;
}

size_t MyString::find(const char * s, size_t pos) const
{
	MyString temp(s);
	return this->find(temp, pos);
}

size_t MyString::find(const char * s, size_t pos, size_t n) const
{
	MyString temp(s, n);
	return this->find(temp, pos);
}

size_t MyString::find(char c, size_t pos) const
{
	MyString temp(1, c);
	return this->find(temp, pos);
}

size_t MyString::rfind(const MyString & str, size_t pos) const
{
	size_t end = pos + 1;
	if (pos == npos)
		end = this->m_size;
	const char *p = this->m_str;
	size_t len = m_strlen(p);
	size_t flag = -1;
	int i = 0;
	while (i< end)
	{
		if (len >= str.m_size)
		{
			if (m_strncmp(p, str.m_str, str.m_size) == 0)
				flag = this->m_size - len;
		}
		p++;
		len--;
		i++;
	}
	return flag;
}

size_t MyString::rfind(const char * s, size_t pos) const
{
	MyString temp(s);
	return this->rfind(temp, pos);
}

size_t MyString::rfind(const char * s, size_t pos, size_t n) const
{
	MyString temp(s, n);
	return this->rfind(temp, pos);
}

size_t MyString::rfind(char c, size_t pos) const
{
	MyString temp(1,c);
	return this->rfind(temp, pos);
}

size_t MyString::find_first_of(const MyString & str, size_t pos) const
{
	for (int i = pos; i < this->m_size; i++)
	{
		for (int j = 0; j < str.m_size; j++)
		{
			if (this->m_str[i] == str.m_str[j])
				return i;
		}
	}
	return npos;
}

size_t MyString::find_first_of(const char * s, size_t pos) const
{
	MyString temp(s);
	return this->find_first_of(temp, pos);
}

size_t MyString::find_first_of(const char * s, size_t pos, size_t n) const
{
	MyString temp(s,n);
	return this->find_first_of(temp, pos);
}

size_t MyString::find_first_of(char c, size_t pos) const
{
	MyString temp(1,c);
	return this->find_first_of(temp, pos);
}

size_t MyString::find_last_of(const MyString & str, size_t pos) const
{
	if (pos == npos)
		pos = this->m_size;
	for (int i = pos; i >= 0; i--)
	{
		for (int j = 0; j < str.m_size; j++)
		{
			if (this->m_str[i] == str.m_str[j])
				return i;
		}
	}
	return npos;
}

size_t MyString::find_last_of(const char * s, size_t pos) const
{
	MyString temp(s);
	return this->find_last_of(temp, pos);
}

size_t MyString::find_last_of(const char * s, size_t pos, size_t n) const
{
	MyString temp(s,n);
	return this->find_last_of(temp, pos);
}

size_t MyString::find_last_of(char c, size_t pos) const
{
	MyString temp(1, c);
	return this->find_last_of(temp, pos);
}

size_t MyString::find_first_not_of(const MyString & str, size_t pos) const
{
	for (int i = pos; i < this->m_size; i++)
	{
		for (int j = 0; j < str.m_size; j++)
		{
			if (this->m_str[i] == str.m_str[j])
				break;
			if (j == str.m_size - 1)
				return i;
		}
	}
	return npos;
}

size_t MyString::find_first_not_of(const char * s, size_t pos) const
{
	MyString temp(s);
	return this->find_first_not_of(temp, pos);
}

size_t MyString::find_first_not_of(const char * s, size_t pos, size_t n) const
{
	MyString temp(s,n);
	return this->find_first_not_of(temp, pos);
}

size_t MyString::find_first_not_of(char c, size_t pos) const
{
	MyString temp(1, c);
	return this->find_first_not_of(temp, pos);
}

size_t MyString::find_last_not_of(const MyString & str, size_t pos) const
{
	return size_t();
}

size_t MyString::find_last_not_of(const char * s, size_t pos) const
{
	return size_t();
}

size_t MyString::find_last_not_of(const char * s, size_t pos, size_t n) const
{
	return size_t();
}

size_t MyString::find_last_not_of(char c, size_t pos) const
{
	return size_t();
}

MyString MyString::substr(size_t pos, size_t len) const
{
	MyString temp(*this, pos, len);
	return temp;
}

int MyString::compare(const MyString & str) const
{
	return m_strcmp(this->m_str, str.m_str);
}

int MyString::compare(size_t pos, size_t len, const MyString & str) const
{
	MyString temp(*this, pos, len);
	return temp.compare(str);
}

int MyString::compare(size_t pos, size_t len, const MyString & str, size_t subpos, size_t sublen) const
{
	MyString temp1(*this, pos, len);
	MyString temp2(str, subpos, sublen);
	return temp1.compare(temp2);
}

int MyString::compare(const char * s) const
{
	return m_strcmp(this->m_str, s);
}

int MyString::compare(size_t pos, size_t len, const char * s) const
{
	MyString temp(*this, pos, len);
	return m_strcmp(temp.m_str, s);
}

int MyString::compare(size_t pos, size_t len, const char * s, size_t n) const
{
	MyString temp1(*this, pos, len);
	MyString temp2(s, n);
	return temp1.compare(temp2);
}

