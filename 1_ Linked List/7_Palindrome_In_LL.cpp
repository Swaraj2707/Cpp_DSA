#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
        Node* next;

        Node(int d){
            data = d;
            next = NULL;
        }
};

Node* reverseLL(Node* head){ //DSA-one Video no.37
    Node* curr = head;
    Node* prev = NULL;

    while(curr != NULL){
        Node* temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
    }

    return prev;
}

Node* middle(Node* head) // DSA one video no.38
{
    Node *fast = head;
    Node* slow = head;

    while(fast!=NULL && fast->next!=NULL){
        	
           fast = fast->next;

            if(fast->next != NULL){
                slow = slow->next;
                fast = fast->next;
            }
   }

    return slow;
}

bool palindrome(Node* head)
{
    if(head == NULL)
    {
        return true;
    }

    Node* mid = middle(head);
    Node* last = reverseLL(mid);
    Node* curr = head;

    while(last != NULL)
    {
        if(last->data != curr->data)
        {
            return false;
        }

        curr = curr->next;
        last = last->next;
    }

    return true;
}
void printList(Node* head){
    Node* temp = head;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

int main()
{
    Node* head = new Node(10);
    Node* second = new Node(20);
    Node* third = new Node(30);
    Node* fourth = new Node(40);

    head->next = second;
    second->next = third;
    third->next = fourth;

    int ans = palindrome(head);
    if(ans)
        cout<<"true";
    else
        cout<<"false";

}