// Problem - https://leetcode.com/contest/weekly-contest-326/problems/distinct-prime-factors-of-product-of-array/

// Solution

class Solution {
public:
    bool isPrime[1000005];
    
    Solution() {
        memset(isPrime, true, sizeof(isPrime));
        computeAllPrimes(1000000);
    }

    void computeAllPrimes(int n) {
        for (int i = 2; i*i <= n; i++) {
            if (isPrime[i]) {
                for (int j = i*i; j <= n; j+=i) {
                    isPrime[j] = false;
                }
            }
        }
        isPrime[1] = false;
    }
    
    vector<int> closestPrimes(int left, int right) {
        vector<int> vec;
        int previous = left, diff = right, l = -1, r = -1;
        for (int current = left; current <= right; current++) {
            if (!isPrime[current]) continue;
            if (current != previous && isPrime[previous]) {
                if (current-previous < diff) {
                    diff = current-previous;
                    l = previous;
                    r = current;
                }
            }
            previous = current;
        }
        cout << isPrime[1];
        vec.push_back(l);
        vec.push_back(r);
        return vec;
    }
};