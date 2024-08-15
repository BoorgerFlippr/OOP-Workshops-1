/*
Glenn Parrreno
geparreno@myseneca.ca
115814196
17-03-22
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#define _CRT_SECURE_NO_WARNINGS
#include "Container.h"
#include<cstring>
#include<string.h>
using namespace std;
namespace sdds
{
	
	Container::Container(const char* content, int capacity, int vol)
	{
		if (vol > capacity || content == NULL)
		{
			cValid = false;
		}
		else
		{
			strcpy(cContent, content);
			cCapacity = capacity;
			cContentVol = vol;
			cValid = true;
		}
	}

	void Container::setEmpty()
	{
		cValid = false;
	}

	int Container::getCapacity() const
	{
		return cCapacity;
	}

	int Container::getVolume() const
	{
		return cContentVol;
	}

	bool Container::getValid() const
	{
		return cValid;
	}

	int Container::operator+=(int toAdd)
	{
	
		int big = cContentVol;
		cContentVol += toAdd;
		if (cContentVol > cCapacity)
		{
			cContentVol = cCapacity;
			toAdd = cContentVol - big;
			
		}

		return toAdd;

		/*if (cContentVol += toAdd <= cCapacity)
		{
			cContentVol += toAdd;
		}
		else
		{
			toAdd = cCapacity - cContentVol;
			cContentVol = cCapacity;
		}

		return toAdd;*/
	}

	int Container::operator-=(int toMinus)
	{
	
		if (cContentVol - toMinus >= 0)
		{
			cContentVol -= toMinus;
		}
		else
		{
			toMinus = cContentVol;
			cContentVol = 0;
		}
		return toMinus;
	}

	Container::operator bool() const 
	{
		return cValid;
	}

	void Container::clear(int capacity, const char* content)
	{
		if (capacity > 0 && content != NULL)
		{
			cCapacity = capacity;
			strcpy(cContent, content);
			cContentVol = 0;
			cValid = true;
		}
	}

	ostream& Container::print(ostream& os) const
	{
		if (cValid)
		{
			os << cContent << ": (" << cContentVol << "cc/" << cCapacity << ")";
		}
		else
		{
			os << "****: (**cc/***)";
		}

		return os;
	}

	istream& Container::read(istream& is)
	{
		int input, result;
		char c;
		if (cValid == false)
		{
			cout << "Broken Container, adding aborted! Press <ENTER> to continue....";
			c = getchar();
			is.ignore(1000, c);
			//c = getchar();
		}
		else
		{
			cout << "Add to ";
			print(cout);
			cout << '\n' << "> ";
			input = getint(1, 220000, nullptr, nullptr);
			result = *this += input;
			cout << "Added " << result << " CCs\n";
			
		}
		//c = ' ';

		return is;
	}

	int getint(int min, int max, const char* prompt = nullptr, const char* errMes = nullptr)
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

	ostream& operator<<(ostream& os, const Container& c)
	{
		return c.print(os);
	}

	istream& operator>>(istream& is, Container& c)
	{
		return c.read(is);
	}
}

