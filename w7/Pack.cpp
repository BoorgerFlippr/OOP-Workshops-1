/*
Glenn Parrreno
geparreno@myseneca.ca
115814196
17-03-22
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#define _CRT_SECURE_NO_WARNINGS
#include"Pack.h"
#include<cstring>
#include<string.h>

using namespace std;
namespace sdds
{
	Pack::Pack(const char* content, int size, int unitSz, int numUnits) 
		:Container(content, unitSz* size, unitSz* numUnits)
	{
		if (size > 0)
		{
			pSize = size;
			pUnitSz = unitSz;
			pNumUnits = numUnits;
		}
		else
		{
			Container::setEmpty();
		}
	}

	int Pack::operator+=(int toAdd)
	{
		int toReturn = Container::operator+=(toAdd * pUnitSz) / pUnitSz;
		pNumUnits += toReturn;
		return toReturn;
	}

	int Pack::operator-=(int toMinus)
	{
		int toReturn = Container::operator-=(toMinus * pUnitSz) / pUnitSz;
		pNumUnits -= toReturn;
		return toReturn;
	}

	int Pack::unit() const
	{
		return pUnitSz;
	}

	int Pack::noOfUnits() const
	{
		int toReturn = Container::getVolume() / pUnitSz;
		return toReturn;
	}

	int Pack::size() const
	{
		int toReturn = Container::getCapacity() / pUnitSz;
		return toReturn;
	}

	void Pack::clear(int size, int unitSz, const char* content)
	{
		if (unitSz > 0)
		{
			Container::clear(size * unitSz, content);
			pUnitSz = unitSz;
			pNumUnits = 0;
			pSize += 2;
		}
	}

	ostream& Pack::print(ostream& os) const
	{
		Container::print(os);
		if (getValid() == true)
		{
			os << ", " << pNumUnits << " in a pack of " << pSize;
		}
		

		return os;
	}

	istream& Pack::read(istream& is)
	{
		char c;
		int input, result;
		if (getValid() == false)
		{
			cout << "Broken Container, adding aborted! Press <ENTER> to continue....";
			//c = getchar();
			is.ignore(1000, '\n');
		}
		else
		{
			if (pNumUnits < pSize)
			{
				cout << "Add to ";
				Pack::print(cout);
				cout << '\n' << "> ";
				input = getint2(1, pSize - pNumUnits, nullptr, nullptr);
				//result = *this += input;
				result = *this += input;
				cout << "Added " << result << "\n";

			}
			else
			{
				cout << "Pack is full, press <ENTER> to continue....";
				c = getchar();
				is.ignore(1000, c);
			}
		}
		//c = ' ';

		return is;
	}

	int getint2(int min, int max, const char* prompt = nullptr, const char* errMes = nullptr)
	{
		int i = 0;
		int input;

		if (prompt != nullptr)
			cout << prompt;

		do
		{
			cin >> input;
			if (cin.fail())
			{
				cin.clear();
				cin.ignore(1000, '\n');
				cout << "Invalid Integer, retry: ";
			}
			else if (input > max || input < min)
			{
				if (errMes != nullptr)
					cout << errMes << ", retry: ";
				else
					cout << "Value out of range [" << min << "<=val<=" << max << "]: ";
			}
			else
				i = 1;
		} while (i == 0);

		return input;
	}

	ostream& operator<<(ostream& os, const Pack& p)
	{
		return p.print(os);
	}

	istream& operator>>(istream& is, Pack& p)
	{
		return p.read(is);
	}
}

