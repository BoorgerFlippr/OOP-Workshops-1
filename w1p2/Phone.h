//Glenn Parrreno
//geparreno@myseneca.ca
//115814196
//23-01-22

#ifndef sdds_PHONE_H
#define sdds_PHONE_H

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

namespace sdds
{
	const int MAX_NAME_LEN = 50;
	const int MAX_CONTACTS = 36;
	struct pInfo
	{
		char name[50];
		char area[4];
		char prefix[4];
		char number[5];
	};

	void phoneDir(const char*, const char*);
	void searchName( char*, const char*);
}

#endif // !sdds_PHONE_H

