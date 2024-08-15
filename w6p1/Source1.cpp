/*
Glenn Parrreno
geparreno@myseneca.ca
115814196
02-03-22
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
/*#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include "HealthCard.h"
using namespace std;
namespace sdds {

	bool HealthCard::validID(const char* name, long long number, const char vCode[], const char sNumber[]) const
	{
		bool toReturn = false;
		int valid = 0;
		/*if (!(name != nullptr))
		{
			toReturn = false;
		}
		if (!(number > 999999999 && number < 9999999999))
		{
			toReturn = false;
		}
		if (!(strlen(vCode) == 2))
		{
			toReturn = false;
		}
		if (!(strlen(sNumber) == 9))
		{
			toReturn = false;
		}

		if (name != nullptr)
		{
			valid++;
		}
		if (number > 999999999 && number < 9999999999)
		{
			toReturn = false;
		}
		if (strlen(vCode) == 2)
		{
			valid++;
		}
		if (strlen(sNumber) == 9)
		{
			valid++;
		}
		if (valid == 4)
		{
			toReturn = true;
		}

		return toReturn;//name != nullptr && number >= 1000000000 && number <= 9999999999 && strlen(vCode) == 2 && strlen(sNumber) == 9;
	}

	void HealthCard::setEmpty()
	{
		m_name = nullptr;
		m_number = 0;
		m_vCode[3] = '\0';
		m_sNumber[10] = '\0';
	}

	void HealthCard::allocateAndCopy(const char* name)
	{
		delete[] m_name;
		m_name = new char[strlen(name) + 1];
		strcpy(m_name, name);
	}

	void HealthCard::extractChar(std::istream& istr, char ch) const
	{
		char next;
		next = istr.peek();

		if (next == ch)
		{
			ch = istr.get();
			//istr.ignore();
		}
		else
		{
			istr.ignore(1000, ch);
			istr.setstate(ios::failbit);
		}
	}

	ostream& HealthCard::printIDInfo(ostream& ostr) const
	{
		ostr << m_number << "-" << m_vCode << "," << " " << m_sNumber;

		return ostr;
	}

	void HealthCard::set(const char* name, long long number, const char vCode[], const char sNumber[])
	{
		if (validID(name, number, vCode, sNumber))
		{
			allocateAndCopy(name);
			m_number = number;
			strcpy(m_vCode, vCode);
			strcpy(m_sNumber, sNumber);
		}
		else
		{
			delete[] m_name;
			setEmpty();
		}
	}

	HealthCard::HealthCard()
	{
		m_name = nullptr;
		m_number = 0;
		m_vCode[3] = '\0';
		m_sNumber[10] = '\0';
	}

	HealthCard::HealthCard(const char* name, long long number, const char vCode[], const char sNumber[])
	{

		set(name, number, vCode, sNumber);
	}

	HealthCard::HealthCard(const HealthCard& hc)
	{
		if (hc)
		{
			set(hc.m_name, hc.m_number, hc.m_vCode, hc.m_sNumber);
		}
		else
		{
			setEmpty();
		}
	}

	HealthCard& HealthCard::operator=(const HealthCard& hc)
	{
		if (this != &hc)
		{
			set(hc.m_name, hc.m_number, hc.m_vCode, hc.m_sNumber);
		}
		return *this;
	}

	HealthCard::~HealthCard()
	{
		delete[] m_name;
	}

	HealthCard::operator bool() const
	{
		bool toReturn = false;

		if (m_name != nullptr)
		{
			toReturn = true;
		}

		return toReturn; //m_name != nullptr && m_number >= 1000000000 && m_number <= 9999999999 && strlen(m_vCode) == 2 && strlen(m_sNumber) == 9;
	}

	ostream& HealthCard::print(std::ostream& ostr, bool toFile = true) const
	{

		if (validID(this->m_name, this->m_number, this->m_vCode, this->m_sNumber))
		{
			if (toFile == true)
			{
				ostr << m_name << ",";
				printIDInfo(ostr);
			}
			else
			{
				ostr << m_name << setfill('.') << setw(50);
				printIDInfo(ostr);
			}
		}

		return ostr;
	}

	istream& HealthCard::read(istream& istr)
	{
		char name[MaxNameLength];
		long long number;
		char vCode[3];
		char sNumber[10];

		istr.get(name, MaxNameLength, ',');
		extractChar(istr, ',');
		istr >> number;
		extractChar(istr, '-');
		istr.get(vCode, 3, ',');
		extractChar(istr, ',');
		istr.get(sNumber, 10, '\n');
		extractChar(istr, '\n');

		if (istr.fail() == false)
		{
			set(name, number, vCode, sNumber);
		}
		else
		{
			istr.clear();
			istr.ignore('\n');
		}

		/*istr.get(name, MaxNameLength, ',');
		extractChar(istr, ',');
		if (istr.fail())
		{
			return istr;
		}
		istr >> number;
		extractChar(istr, '-');
		if (istr.fail())
		{
			return istr;
		}
		istr.get(vCode, 3, ',');
		extractChar(istr, '-');
		if (istr.fail())
		{
			return istr;
		}
		istr.get(sNumber, 10, '\n');
		extractChar(istr, '\n');
		if (istr.fail())
		{
			return istr;
		}
		return istr;

	}

	ostream& operator<<(std::ostream& ostr, const HealthCard& hc)
	{
		if (hc)
		{
			hc.print(ostr, false);
		}
		else
		{
			cout << "Invalid Card Number";
		}

		return ostr;
	}

	istream& operator>>(std::istream& istr, HealthCard& hc)
	{
		return hc.read(istr);
	}

}*/