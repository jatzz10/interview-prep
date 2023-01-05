/*
    Problem Statement:
    Given a string M of length N, and a sub-string S, 
    return the starting indices of all the possible substring anagrams of the string.

    Example: M = "abcghbcab"
    S = "abc"
    Possible anagrams present in M are: abc, bca, cab
    Therefore, their indices will be [0, 5, 6]
*/

// Solutions -

// 1. Brute Force
class Solution {
  public:
    vector<int> returnAnagramIndices(string mainString, string sub) {
        vector<int> result;
        set<char> freqSub;

        for (int i = 0; i < sub.size(); i++) {
            freqSub.insert(sub[i]);
        }

        for (int i = 0; i < mainString.size()-sub.size()+1; i++) {
            set<char> freq;
            bool valid = true;
            int count = 0;

            for (int j = i; j < mainString.size(); j++) {
                if (count == sub.size()) break;
                freq.insert(mainString[j]);
                count++;
            }

            if (freq == freqSub) {
                result.push_back(i);
            }
        }

        return result;
    }
};