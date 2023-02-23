#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* next;

        Node(int d){ // parameterised constructor
            data = d;
            next = NULL;
        }
};

Node* insertAtStart(Node* head){
    Node* new_node = new Node(50);
    new_node->next = head;
    return new_node;     // since return type is "Node*"
}


void printList(Node* head){
    Node* temp = head;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

int main(){
    Node* head = new Node(10);
    Node* second = new Node(20);
    Node* third = new Node(30);
    Node* fourth = new Node(40);

    head->next = second;
    second->next = third;
    third->next = fourth;

    head = insertAtStart(head);   

    printList(head);

}
