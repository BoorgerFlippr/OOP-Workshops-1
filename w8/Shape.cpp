/*
Glenn Parrreno
geparreno@myseneca.ca
115814196
22-03-22
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#include"Shape.h"

using namespace std;
namespace sdds
{
	ostream& operator<<(ostream& os, const Shape& sh)
	{
		sh.draw(os);
		return os;
	}

	istream& operator>>(istream& is, Shape& sh)
	{
		sh.getSpecs(is);
		return is;
	}
}