# Problem - https://leetcode.com/problems/reverse-words-in-a-string

# Approach 1: Using extra list
class Solution:
    def reverseWords(self, s: str) -> str:
        words = s.split(' ')
        words = [w for w in words if w != '']
        words.reverse()
        return ' '.join(words)
# Time Complexity - O(n)
# Space Complexity - O(n)
# Auxiliary space - O(n)


# Approach 2: Using C++, reverse the whole string, then reverse back individual sub-strings
class Solution {
public:
    void reverseString(string &s, int l, int r) {
        for (int idx = l; idx <= (l+r)/2; idx++) {
            swap(s[idx], s[l+r-idx]);
        }
    }

    string reverseWords(string s) {
        int l = 0, r = 0;
        bool charFound = false;

        reverseString(s, 0, s.size()-1);

        while (r < s.size()) {
            if (s[r] != ' ') {
                if (charFound == false) {
                    l = r;
                }
                charFound = true;
            }

            if (charFound == true && s[r] == ' ') {
                reverseString(s, l, r-1);
                charFound = false;
            }

            if (s[r] != ' ' && r == s.size()-1) {
                reverseString(s, l, r);
                charFound = false;
            }
            
            r++;
        }

        string result = "";
        int endOfChar = s.size()-1;

        for (int idx = s.size()-1; idx >= 0; idx--) {
            if (s[idx] != ' ') break;
            endOfChar--;
        }

        for (int idx = 0; idx < s.size(); idx++) {
            if (idx > endOfChar) break;
            if (s[idx] != ' ') {
                result += s[idx];
                charFound = true;
            } else if (charFound == true) {
                result += " ";
                charFound = false;
            }
        }

        return result;
    }
};
# Time Complexity - O(n)
# Space Complexity - O(n)
# Auxiliary space - O(1)