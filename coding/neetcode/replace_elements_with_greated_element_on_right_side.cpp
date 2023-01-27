// Leetcode problem link - https://leetcode.com/problems/replace-elements-with-greatest-element-on-right-side

// Solutions -

// 1. Approach 1
class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        vector<int> vec;
        int maxEle = -1;
        for (int i = arr.size()-1 ; i >= 0; i--) {
            vec.push_back(maxEle);
            maxEle = max(maxEle, arr[i]);
        }

        // fix the order
        for (int i = 0; i < vec.size()/2; i++) {
            swap(vec[i], vec[vec.size()-1-i]);
        }

        return vec;
    }
};
// Time complexity - O(n)
// Space complexity - O(n)
// Auxiliary space - O(1)