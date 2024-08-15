/*
Glenn Parrreno
geparreno@myseneca.ca
115814196
22-03-22
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#include <string.h>
#include <cstring>
#include "Line.h"

using namespace std;
namespace sdds
{
	Line::Line()
	{
		m_length = 0;
	}

	Line::Line(const char* lbl, int length) : LblShape(lbl)
	{
		m_length = length;
	}

	void Line::getSpecs(istream& is)
	{
		LblShape::getSpecs(is);
		is >> m_length;
		is.ignore();
	}

	void Line::draw(ostream& os) const
	{
		if (m_length > 0 && label() != nullptr)
		{
			os << label() << endl;
			for (int i = 0; i < m_length; i++)
			{
				os << '=';
			}
		}

	}
}