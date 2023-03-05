# Problem - https://leetcode.com/problems/longest-common-prefix/

# Solutions

class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        base_string = strs[0]
        common_prefix = ''

        for i in range(len(base_string)):
            for j in range(1, len(strs)):
                if i == len(strs[j]) or strs[j][i] != base_string[i]:
                    return common_prefix

            common_prefix += base_string[i]
        
        return common_prefix
# Time complexity - O(m*(n-1)) - O(m*n) where m = size of base string and n = size of list of strings
# Space complexity - O(n)
# Auxiliary space - O(1)
