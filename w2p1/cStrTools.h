//Glenn Parrreno
//geparreno@myseneca.ca
//115814196
//23-01-27

#ifndef sdds_CSTRTOOLS_H
#define sdds_CSTRTOOLS_H
#include <iostream>

namespace sdds
{
	char toLower(char);
	int strCmp(const char*, const char*);
	int strnCmp(const char*, const char*, int);
	const char* strStr(const char*, const char*);
	void strCpy(char*, const char*);
	int strLen(const char*);
	int isAlpha(char);
	int isSpace(char);
	void trim(char[]);
	void toLowerCaseAndCopy(char[], const char[]);
	void read(char*, unsigned int, char = '\n');
}

#endif // !sdds_CSTRTOOLS_H
