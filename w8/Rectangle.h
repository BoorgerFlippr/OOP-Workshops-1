/*
Glenn Parrreno
geparreno@myseneca.ca
115814196
22-03-22
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#ifndef SDDS_RECTANGLE_H
#define SDDS_RECTANGLE_H

#include "LblShape.h"
using namespace std;
namespace sdds
{
	class Rectangle : public LblShape
	{
		int m_width;
		int m_height;

	public:
		Rectangle();
		Rectangle(const char*, int, int);
		void getSpecs(istream&);
		void draw(ostream&) const;
	};
}
#endif // !SDDS_RECTANGLE_H
