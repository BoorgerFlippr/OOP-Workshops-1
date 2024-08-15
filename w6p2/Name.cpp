/*
Glenn Parrreno
geparreno@myseneca.ca
115814196
02-03-22
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <iomanip>
#include <cstring>
#include <string.h>
#include <string>
#include "Name.h"

using namespace std;
namespace sdds
{
	void Name::alocpy(char*& destination, const char* source)
	{
		if (destination != nullptr)
		{
			delete[] destination;
			destination = nullptr;
		}
		destination = new char[strlen(source) + 1];
		strcpy(destination, source);

		/*if (source != nullptr)
		{
			delete[] destination;
			destination = nullptr;
			destination = new char[strlen(source) + 1];
			strcpy(destination, source);
		}*/
	}

	Name::Name()
	{
		fName = nullptr;
		mName = nullptr;
		lName = nullptr;
	}

	Name::Name(const char* name1)
	{
		alocpy(fName, name1);
	}

	Name::Name(const char* name1, const char* name2)
	{
		alocpy(fName, name1);
		alocpy(lName, name2);
	}

	Name::Name(const char* name1, const char* name2, const char* name3)
	{
		alocpy(fName, name1);
		alocpy(mName, name2);
		alocpy(lName, name3);
	}

	Name::Name(const Name& n)
	{
		if (n.fName != nullptr)
		{
			alocpy(fName, n.fName);
		}
		else
		{
			fName = nullptr;
		}

		if (n.mName != nullptr)
		{
			alocpy(mName, n.mName);
		}
		else
		{
			mName = nullptr;
		}
		
		if (n.lName != nullptr)
		{
			alocpy(lName, n.lName);
		}
		else
		{
			lName = nullptr;
		}
	}

	Name& Name::operator=(const Name& n)
	{
		if (this != &n)
		{
			if (n.fName != nullptr)
			{
				
				alocpy(fName, n.fName);
			}
			else
			{
				fName = nullptr;
			}

			if (n.mName != nullptr)
			{
				alocpy(mName, n.mName);
			}
			else
			{
				mName = nullptr;
			}

			if (n.lName != nullptr)
			{
				alocpy(lName, n.lName);
			}
			else
			{
				lName = nullptr;
			}
		}

		return *this;
	}

	Name::~Name()
	{
		delete[] fName;
		delete[] mName;
		delete[] lName;

		fName = nullptr;
		mName = nullptr;
		lName = nullptr;
	}

	void Name::setShort(bool isShort)
	{
		if (isShort == true && mName != nullptr)
		{
			if(mName != nullptr){ 
			char m[] = {mName[0], '.', '\0'};
			//m[0] = mName[0];
			//m[1] = '.';

			
			alocpy(mName, m);
			}
		}
	}

	Name& Name::operator+=(const char* toAdd)
	{
		bool hasSpace = false;
		int num = strlen(toAdd);

		if (!(toAdd == nullptr || strcmp(toAdd, "") == 0 ||  strcmp(toAdd, "   ") == 0))
		{
			for (int i = 0; i < num; i++)
			{
				if (isspace(toAdd[i]) > 0)
				{
					hasSpace = true;
					break;
				}
			}

			if (hasSpace == false)
			{
				if (fName == nullptr)
				{
					delete[] fName;
					fName = new char[strlen(toAdd) + 1];
					strcpy(fName, toAdd);
				}
				else if (mName == nullptr)
				{
					delete[] mName;
					mName = new char[strlen(toAdd) + 1];
					strcpy(mName, toAdd);
				}
				else if (lName == nullptr)
				{
					delete[] lName;
					lName = new char[strlen(toAdd) + 1];
					strcpy(lName, toAdd);
				}
				else if (fName != nullptr && mName != nullptr && lName != nullptr)
				{
					delete[] fName;
					delete[] mName;
					delete[] lName;

					fName = nullptr;
					mName = nullptr;
					lName = nullptr;
				}

			}
			else if (hasSpace == true)
			{
				delete[] fName;
				delete[] mName;
				delete[] lName;

				fName = nullptr;
				mName = nullptr;
				lName = nullptr;
			}
		}

		return *this;
	}
	ostream& Name::display(ostream& os) const
	{
		if (fName != nullptr && mName != nullptr && lName != nullptr)
		{
			os << fName << " " << mName << " " << lName;
		}
		else if (fName != nullptr && mName != nullptr)
		{
			os << fName << " " << mName;
		}
		else if (/*mName == nullptr*/ fName != nullptr && lName != nullptr)
		{
			os << fName << " " << lName;
		}
		else if (fName!= nullptr)
		{
			os << fName;
		}
		else if (fName == nullptr && mName == nullptr && lName == nullptr)
		{
			os << "Bad Name";
			//os.clear();
		}
		//os.clear();

		return os;
	}

	istream& Name::read(istream& is)
	{
		string first = "";
		string mid = "";
		string last = "";


		/*if (fName != nullptr)
		{
			delete[] fName;
			fName = nullptr;
		}
		if (mName != nullptr)
		{
			delete[] mName;
			mName = nullptr;
		}
		if (lName != nullptr)
		{
			delete[] lName;
			lName = nullptr;
		}*/
		

		is >> first;
		if (is.peek() != '\n')
			is >> mid;
		if (is.peek() != '\n')
			is >> last;
		if (is.peek() == '\n')
		{
			if (first != "")
			{
				alocpy(fName, first.c_str());
			}
			if (last != "")
			{
				alocpy(mName, mid.c_str());
				alocpy(lName, last.c_str());
			}
			if (mid != "" && last == "")
			{
				
				alocpy(lName, mid.c_str());
			}
		}

		return is;
	}

	Name::operator bool() const
	{
		bool toReturn = true;

		if (fName == nullptr && mName == nullptr && lName == nullptr)
			toReturn = false;

		return toReturn;
	}

	ostream& operator<<(ostream& os, const Name& n)
	{
		//n.display(os);

		return n.display(os);
	}

	istream& operator>>(istream& is, Name& n)
	{
		//is.clear();
		//n.read(is);

		return n.read(is);
	}
}