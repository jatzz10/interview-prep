// Problem - 

// Solutions

// Approach 1 - Loop
class Solution {
public:
    bool isPowerOfFour(long long n) {
        if (n == 0) return false;
        
        while (n % 4 == 0) {
            n /= 4;
        }

        return n == 1;
    }
};
// Time Complexity - O(log n)
// Space Complexity (auxiliary) - O(1)


// Approach 2 - Recursive
class Solution {
public:
    bool isPowerOfFour(int n) {
        if (n == 0) return false;
        if (n == 1) return true;
        
        return n % 4 == 0 && isPowerOfFour(n/4);
    }
};
// Time complexity - O(log n)
// Space complexity (auxiliary) - O(log n) [due to recursion call stack]