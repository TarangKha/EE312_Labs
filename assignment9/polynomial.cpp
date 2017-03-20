#include "polynomial.hh"
#include <stdio.h>


Node::Node(double v, Node* n){
	this->value = v;
	this->next = n;
}

Node::~Node(){
}

Node* Poly::getHead(){
	return head;
}

Poly::Poly(){
	head = NULL;
	length = 0;
}

Poly::Poly(const Poly &p) {
	head = p.head;
	length = p.length;
//	return;
	head = 0;
	Node* temp = p.head;
	Node* temp2 = 0;
	int firstTime = 0;
	while (temp != 0) {
		if (firstTime == 0) {
			temp2 = new Node(temp->value, 0);
			head = temp2;
			firstTime = 1;
		}
		else {
			temp2->next = new Node(temp->value, 0);
			temp2 = temp2->next;
		}
//		length++;
		temp = temp->next;
	}
}
void Poly::operator=(const Poly &p) {
	head = p.head;
	length = p.length;
//	return;
	head = 0;
	Node* temp = p.head;
	Node* temp2 = 0;
	int firstTime = 0;
	while (temp != 0) {
		if (firstTime == 0) {
			temp2 = new Node(temp->value, 0);
			head = temp2;
			firstTime = 1;
		}
		else {
			temp2->next = new Node(temp->value, 0);
			temp2 = temp2->next;
		}
		temp = temp->next;
	}
}

Poly::~Poly() {
	Node* temp = getHead();

	while (temp != 0) {
		Node* delNode = temp;
		temp = temp->next;
		delete delNode;
	}

}

void Poly::append(double v){
	Node* temp = getHead();
	Node* prev = temp;
	Node* newNode = new Node(v, 0);
	this->length++;
	if (temp == NULL) {
		head = newNode;
		return;
	}
	while(temp != 0) {
		prev = temp;
		temp = temp->next;
	}
	prev->next = newNode;
	return;
}

void Poly::print(){
	Node* temp = getHead();
	printf("\n");
	while(temp!=0){
		printf("%.2f ", temp->value);
		temp = temp->next;
	}
}

int Poly::getLength() {
	int listlength = 0;
	Node* temp = getHead();
	while (temp != 0) {
		listlength++;
		temp = temp->next;
	}
	return listlength;
}
