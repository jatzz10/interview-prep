// Problem - https://leetcode.com/problems/longest-consecutive-sequence

// Solutions

// Approach 1 
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int count = 1, maxCount = 0;
        sort(nums.begin(), nums.end());

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] - nums[i-1] == 1) {
                count++;
            } else if (nums[i] - nums[i-1] == 0) {
                continue;
            } else {
                maxCount = count > maxCount ? count : maxCount;        
                count = 1;
            }
        }
        maxCount = count > maxCount ? count : maxCount;

        return nums.size() != 0 ? maxCount : 0;
    }
};
// Time complexity - O(n * log(n)) [where 'n' is size of vector]
// Space complexity - O(n)
// Auxiliary space - O(1)


// Approach 2
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int> st(nums.begin(), nums.end());
        vector<int> vec(st.begin(), st.end());
        int count = 1, maxCount = 0;

        for (int i = 1; i < vec.size(); i++) {
            if (vec[i] - vec[i-1] == 1) {
                count++;
            } else {
                maxCount = count > maxCount ? count : maxCount;        
                count = 1;
            }
        }
        maxCount = count > maxCount ? count : maxCount;

        return vec.size() != 0 ? maxCount : 0;
    }
};
// Time complexity - O(n) [where 'n' is size of vector]
// Space complexity - O(n)
// Auxiliary space - O(n)