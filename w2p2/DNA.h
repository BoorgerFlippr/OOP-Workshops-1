/*
Glenn Parrreno
geparreno@myseneca.ca
115814196
23-01-29
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#ifndef sdds_DNA_H
#define sdds_DNA_H
#define _CRT_SECURE_NO_WARNINGS

namespace sdds
{
	struct DNA
	{
		int ID;
		char* strand = nullptr;
	};

	bool beginSearch(const char*);
	bool read(const char*);
	void sort();
	void displayMatches();
	void deallocate();
	void endSearch();
}
#endif // !sdds_DNA_H

