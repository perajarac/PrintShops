#include "spil.h"

void Spil::kopiraj(const Spil& s)
{
	head = tail = nullptr;
	for (Elem* tek = s.head; tek; tek = tek->next)
		*this += tek->s;
}

void Spil::premesti(Spil& s)
{
	
		head = s.head; tail = s.tail;
		s.head = s.tail = nullptr;
}

void Spil::brisi()
{
	while (head) {
		Elem* temp = head;
		head = head->next;
		delete temp;
	}
}

bool Spil::proveriNijeKraj(int i) const
{
	Elem* temp = head;
	while (i > 0 && temp) {
		temp = temp->next;
		i--;
	}
	if (temp == nullptr) return false; 
	return true;
}

Slicica* Spil::vratiSlicicuSaP(int i) const
{
	Elem* temp = head;
	int br = 0;
	while (temp && br != i) {
		temp = temp->next;
		br++;
	}
	if (!temp) return nullptr;

	return &temp->s;
}

Spil& Spil::obrisiSlicicu(int i)
{
	if (!head) return *this;

	Elem* temp = head;
	Elem* curr = head->next;
	Elem* temp1;
	

	while (curr) {
		if (curr->s.dohvBroj() == i) {
			temp1 = curr;
			temp->next = curr->next;
			curr = curr->next;
			delete temp1;
		}
		else if (temp->s.dohvBroj() == i) {
			temp1 = temp;
			temp = temp->next;
			curr = curr->next;
			head = temp;
			delete temp1;
		}
		else {
			temp = curr;
			curr = curr->next;
		}
	}

	if (!curr) return *this;

	return *this;
}

Spil& Spil::pomeriTnaN(int i)
{
	if (!head) return *this;
	int br = 0;
	Elem* temp = head;
	Elem* curr1 = head->next;

	if (!curr1) return *this;

	Elem* curr2 = curr1->next;

	if (!curr2) {
		switch (i) {
		case 0:
			head->next = curr1->next;
			curr1->next = head;
			head = curr1;
			return *this;
		case 1:
			return *this;
		default: return *this;
		}
	}

	if (i == 0) {
		head->next = curr1->next;
		curr1->next = head;
		head = curr1;
		return *this;
	};

		while (curr2->next != nullptr && br < i - 1) {
			temp = curr1;
			curr1 = curr2;
			curr2 = curr2->next;
			br++;
		}

		if (curr2->next == nullptr && br != i-1) { return *this; }

		temp->next = curr2;
		curr1->next = curr2->next;
		curr2->next = curr1;
		return *this;
}


Spil& Spil::pomeriTnaP(int i)
{
	if (!head) return *this;
	int br = 0;
	Elem* temp = head;
	Elem* curr = head->next;

	while (curr && br < i - 1) {
		temp = curr;
		curr = curr->next;
		br++;
	}
	if (!curr)
		return *this;

	temp->next = curr->next;
	curr->next = head;
	head = curr;
	return *this;
}

Spil& Spil::operator+=(Slicica& sc)
{
	Elem* n = new Elem(sc);
	Elem* temp = head;
	if (!head) {
		head = n;
		return *this;
	}
	else {
		while (temp->next !=nullptr) {
			temp = temp->next;
		}
		temp ->next = n;
		tail = n;
		return *this;
	}
}

bool operator%(const Spil& spil, int i)
{
	Spil::Elem* temp = spil.head;

	while (temp) {
		if (temp->s.dohvBroj() == i) return true;
		temp = temp->next;
	}
	return false;
}

ostream& operator<<(ostream& it, const Spil& spil)
{
	Spil::Elem* tek = spil.head;
	while (tek) {
		it << tek->s;
		tek = tek->next;
	}
	return it;
}