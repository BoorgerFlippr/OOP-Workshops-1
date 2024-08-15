/*
Glenn Parrreno
geparreno@myseneca.ca
115814196
22-03-22
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/


#ifndef SDDS_SHAPE_H
#define SDDS_SHAPE_H
#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
using namespace std;
namespace sdds
{
	class Shape
	{
	public:
		virtual void draw(ostream&) const = 0;
		virtual void getSpecs(istream&) = 0;
		virtual ~Shape() {};
	};

	ostream& operator<<(ostream&, const Shape&);
	istream& operator>>(istream&, Shape&);
}
#endif // !SDDS_SHAPE_H
