/*
Glenn Parrreno
geparreno@myseneca.ca
115814196
23-02-29
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#ifndef sdds_TRAIN_H
#define sdds_TRAIN_H
#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<cstring>
#include<string.h>


namespace sdds
{
	const int MAX_NAME_LEN = 20;
	const int MAX_PEOPLE = 1000;
	const int MAX_SPEED = 320;

	class Train
	{
	private:
		char tName[MAX_NAME_LEN];
		int tNumPeople;
		double tSpeed;
	public:
		void set(const char*, int, double);
		int getNumberOfPeople() const;
		const char* getName() const;
		double getSpeed() const;
		bool isSafeEmpty() const;
		void display() const;
	};
}

#endif // !sdds_TRAIN_H