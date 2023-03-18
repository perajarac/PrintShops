#ifndef _slicica_h_
#define _slicica_h_
#include <iostream>
#include <string>
using namespace std;

class Slicica {
	int broj;
	string naziv;
	static int ID;
	int identifikator = ID;
	 
	Slicica(int b, string n) : broj(b), naziv(n) { ID++; }

public:

	Slicica(const Slicica&) = delete;

	int dohvBroj() const;
	string dohvNaziv() const;
	int dohvId() const;

	friend class Stamparija;
	friend ostream& operator<<(ostream& it, Slicica& s);
};
#endif