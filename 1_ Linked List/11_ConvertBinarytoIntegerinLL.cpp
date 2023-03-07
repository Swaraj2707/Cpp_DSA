/* Leetcode 1290 Convert Binary Number in a Linked List to Integer
Given head which is a reference node to a singly-linked list. 
The value of each node in the linked list is either 0 or 1. 
The linked list holds the binary representation of a number.

Return the decimal value of the number in the linked list.

The most significant bit is at the head of the linked list.

 

Example 1:

Input: head = [1,0,1]
Output: 5
Explanation: (101) in base 2 = (5) in base 10
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

    Node* reverse(Node* head) {
        Node* current = head; 
        Node *prev = NULL, *next = NULL; 
        
          while (current != NULL) { 
            next = current->next; 
            current->next = prev;  
            prev = current; 
            current = next; 
        } 
        head = prev; 
        return head;
    }
    
    int getDecimalValue(Node* head){
        Node* temp = reverse(head);
        int x, total = 0, i = 0;

        while (temp != NULL){
            x = temp->data;
            total = total + pow(2, i)*x;
            i++;
            temp = temp->next;
        }
        return total;
    }