#ifndef _stamparija_h_
#define _stamparija_h_
#include <iostream>
#include "slicica.h"
class Stamparija {
private:
	string* niz;
	int brEl;
public:

	//friend class Slicica;

	Stamparija(string n[], int bE) : niz(n), brEl(bE) {}
	Stamparija(const Stamparija&) = delete;

	Slicica* napraviSlicicu(int i);
	
	int brojRazlicitih() const; //vraca broj razlicitih slicica u nizu

	//friend ostream& operator<<(ostream& os, const Stamparija& s) {
	//	for (int i = 0; i < s.brEl; i++) {
	//		if (i < s.brEl - 1) {
	//			os << s.niz[i] << ",";
	//		}
	//		else os << s.niz[i];
	//	}
	//	return os;
	//}                                 NAPISANO ZA POTREBE PROVERE PRAVILNOSTI KONSTUKTORA STAMPARIJE


};

#endif