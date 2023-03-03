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

Node *mergeTwoSortedLinkedLists(Node *head1, Node *head2)
{
    //Write your code here
	    Node *fh=NULL, *ft=NULL; //fh means final head and ft means fianl tail.

        if(head1 == NULL) {
            return head2;
        }

        if(head2 == NULL) {
            return head1;
        }

    while(head1!=NULL && head2!=NULL){
        
        if(fh== NULL && ft==NULL)
        {

            if(head1->data > head2->data)
            {
                fh=head2;
                ft=head2;
                head2=head2->next;
            }
			else
            {
                fh=head1;
                ft=head1;
                head1=head1->next;
            }

        }
		else
        {
            
            if(head1->data < head2->data)
            {
                ft->next=head1;
                ft=ft->next;
                head1=head1->next;

            }
		    else 
            {
                ft->next=head2;
                ft=ft->next;
                head2=head2->next;
            }   
        }
        
    }
    
    if(head1 != NULL){
        ft->next=head1;
    }

    if(head2 != NULL){
        ft->next=head2;
    }
    
    return fh;
}

Node *takeinput() //taking input LL from user
{
	int data;
	cin >> data;
	Node *head = NULL, *tail = NULL;

	while (data != -1)
	{
		Node *newNode = new Node(data);
		if (head == NULL)
		{
			head = newNode;
			tail = newNode;
		}
		else
		{
			tail->next = newNode;
			tail = newNode;
		}
		cin >> data;
	}
	return head;
}

void print(Node *head) // print LL
{
	Node *temp = head;
	while (temp != NULL)
	{
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << endl;
}

int main()
{

		Node *head1 = takeinput(); // input : 2 5 3 -1
		Node *head2 = takeinput(); // input : 1 6 4 8 -1
		Node *head3 = mergeTwoSortedLinkedLists(head1, head2); // this will have '1'
		print(head3); // op: 1 2 5 3 6 4 8 
	
	


}