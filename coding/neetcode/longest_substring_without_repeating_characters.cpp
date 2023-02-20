// Problem - https://leetcode.com/problems/longest-substring-without-repeating-characters

// Solutions

// Approach 1: Brute Force
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxCount = 0;

        for (int i = 0; i < s.size(); i++) {
            int tempCount = 0;
            map<char, int> mp;

            for (int j = i; j < s.size(); j++) {
                mp[s[j]]++;

                if (mp[s[j]] > 1) break;

                tempCount++;
            }

            maxCount = max(tempCount, maxCount);
        }

        return maxCount;
    }
};
// Time complexity - O(n^2)
// Space complexity - O(n)
// Auxiliary space - O(n)


// Approach 2
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char, int> mp;
        int l = 0, r = 0, maxCount = 0;

        while (r < s.size()) {
            mp[s[r]]++;

            while (mp[s[r]] > 1) {
                mp[s[l]]--;
                l++;
            }

            maxCount = max(maxCount, r-l+1);
            r++;
        }

        return maxCount;
    }
};
// Time complexity - O(2n) since each charater will be visited atleast twice
// Space complexity - O(n)
// Auxiliary space - O(n)


// Approach 3: Slider Window Optimized
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char, int> mp;
        int l = 0, r = 0, maxCount = 0;

        while (r < s.size()) {
            if (mp[s[r]] > 0) {
                l = max(l, mp[s[r]]);
            }
            mp[s[r]] = r+1;
            maxCount = max(maxCount, r-l+1);
            r++;
        }

        return maxCount;
    }
};
// Time complexity - O(n)
// Space complexity - O(n)
// Auxiliary space - O(n)
