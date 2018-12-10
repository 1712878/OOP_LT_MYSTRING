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
	{
		MyString name("John");
		MyString family("Smith");
		name += " K. ";         // c-string
		name += family;         // string
		name += '\n';           // character
		std::cout << name;
	}
	std::cout << "2. append\n";
	{
		MyString str = "Start ";
		MyString str2 = "Writing ";
		MyString str3 = "print 10 and then 5 more";
		// used in the same order as described above:
		str.append(str2);                       // "Writing "
		str.append(str3, 6, 3);                   // "10 "
		str.append("dots are cool", 5);          // "dots "
		str.append("here: ");                   // "here: "
		str.append(10u, '.');                    // ".........."
		std::cout << str << '\n';
	}

	std::cout << "3. push_back\n";
	{
		MyString s = "nguyen tho tua";
		s.push_back('n');
		cout << s << endl;
	}

	std::cout << "4. assign\n";
	{
		MyString str;
		MyString base = "The quick brown fox jumps over a lazy dog.";
		// used in the same order as described above:
		str.assign(base);
		std::cout << str << '\n';
		str.assign(base, 10, 9);
		std::cout << str << '\n';         // "brown fox"
		str.assign("pangrams are cool", 7);
		std::cout << str << '\n';         // "pangram"
		str.assign("c-string");
		std::cout << str << '\n';         // "c-string"
		str.assign(10, '*');
		std::cout << str << '\n';         // "**********"
		//str.assign<int>(10, 0x2D);
		//std::cout << str << '\n';         // "----------"
		//str.assign(base.begin() + 16, base.end() - 12);
		//std::cout << str << '\n';         // "fox jumps over"
	}

	std::cout << "5. Insert\n";
	{
		MyString str = "to be question";
		MyString str2 = "the ";
		MyString str3 = "or not to be";
		//std::string::iterator it;
		// used in the same order as described above:
		str.insert(6, str2);                 // to be (the )question
		str.insert(6, str3, 3, 4);             // to be (not )the question
		str.insert(10, "that is cool", 8);    // to be not (that is )the question
		str.insert(10, "to be ");            // to be not (to be )that is the question
		str.insert(15, 1, ':');               // to be not to be(:) that is the question
		//it = str.insert(str.begin() + 5, ','); // to be(,) not to be: that is the question
		//str.insert(str.end(), 3, '.');       // to be, not to be: that is the question(...)
		//str.insert(it + 2, str3.begin(), str3.begin() + 3); // (or )
		std::cout << str << '\n';
	}

	std::cout << "\n6. Erase\n";
	{
		MyString str = "This is an example sentence.";
		std::cout << str << '\n';
		// "This is an example sentence."
		str.erase(10, 8);                        //            ^^^^^^^^
		std::cout << str << '\n';
		// "This is an sentence."
		//str.erase(str.begin() + 9);               //           ^
		//std::cout << str << '\n';
		// "This is a sentence."
		//str.erase(str.begin() + 5, str.end() - 9);  //       ^^^^^
		//std::cout << str << '\n';
		// "This sentence."
	}

	std::cout << "\n7. Replace\n";
	{
		MyString base = "this is a test string.";
		MyString str2 = "n example";
		MyString str3 = "sample phrase";
		MyString str4 = "useful.";
		// replace signatures used in the same order as described above:
		// Using positions:                 0123456789*123456789*12345
		MyString str = base;           // "this is a test string."
		str.replace(9, 5, str2);          // "this is an example string." (1)
		str.replace(19, 6, str3, 7, 6);     // "this is an example phrase." (2)
		str.replace(8, 10, "just a");     // "this is just a phrase."     (3)
		str.replace(8, 6, "a shorty", 7);  // "this is a short phrase."    (4)
		str.replace(22, 1, 3, '!');        // "this is a short phrase!!!"  (5)
		// Using iterators:                                               0123456789*123456789*
		//str.replace(str.begin(), str.end() - 3, str3);                    // "sample phrase!!!"      (1)
		//str.replace(str.begin(), str.begin() + 6, "replace");             // "replace phrase!!!"     (3)
		//str.replace(str.begin() + 8, str.begin() + 14, "is coolness", 7);    // "replace is cool!!!"    (4)
		//str.replace(str.begin() + 12, str.end() - 4, 4, 'o');                // "replace is cooool!!!"  (5)
		//str.replace(str.begin() + 11, str.end(), str4.begin(), str4.end());// "replace is useful."    (6)
		std::cout << str << '\n';
	}
	
	std::cout << "\n8.Swap \n";
	{
		MyString buyer("money");
		MyString seller("goods");
		std::cout << "Before the swap, buyer has " << buyer;
		std::cout << " and seller has " << seller << '\n';
		seller.swap(buyer);
		std::cout << " After the swap, buyer has " << buyer;
		std::cout << " and seller has " << seller << '\n';
	}

	std::cout << "\n9.Pop_back \n";
	{
		MyString str = "hello world!";
		str.pop_back();
		std::cout << str << '\n';
	}
}

