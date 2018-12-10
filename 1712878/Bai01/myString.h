#ifndef __MY_STRING_H__
#define __MY_STRING_H__

#include <iostream>
#include <fstream>
using namespace std;

int m_strlen(const char *s);
int m_strcmp(const char *s1, const char* s2);
int m_strncmp(const char *s1, const char* s2, int n);
void m_strcpy(char* dest, const char* src);
void m_strncpy(char* dest, const char* src, int n);
void m_strncpy(char* dest, const char* src, int pos, int len);
const int _DEFAULT_SIZE = 32;
const size_t _MAX_LENGTH = 1024;
static const size_t npos = -1;
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
	MyString(const MyString& str, size_t pos, size_t len = npos);
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


	//Modifiers
	MyString& operator+= (const MyString& str);
	MyString& operator+= (const char* s);
	MyString& operator+= (char c);

	MyString& append(const MyString& str);
	MyString& append(const MyString& str, size_t subpos, size_t sublen);
	MyString& append(const char* s);
	MyString& append(const char* s, size_t n);
	MyString& append(size_t n, char c);
	//template <class InputIterator>
	//MyString& append(InputIterator first, InputIterator last);
	//MyString& append(initializer_list<char> il);

	void push_back(char c);

	MyString& assign(const MyString& str);
	MyString& assign(const MyString& str, size_t subpos, size_t sublen);
	MyString& assign(const char* s);
	MyString& assign(const char* s, size_t n);
	MyString& assign(size_t n, char c);
	//template <class InputIterator>
	//MyString& assign(InputIterator first, InputIterator last);
	//MyString& assign(initializer_list<char> il);
	//MyString& assign(MyString&& str) noexcept;

	MyString& insert(size_t pos, const MyString& str);
	MyString& insert(size_t pos, const MyString& str, size_t subpos, size_t sublen = npos);
	MyString& insert(size_t pos, const char* s);
	MyString& insert(size_t pos, const char* s, size_t n);
	MyString& insert(size_t pos, size_t n, char c);
	//iterator insert(const_iterator p, size_t n, char c);
	//iterator insert(const_iterator p, char c);
	//template <class InputIterator>
	//iterator insert(iterator p, InputIterator first, InputIterator last);
	//MyString& insert(const_iterator p, initializer_list<char> il);

	MyString& erase(size_t pos = 0, size_t len = npos);
	//iterator erase(const_iterator p);
	//iterator erase(const_iterator first, const_iterator last);

	MyString& replace(size_t pos, size_t len, const MyString& str);
	//MyString& replace(const_iterator i1, const_iterator i2, const MyString& str);
	MyString& replace(size_t pos, size_t len, const MyString& str,size_t subpos, size_t sublen);
	MyString& replace(size_t pos, size_t len, const char* s);
	//MyString& replace(const_iterator i1, const_iterator i2, const char* s);
	MyString& replace(size_t pos, size_t len, const char* s, size_t n);
	//MyString& replace(const_iterator i1, const_iterator i2, const char* s, size_t n);
	MyString& replace(size_t pos, size_t len, size_t n, char c);
	//MyString& replace(const_iterator i1, const_iterator i2, size_t n, char c);
	//template <class InputIterator>
	//MyString& replace(const_iterator i1, const_iterator i2, InputIterator first, InputIterator last);
	//MyString& replace(const_iterator i1, const_iterator i2, initializer_list<char> il);

	void swap(MyString& str);

	void pop_back();


	//String operations:
	const char* c_str() const;

	const char* data() const;

	//allocator_type get_allocator() const;

	size_t copy(char* s, size_t len, size_t pos = 0) const;

	size_t find(const MyString& str, size_t pos = 0) const;
	size_t find(const char* s, size_t pos = 0) const;
	size_t find(const char* s, size_t pos, size_t n) const;
	size_t find(char c, size_t pos = 0) const;

	size_t rfind(const MyString& str, size_t pos = npos) const;
	size_t rfind(const char* s, size_t pos = npos) const;
	size_t rfind(const char* s, size_t pos, size_t n) const;
	size_t rfind(char c, size_t pos = npos) const;

	size_t find_first_of(const MyString& str, size_t pos = 0) const;
	size_t find_first_of(const char* s, size_t pos = 0) const;
	size_t find_first_of(const char* s, size_t pos, size_t n) const;
	size_t find_first_of(char c, size_t pos = 0) const;

	size_t find_last_of(const MyString& str, size_t pos = npos) const;
	size_t find_last_of(const char* s, size_t pos = npos) const;
	size_t find_last_of(const char* s, size_t pos, size_t n) const;
	size_t find_last_of(char c, size_t pos = npos) const;

	size_t find_first_not_of(const MyString& str, size_t pos = 0) const;
	size_t find_first_not_of(const char* s, size_t pos = 0) const;
	size_t find_first_not_of(const char* s, size_t pos, size_t n) const;
	size_t find_first_not_of(char c, size_t pos = 0) const;

	size_t find_last_not_of(const MyString& str, size_t pos = npos) const;
	size_t find_last_not_of(const char* s, size_t pos = npos) const;
	size_t find_last_not_of(const char* s, size_t pos, size_t n) const;
	size_t find_last_not_of(char c, size_t pos = npos) const;

	MyString substr(size_t pos = 0, size_t len = npos) const;

	int compare(const MyString& str) const;
	int compare(size_t pos, size_t len, const MyString& str) const;
	int compare(size_t pos, size_t len, const MyString& str, size_t subpos, size_t sublen) const;
	int compare(const char* s) const;
	int compare(size_t pos, size_t len, const char* s) const;
	int compare(size_t pos, size_t len, const char* s, size_t n) const;

	//Non-member function overloads
	friend MyString operator+ (const MyString& lhs, const MyString& rhs);
	friend MyString operator+ (const char*   lhs, const MyString& rhs);
	friend MyString operator+ (const MyString& lhs, char          rhs);
	friend MyString operator+ (char         lhs, const MyString& rhs);
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
