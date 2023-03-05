# Problem - https://leetcode.com/problems/length-of-last-word/

# Solution

class Solution:
    def lengthOfLastWord(self, s: str) -> int:
        li = [i for i in s.split(' ') if i]
        return len(li[-1])