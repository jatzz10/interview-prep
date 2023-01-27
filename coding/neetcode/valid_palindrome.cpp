// Leetcode problem link - https://leetcode.com/problems/valid-palindrome

// Solutions -

// 1. Traverse twice
class Solution {
public:
    bool isPalindrome(string s) {
        // remove non-alphanumeric characters
        for (int i = 0; i < s.size(); i++) {
            if ((s[i] < 'A' || s[i] > 'Z') 
                && (s[i] < 'a' || s[i] > 'z')
                && (s[i] < '0' || s[i] > '9')
            ) {
                s.erase(i, 1);
                i--;
            } else {
                s[i] = tolower(s[i]);
            }
        }

        // check for palindrome
        for (int i = 0; i < s.size()/2; i++) {
            if (s[i] != s[s.size()-1-i]) {
                return false;
            }
        }

        return true;
    }
};
// Time Complexity - O(N)
// Space Complexity - O(N)
