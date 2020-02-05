#pragma once
#include <iostream>
#include <string>
#include "Inregistrare.h"
using namespace std;

class Bautura : public Inregistrare
{
public:
	bool bule;
	float zahar;
	float cantitate;

	Bautura() : Inregistrare() {

	}

	Bautura(string nume, bool bule, float zahar, float cantitate) : Inregistrare(nume) {
		this->bule = bule;
		this->zahar = zahar;
		this->cantitate = cantitate;
	}

	void print(ostream& out) override {
		out << nume << "\n";
	}
};

