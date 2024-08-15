/*
Glenn Parrreno
geparreno@myseneca.ca
115814196
13-02-22
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#ifndef sdds_ROBOT_H
#define sdds_ROBOT_H
#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<cstring>
#include<string.h>
#include<iomanip>

namespace sdds
{
	class Robot
	{
		char* rName;
		char* rLocation;
		double rWeight;
		double rWidth;
		double rHeight;
		double rSpeed;
		bool rDeployed;

	public:
		//constructor/destructor
		Robot();
		Robot(const char*, const char*, double, double, double, double, bool);
		~Robot();
		//setters
		Robot& set(const char*, const char*, double, double, double, double, bool);
		void setLocation(const char*);
		void setDeployed(bool);
		//getters
		char* getName() const;
		char* getLocation() const;
		bool isDeployed() const;
		bool isValid() const;
		double speed() const;
		void display() const;
	};

	int conrtolRooomReport(const Robot[], int);
}
#endif // !sdds_ROBOT_H
