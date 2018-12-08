#include "myString.h"
#include <string>
void TestContructor()
{
	cout << "\nTestContructor" << endl;
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
void TestOperatorEqual ()
{
	cout << "\nTestOperatorEqual" << endl;
	MyString str1, str2, str3;
	str1 = "Test string: ";   // c-string
	str2 = 'x';               // single character
	str3 = str1 + str2;       // string
	std::cout << str3 << '\n';
}
void TestBeginEnd()
{
	cout << "\nTestBeginEnd" << endl;
	MyString str("Test string");
	for (MyString::iterator it = str.begin(); it != str.end(); ++it)
		std::cout << *it;
	std::cout << '\n';
}

int main()
{
	/*TestContructor();
	TestOperatorEqual();
	TestBeginEnd();*/
	/*fstream fp;
	fp.open("a.txt", ios::in);
	if (!fp.fail())
	{
		MyString kq;
		fp >> kq;
		cout << kq;
	}*/
	MyString s;
	cin >> s;
	cout << s << endl;
	cout << sizeof(s);

	system("pause");
	return 0;
}