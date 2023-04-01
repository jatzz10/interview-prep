// Problem - 

// Solution
class Solution {
public:
    int count1Bit(int n) {
        int count = 0;

        while (n) {
            if (n & 1) {
                count++;
            }
            n = n >> 1;
        }

        return count;
    }

    vector<int> countBits(int n) {
        vector<int> result;

        for (int idx = 0; idx <= n; idx++) {
            result.push_back(count1Bit(idx));
        }

        return result;
    }
};
// Time complexity - N*log(N)
// Space complexity - O(N)
// Auxiliary space - O(1)