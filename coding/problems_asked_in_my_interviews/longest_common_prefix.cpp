// Leetcode problem link - https://leetcode.com/problems/longest-common-prefix

// Solutions -

// Approach 1
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
// Time complexity - O(m*n) [assuming size of the base string as 'm', and size of array as 'n']
// Space complexity - O(m*n)
// Auxiliary space - O(1)


