# Problem -

# Solution
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

from collections import defaultdict

class Solution:
    def dfs(self, di, root, level, idx):
        if root is not None:
            di[level].append(idx)
            self.dfs(di, root.left, level+1, 2*idx)
            self.dfs(di, root.right, level+1, 2*idx+1)

    def widthOfBinaryTree(self, root: Optional[TreeNode]) -> int:
        di = defaultdict(list)
        self.dfs(di, root, 0, 0)

        return max([max(di[level])-min(di[level])+1 for level in di])
# Time Complexity - O(n)
# Space Complexity - O(n)
# Auxiliary space - O(n)