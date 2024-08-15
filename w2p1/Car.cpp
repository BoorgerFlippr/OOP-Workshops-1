//Glenn Parrreno
//geparreno@myseneca.ca
//115814196
//23-01-27

#include "cStrTools.h"
#include "Car.h"
using namespace std;
using namespace sdds;

namespace sdds
{
	Car* arrCars = nullptr;
	int allocSz, numCars, arrCarsSize;

	void VBPLE_Title()
	{
		cout << "Vehicle Border Passing Log Entry\n";
		cout << "Enter the data in the following format:\n";
		cout << "Make and model,LicensePlate,MilitaryTime<ENTER>\n";
		cout << "Exit the program by entering the following:\n";
		cout << "X,<ENTER>\n";
	}

	void initialize(int allocSize)
	{
		numCars = 0;
		arrCarsSize = allocSize;
		allocSz = allocSize;
		arrCars = new Car[allocSz];
	}

	void deallocate(Car& C)
	{
		delete[] C.makeModel;
		C.makeModel = nullptr;
	}

	bool read(Car& C)
	{
		bool flag = false;
		char mkModel[60];

		read(mkModel, 60, ',');

		if (strCmp(mkModel, "X") != 0)
		{
			flag = true;
			C.makeModel = new char[strLen(mkModel) + 1];
			strCpy(C.makeModel, mkModel);
			read(C.plate, 8, ',');
			cin >> C.time;
		}

		return flag;
	}

	void print(const Car& C)
	{
		cout << C.time << ": " << C.makeModel << "," << C.plate << endl;
	}


	void record(const Car& C)
	{
		int i, resize;
		if (numCars == arrCarsSize)
		{
			Car* localCar = nullptr;
			resize = arrCarsSize + allocSz;
			localCar = new Car[arrCarsSize + allocSz];

			for (i = 0; i < arrCarsSize; i++)
			{
				localCar[i].makeModel = arrCars[i].makeModel;
				strCpy(localCar[i].plate, arrCars[i].plate);
				localCar[i].time = arrCars[i].time;
			}

			delete[] arrCars;
			arrCars = nullptr;
			arrCarsSize = resize;
			arrCars = localCar;
			localCar = nullptr;
			delete[] localCar; 

		}
		arrCars[numCars].makeModel = C.makeModel;
		strCpy(arrCars[numCars].plate, C.plate);
		arrCars[numCars].time = C.time;
		numCars++;
	}

	void endOfDay()
	{
		int i;
		for (i = 0; i < numCars; i++)
		{
			print(arrCars[i]);
			deallocate(arrCars[i]);
		}

		delete[] arrCars;//?
	}


}