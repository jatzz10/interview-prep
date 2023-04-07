// Problem - 

// Solutions

// Approach 1: Recursive
class Solution {
public:
    int findTribonacci(int n) {
        if (n < 1) {
            return 0;
        }

        if (n == 1 || n == 2) {
            return 1;
        }
        
        return findTribonacci(n-1) + findTribonacci(n-2) + findTribonacci(n-3);
    }

    int tribonacci(int n) {
        return findTribonacci(n);
    }
};
// Time Complexity - O(3^n)
// Space Complexity (auxiliary) - O(n) [due to recursion call stack]


// Approach 2: DP top-down (Recursive + Memoization)
class Solution {
public:
    int findTribonacci(int n, vector<int> dp) {
        if (n < 1) {
            return 0;
        }

        if (n == 1 || n == 2) {
            return 1;
        }

        if (dp[n]) {
            return dp[n];
        }
        else {
            dp[n] = findTribonacci(n-1, dp) + findTribonacci(n-2, dp) + findTribonacci(n-3, dp);
            return dp[n];
        }
    }

    int tribonacci(int n) {
        vector<int> dp(n+1, 0);
        return findTribonacci(n, dp);
    }
};
// Time Complexity - O(n)
// Space Complexity (auxiliary) - O(n) [due to recursion call stack]


// Approach 3: DP bottom-up (Tabulation)
class Solution {
public:
    int tribonacci(int n) {
        if (n < 2) {
          return n;
        }

        if (n == 2) {
          return 1;
        }
        
        vector<int> dp(n+1, 0);
        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 1;

        for (int i = 3; i < n+1; i++) {
          dp[i] = dp[i-1] + dp[i-2] + dp[i-3];
        }
        
        return dp[n];
    }
};
// Time Complexity - O(n)
// Space Complexity (auxiliary) - O(n) [due to extra vector DS used]