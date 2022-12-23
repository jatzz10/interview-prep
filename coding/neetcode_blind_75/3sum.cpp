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
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>> st;
        map<int, int> mp;
        for (int i = 0; i < nums.size(); i++) {
            mp[nums[i]]++;
        }
        for (int i = 0; i < nums.size(); i++) {
            for (int j = 0; j < nums.size(); j++) {
                if (i == j) continue;
                int third_ele = -1 * (nums[i] + nums[j]);
                if (mp[third_ele]) {
                    if ((third_ele == nums[i] && mp[nums[i]]-2 < 0) 
                        || (third_ele == nums[j] && mp[nums[j]]-2 < 0) 
                        || (third_ele == nums[i] && third_ele == nums[j] && mp[nums[j]]-3 < 0)) {
                        continue;
                    }

                    // load the set of numbers
                    vector<int> temp {nums[i], nums[j], third_ele};
                    sort(temp.begin(), temp.end());
                    st.insert(temp);
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

