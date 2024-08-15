/*
Glenn Parrreno
geparreno@myseneca.ca
115814196
10-02-22
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#ifndef sdds_CARINVENTORY_H
#define sdds_CARINVETORY_H
#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<cstring>
#include<string.h>
#include<iomanip>

namespace sdds
{
	
	class CarInventory
	{
		char* m_type;
		char* m_brand;
		char* m_model;
		int m_year;
		int m_code;
		double m_price;
		void resetInfo(); //destructor

	public:
		CarInventory(); //constructor
		CarInventory(const char*, const char*, const char*, int = 2022, int = 100, double = 1); //constructor
		CarInventory& setInfo(const char*, const char*, const char*, int, int, double); 
		void printInfo() const;
		bool isValid() const;
		bool isSimilarTo(const CarInventory&) const;
	};

	bool find_similar(CarInventory[], const int);
}
#endif // !sdds_CARINVENTORY_H
