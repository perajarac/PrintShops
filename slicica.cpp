#include "slicica.h"

int Slicica::dohvBroj() const
{
	return broj;
}

string Slicica::dohvNaziv() const
{
	return naziv;
}

int Slicica::dohvId() const{

	return identifikator;
}

int Slicica::ID = 1;

ostream& operator<<(ostream& it, Slicica& s)
{
	it << "Slicica" << s.dohvBroj() << "-" << s.dohvNaziv() << "(" << s.dohvId() << ")" << endl;
	return it;
}