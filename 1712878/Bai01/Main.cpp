#include "myString.h"
#include "Test.h"
#include <string>

int main()
{
	//MemberFunctions();
	//Iterators();
	//Capacity();
	//ElementAccess();
	//Modifiers();
	//StringOperations();
	
	MyString str("look for non-alphabetic characters...");

	std::size_t found = str.find_first_not_of("abcdefghijklmnopqrstuvwxyz ");

	if (found != npos)
	{
		std::cout << "The first non-alphabetic character is " << str[found];
		std::cout << " at position " << found << '\n';
	}

	system("pause");
	return 0;
}