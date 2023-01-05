// Leetcode problem link - https://leetcode.com/problems/top-k-frequent-elements/description/

// Solutions -
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> mp;
        map<int, int>::iterator itr;

        vector<pair<int, int>> vec;
        vector<int> result;

        // iterate array
        for (int i = 0; i < nums.size(); i++) {
            mp[nums[i]]++;
        }

        // iterate map
        for (itr = mp.begin(); itr != mp.end(); itr++) {
            vec.push_back(make_pair(itr->second, itr->first));
        }

        // sort
        sort(vec.begin(), vec.end());

        // iterate backwards K elements
        for (int i = vec.size()-1; i >= 0; i--) {
            if (k == 0) break;
            result.push_back(vec[i].second);
            k--;
        }
        return result;
    }
};