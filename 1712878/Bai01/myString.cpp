#include "myString.h"
int mstrlen(char *s)
{
	int i = 0;
	while (s[i] != '\0')
		i++;
	return i;
}
int mstrcmp(char *s1, char* s2)
{
	// 1 if s1>s2, -1 if s1<s2, 0 if s1=s2
	int n1 = mstrlen(s1), n2 = mstrlen(s2);
	int n = (n1 > n2)*n2 + (n2 >= n1)*n1;
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
char* mstrcpy(char* dest, char* src)
{
	int nSrc = mstrlen(src);
	if (&dest != &src)
	{
		for (int i = 0; i < nSrc; i++)
			dest[i] = src[i];
		dest[nSrc] = '\0';
	}
	return dest;
}