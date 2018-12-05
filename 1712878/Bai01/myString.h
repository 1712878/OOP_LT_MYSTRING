#ifndef __MY_STRING_H__
#define __MY_STRING_H__

#include <iostream>
int mstrlen(char *s);
int mstrcmp(char *s1, char* s2);
char* mstrcpy(char* dest, char* src);

class myString
{
private:
	char *mstr;
	int msize;
	int mresize;
public:

};

#endif

