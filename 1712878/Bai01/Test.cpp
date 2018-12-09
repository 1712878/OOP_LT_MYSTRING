#include "Test.h"

void Contructor()
{
	cout << "\nCONTRUCTOR" << endl;
	MyString s0("Initial string");
	// constructors used in the same order as described above:
	MyString s1;
	MyString s2(s0);
	MyString s3(s0, 8, 3);
	MyString s4("A character sequence");
	MyString s5("Another character sequence", 12);
	MyString s6a(10, 'x');
	MyString s6b(10, 42);      // 42 is the ASCII code for '*'
	//MyString s7(s0.begin(), s0.begin() + 7);
	std::cout << "s1: " << s1 << "\ns2: " << s2 << "\ns3: " << s3;
	std::cout << "\ns4: " << s4 << "\ns5: " << s5 << "\ns6a: " << s6a;
	std::cout << "\ns6b: " << s6b << "\ns7: " << /*s7 <<*/ '\n';
}

void OperatorEqual()
{
	cout << "\nOPERATOREQUAL" << endl;
	MyString str1, str2, str3;
	str1 = "Test string: ";   // c-string
	str2 = 'x';               // single character
	str3 = str1 + str2;       // string
	std::cout << str3 << '\n';
}

void BeginEnd()
{
	cout << "\nBEGINEND" << endl;
	MyString str("Test string");
	for (MyString::iterator it = str.begin(); it != str.end(); ++it)
		std::cout << *it;
	std::cout << '\n';
}

void SizeLengthCapacityMax_size()
{
	cout << "\nSIZELENGTHCAPACITYMAXSIZE" << endl;
	MyString str("Test string");
	std::cout << "size: " << str.size() << "\n";
	std::cout << "length: " << str.length() << "\n";
	std::cout << "capacity: " << str.capacity() << "\n";
	std::cout << "max_size: " << str.max_size() << "\n";
}

void Resize()
{
	cout << "\nRESIZE" << endl;
	MyString str("I like to code in C");
	std::cout << str << '\n';
	unsigned sz = str.size();
	str.resize(sz + 2, '+');
	std::cout << str << '\n';
	str.resize(14);
	std::cout << str << '\n';
}
