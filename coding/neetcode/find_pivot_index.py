# Problem - 

# Solution

# Approach 1: Brute force
class Solution:
    def pivotIndex(self, nums: List[int]) -> int:
        for pivot in range(len(nums)):
            left_sum = 0
            right_sum = 0

            for i in range(pivot):
                left_sum += nums[i]

            for i in range(pivot+1, len(nums)):
                right_sum += nums[i]

            if left_sum == right_sum:
                return pivot

        return -1
# Time complexity - O(n^2) [Gives Time Limit Exceeded]
# Space comlexity - O(n)
# Auxiliary space - O(1)


# Approach 2
class Solution:
    def pivotIndex(self, nums: List[int]) -> int:
        forward_list = [0] * len(nums)
        forward = 0
        forward_sum = 0

        backward_list = [0] * len(nums)
        backward = len(nums) - 1
        backward_sum = 0

        while forward < len(nums) and backward >= 0:
            forward_list[forward] = forward_sum + nums[forward]
            forward_sum += nums[forward]
            forward += 1

            backward_list[backward] = backward_sum + nums[backward]
            backward_sum += nums[backward]
            backward -= 1

        for i in range(len(nums)):
            if forward_list[i] == backward_list[i]:
                return i

        return -1
# Time complexity - O(n)
# Space comlexity - O(n)
# Auxiliary space - O(n)