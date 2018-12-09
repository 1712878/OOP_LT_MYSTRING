#include "myString.h"
#include "Test.h"
#include <string>

int main()
{
	//Contructor();
	//OperatorEqual();
	//BeginEnd();
	//SizeLengthCapacityMax_size();
	//Resize();
	//ClearEmty();
	//ShrinkToFit();

	string s = "nguyen tho tuan";
	int size = s.size();
	s.resize(size + 2);
	s[size + 1] = 'a';
	cout << s;
	cout << s.at(100);
	system("pause");
	return 0;
}