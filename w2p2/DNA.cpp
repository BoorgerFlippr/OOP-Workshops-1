/*
Glenn Parrreno
geparreno@myseneca.ca
115814196
23-01-29
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#include "cStrTools.h"
#include "DNA.h"
using namespace std;
using namespace sdds;


namespace sdds
{
	DNA* arrDNA = nullptr;
	DNA* tempArr = nullptr;
	int arrSize = 0, tempArrSz = 0;

	bool beginSearch(const char* filename)
	{
		bool fileExist = true;
		FILE* fp = fopen(filename, "r");
		int j, i = 0;
		char line[1000];
		char* p, q;
		if (fp == NULL)
		{
			fileExist = false;
		}
		else
		{
			while (EOF != (j = getc(fp)))
			{
				if ('\n' == j)
					tempArrSz++;
			}

			tempArr = new DNA[tempArrSz + 1];

			while (fgets(line, 1000, fp) != NULL)
			{
				p = strtok(line, ",");
				tempArr[i].ID = atoi(p);

				q = strtok(NULL, ",");
				tempArr[i].strand = new char[strLen(q)];
				strCpy(tempArr[i].strand, q);
			}

			fclose(fp);

		}

		return fileExist;
	}

	bool read(const char* subDNA)
	{
		int i;
		const char* found;
		bool foundSomthing;
		for (i = 0; i < tempArrSz + 1; i++)
		{
			found = (tempArr[i].strand, subDNA);
			if (found != NULL)
			{
				arrSize++;
			}
		}

		if (arrSize == 0)
		{
			foundSomthing = false;
		}
		else
		{
			foundSomthing = true;

			arrDNA = new DNA[arrSize];

			for (i = 0; i < tempArrSz + 1; i++)
			{
				found = (tempArr[i].strand, subDNA);
				if (found != NULL)
				{
					arrDNA[i].strand = new char[strLen(tempArr[i].strand)];
					strCpy(arrDNA[i].strand, tempArr[i].strand);
				}
			}
		}

		return foundSomthing;
	}

	void sort()
	{
		
	}

	void displayMatches()
	{
		int i;
		cout << arrSize << " matches found:\n";
		for (i = 0; i < arrSize; i++)
		{
			cout << i + 1 << ") " << arrDNA[i].ID << ":\n";
			cout << arrDNA[i].strand << endl;
			cout << "======================================================================\n";

		}
	}

	void deallocate()
	{
		int i;
		for (i = 0; i < tempArrSz; i++)
		{
			delete[] arrDNA[i].strand;
			arrDNA[i].strand = nullptr;
		}
		delete[] arrDNA;
		arrDNA = nullptr;

	}

	void endSearch()
	{
		int i;
		for (i = 0; i < arrSize; i++)
		{
			delete[] tempArr[i].strand;
			tempArr[i].strand = nullptr;
		}
		delete[] tempArr;
		tempArr = nullptr;
	}
}