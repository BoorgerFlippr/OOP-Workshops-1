//Glenn Parrreno
//geparreno@myseneca.ca
//115814196
//23-01-27

#ifndef sdds_CAR_H
#define sdds_CAR_H

namespace sdds
{
	struct Car
	{
		char plate[9];
		char* makeModel = nullptr;
		int time;
	};

	void VBPLE_Title();
	void initialize(int);
	void deallocate(Car&);
	bool read(Car&);
	void print(const Car&);
	void record(const Car&);
	void endOfDay();
}
#endif // !sdds_CAR_H

