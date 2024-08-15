/*
Glenn Parrreno
geparreno@myseneca.ca
115814196
02-03-22
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#ifndef SDDS_NAME_H
#define SDDS_NAME_H

using namespace std;
namespace sdds
{
	class Name
	{
		char* fName = nullptr;
		char* mName = nullptr;
		char* lName = nullptr;
	public:
		//construction
		Name();
		Name(const char*);
		Name(const char*, const char*);
		Name(const char*, const char*, const char*);

		//rule of 3
		Name(const Name&);
		Name& operator=(const Name&);
		~Name();

		void setShort(bool);
		Name& operator+=(const char*);

		ostream& display(ostream&) const;
		istream& read(istream&);
		void alocpy(char*&, const char*);

		operator bool() const;
	};

	ostream& operator<<(ostream&, const Name&);
	istream& operator>>(istream&, Name&);
}
#endif // !SDDS_NAME_H
