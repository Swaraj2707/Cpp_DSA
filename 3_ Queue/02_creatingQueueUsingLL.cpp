#include<bits/stdc++.h>
using namespace std;

class Node {
   public:
    int data;
    Node *next;

    Node(int data) {
        this->data = data;
        next = NULL;
    }
};

class Queue {
	// Define the data members
   private:
   Node* head;
   Node* tail;
   int size;
   
   public:
    Queue() {
		// Implement the Constructor
		head = NULL;
		tail = NULL;
        size = 0;
	}
	
	/*----------------- Public Functions of Stack -----------------*/

	int getSize() {
        //It returns the size of the queue at any given instance of time.
		return this->size;
	}

    bool isEmpty() {
		// return if queue is empty or NOT
		return size == 0;
	}

    void enqueue(int data) {
        /*
        This function should take one argument of type integer. 
        It enqueues the element into the queue and returns nothing.
        */
		
		Node *newNode = new Node (data);

		if(head == NULL) {
			head = newNode;
			tail = newNode;
		}
		else {
			tail -> next = newNode;
			tail = newNode;
		}

		size++;
	}

    int dequeue() {
        /*
        It dequeues/removes the element from the front of the queue and in turn, 
        returns the element being dequeued or removed. In case the queue is empty, it returns -1.
        */

		if(isEmpty()) 
			 return -1;

		int ans = head -> data;
		Node *temp = head;
		head = head -> next;
		delete temp;

		size--;
		return ans;
    }

    int front() {
        /*
        It returns the element being kept at the front of the queue. In case the queue is empty, it returns -1.
        */

		if(head == NULL)
			return -1;

		return head->data;
    }
};

int main() {
    Queue q;

    int t;
    cin >> t;

    while (t--) {
        int choice, input;
        cin >> choice;
        switch (choice) {
            case 1:
                cin >> input;
                q.enqueue(input);
                break;
            case 2:
                cout << q.dequeue() << "\n";
                break;
            case 3:
                cout << q.front() << "\n";
                break;
            case 4:
                cout << q.getSize() << "\n";
                break;
            default:
                cout << ((q.isEmpty()) ? "true\n" : "false\n");
                break;
        }
    }
}