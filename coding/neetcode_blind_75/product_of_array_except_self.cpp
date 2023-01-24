// Problem - https://leetcode.com/problems/product-of-array-except-self

// Solutions

// Approach 1: Brute force
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> productStore;

        for (int i = 0; i < nums.size(); i++) {
            int product = 1;
            for (int j = 0; j < nums.size(); j++) {
                if (i == j) continue;
                product *= nums[j];
            }
            productStore.push_back(product);
        }

        return productStore;
    }
};
// Time complexity - O(n^2) [where 'n' is size of nums vector/array]
// Space complexity - O(n)
// Auxiliary space - O(1)


// Approach 2: Iterate twice
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> productStore(nums.size(), 1);
        int preProduct = 1, postProduct = 1;

        // calculate product forward
        for(int i = 0; i < nums.size(); i++) {
            productStore[i] *= preProduct;
            preProduct *= nums[i];   
        }

        // calculate product backward
        for (int i = nums.size()-1; i >= 0; i--) {
            productStore[i] *= postProduct;
            postProduct *= nums[i];
        }

        return productStore;
    }
};
// Time complexity - O(n) [where 'n' is size of nums vector/array]
// Space complexity - O(n)
// Auxiliary space - O(1)