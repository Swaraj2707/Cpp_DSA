#include<bits/stdc++.h>
using namespace std;

/*
    Time Complexity : O(N)
    Space Complexity: O(N)

    Where 'N' is the size of the given stack MY_STACK.      
*/

stack<int> pushAtBottom(stack<int> &myStack, int x)
{
	// Base Case
	if (myStack.empty())
	{
		myStack.push(x);
		return myStack;
	}

	// Store top element in 'num'
	int num = myStack.top();

	// Pop the top element
	myStack.pop();

	// Recursive call
	pushAtBottom(myStack, x);

	// Add 'num' to stack
	myStack.push(num);

	return myStack;
}
