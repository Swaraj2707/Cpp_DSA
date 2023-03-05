/*
For a given singly linked list of integers, arrange the elements such that all the even numbers are placed 
after the odd numbers. The relative order of the odd and even terms should remain unchanged.
Note :
No need to print the list, it has already been taken care. Only return the new head to the list.

Input format:
The first line contains an Integer 't' which denotes the number of test cases or queries to be run.
 Then the test cases follow.

The first line of each test case or query contains the elements of the singly linked list separated
 by a single space. 

 Remember/Consider :
While specifying the list elements for input, -1 indicates the end of the singly linked list and hence,
would never be a list element

Output format:
For each test case/query, print the elements of the updated singly linked list.

Output for every test case will be printed in a seperate line.
Constraints :
1 <= t <= 10^2
0 <= M <= 10^5
Where M is the size of the singly linked list.

Time Limit: 1sec
Sample Input 1 :
1
1 4 5 2 -1
Sample Output 1 :
1 5 4 2 

Sample Input 2 :
2
1 11 3 6 8 0 9 -1
10 20 30 40 -1
Sample Output 2 :
1 11 3 9 6 8 0
10 20 30 40
*/

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

Node *evenAfterOdd(Node *head)
{
	//write your code here
	if(head==NULL || head->next ==NULL)
        return head ;
    
	Node* oddh =NULL ;  //oddh means odd Head
    Node* evenh = NULL ;
    Node* oddt = NULL ; //oddt means odd tail
    Node* event = NULL ;
    
    while(head!=NULL)
    {
        //even
        if(head->data %2 == 0)
        {
            if(evenh == NULL)
            {
                evenh =head ;
                event = head ;
                head=head->next ;
            }
            else
            {
                event->next = head ;
                event =head ;
                head=head->next ;
            }
        }
        else
        {
            //odd 
             if(oddh == NULL)
            {
                oddh =head ;
                oddt = head ;
                head=head->next ;
            }
            else
            {
                oddt->next = head ;
                oddt = head ;
                head=head->next ;
            }
        }
        
    }
    if(event!=NULL)
    {
        event->next = NULL;
    	
    }
    else
    {
        oddt->next =NULL ;
        return oddh ;
    }
    if(oddt!=NULL)
    {
        oddt->next =evenh ;
        return oddh;
    }
    else
    {
        return evenh ;
    }
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
    Node *head = takeinput();
	head = evenAfterOdd(head);
	print(head);
}