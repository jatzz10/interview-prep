// Leetcode problem link - https://leetcode.com/problems/valid-anagram/

// Solutions -

// 1. Brute Force
class Solution1 {
public:
    bool isAnagram(string s, string t) {
        bool anagram = true;
        if (s.length() != t.length()) {
            return false;
        }
        for (int i = 0; i < s.length(); i++) {
            bool matchFound = false;
            for (int j = 0; j < t.length(); j++) {
                if (s[i] == t[j]) {
                    matchFound = true;
                    break;
                }
            }
            if (matchFound == false) {
                anagram = false;
                break;
            }
        }
        return anagram;
    }
};
// Time complexity - O(n^2)
// Space complexity - O(n)


// 2. Sort
class Solution2 {
public:
    bool isAnagram(string s, string t) {
        bool anagram = true;
        if (s.length() != t.length()) {
            return false;
        }
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        for (int itr = 0; itr < s.length(); itr++) {
            if (s[itr] != t[itr]) {
                anagram = false;
                break;
            }
        }
        return anagram;
    }
};
// Time complexity - O(nlogn)
// Space complexity - O(n)


// 3. Hash Map
class Solution3 {
public:
    bool isAnagram(string s, string t) {
        bool anagram = true;
        map<char, int> mp;
        if (s.length() != t.length()) {
            return false;
        }
        for (int itr = 0; itr < s.length(); itr++) {
            mp[s[itr]]++;
            mp[t[itr]]--;
        }
        for (int itr = 0; itr < t.length(); itr++) {
            if (mp[t[itr]] != 0) {
                anagram = false;
                break;
            }
        }
        return anagram;
    }
};
// Time complexity - O(n)
// Space complexity - O(n)
// Best apprach

