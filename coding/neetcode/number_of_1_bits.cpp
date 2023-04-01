// Problem - 

// Solution
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count = 0;

        while (n) {
            if (n & 1) {
                count++;
            }
            n = n >> 1;
        }

        return count;
    }
};
// Time complexity - log(N)
// Space complexity - O(1)
// Auxiliary space - O(1)