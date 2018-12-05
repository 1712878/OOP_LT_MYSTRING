#include "myString.h"
#include <string>
void TestContructor()
{
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
int main()
{
	TestContructor();
	system("pause");
	return 0;
}