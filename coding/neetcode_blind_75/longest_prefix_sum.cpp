// Leetcode problem link - https://leetcode.com/problems/longest-common-prefix/

// Solutions

// 1. Brute Force
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string baseString = strs[0], finalString = "";
        for (int i = 0; i < strs[0].size(); i++) {
            char baseChar = strs[0][i];
            for (int j = 1; j < strs.size(); j++) {
                if (i == strs[j].size() || strs[j][i] != baseChar) {
                    return finalString;
                }
            }
            finalString += baseChar;
        }
        return finalString;
    }
};

// (Assuming length of base string as 'm' and length of array of strings as 'n)
// Time Complexity - O(m * n)
// Space Complexity - O(m * n)
// Auxiliary space - O(1)