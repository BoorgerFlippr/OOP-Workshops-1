/*
Glenn Parrreno
geparreno@myseneca.ca
115814196
17-03-22
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#ifndef SDDS_CONTAINER_H
#define SDDS_CONTAINER_H

#include<iostream>

using namespace std;
namespace sdds
{
	class Container
	{
		char cContent[50];
		int cCapacity;
		int cContentVol;
		bool cValid;

	protected:
		void setEmpty();
		int getCapacity() const;
		int getVolume() const;
		bool getValid() const;

	public:
		//Container(const char*, int);
		Container(const char*, int, int = 0);
		int operator +=(int);
		int operator -=(int);
		operator bool() const;
		void clear(int, const char*);
		ostream& print(ostream&) const;
		istream& read(istream&);
	};

	int getint(int, int, const char*, const char*);
	ostream& operator<<(ostream&, const Container&);
	istream& operator>>(istream&, Container&);

}

#endif // !SDDS_CONTAINER_H


