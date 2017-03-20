//
//  main.cpp
//  Assignment 8
//
//  Created by Elie Antoun on 4/7/16.
//  Copyright © 2016 Elie Antoun. All rights reserved.
//

#include <stdio.h>
#include "linkedlist.cpp"
#include <cassert>

void test1(){
    int value = 5;
    int postion = 0;
    LinkedList l;
    l.addToListAtPosition(postion, value);
	l.printList();
    assert(l.getListLength() == 1);
    assert(l.getHead()->value == 5);
    printf("Test1 Passed!\n");
}

void test2(){
    int value = 10;
    int postion = 0;
    LinkedList l;
    l.addToListAtPosition(postion, value);
	l.printList();
    assert(l.getListLength() == 1);
    assert(l.getHead()->value == 10);
    printf("Test2 Passed!\n");
}

void test3(){
    int value = 2;
    LinkedList l;
    l.addToHead(value);
	l.printList();
    assert(l.getListLength() == 1);
    assert(l.getHead()->value == 2);
    printf("Test3 Passed!\n");

}

void test4(){
    LinkedList l;
    l.addToHead(1);
    l.addToHead(2);
	l.printList();
    assert(l.getListLength() == 2);
    assert(l.getHead()->value == 2);
    assert(l.getHead()->next->value == 1);
    printf("Test4 Passed!\n");
}

void test5(){
    LinkedList l;
    l.addToListAtPosition(0, 1);
    l.addToListAtPosition(1, 2);
	l.printList();
    assert(l.getListLength() == 2);
    assert(l.getHead()->value == 1);
    assert(l.getHead()->next->value == 2);
    printf("Test5 Passed!\n");
}

void test6(){
    LinkedList l;
    l.addToListAtPosition(0, 1);
    l.addToListAtPosition(1, 2);
	l.printList();
    assert(l.find(1) == true);
    assert(l.find(2) == true);
    printf("Test6 Passed!\n");
}

void test7(){
    LinkedList l;
    l.addToListAtPosition(0, 1);
    l.addToListAtPosition(1, 2);
	l.printList();
    l.removeFromListAtPosition(1);
	l.printList();
    assert(l.getHead()->value == 1);
    assert(l.getHead()->next == 0);
    printf("Test7 Passed!\n");

    
}

void test8(){
    LinkedList l;
    l.addToListAtPosition(0, 1);
    l.addToListAtPosition(1, 2);
	l.printList();
    l.removeFromListAtPosition(0);
	l.printList();
    assert(l.getHead()->value == 2);
    assert(l.getHead()->next == 0);
    printf("Test8 Passed!\n");

    
}

void test9(){
    LinkedList l;
    l.addToListAtPosition(0, 1);
    l.addToListAtPosition(1, 2);
	l.printList();
    l.removeFromHead();
	l.printList();
    assert(l.getHead()->value == 2);
    assert(l.getHead()->next == 0);
    printf("Test9 Passed!\n");

}

void test10(){
    LinkedList l;
    l.addToListAtPosition(0, 1);
    l.addToListAtPosition(1, 2);
	l.printList();
    l.removeFromEnd();
	l.printList();
    assert(l.getHead()->value == 1);
    assert(l.getHead()->next == 0);
    printf("Test10 Passed!\n");

}


void test11(){
    LinkedList l;
    l.addToListAtPosition(0, 1);
    l.addToListAtPosition(1, 2);
	l.printList();
    l.reverseList();
	l.printList();
    assert(l.getHead()->value == 2);
    assert(l.getHead()->next->value == 1);
    printf("Test11 Passed!\n");
}

void test12(){
    LinkedList l;
	l.printList();
    l.removeFromHead();
    assert(l.getHead() == NULL);
    l.removeFromEnd();
    assert(l.getHead() == NULL);
    l.removeFromListAtPosition(0);
    assert(l.getHead() == NULL);
    l.reverseList();
    assert(l.getHead() == NULL);
    printf("Test12 Passed!\n");
}

void test13(){
    LinkedList l;
    l.addToHead(1);
    l.addToHead(2);
    l.addToHead(3);
    l.addToHead(4);
    l.addToHead(5);
	assert(l.getHead()->value == 5);
	assert(l.getHead()->next->value == 4);
	assert(l.getHead()->next->next->value == 3);
	assert(l.getHead()->next->next->next->value == 2);
	assert(l.getHead()->next->next->next->next->value == 1);
	l.printList();
	l.reverseList();
	assert(l.getHead()->value == 1);
	assert(l.getHead()->next->value == 2);
	assert(l.getHead()->next->next->value == 3);
	assert(l.getHead()->next->next->next->value == 4);
	assert(l.getHead()->next->next->next->next->value == 5);
	l.printList();
    printf("Test13 Passed!\n");
}

void test14(){
    LinkedList l;
    l.addToHead(1);
    l.addToHead(2);
    l.addToHead(3);
    l.addToHead(4);
    l.addToHead(5);
    l.addToHead(6);
	assert(l.getHead()->value == 6);
	assert(l.getHead()->next->value == 5);
	assert(l.getHead()->next->next->value == 4);
	assert(l.getHead()->next->next->next->value == 3);
	assert(l.getHead()->next->next->next->next->value == 2);
	assert(l.getHead()->next->next->next->next->next->value == 1);
	l.printList();
	l.reverseList();
	assert(l.getHead()->value == 1);
	assert(l.getHead()->next->value == 2);
	assert(l.getHead()->next->next->value == 3);
	assert(l.getHead()->next->next->next->value == 4);
	assert(l.getHead()->next->next->next->next->value == 5);
	assert(l.getHead()->next->next->next->next->next->value == 6);
	l.printList();
    printf("Test14 Passed!\n");
}

void test15(){
    LinkedList l;
    l.addToHead(1);
    l.addToHead(2);
    l.addToHead(3);
    l.addToHead(4);
    l.addToHead(5);
    l.addToHead(6);
	assert(l.getHead()->value == 6);
	assert(l.getHead()->next->value == 5);
	assert(l.getHead()->next->next->value == 4);
	assert(l.getHead()->next->next->next->value == 3);
	assert(l.getHead()->next->next->next->next->value == 2);
	assert(l.getHead()->next->next->next->next->next->value == 1);
	assert(l.getListLength() == 6);
	l.printList();
    l.addToListAtPosition(3, 9);
	assert(l.getHead()->value == 6);
	assert(l.getHead()->next->value == 5);
	assert(l.getHead()->next->next->value == 4);
	assert(l.getHead()->next->next->next->value == 9);
	assert(l.getHead()->next->next->next->next->value == 3);
	assert(l.getHead()->next->next->next->next->next->value == 2);
	assert(l.getHead()->next->next->next->next->next->next->value == 1);
	assert(l.getListLength() == 7);
	assert(l.find(9) == true);
	l.printList();
	l.removeFromListAtPosition(3);
	assert(l.getHead()->value == 6);
	assert(l.getHead()->next->value == 5);
	assert(l.getHead()->next->next->value == 4);
	assert(l.getHead()->next->next->next->value == 3);
	assert(l.getHead()->next->next->next->next->value == 2);
	assert(l.getHead()->next->next->next->next->next->value == 1);
	assert(l.getListLength() == 6);
	assert(l.find(9) == false);
	l.printList();
    printf("Test15 Passed!\n");
}


int main(){
    
    test1();
    test2();
    test3();
    test4();
    test5();
    test6();
    test7();
    test8();
    test9();
    test10();
    test11();
    test12();
    test13();
    test14();
    test15();
    
}