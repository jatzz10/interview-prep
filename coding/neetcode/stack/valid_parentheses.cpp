// Problem - https://leetcode.com/problems/valid-parentheses

// Solution
class Solution {
public:
    bool isValid(string s) {
        stack<char> st;

        for (int i = 0; i < s.size(); i++) {
            if (!st.empty() 
                && ((st.top() == '(' && s[i] == ')') 
                    || (st.top() == '[' && s[i] == ']') 
                    || (st.top() == '{' && s[i] == '}'))
                ) {
                st.pop();
            } else {
                st.push(s[i]);
            }
        }

        return st.empty();
    }
};
// Time Complexity - O(N)
// Space Complexity - O(N)
// Auxiliary space - O(N)