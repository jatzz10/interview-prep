// Problem - https://leetcode.com/problems/two-sum-ii-input-array-is-sorted

// Solutions

// Approach 1
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
       int left = 0, right = numbers.size()-1;
        vector<int> result;

        while (left < right) {
            int numSum = numbers[left] + numbers[right];
            if (numSum == target) {
                result.push_back(left+1);
                result.push_back(right+1);
                break;
            } else if (numSum > target) {
                right--;
            } else {
                left++;
            }
        }

        if (result.size() == 0) result.push_back(-1);
        return result;
    }
};
// Time complexity - O(n) [where 'n' is size of vector]
// Space complexity - O(n)
// Auxiliary space - O(1)