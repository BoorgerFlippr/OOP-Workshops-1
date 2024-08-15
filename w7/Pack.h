/*
Glenn Parrreno
geparreno@myseneca.ca
115814196
17-03-22
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#ifndef SDDS_PACK_H
#define SDDS_PACK_H

#include<iostream>
#include"Container.h"

using namespace std;
namespace sdds
{
	class Pack :public Container
	{
		int pUnitSz;
		int pSize;
		int pNumUnits;

	public:
		Pack(const char*, int, int = 330, int = 0);
		int operator += (int);
		int operator -= (int);
		int unit() const;
		int noOfUnits() const;
		int size() const;
		void clear(int, int, const char*);
		ostream& print(ostream&) const;
		istream& read(istream&);
	};

	int getint2(int, int, const char*, const char*);
	ostream& operator<<(ostream&, const Pack&);
	istream& operator>>(istream&, Pack&);
}
#endif // !SDDS_PACK_H


