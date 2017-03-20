#include "functions.hh"
//#include "polynomial.hh"
#include <stdio.h>

Poly addPolynomials(Poly p1, Poly p2) {
	Poly p;
	Node* temp1 = p1.getHead();
	Node* temp2 = p2.getHead();
	int p1length = p1.getLength();
	int p2length = p2.getLength();
	if (p1length == 0 || p2length == 0) {
		if (p1length == 0 && p2length == 0) {
			printf("\n Both Polynomials are enpty");
			return p;
		}
		if (p1length == 0) {
			return p2;
		}
		if (p2length == 0) {
			return p1;
		}
	}
	if (p1length == p2length) {
		while (temp1 != 0) {
			p.append(temp1->value + temp2->value);
			temp1 = temp1->next;
			temp2 = temp2->next;
		}
	}
	else {
		if (p1length > p2length) {
			while (p1length > p2length) {
				p.append(temp1->value);
				temp1 = temp1->next;
				p1length--;
			}
			while (temp1 != 0) {
				p.append(temp1->value + temp2->value);
				temp1 = temp1->next;
				temp2 = temp2->next;
			}
		}
		else {
			while (p2length > p1length) {
				p.append(temp2->value);
				temp2 = temp2->next;
				p2length--;
			}
			while (temp2 != 0) {
				p.append(temp2->value + temp1->value);
				temp2 = temp2->next;
				temp1 = temp1->next;
			}
		}
	}
	p = removeLeadingZeros(p);
	return p;
}

Poly subtractPolynomials(Poly p1, Poly p2) {
	Poly p2temp;
	Node* temp2 = p2.getHead();
	while (temp2 != 0) {
		p2temp.append(temp2->value * (-1));
		temp2 = temp2->next;
	}
	Poly p = addPolynomials(p1, p2temp);
	return p;
}

Poly multiplyPolynomials(Poly p1, Poly p2) {
	Poly p;
	int p1Degree = p1.getLength() - 1;
	int p2Degree = p2.getLength() - 1;
	if (p1Degree == -1 || p2Degree == -1) {
		if (p1Degree == -1 && p2Degree == -1) {
			printf("\n Both Polynomials are enpty");
			return p;
		}
		printf("\n Atleast one Polynomial is enpty");
		if (p1Degree == -1) {
			return p2;
		}
		else {
			return p1;
		}
	}

	int totDegree = p1Degree + p2Degree;
	int i = totDegree;
	while (i >= 0) {
		p.append(1);
		i--;
	}
	Node* pHead = p.getHead();
	Node* temp = pHead;
	while (temp != 0) {
		temp->value = 0;
		temp = temp->next;
	}
	temp = pHead;
	Node* p1Head = p1.getHead();
	Node* temp1 = 0;
	Node* p2Head = p2.getHead();
	Node* temp2 = 0;
	int i1 = 0;
	int i2 = 0;
	if (p1Degree >= p2Degree) {
		i1 = p1Degree;
		temp1 = p1Head;
		i2 = p2Degree;
		temp2 = p2Head;
	}
	else {
		i1 = p2Degree;
		temp1 = p2Head;
		i2 = p1Degree;
		temp2 = p1Head;
	}
	while (i1 >= 0) {
		if (p1Degree >= p2Degree) {
			i2 = p2Degree;
			temp2 = p2Head;
		}
		else {
			i2 = p1Degree;
			temp2 = p1Head;
		}
		while (i2 >= 0) {
			temp = pHead;
			for (int j = totDegree; (j > (i1 + i2)); j--) {
				temp = temp->next;
			}
			temp->value = temp->value + temp1->value * temp2->value;
			i2--;
			temp2 = temp2->next;
		}

		i1--;
		temp1 = temp1->next;
	}
	p = removeLeadingZeros(p);
	return p;
}

Poly removeLeadingZeros(Poly p) {
	Node* temp = p.getHead();
	int pLength = p.getLength();
	while (temp != 0 && temp->value == 0 && pLength > 1) {
		Node* delNode = temp;
		p.head = temp->next;
		temp = temp->next;
		delete delNode;
		pLength--;
		p.length--;
	}
	return p;
}