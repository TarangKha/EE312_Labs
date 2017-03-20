//#include "polynomial.cpp"
//#include "functions.cpp"

#include "functions.hh"
#include <stdio.h>
#include <cassert>


void test00(){
	Poly p1;
	Poly p2;
	p1.append(0);
	p1.append(1);
	p1.append(2);
	p2.append(3);

	printf("\n 0 1 2 + 3");
	Poly result = addPolynomials(p1, p2);
	result.print();
	assert(result.getHead()->value ==1);
	assert(result.getHead()->next->value == 5);
}

void test01(){
	Poly p1;
	Poly p2;

	p1.append(1);
	p1.append(2);
	p2.append(3);

	printf("\n 1 2 - 3");
	Poly result = subtractPolynomials(p1, p2);
	result.print();
	assert(result.getHead()->value ==1);
	assert(result.getHead()->next->value == -1);
}

void test02(){
	Poly p1;
	Poly p2;
	p1.append(1);
	p1.append(2);
	p2.append(3);

	Poly result = multiplyPolynomials(p1, p2);
	printf("\n 1 2 * 3");
	result.print();
	assert(result.getHead()->value ==3);
	assert(result.getHead()->next->value == 6);
}

void test03(){
	Poly p1;
	Poly p2;
	p1.append(1);
	p2.append(1);
	printf("\n 1 + 1");
	Poly result = addPolynomials(p1, p2);
	result.print();
	assert(result.getHead()->value == 2);
	Poly p3;
	p3.append(2);
	printf("\n 1 + 2");
	result = addPolynomials(p1, p3);
	result.print();
	assert(result.getHead()->value == 3);
}
void test04() {
	Poly p1;
	Poly p2;
	p1.append(0);
	p1.append(1);
	p1.append(2);
	p1.append(3);
	p1.append(4);
	p2.append(0);
	p2.append(4);
	p2.append(0);
	p2.append(6); 

	printf("\n 0 1 2 3 4 * 0 4 0 6");
	Poly result = multiplyPolynomials(p1, p2);
	result.print();
}

void test05() {
	Poly p1;
	Poly p2;
	p1.append(0);
	p1.append(1);
	p1.append(0);
	p2.append(0);
	p2.append(2);
	p2.append(0);
	p2.append(0);

	printf("\n 0 1 0 * 0 2 0 0");
	Poly result = multiplyPolynomials(p1, p2);
	result.print();
}

void test06() {
	Poly p1;
	Poly p2;
	p1.append(-1);
	p2.append(1);

	printf("\n -1 * 1");
	Poly result = multiplyPolynomials(p1, p2);
	result.print();
	printf("\n -1 + 1");
	result = addPolynomials(p1, p2);
	result.print();
	printf("\n -1 - 1");
	result = subtractPolynomials(p1, p2);
	result.print();
	printf("\n 1 - -1");
	result = subtractPolynomials(p2, p1);
	result.print();
}


void test07() {
	Poly p1;
	Poly p2;
	p1.append(1);

	printf("\n 1 * empty");
	Poly result = multiplyPolynomials(p1, p2);
	result.print();
	printf("\n 1 + empty");
	result = addPolynomials(p1, p2);
	result.print();
	printf("\n empty  + 1");
	result = addPolynomials(p2, p1);
	result.print();
	printf("\n 1 - empty");
	result = subtractPolynomials(p1, p2);
	result.print();
	printf("\n empty  - 1");
	result = subtractPolynomials(p2, p1);
	result.print();

}

void test08() {
	Poly p1;
	Poly p2;

	printf("\n empty * empty");
	Poly result = multiplyPolynomials(p1, p2);
	result.print();
	printf("\n empty + empty");
	result = addPolynomials(p2, p1);
	result.print();
	printf("\n empty - empty");
	result = subtractPolynomials(p1, p2);
	result.print();
	printf("\n empty - empty");
	result = subtractPolynomials(p2, p1);
	result.print();
}
void test09() {
	Poly p1;
	Poly p2;
	p1.append(-3.24);
	p2.append(4.26);
	p2.append(2.14);

	printf("\n -3.24 * 4.26 2.14");
	Poly result = multiplyPolynomials(p1, p2);
	result.print();
	printf("\n -3.24 + 4.26 2.14");
	result = addPolynomials(p1, p2);
	result.print();
	printf("\n -3.24 - 4.26 2.14");
	result = subtractPolynomials(p1, p2);
	result.print();
	printf("\n 4.26 2.14 - -3.24");
	result = subtractPolynomials(p2, p1);
	result.print();
}

void test10() {
	Poly p1;
	Poly p2;
	p1.append(1);
	p1.append(2);
	p2.append(1);
	p2.append(2);

	printf("\n 1 2 * 1 2 ");
	Poly result = multiplyPolynomials(p1, p2);
	result.print();
	printf("\n 1 2 + 1 2 ");
	result = addPolynomials(p1, p2);
	result.print();
	printf("\n 1 2 - 1 2 ");
	result = subtractPolynomials(p1, p2);
	result.print();
	printf("\n 1 2 - 1 2 ");
	result = subtractPolynomials(p2, p1);
	result.print();
}

void test11() {
	Poly p1;
	Poly p2;
	p1.append(1);
	p2.append(0);

	printf("\n 1 * 0");
	Poly result = multiplyPolynomials(p1, p2);
	result.print();
	printf("\n 1 + 0");
	result = addPolynomials(p1, p2);
	result.print();
	printf("\n 0  + 1");
	result = addPolynomials(p2, p1);
	result.print();
	printf("\n 1 - 0");
	result = subtractPolynomials(p1, p2);
	result.print();
	printf("\n 0  - 1");
	result = subtractPolynomials(p2, p1);
	result.print();
}

int main(){
	test00();
	test01();
	test02();
	test03();
	test04();
	test05();
	test06();
	test07();
	test08();
	test09();
	test10();
	test11();
}