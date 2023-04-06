// Problem - 

// Solutions

// Approach 1 - Brute force
class Solution {
public:
    bool isPalindrome(string s) {
        for (int i = 0; i < s.size()/2; i++) {
            if (s[i] != s[s.size()-1-i]) {
                return false;
            }
        }
        
        return true;
    }

    string longestPalindrome(string s) {
        string result = "";

        for (int i = 0; i < s.size(); i++) {
            string temp = "";
            for (int j = i; j < s.size(); j++) {
                temp += s[j];

                if (isPalindrome(temp) && temp.size() > result.size()) {
                    result = temp;
                }
            }
        }

        return result;
    }
};
// Time complexity - O(n^3) where n = size of string
// Space complexity - O(1)
// Auxiliary space - O(1)


// Approach 2 - Brute force + memoization
class Solution {
public:
    bool isPalindrome(string s) {
        for (int i = 0; i < s.size()/2; i++) {
            if (s[i] != s[s.size()-1-i]) {
                return false;
            }
        }
        
        return true;
    }

    string longestPalindrome(string s) {
        string result = "";
        unordered_map<string, bool> hm;

        for (int i = 0; i < s.size(); i++) {
            string temp = "";
            for (int j = i; j < s.size(); j++) {
                temp += s[j];
                bool palindrome = false;

                if (hm[temp]) {
                    palindrome = hm[temp];
                } else {
                    palindrome = isPalindrome(temp);
                    hm[temp] = palindrome;
                }

                if (palindrome && temp.size() > result.size()) {
                    result = temp;
                }
            }
        }

        return result;
    }
};