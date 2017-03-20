//#pragma once

class Node {

public:
	double value;
	Node* next;

	Node(double v, Node* n);
	~Node();

};

class Poly {

public:
	Node* head;
	int length;

	Node* getHead();
	Poly();
	Poly(const Poly &p);
	void operator=(const Poly &p);
	void print();
	void append(double v);
	int getLength();
	~Poly();
};
