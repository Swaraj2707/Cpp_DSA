#include <bits/stdc++.h>
using namespace std;

class Node {  // this will act as Structure of Node.
public:
	int data;
	Node* next; // will store address of "next" node to whomesoever it will link 
};

void printList(Node* head) // function to print linked list
{
	Node* temp = head;  // "temp" pointer mai "head" node ka address daal diya

	while (temp != NULL) {
		cout << temp->data << " ";
		temp = temp->next;
	}
}

int main()
{
	Node* head = new Node();
	Node* second = new Node();
	Node* third = new Node();

	head->data = 1; 
	head->next = second; 

	second->data = 2;
	second->next = third;

	third->data = 3; 
	third->next = NULL;
	printList(head); // will print 1 2 3

	return 0;
}