void StringOperations()
{
	std::cout << "\n\n---StringOperations---\n";

	std::cout << "\n1. c_ctr \n";
	{
		MyString str = "Please split this sentence into tokens";
		char * cstr = new char[str.length() + 1];
		std::strcpy(cstr, str.c_str());
		// cstr now contains a c-string copy of str
		char * p = std::strtok(cstr, " ");
		while (p != 0)
		{
			std::cout << p << '\n';
			p = std::strtok(NULL, " ");
		}
		delete[] cstr;
	}

	std::cout << "\n2. data() \n";
	{
		int length;
		MyString str = "Test string";
		char cstr1[] = "Test string";
		if (str.length() == std::strlen(cstr1))
		{
			std::cout << "str and cstr have the same length.\n";

			if (memcmp(cstr1, str.data(), str.length()) == 0)
				std::cout << "str and cstr have the same content.\n";
		}
	}

	std::cout << "\n3. copy() \n";
	{
		char buffer[20];
		MyString str = "Test string...";;
		std::size_t length = str.copy(buffer, 6, 5);
		buffer[length] = '\0';
		std::cout << "buffer contains: " << buffer << '\n';
	}

	std::cout << "\n4. find() \n";
	{
		MyString str("There are two needles in this haystack with needles.");
		MyString str2("needle");
		// different member versions of find in the same order as above:
		std::size_t found = str.find(str2);
		if (found != npos)
			std::cout << "first 'needle' found at: " << found << '\n';

		found = str.find("needles are small", found + 1, 6);
		if (found != npos)
			std::cout << "second 'needle' found at: " << found << '\n';

		found = str.find("haystack");
		if (found != npos)
			std::cout << "'haystack' also found at: " << found << '\n';

		found = str.find('.');
		if (found != npos)
			std::cout << "Period found at: " << found << '\n';

		// let's replace the first needle:
		str.replace(str.find(str2), str2.length(), "preposition");
		std::cout << str << '\n';
	}
	
	std::cout << "\n5. rfind() \n";
	{
		MyString str("The sixth sick sheik's sixth sheep's sick.");
		MyString key("sixth");
		std::size_t found = str.rfind(key);
		if (found != std::string::npos)
			str.replace(found, key.length(), "seventh");
		std::cout << str << '\n';
	}

	std::cout << "\n6. find_first_of() \n";
	{
		MyString str("Please, replace the vowels in this sentence by asterisks.");
		std::size_t found = str.find_first_of("aeiou");
		while (found != npos)
		{
			str[found] = '*';
			found = str.find_first_of("aeiou", found + 1);
		}
		std::cout << str << '\n';
	}

	std::cout << "\n6. find_first_of() \n";
	{

	}
}

