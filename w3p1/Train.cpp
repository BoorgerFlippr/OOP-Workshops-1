/*
Glenn Parrreno
geparreno@myseneca.ca
115814196
23-02-29
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#include "Train.h"


using namespace std;
using namespace sdds;

namespace sdds
{
	void Train::set(const char* name, int numPeople, double speed)
	{
		bool valid;
		
		if (name == nullptr || strlen(name) <= 0)
		{
			valid = false;
		}
		else if (numPeople > MAX_PEOPLE || numPeople < 0)
		{
			valid = false;
		}
		else if (speed > MAX_SPEED || speed < 0)
		{
			valid = false;
		}
		else
		{
			valid = true;
		}

		if (valid == true)
		{
			strncpy(tName, name, MAX_NAME_LEN);
			tNumPeople = numPeople;
			tSpeed = speed;
		}
		else
		{
			strncpy(tName, "", MAX_NAME_LEN);
			tNumPeople = 0;
			tNumPeople = 0;
		}
	}

	int Train::getNumberOfPeople() const
	{
		return tNumPeople;
	}

	const char* Train::getName() const
	{
		return tName;
	}

	double Train::getSpeed() const
	{
		return tSpeed;
	}

	bool Train::isSafeEmpty() const
	{
		bool isEmpty = false;

		if (tName == nullptr || tNumPeople == 0 || tSpeed == 0)
		{
			isEmpty = true;
		}

		return isEmpty;
	}

	void Train::display() const
	{
		if (isSafeEmpty())
		{
			cout << "Safe Empty State!" << endl;
		}
		else
		{
			cout <<
				"NAME OF THE TRAIN : " << tName << endl <<
				"NUMBER OF PEOPLE  : " << tNumPeople << endl <<
				"SPEED             : " << tSpeed << " km/h" << endl;
		}
	}
}