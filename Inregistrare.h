#pragma once
#include <iostream>
#include <string>
using namespace std;

struct DateTime{
	int an, luna, zi, ora, minut;
};

class Inregistrare
{
public:
	int id;
	string nume;
	DateTime cand;

	Inregistrare() {
		static int _id = 0;
		id = ++_id;
	}

	Inregistrare(string nume) {
		static int _id = 0;
		id = ++_id;
		this->nume = nume;
	}

	virtual void print(ostream&) = 0;

	friend istream& operator >>(istream& in, Inregistrare* h) {
		return in;
	}

	friend ostream& operator <<(ostream& out, Inregistrare* h) {
		h->print(out);
		return out;
	}
};
