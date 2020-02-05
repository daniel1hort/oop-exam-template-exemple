#pragma once
#include <iostream>
#include <string>
using namespace std;

template <class T>
class Functor {
public:
	virtual void operator ()(T*) = 0;
};

template <class T1, class T2>
class Predicate {
public:
	virtual bool operator()(T1, T2) = 0;
};

template <class T>
class List
{
public:
	List<T>* tail;
	T* head;

	List() {
		tail = nullptr;
		head = nullptr;
	}
	List(T* obj) {
		head = obj;
		tail = nullptr;
	}

	~List() {
		delete tail;
		delete head;
		tail = nullptr;
		head = nullptr;
	}

	void add(T* obj) {
		List<T>* q;
		if (head == nullptr) head = obj;
		else {
			for (q = this; q->tail != nullptr; q = q->tail);
			q->tail = new List<T>(obj);
		}
	}

	void execute(Functor<T>* func) {
		(*func)(head);
		if (tail != nullptr) tail->execute(func);
		else delete func;
	}

	template<class Y>
	T* find(Y obj, Predicate<Y, T*>* pred) {
		if ((*pred)(obj, head)) return head;
		else if(tail != nullptr) return tail->find(obj, pred);
	}

	List<T>* remove(T* obj) {
		List<T>* q;
		List<T>* a;
		if (head == obj) {
			return tail;
		}
		else {
			for (q = this; q->tail != nullptr; q = q->tail)
				if (q->tail->head == obj) {
					a = q->tail;
					q->tail = a->tail;
					a->tail = nullptr;
					delete a;
					return this;
				}
		}
		return this;
	}
};

