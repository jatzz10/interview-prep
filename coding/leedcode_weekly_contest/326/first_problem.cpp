// Problem - https://leetcode.com/contest/weekly-contest-326/problems/count-the-digits-that-divide-a-number/

// Solution -

class Solution {
public:
    int countDigits(int num) {
        int count = 0, temp = num;
        while (temp) {
            int lastDigit = temp % 10;
            if (num % lastDigit == 0) count++;
            temp /= 10;
        }
        return count;
    }
};