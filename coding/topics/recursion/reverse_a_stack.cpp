#include <bits/stdc++.h>
using namespace std;


stack<int> insertInSortedStack(stack<int> stack, int num) {
    if (stack.empty()) {
        stack.push(num);
        return stack;
    }
    
    int topElement = stack.top();
    stack.pop();
    stack = insertInSortedStack(stack, num);
    
    stack.push(topElement);
    
    return stack;
}


stack<int> reverseStack(stack<int> stack) {
    // Base condition
    if (stack.size() == 1) {
        return stack;
    }
    
    // Hypothesis
    int topElement = stack.top();
    stack.pop();
    stack = reverseStack(stack);
    
    // Induction
    stack = insertInSortedStack(stack, topElement);
    
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
    
    stack = reverseStack(stack);
    
    while (!stack.empty()) {
        cout << stack.top() << " ";
        stack.pop();
    }

    return 0;
}

// Time Complexity = O(N^2)
// Space Complexity = O(N)
