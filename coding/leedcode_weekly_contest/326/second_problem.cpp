// Problem - https://leetcode.com/contest/weekly-contest-326/problems/distinct-prime-factors-of-product-of-array/

// Solution -

class Solution {
public:
    unordered_set<int> distinctPrimeFactorsSet;
    
    void primeFactors(int n) {
        while (n % 2 == 0) {
            distinctPrimeFactorsSet.insert(2);
            n = n/2;
        }
        
        for (int i = 3; i <= sqrt(n); i = i + 2) {
            while (n % i == 0) {
                distinctPrimeFactorsSet.insert(i);
                n = n/i;
            }
        }

        if (n > 2)
            distinctPrimeFactorsSet.insert(n);
    }
    
    int distinctPrimeFactors(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) {
            primeFactors(nums[i]);
        }
        return distinctPrimeFactorsSet.size();
    }
};