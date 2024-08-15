/*
Glenn Parrreno
geparreno@myseneca.ca
115814196
22-03-22
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#include <string.h>
#include <cstring>
#include "Rectangle.h"

using namespace std;
namespace sdds
{
	Rectangle::Rectangle()
	{
		m_height = 0;
		m_width = 0;
	}

	Rectangle::Rectangle(const char* lbl, int width, int height) : LblShape(lbl)
	{
		m_width = width;
		m_height = height;
	}

	void Rectangle::getSpecs(istream& is)
	{
		LblShape::getSpecs(is);
		is >> m_width;
		is.ignore();
		is >> m_height;
		is.ignore();
	}

	void Rectangle::draw(ostream& os) const
	{
		int len = strlen(label());
		if (label() != nullptr && m_width > 1 && m_height > 1)
		{
			//first
			os << '+';
			for (int i = 0; i < m_width - 2; i++)
			{
				os << '-';
			}
			os << '+' << endl;

			//second
			os << '|';
			os << label();
			for (int i = 0; i < m_width - (2 + len); i++)
			{
				os << ' ';
			}
			os << '|' << endl;

			//the rest
			for (int i = 0; i < m_height - 3; i++)
			{
				cout << '|';
				for (int j = 0; j < m_width - 2;j++)
				{
					os << ' ';
				}
				os << '|' << endl;
			}
			//last
			os << '+';
			for (int i = 0; i < m_width - 2; i++)
			{
				os << '-';
			}
			os << '+';
		}
		
	}
}