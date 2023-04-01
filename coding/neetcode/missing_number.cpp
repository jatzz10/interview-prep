// Problem -

// Solutions

// Approach 1 - Sum
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int totalSum = nums.size()*(nums.size()+1)/2;

        for (int idx = 0; idx < nums.size(); idx++) {
            totalSum -= nums[idx];    
        }

        return totalSum;
    }
};
// Time complexity - O(N)
// Space complexity - O(N)
// Auxiliary space - O(1)


// Approach 2 - XOR
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int res = nums.size();

        for (int idx = 0; idx < nums.size(); idx++) {
            res ^= idx;
            res ^= nums[idx];
        }

        return res;
    }
};
// Time complexity - O(N)
// Space complexity - O(N)
// Auxiliary space - O(1)