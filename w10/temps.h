/*
Glenn Parrreno
geparreno@myseneca.ca
115814196
11-04-22
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/


#ifndef SDDS_TEMPS_H_
#define SDDS_TEMPS_H_

#include "Car.h"
#include "Employee.h"
#include "Student.h"
#include "Collection.h"
#include "Displayable.h"
#include <iostream>

using namespace std;
namespace sdds
{
	template<typename T>
	//T in this function can be substituted with other classes such as car and employee. T is needed since in order to create a collection object
	//you need a size and another object(represented by T)
	Collection<T> select(const T objArr[], int size, const T& object)
	{
		int matches = 0, j = 0;

		for (int i = 0; i < size; i++)
		{
			if (objArr[i] == object)
				matches++;
		}

		Collection<T> col(matches);

		for (int i = 0; i < size; i++)
		{
			if (objArr[i] == object)
			{
				col[j] = objArr[i];
				j++;
			}
		}
		return col;
	}

	template<typename Class>
	//Class is used to specify what class of objects will Collection use to print data from.
	void printCollection(const Collection<Class>& col, const char* title)
	{
		cout << title << endl;

		for (int i = 0; i < col.size(); i++)
		{
			cout << col[i] << endl;
		}
	}
}
#endif // !SDDS_TEMPS_H_
