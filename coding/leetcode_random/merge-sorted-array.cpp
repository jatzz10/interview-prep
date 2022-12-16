// Leetcode problem link - https://leetcode.com/problems/merge-sorted-array

// Solutions -

// 1. Use vector and sort
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> vec;
        for (int i = 0; i < m; i++) {
            vec.push_back(nums1[i]);
        }
        for (int i = 0; i < n; i++) {
            vec.push_back(nums2[i]);
        }
        sort(vec.begin(), vec.end());
        for (int i = 0; i < m+n; i++) {
            nums1[i] = vec[i];
        }
    }
};
// Time Complexity - O((m+n)*log(m+n))
// Space Complexity - O(m+n)
// Auxiliary space - O(m+n)


// 2. Two pointers
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int x = 0, y = 0, z = 0;
        int nums3[m+n];
        while (x < m || y < n) {
            if (x < m && y < n && nums1[x] <= nums2[y]) {
                nums3[z++] = nums1[x++];
            } else if (x < m && y < n && nums1[x] > nums2[y]) {
                nums3[z++] = nums2[y++];
            } else if (x < m && y >= n) {
                nums3[z++] = nums1[x++];
            } else if (y < n && x >= m) {
                nums3[z++] = nums2[y++];
            }    
        }
        for (int i = 0; i < m+n; i++) {
            nums1[i] = nums3[i];
        }
    }
};
// Time Complexity - O(m+n)
// Space Complexity - O(m+n)
// Auxiliary space - O(m+n)