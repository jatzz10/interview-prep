// Problem - https://leetcode.com/problems/group-anagrams

// Solutions

// Approach 1
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> vec;
        map<string, vector<string>> mp;
        map<string, vector<string>>::iterator it;
        
        for (int i = 0; i < strs.size(); i++) {
            string temp = strs[i];
            sort(temp.begin(), temp.end());
            mp[temp].push_back(strs[i]);
        }

        for (it = mp.begin(); it != mp.end(); it++) {
            vec.push_back(it->second);
        }

        return vec;
    }
};
// Time complexity - O(m*log(m)*n) where m is the size of string with max. size, and n being size of array
// Space complexity - O(m*n)
// Auxiliary space - O(m*n)


// Approach 2
class Solution {
public:
    string buildSortedString(string s) {
        char count[26] = {0};
        string newStr = "";
        for (int i = 0; i < s.size(); i++) {
            count[s[i]-'a']++;
        }

        for (int i = 0; i < 26; i++) {
            newStr += string(count[i], i + 'a');
        }

        return newStr;
    }
    
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> vec;
        map<string, vector<string>> mp;
        map<string, vector<string>>::iterator it;
        
        for (int i = 0; i < strs.size(); i++) {
            mp[buildSortedString(strs[i])].push_back(strs[i]);
        }

        for (it = mp.begin(); it != mp.end(); it++) {
            vec.push_back(it->second);
        }

        return vec;
    }
};
// Time complexity - O(m*n) where m is the size of string with max. size, and n being size of array
// Space complexity - O(m*n)
// Auxiliary space - O(m*n)