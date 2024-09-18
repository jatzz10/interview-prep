#include <bits/stdc++.h>
using namespace std;


stack<int> deleteMiddleElement(stack<int> stack, int originalSize) {
    // Base condition
    if (stack.size() == (originalSize/2)+1) {
        stack.pop();
        return stack;
    }
    
    // Hypothesis
    int topElement = stack.top();
    stack.pop();
    stack = deleteMiddleElement(stack, originalSize);
    
    // Induction
    stack.push(topElement);
    
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
    
    stack = deleteMiddleElement(stack, stack.size());
    
    while (!stack.empty()) {
        cout << stack.top() << " ";
        stack.pop();
    }

    return 0;
}

// Time Complexity - O(N)
// Space Complexity - O(N)
