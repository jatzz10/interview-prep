# Leetcode problem link - https://leetcode.com/problems/path-sum/

# Solutions -

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def findPathSum(self, root, targetSum, pathSum):
        if root is None:
            return False

        pathSum += root.val

        if pathSum == targetSum and root.left is None and root.right is None:
            return True

        return self.findPathSum(root.left, targetSum, pathSum) \
            or self.findPathSum(root.right, targetSum, pathSum)
    
    def hasPathSum(self, root, targetSum) -> bool:
        return self.findPathSum(root, targetSum, 0)