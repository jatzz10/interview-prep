# Problem - https://leetcode.com/problems/remove-element

# Solution

class Solution:
    def removeElement(self, nums: List[int], val: int) -> int:
        left = right = len(nums) - 1

        while left >= 0:
            if nums[left] == val:
                nums[left] = None
                nums[left], nums[right] = nums[right], nums[left]
                right -= 1

            left -= 1
        
        return right + 1





