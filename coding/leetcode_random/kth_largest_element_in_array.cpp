// Problem - https://leetcode.com/problems/kth-largest-element-in-an-array

// Solutions

// Approach 1: Sort
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end(), greater<int>());
        return nums[k-1];
    }
};
// Time complexity - O(nlogn)
// Space complexity - O(n)
// Auxiliary space - O(1)


// Apprach 2
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        map<int, int> mp;
        
        for (int i = 0; i < nums.size(); i++) {
            mp[nums[i]]++;
        }

        for (auto itr = mp.rbegin(); itr != mp.rend(); itr++) {
            int freq = mp[itr->first];

            while (freq && k) {
                if (k == 1) {
                    return itr->first;
                }
                k--;
                freq--;
            }
        }

        return 0;
    }
};
// Time complexity - O(m.logn) where m = no. of distint elements in array
// Space complexity - O(n)
// Auxiliary space - O(n)
// This approach is slightly more optimized that the 1st approach in case 
// there are many duplicate elements in the array.