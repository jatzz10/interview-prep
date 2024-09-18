#include <bits/stdc++.h>
using namespace std;


stack<int> insertIntoSortedStack(stack<int> stack, int num) {
    if (stack.empty() || stack.top() <= num) {
        stack.push(num);
        return stack;
    }
    
    int topElement = stack.top();
    stack.pop();
    stack = insertIntoSortedStack(stack, num);
    stack.push(topElement);
    return stack;
}

stack<int> sortStack(stack<int> stack) {
    if (stack.size() == 1) {
        return stack;
    }
    
    int topElement = stack.top();
    stack.pop();
    stack = sortStack(stack);
    stack = insertIntoSortedStack(stack, topElement);
    return stack;
}

int main() {
    stack<int> stack;
    stack.push(5);
    stack.push(8);
    stack.push(4);
    stack.push(2);
    stack.push(3);
    stack.push(7);
    
    stack = sortStack(stack);
    
    while (!stack.empty()) {
        cout << stack.top() << " ";
        stack.pop();
    }

    return 0;
}

// Time Complexity = O(N^2)
// Space Complexity = O(N)
