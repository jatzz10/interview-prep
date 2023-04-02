# Problem - https://leetcode.com/problems/subsets/

# Approach 1 - Recursive
class Solution:
    def findSubsets(self, nums, l, r, subset, result):
        if l == r:
            result.append(subset)
            return

        self.findSubsets(nums, l+1, r, [nums[l]] + subset, result)
        self.findSubsets(nums, l+1, r, subset, result)

    def subsets(self, nums: List[int]) -> List[List[int]]:
        result = []
        self.findSubsets(nums, 0, len(nums), [], result)
        return result                                                                        
# Time complexity - O(n * 2^n)
# Space comlexity - O(n * 2^n)
# Auxiliary space - O(n * 2^n)