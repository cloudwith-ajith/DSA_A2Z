#include <bits/stdc++.h>
using namespace std;

// Helper function to insert an element at the very bottom of the stack
void insertst(stack<int> &st, int item) {
    // Base case: if the stack is empty, push the item at the bottom and return
    if (st.empty()) {
        st.push(item);
        return;
    }

    // Store the top element and pop it to reach the bottom
    int topnum = st.top();
    st.pop();

    // Recursively call insertst until the stack becomes empty
    insertst(st, item);

    // Push the stored top element back on top of the newly inserted bottom item
    st.push(topnum);
}

// Main recursive function to reverse the stack
void reverseStack(stack<int> &st) {
    // Base case: if the stack is empty, there is nothing left to reverse
    if (st.empty()) {
        return;
    }

    // Remove and hold the current top element in the function call stack
    int topnum = st.top();
    st.pop();

    // Recursively reverse the remaining stack
    reverseStack(st);

    // Insert the held top element at the bottom of the reversed stack
    insertst(st, topnum);
}

int main() {
    stack<int> st;

    // Pushing elements: 4 (bottom) -> 1 -> 3 -> 2 (top)
    st.push(4);
    st.push(1);
    st.push(3);
    st.push(2);

    // Reverse the stack in-place using recursion
    reverseStack(st);

    // Print and pop elements from top to bottom
    // Expected output: 4 1 3 2
    while (!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }

    return 0;
}
