# Problem - https://leetcode.com/problems/is-subsequence

# Solutions

class Solution:
    def isSubsequence(self, s: str, t: str) -> bool:
        count = 0
        
        for i in t:
            if count == len(s):
                return True
            if s[count] == i:
                count += 1

        if count == len(s):
            return True
        else:
            return False