/*
Glenn Parrreno
geparreno@myseneca.ca
115814196
22-03-22
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#ifndef SDDS_LINE_H
#define SDDS_LINE_H

#include "LblShape.h"
using namespace std;
namespace sdds
{
	class Line : public LblShape
	{
		int m_length;

	public:
		Line();
		Line(const char*, int);
		void getSpecs(istream&);
		void draw(ostream&) const;
	};
}
#endif // !SDDS_LINE_H
