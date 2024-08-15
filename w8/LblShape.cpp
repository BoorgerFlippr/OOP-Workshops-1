/*
Glenn Parrreno
geparreno@myseneca.ca
115814196
22-03-22
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
#include <cstring>
#include "LblShape.h"

using namespace std;
namespace sdds
{
	char* LblShape::label() const
	{
		return m_label;
	}

	LblShape::LblShape()
	{
		m_label = nullptr;
	}

	LblShape::LblShape(const char* label)
	{
		alocpy(m_label, label);
	}

	LblShape::~LblShape()
	{
		delete[] m_label;
	}

	void LblShape::getSpecs(istream& is)
	{
		char label[41];

		is.get(label, 41, ',');
		is.ignore();

		alocpy(m_label, label);
	}

	void alocpy(char*& destination, const char* source)
	{
		delete[] destination;
		destination = nullptr;

		if (source != nullptr)
		{
			destination = new char[strlen(source) + 1];
			strcpy(destination, source);
		}
	}
}