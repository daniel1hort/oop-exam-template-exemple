#include <iostream>
#include <string>
#include "Inregistrare.h"
#include "Hrana.h"
#include "Bautura.h"
#include "List.h"

using namespace std;

class PrintFunc : public Functor<Inregistrare> {
public:
	void operator()(Inregistrare* i) override {
		cout << i;
	}
};

class FindById : public Predicate<int, Inregistrare*> {
public:
	bool operator()(int id, Inregistrare* i) override {
		return i->id == id;
	}
};

int main() {
	Hrana* h = new Hrana();
	h->nume = "Shaorma";
	Bautura* b = new Bautura();
	b->nume = "Cola";
	Hrana* h1 = new Hrana();
	h1->nume = "Cora";

	List<Inregistrare>* list = new List<Inregistrare>();
	list->add(h);
	list->add(b);
	list->add(h1);
	list->execute(new PrintFunc());

	auto x = list->find<int>(2, new FindById());
	cout << "\n" << x << "\n";

	list->remove(x);
	list->execute(new PrintFunc());

	delete list;
	return 0;
}