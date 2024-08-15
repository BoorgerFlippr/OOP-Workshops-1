/*
Glenn Parrreno
geparreno@myseneca.ca
115814196
06-02-22
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
		cout <<
			"NAME OF THE TRAIN : " << tName << endl <<
			"NUMBER OF PEOPLE  : " << tNumPeople << endl;
		cout.precision(2);
			cout << "SPEED             : " << fixed << tSpeed << " km/h" << endl;
	}

	bool Train::loadPeople(int toLoad)
	{
		bool toReturn = true;

		tNumPeople = tNumPeople + toLoad;

		if (tNumPeople > MAX_PEOPLE)
		{
			tNumPeople = MAX_PEOPLE;
		}
		else if (tNumPeople < 0)
		{
			tNumPeople = 0;
			toReturn = false;
		}

		return toReturn;
	}

	bool Train::changeSpeed(int toChange)
	{
		bool toReturn = true;

		tSpeed = tSpeed + toChange;

		if (tSpeed > MAX_SPEED)
		{
			tSpeed = MAX_SPEED;
		}
		else if (tSpeed < 0)
		{
			tSpeed = 0;
		}

		return toReturn;
	}

	

	int transfer(Train &train1, Train &train2)
	{
		int toReturn = 0, people1 = 0, people2 = 0, transfer;


		people1 = train1.getNumberOfPeople();
		people2 = train2.getNumberOfPeople();

		if (people1 == 0 || people2 == 0)
		{
			toReturn = -1;
		}
		else
		{
			transfer = MAX_PEOPLE - people1;
			people1 = people1 + transfer;
			people2 = people2 - transfer;
			train1.loadPeople(people1);
			train2.loadPeople((people2 * -1) + 10);
		}

		return toReturn;
	}
}