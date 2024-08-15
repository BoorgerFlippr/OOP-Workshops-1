//Glenn Parrreno
//geparreno@myseneca.ca
//115814196
//23-01-22

#include "Phone.h"
#include "cStrTools.h"

using namespace std;
using namespace sdds;

namespace sdds
{
	pInfo info[MAX_CONTACTS];
	void phoneDir(const char* programTitle, const char* fileName)
	{
		char toSearch[MAX_NAME_LEN];
		cout << programTitle << " phone direcotry search" << "\n";
		cout << "-------------------------------------------------------" << "\n";
		FILE* fp = fopen(fileName, "r");

		if (fp == NULL)
		{
			cout << fileName << " file not found!" << "\n";
			cout << "Thank you for using Broken Phone Book directory." << "\n";
		}
		else
		{
			do
			{
				cout << "Enter a partial name to search (no spaces) or enter '!' to exit" << "\n" << "> ";
				cin >> toSearch;
				if (strCmp(toSearch, "!") != 0)
				{
					searchName(toSearch, fileName);
				}

			} while (strCmp(toSearch, "!") > 0);

			fclose(fp);
			cout << "Thank you for using Star Wars directory." << "\n";
		}

	}

	void searchName(char* toSearch, const char* filename)
	{
		FILE* fp = NULL;
		fp = fopen(filename, "r");
		int i = 0;
		const char* found;
		char name1[MAX_NAME_LEN]/*toSearch*/, name2[MAX_NAME_LEN]/*name in contact*/;

		toLowerCaseAndCopy(name1, toSearch);
		//cout << name1;
		if (fp != NULL)
		{
			while (fscanf(fp, "%[^\t]\t%s\t%s\t%s\n", info[i].name, info[i].area, info[i].prefix, info[i].number) == 4)
			{
				i++;
			}
			fclose(fp);
		}

		for (i = 0; i < MAX_CONTACTS; i++)
		{
			toLowerCaseAndCopy(name2, info[i].name);
			found = strStr(name2, name1);
			if (found != nullptr)
			{
				cout << info[i].name << ":" << " (" << info[i].area << ") " << info[i].prefix << "-" << info[i].number << "\n";
			}
		}
		//cout << info[0].name;
	}
}