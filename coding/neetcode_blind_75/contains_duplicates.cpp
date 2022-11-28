// Leetcode problem link - https://leetcode.com/problems/contains-duplicate/

// Solutions -

// 1. Brute Force
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        bool haveDuplicate = false;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = 0; j < nums.size(); j++) {
                if (i != j and nums[i] == nums[j]) {
                    haveDuplicate = true;
                    break;
                }
            }
            if (haveDuplicate == true) {
                break;
            }
        }
        return haveDuplicate;
    }
};
// Time complexity - O(n^2)
// Space complexity - O(n)


// 2. Sort
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        bool haveDuplicate = false;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size()-1; i++) {
            if (nums[i] == nums[i+1]) {
                haveDuplicate = true;
                break;
            }
        }
        return haveDuplicate;
    }
};
// Time complexity - O(nlogn + n) = O(nlogn)
// Space complexity - O(n)


// 3. Unordered Set
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> st(nums.begin(), nums.end());
        return st.size() != nums.size() ? true : false;
    }
};
// Time complexity - O(n) (note: n inserts * O(1) for each insert)
// Space complexity - O(n)


// 4.  Hash Map
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        bool haveDuplicate = false;
        map<int, int> visited;
        for (int i = 0; i < nums.size(); i++) {
            if (visited.find(nums[i]) != visited.end()) {
                haveDuplicate = true;
                break;
            }
            visited[nums[i]] = nums[i];
        }
        return haveDuplicate;
    }
};
// Time complexity - O(n)
// Space complexity - O(n)

// Both approaches 3 and 4 are the best ones, having O(n) time complexity
