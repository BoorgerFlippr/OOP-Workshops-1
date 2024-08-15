/*
Glenn Parrreno
geparreno@myseneca.ca
115814196
10-02-22
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#include "CarInventory.h"

using namespace std;
using namespace sdds;

namespace sdds
{
	//constructors
	CarInventory::CarInventory()
	{
		resetInfo();
	}

	CarInventory::CarInventory(const char* type, const char* brand, const char* model, int year, int code, double price)
	{
		bool valid;

		if (type == nullptr)
		{
			valid = false;
		}
		else if (brand == nullptr)
		{
			valid = false;
		}
		else if (model == nullptr)
		{
			valid = false;
		}
		else if (year < 1990)
		{
			valid = false;
		}
		else if (code < 100 || code > 999)
		{
			valid = false;
		}
		else if (price < 1)
		{
			valid = false;
		}
		else
		{
			valid = true;
		}

		if (valid == true)
		{
			m_type = (char*)type;
			m_brand = (char*)brand;
			m_model = (char*)model;
			m_year = year;
			m_code = code;
			m_price = price;
		}
		else
		{
			resetInfo();
		}
	}

	//destructor
	void CarInventory::resetInfo()
	{
		m_type = nullptr;
		m_brand = nullptr;
		m_model = nullptr;
		m_year = 0;
		m_code = 0;
		m_price = 0;
	}

	//member functions
	CarInventory& CarInventory::setInfo(const char* type, const char* brand, const char* model, int year, int code, double price)
	{
		resetInfo();

		bool valid;

		if (type == nullptr)
		{
			valid = false;
		}
		else if (brand == nullptr)
		{
			valid = false;
		}
		else if (model == nullptr)
		{
			valid = false;
		}
		else if (year < 1990)
		{
			valid = false;
		}
		else if (code < 100 || code > 999)
		{
			valid = false;
		}
		else if (price < 1)
		{
			valid = false;
		}
		else
		{
			valid = true;
		}

		if (valid == true)
		{
			m_type = (char*)type;
			m_brand = (char*)brand;
			m_model = (char*)model;
			m_year = year;
			m_code = code;
			m_price = price;
		}
		else
		{
			resetInfo();
		}

		return *this;

	}

	void CarInventory::printInfo() const
	{
		cout << left;
		cout << "| " << setw(10);
		cout << m_type << " | " << setw(16);
		cout << m_brand << " | " << setw(16);
		cout << m_model << " | " << m_year << " |  " << m_code;
		cout << " | " << setw(9);
		cout.setf(ios::right);
		cout.precision(2);
		cout << fixed << m_price << " |" << endl;
	}

	bool CarInventory::isValid() const
	{
		bool valid = false;

		if((m_type != nullptr) && (m_brand != nullptr) && (m_model != nullptr) && 
			(m_year >= 1990) && (m_code > 99 && m_code <= 999) && (m_price > 0))
		{
			valid = true;
		}

		return valid;
	}

	bool CarInventory::isSimilarTo(const CarInventory& car) const
	{
		bool similar = false;

		if (this->m_type == car.m_type)
		{
			similar = true;
		}
		else if (this->m_brand == car.m_brand)
		{
			similar = true;
		}
		else if (this->m_model == car.m_model)
		{
			similar = true;
		}
		else if (this->m_year == car.m_year)
		{
			similar = true;
		}
		else if (this->m_code == car.m_code)
		{
			similar = true;
		}
		else if (this->m_price == car.m_price)
		{
			similar = true;
		}
		else
		{
			similar = false;
		}

		return similar;
	}

	bool find_similar(CarInventory car[], const int num_cars)
	{
		int i, j;
		bool similar = true;

		for (i = 0; i < num_cars; i++)
		{
			for (j = i + 1; j < num_cars; j++)
			{
				if (car[i].isSimilarTo(car[j]))
				{
					similar = true;
				}
			}
		}

		return similar;
	}
}

