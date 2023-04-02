// Problem - https://leetcode.com/problems/reverse-bits

// Solution
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t result = 0;
        vector<int> bits(32, 0);
        int counter = 0;

        while (n) {
            bits[counter++] = n&1;
            n = n >> 1;
        }

        counter = 0;
        for (int idx = bits.size()-1; idx >= 0; idx--) {
            result += bits[idx]*pow(2, counter++);
        }

        return result;
    }
};
// Time complexity - log(N)
// Space complexity - O(1)
// Auxiliary space - O(1)