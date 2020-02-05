#pragma once
#include <iostream>
#include <string>
#include "Inregistrare.h"
using namespace std;

class Hrana : public Inregistrare
{
public:
	string alimente;
	float gramaj;
	float calorii;
	float total_calorii() {
		return gramaj * calorii * 0.01;
	}

	Hrana() : Inregistrare() {

	}

	Hrana(string nume, string alimente, float gramaj, float calorii) : Inregistrare(nume) {
		this->alimente = alimente;
		this->calorii = calorii;
		this->gramaj = gramaj;
	}

	void print(ostream& out) override {
		out << nume << "\n";
	}
};

