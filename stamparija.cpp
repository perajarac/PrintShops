#include "stamparija.h"


int Stamparija::brojRazlicitih() const
{
	return brEl;
}

Slicica* Stamparija::napraviSlicicu(int i)
{
	if (i > brEl-1) return nullptr;
	return new Slicica(i, niz[i]);
}