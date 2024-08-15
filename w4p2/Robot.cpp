/*
Glenn Parrreno
geparreno@myseneca.ca
115814196
13-02-22
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#include "Robot.h"

using namespace std;
using namespace sdds;

namespace sdds
{
	Robot::Robot()
	{
		rName = nullptr;
		rLocation = nullptr;
		rWeight = 0;
		rWidth = 0;
		rHeight = 0;
		rSpeed = 0;
		rDeployed = false;
	}

	Robot::Robot(const char* name, const char* location, double weight, double width, double height, double speed, bool deployed)
	{
		int nameLen = strlen(name) + 1,
			locLen = strlen(location )+ 1;
		rName = new char[nameLen];
		strcpy(rName, name);
		//cout << "allocCons\n";
		rLocation = new char[locLen];
		strcpy(rLocation, location);
		//cout << "allocCons\n";

		rWeight = weight;
		rWidth = width;
		rHeight = height;
		rSpeed = speed;
		rDeployed = deployed;

	}

	Robot::~Robot()
	{
		delete[] rName;
		//cout << "dealloc\n";
		delete[] rLocation;
		//cout << "dealloc\n";

		rName = nullptr;
		rLocation = nullptr;
	}

	Robot& Robot::set(const char* name, const char* location, double weight, double width, double height, double speed, bool deployed)
	{
		int nameLen = strlen(name) + 1,
			locLen = strlen(location) + 1;

		if (this->rName != nullptr || this->rLocation != nullptr)
		{
			this->~Robot();
		}

		rName = new char[nameLen];
		strcpy(rName, name);
		//cout << "allocSet\n";

		rLocation = new char[locLen];
		strcpy(rLocation, location);
		//cout << "allocSet\n";

		rWeight = weight;
		rWidth = width;
		rHeight = height;
		rSpeed = speed;
		rDeployed = deployed;

		return *this;
	}

	void Robot::setLocation(const char* location)
	{
		int locLen = strlen(location) + 1;
		rLocation = new char[locLen];
		//cout << "alloc\n";
		strcpy(rLocation, location);
	}

	void Robot::setDeployed(bool isDeployed)
	{
		rDeployed = isDeployed;
	}

	char* Robot::getName() const
	{
		return rName;
	}

	char* Robot::getLocation() const
	{
		return rLocation;
	}

	bool Robot::isDeployed() const
	{
		bool isDeployed = false;

		if (rDeployed == true)
		{
			isDeployed = true;
		}

		return isDeployed;
	}

	bool Robot::isValid() const
	{
		bool valid;

		if (rName == nullptr)
		{
			valid = false;
		}
		else if (rLocation == nullptr)
		{
			valid = false;
		}
		else if (rWeight <= 0)
		{
			valid = false;
		}
		else if (rWidth <= 0)
		{
			valid = false;
		}
		else if (rHeight <= 0)
		{
			valid = false;
		}
		else if (rSpeed <= 0)
		{
			valid = false;
		}
		else
		{
			valid = true;
		}

		return valid;
	}

	double Robot::speed() const
	{
		return rSpeed;
	}

	void Robot::display() const
	{
		if (rDeployed)
		{
			cout << left;
			cout << "| " << setw(10);
			cout << rName << " | " << setw(15);
			cout << rLocation << " | " << setw(6);
			cout << right;
			cout << rWeight << " | " << setw(6);
			cout << rWidth << " | " << setw(6);
			cout << rHeight << " | " << setw(6);
			cout << rSpeed << " | " << setw(8);
			cout << left;
			cout << "YES" << " |" << endl;
		}
		else
		{
			cout << left;
			cout << "| " << setw(10);
			cout << rName << " | " << setw(15);
			cout << rLocation << " | " << setw(6);
			cout << right;
			cout << rWeight << " | " << setw(6);
			cout << rWidth << " | " << setw(6);
			cout << rHeight << " | " << setw(6);
			cout << rSpeed << " | " << setw(8);
			cout << left;
			cout << "NO" << " |" << endl;
		}
	}

	
	int conrtolRooomReport(const Robot robot[], int num_robots)
	{
		int i, toReturn = -1, fastest = 0;
		double fast = 0;

		cout << "                        ------ Robot Control Room -----" << endl;
		cout << "                    ---------------------------------------" << endl;
		cout << "| Robot ID   | Location        | Weight |  Width | Height |  Speed | Deployed |" << endl;
		cout << "|------------+-----------------+--------+--------+--------+--------+----------|" << endl;

		for (i = 0; i < num_robots; i++)
		{
			cout << fixed << setprecision(1);
			if (robot[i].isValid() == true)
			{
				robot[i].display();
			}
			else
			{
				toReturn = i;
				break;
			}
			
			
			//robot[i].~Robot();
		}

		if (toReturn == -1)
		{
			for (i = 0; i < num_robots; i++)
			{
				if (robot[i].speed() > fast)
				{
					fast = robot[i].speed();
					fastest = i;
				}
			}

			cout << "|=============================================================================|" << endl;
			cout << "| SUMMARY:                                                                    |" << endl;
			cout << "| 3  robots are deployed.                                                     |" << endl;
			cout << "| The fastest robot is:                                                       |" << endl;
			cout << "| Robot ID   | Location        | Weight |  Width | Height |  Speed | Deployed |" << endl;
			cout << "|------------+-----------------+--------+--------+--------+--------+----------|" << endl;
			cout<< fixed << setprecision(1);
			robot[fastest].display();
			cout << "|=============================================================================|" << endl;

			
			
		}
		return toReturn;
	}
}