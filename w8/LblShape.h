/*
Glenn Parrreno
geparreno@myseneca.ca
115814196
22-03-22
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#ifndef SDDS_LBLSHAPE_H
#define SDDS_LBLSHAPE_H

//#include<iostream>
#include "Shape.h"
using namespace std;
namespace sdds
{
	class LblShape : public Shape
	{
		char* m_label = nullptr;
		
	protected:
		char* label() const;

	public:
		LblShape();
		LblShape(const char*);
		~LblShape();
		void getSpecs(istream&);
	};

	void alocpy(char*&, const char*);
}
#endif // !SDDS_LBLSHAPE_H

