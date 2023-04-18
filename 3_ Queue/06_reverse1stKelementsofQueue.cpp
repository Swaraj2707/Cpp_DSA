// Function to reverse first k elements of a queue.
#include<bits/stdc++.h>
using namespace std;

queue<int> modifyQueue(queue<int> q, int k) {
    // using a stack and another queue to reverse first k elements.
    stack<int> s;
    queue<int> qq;

    // we pop first k elements from queue and push it in the stack.
    while (k-- > 0) {
        int a = q.front();
        q.pop();
        s.push(a);
    }

    // while stack is not empty, we push the elements into the new queue.
    while (!s.empty()) {
        int a = s.top();
        s.pop();
        qq.push(a);
    }

    // then we add rest of the elements of original queue to the new queue.
    while (!q.empty()) {
        int a = q.front();
        q.pop();
        qq.push(a);
    }

    // returning the new queue.
    return qq;
}

int main() 
{
    int t;
    cin >> t;
    while (t-- > 0) {
        int n, k;
        cin >> n >> k;
        queue<int> q;
        while (n-- > 0) {
            int a;
            cin >> a;
            q.push(a);
        }
        queue<int> ans = modifyQueue(q, k);
        while (!ans.empty()) {
            int a = ans.front();
            ans.pop();
            cout << a << " ";
        }
        cout << endl;
    }
}