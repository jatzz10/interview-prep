// Problem - https://leetcode.com/contest/weekly-contest-326/problems/partition-string-into-substrings-with-values-at-most-k/

// Solution -

class Solution {
public:
    long long numValue(char c) {
        long long num = int(c) - '0';
        return num;
    }
    
    long long minimumPartition(string s, int k) {
        long long count = 0, temp = 0, power = 0;
        for (int i = s.size()-1; i >= 0; i--) {
            temp += numValue(s[i])*pow(10, power);
            if (temp > k && power == 0) return -1;
            power++;
            if (temp > k) {
                count++;
                temp = 0;
                power = 0;
                i++;
            }
        }
        return count+1;
    }
};