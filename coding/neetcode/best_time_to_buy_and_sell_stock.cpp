// Leetcode problem link - https://leetcode.com/problems/best-time-to-buy-and-sell-stock

// Solutions -

// 1. Brute Force
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max_profit = 0;
        for (int i = 0; i < prices.size(); i++) {
            for (int j = i+1; j < prices.size(); j++) {
                if (prices[j] - prices[i] > max_profit) {
                    max_profit = prices[j] - prices[i];
                }
            }
        }
        return max_profit;
    }
};
// Time Complexity - O(N^2)
// Space Complexity - O(N)
// Auxiliary space - O(1)


// 2. Single traversal
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0, minPrice = prices[0];
        for (int i = 1; i < prices.size(); i++) {
            minPrice = min(prices[i], minPrice);
            profit = max(prices[i]-minPrice, profit);
        }
        return profit;
    }
};
// Time Complexity - O(N)
// Space Complexity - O(N)
// Auxiliary space - O(1).