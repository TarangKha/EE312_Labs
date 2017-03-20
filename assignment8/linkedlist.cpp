#include <iostream>
using namespace std;

class LinkedList{

private:
    struct Node {
        int value;
        Node *next;
    };    // This Node is not used by the called function. 
	int listlength;
    Node *head; 

public:
    LinkedList(){
        head = NULL; 
		listlength = 0;
    }//constructor

	void addToListAtPosition(int position, int value){
		printf("Adding %d at Position %d \n",value,position);
		if (position < 0 || position > listlength + 1){
			printf("Invalid Position\n");
			return;
		}
		if (position == 0){
			addToHead(value);
			return;
		}
		if (position == listlength){
			appendToList(value);
			return;
		}
		int count = 0;
        Node *newNode = new Node();
        Node *n = head;
        Node *p = head;
		newNode->value = value;
		for (; count < position; count++){
			p = n;
			n = n->next;
		}
		Node *tmp = p->next;
		p->next = newNode;
		newNode->next = tmp;
		listlength++;
		return;
	}
	
	void addToHead(int value){
		printf("Adding %d at Head \n",value);
        Node *n = new Node();
        n->value = value;
		n->next = head;
		head = n;
		listlength++;
		return;
	}

	void appendToList(int value){
		printf("Adding %d at End \n",value);
        Node *n = new Node();
        Node *tmp = head;
		while (tmp->next != NULL){
			tmp = tmp->next;
		}
		tmp->next = n;
		n->value = value;
		n->next = NULL;
		listlength++;
		return;
	}
	
	void removeFromListAtPosition(int position){
		printf("Removing Node from Position %d \n",position);
		if (position < 0 || position > listlength + 1){
			printf("Invalid Position\n");
			return;
		}
		if (position == 0){
			removeFromHead();
			return;
		}
		if (position == listlength){
			removeFromEnd();
			return;
		} 
		int count = 0;
        Node *p = head;
        Node *n = head;
		for (; count < position; count++){
			p = n;
			n = n->next;
		}
		p->next = n->next;
		listlength--;
		return;
	}

	void removeFromHead(){
		printf("Removing Node from Head \n");
		if (listlength <= 0){
			printf("Nothing to remove - List is empty\n");
			return;
		}
		Node *n = head;
		head = n->next;
		listlength--;
		return;
	}

	void removeFromEnd(){
		printf("Removing Node from End \n");
		if (listlength <= 0){
			printf("Nothing to remove - List is empty\n");
			return;
		}

        Node *tmp = head;
		Node *p = head;
		while (tmp->next != NULL){
			p = tmp;
			tmp = tmp->next;
		}
		p->next = NULL;
		listlength--;
		return;
	}

	bool find(int value){
		printf("Finding %d \n", value);
        Node *tmp = head;
		while (tmp->next != NULL && tmp-> value != value){
			tmp = tmp->next;
		}
		if (tmp->value == value){
			return true;
		}
		else {
			return false;
		}
	}

	void reverseList(){
		printf("Reversing List \n");
		Node* n = head;
		Node *p = head;
		int count = listlength / 2; //if lislength is odd then the middle Node should stays as it is anyway.
		for (int i = 0; i < count; i++){
			p = n;
			for (int j = i; j < (listlength - i -1); j++){
				p = p->next;
			}
			int value = n->value;
			n->value = p->value;
			p->value = value;
			n = n->next;
		}
	}

	int getListLength(){
        return listlength;
	};

	Node* getHead(){
        Node *n = head;
        return n;
	};
	
	void printList(){
        Node *n = head;
		for(int count = 0; count <= listlength - 1;count++){
			printf("%d ", n->value);
			n = n->next;
		}
		printf("\n");
	}

};

