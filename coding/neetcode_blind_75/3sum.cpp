// Leetcode problem link - https://leetcode.com/problems/3sum/

// Solutions -

// Brute Force
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>> st;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = 0; j < nums.size(); j++) {
                for (int k = 0; k < nums.size(); k++) {
                    if (i != j && i != k && j != k && nums[i]+nums[j]+nums[k] == 0) {
                        vector<int> temp {nums[i], nums[j], nums[k]};
                        sort(temp.begin(), temp.end());
                        st.insert(temp);
                    }
                }
            }
        }
        vector<vector<int>> vec(st.begin(), st.end());
        return vec;
    }
};
// Time Complexity - O(N^3)
// Space Complexity - O(N)
// Auxiliary space - O(N)


// 2. More optimized that 1st approach
// Sort, HashMap
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>> st;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++) {
            if (i > 0 && nums[i] == nums[i-1]) continue;
            map<int, int> mp;
            for (int j = i+1; j < nums.size(); j++) {
                int target_sum = -1 * (nums[i] + nums[j]);
                if (mp.find(target_sum) != mp.end()) {
                    vector<int> temp {nums[i], nums[j], target_sum};
                    sort(temp.begin(), temp.end());
                    st.insert(temp);
                } else {
                    mp[nums[j]] = j;
                }
            }
        }
        vector<vector<int>> vec(st.begin(), st.end());
        return vec;
    }
};
// Time Complexity - O(N^2)
// Space Complexity - O(N)
// Auxiliary space - O(N)


// 3. Two pointers
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> vec;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++) {
            if (i > 0 && nums[i] == nums[i-1]) continue;
            int l = i+1, r = nums.size()-1;
            while (l < r) {
                int sum = nums[i]+nums[l]+nums[r];
                if (sum == 0) {
                    vector<int> temp {nums[i], nums[l], nums[r]};
                    vec.push_back(temp);
                    l++;
                    while (nums[l] == nums[l-1] && l < r) {
                        l++;
                    }
                } else if (sum > 0) {
                    r--;
                } else {
                    l++;
                }
            }
        }
        return vec;
    }
};
// Time Complexity - O(N^2)
// Space Complexity - O(N)
// Auxiliary space - O(1)