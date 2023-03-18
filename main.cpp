#include <iostream>
#include "slicica.h"
#include "stamparija.h"
#include "spil.h"
using namespace std;

int main() {
	string niz[] = {"Pera", "Mika", "Laza", "Mare", "Dzoni"};
	Stamparija s(niz, 5);

	cout << "TEST:" << endl;

	cout << "Funckija koja proverava broj razlicitih slicica: " << s.brojRazlicitih() << endl << endl;

	Slicica* c = s.napraviSlicicu(1);
	Slicica* c1 = s.napraviSlicicu(3);
	Slicica* c2 = s.napraviSlicicu(2);
	Slicica* c3 = s.napraviSlicicu(0);
	Slicica* c4 = s.napraviSlicicu(4);


	Slicica* temp1;           //Ispitivanje da li pravi slicicu ako je dat nevalidan indeks
	if ((temp1 = s.napraviSlicicu(5))) {
		cout << *temp1 << endl;
	}
	else cout << "Vracena je nula, jer slicica sa zadatim brojem ne postoji" << endl << endl;
	
	cout << "Provera funkcionalnosti klase slicica: " << *c << endl;  //ispis slicice sadrzi sve trazene 'Geter funckije'
	Spil spil;
	spil += *c2;
	spil += *c2;
	spil += *c2;
	spil += *c2;
	spil += *c2;
	spil += *c1;
	spil += *c;
	spil += *c1;
	spil += *c3;
	spil += *c1;
	spil += *c4;

	cout << "Provera ispisa klase spil i operatora +=: " << endl <<  spil << endl;

	cout<< "Provera da li je slicica za zadatim indeksom(desni operand) u spilu, 0 je FALSE, 1 je TRUE: " << "ne postoji sa brojem 5: " << (spil % 5) << " ,postoji sa brojem 1: " << (spil % 1) << endl << endl;

	cout << "Provera da li brise slicicu sa brojem 2 i 3(2 je edge case jer je pocetak niza): " << endl;
	spil.obrisiSlicicu(2);
	spil.obrisiSlicicu(3);
	cout << spil << endl;

	spil += *c2;
	spil += *c1;
	spil += *c;

	int vratiInalazi = 5; // provera da li se na poziciji nalazi slicica
	Slicica* temp2;
	cout << "Provera da li na indeksu 1 nalazi element i dohvatanje sa tog mesta: ";
	if ((temp2 = spil.vratiSlicicuSaP(vratiInalazi))) cout << *temp2 << endl;
	else cout << "Doslo se do kraja spila";

	cout << "Pomeranje karte sa indeksom 4 na sledece mesto u spilu: " << endl;
	cout << "Spil pre pomeranja: " << endl << endl;
	cout << spil << endl;
	spil.pomeriTnaN(4); //karta sa indeksom 4 se pomera na kartu sa indeksom 5
	cout << "Spil posle pomeranja i pre stavljanja elementa sa indeksom 3 na vrh: " << endl << endl;
	cout << spil << endl;

	cout << "Stavljanje karte sa zadatim indeksom na vrh spila:" << endl << endl; 
	spil.pomeriTnaP(3); //karta sa indeksom 3 se pomera na vrh
	cout << spil << endl << endl << "KRAJ TESTA" << endl;
}