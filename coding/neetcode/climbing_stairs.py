# Problem - https://leetcode.com/problems/climbing-stairs

# Solutions

# Approach 1: Recursive
class Solution:
    def climbStairs(self, n: int) -> int:
        if n == 1 or n == 2:
            return n

        return self.climbStairs(n-1) + self.climbStairs(n-2)
# Time complexity - O(2^n)
# Space comlexity - O(n)
# Auxiliary space - O(n)


# Approach 2: Recursive + Memoization
class Solution:
    def findDistinct(self, n, hm): 
        if n in hm:
            return hm[n]
        else:
            hm[n] = self.findDistinct(n-1, hm) + self.findDistinct(n-2, hm)
            return hm[n]
    
    def climbStairs(self, n: int) -> int:
        hm = {}
        hm[1] = 1
        hm[2] = 2

        return self.findDistinct(n, hm)
# Time complexity - O(n)
# Space comlexity - O(n)
# Auxiliary space - O(n)