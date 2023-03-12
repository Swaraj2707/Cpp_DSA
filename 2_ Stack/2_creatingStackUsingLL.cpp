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

class Stack {
	// Define the data members
    private:
        Node* head ;
        int size;

   public:
    Stack() {
        // Implement the Constructor
        head = NULL;
        this->size = 0;
    }

	/*----------------- Public Functions of Stack -----------------*/

    int getSize() {
        // Implement the getSize() function
        return this->size;
    }

    bool isEmpty() {
        // Implement the isEmpty() function
        if(size == 0)
            return true;
        else
            return false;
    }

    void push(int element) {
        // Implement the push() function
        Node* newNode = new Node (element);
        newNode->next = head;
        head = newNode;
        size++;
    }

    int pop() {
        // Implement the pop() function
        if(head == NULL)
            return -1;

        int temp = head->data;
        head = head->next;
        size--;
        return temp;
    }

    int top() {
        // Implement the top() function
        if(head == NULL)
            return -1;
            
        return head->data;
    }
};


int main()
{
    Stack st;

    int q;
    cin >> q;

    while (q--) {
        int choice, input;
        cin >> choice;
        switch (choice) {
            case 1:
                cin >> input;
                st.push(input);
                break;
            case 2:
                cout << st.pop() << "\n";
                break;
            case 3:
                cout << st.top() << "\n";
                break;
            case 4:
                cout << st.getSize() << "\n";
                break;
            default:
                cout << ((st.isEmpty()) ? "true\n" : "false\n");
                break;
        }
    }
}