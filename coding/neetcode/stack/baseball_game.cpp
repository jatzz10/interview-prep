// Problem - https://leetcode.com/problems/baseball-game

// Solution
class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> stk;
        int sumOfScores = 0;

        for (int i = 0; i < operations.size(); i++) {
            if (!stk.empty() && operations[i] == "+") {
                int prev = stk.top();
                stk.pop();
                int newEle = stk.top() + prev; 
                stk.push(prev);
                stk.push(newEle);
            } else if (!stk.empty() && operations[i] == "C") {
                stk.pop();
            } else if (!stk.empty() && operations[i] == "D") {
                stk.push(stk.top()*2);
            } else {
                stk.push(stoi(operations[i]));    
            }
        }

        while (!stk.empty()) {
            sumOfScores += stk.top();
            stk.pop();
        }

        return sumOfScores;
    }
};
// Time Complexity - O(N)
// Space Complexity - O(N)
// Auxiliary space - O(N)