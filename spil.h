#ifndef _spil_h_
#define _spil_h_
#include <iostream>
#include "slicica.h"
using namespace std;
#include <string>
#include "stamparija.h"

class Spil {
private:
	struct Elem {
		Slicica& s;
		Elem* next;
		Elem(Slicica& i) : s(i), next(nullptr){}
	};
	Elem* head = nullptr;
	Elem* tail = nullptr;

	void kopiraj(const Spil& s);
	void premesti(Spil& s);
	void brisi();

public:
	Spil() = default;
	Spil(const Spil& s) = delete;
	Spil& operator=(const Spil&) = delete;
	~Spil() { brisi(); }

	bool proveriNijeKraj(int i) const;
	Slicica* vratiSlicicuSaP(int i) const;
	Spil& obrisiSlicicu(int i);

	Spil& pomeriTnaN(int i);
	Spil& pomeriTnaP(int i);

	Spil& operator+=(Slicica& s);
	friend bool operator%(const Spil& spil, int i);
	friend ostream& operator<<(ostream& it, const Spil& spil);
	
};

#endif