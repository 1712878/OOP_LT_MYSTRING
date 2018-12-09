#include "Test.h"

void MemberFunctions()
{
	std::cout << "\n\n---MemberFunctions---\n";

	cout << "\t1. constructor\n";
	//http://www.cplusplus.com/reference/string/string/string/
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

	std::cout << "\t2. destuctor\n";

	std::cout << "\t3. operator\n";
	//http://www.cplusplus.com/reference/string/string/operator=/
	MyString str1, str2, str3;
	str1 = "Test string: ";   // c-string
	str2 = 'x';               // single character
	str3 = str1 + str2;       // string
	std::cout << str3 << '\n';
}

void Iterators()
{
	std::cout << "\n\n---Iterators---\n";
	MyString str("Test string");
	std::cout << "str = " << str << '\n';

	std::cout << "1. iterator it: begin -> end\n";
	for (MyString::iterator it = str.begin(); it != str.end(); ++it)
		std::cout << *it;
	std::cout << '\n';
}

void Capacity()
{
	std::cout << "\n\n---Iterators---\n";
	MyString str("Nguyen Tho Tuan");

	std::cout << "str = " << str << '\n';
	std::cout << "1. str.size()    : " << str.size() << "\n";
	std::cout << "2. str.length()  : " << str.length() << "\n";
	str.resize(str.size() + 2, '+');
	std::cout << "3. str.resize(str.size()+2,'+'): " << str << "\n";
	str.resize(str.size() - 2);
	std::cout << "4. str.resize(str.size()-2,'+'): " << str << "\n";
	std::cout << "5. str.max_size(): " << str.max_size() << "\n";
	std::cout << "6. str.capacity(): " << str.capacity() << "\n";
	std::cout << "7. str.capacity(): " << str.capacity() << "\n";
	std::cout << "8. str.empty(): " << str.empty() << "\n";
	str.clear();
	std::cout << "9. str.empty() after s.clear(): " << str.empty() << "\n";
	str = "Nguyen Tho Tuan";
	std::cout << "str = " << str << '\n';
	str.resize(10);
	std::cout << "10. str.capacity() after str.resize(10): " << str.capacity() << '\n';
	str.shrink_to_fit();
	std::cout << "11. str.capacity() after str.shrink_to_fit(): " << str.capacity() << '\n';
}

void ElementAccess()
{
	std::cout << "\n\n---ElementAccess---\n";
	MyString str("test string.");

	std::cout << "\t1. operator[]\n";
	for (int i = 0; i < str.length(); ++i)
	{
		std::cout << str[i];
	}

	std::cout << "\n\t2. at\n";
	for (unsigned i = 0; i < str.length(); ++i)
	{
		std::cout << str.at(i);
	}

	std::cout << "\n\t3. back\n";
	str.back() = '!';
	std::cout << str << '\n';

	std::cout << "\t4. back\n";
	str.front() = 'T';
	std::cout << str << '\n';
}

void Modifiers()
{
	std::cout << "\n\n---Modifiers---\n";

	std::cout << "1. operator+=\n";
	MyString name("John");
	MyString family("Smith");
	name += " K. ";         // c-string
	name += family;         // string
	name += '\n';           // character
	std::cout << name;

	MyString str = "Start ";
	MyString str2 = "Writing ";
	MyString str3 = "print 10 and then 5 more";

	std::cout << "2. operator+=\n";
	// used in the same order as described above:
	str.append(str2);                       // "Writing "
	str.append(str3, 6, 3);                   // "10 "
	str.append("dots are cool", 5);          // "dots "
	str.append("here: ");                   // "here: "
	str.append(10u, '.');                    // ".........."
	std::cout << str << '\n';

	std::cout << "3. push_back\n";
	MyString s = "nguyen tho tua";
	s.push_back('n');
	cout << s << endl;
}
