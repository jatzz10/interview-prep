// Problem - https://leetcode.com/problems/longest-substring-without-repeating-characters

// Solutions

// Approach 1
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
        int count = 0;

        for (int i = 0; i < s.size(); i++) {
            mp[s[i]]++;
            
            if (mp[s[i]] > 1) {
                count = mp.size() > count ? mp.size() : count;
                mp.clear();
                mp[s[i]]++;
            }
        }

        count = mp.size() > count ? mp.size() : count;

        return count;
    }
};
// Time complexity - O(n)
// Space complexity - O(n)
// Auxiliary space - O(n)
