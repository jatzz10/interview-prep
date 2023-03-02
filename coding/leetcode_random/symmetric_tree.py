# Leetcode problem link - https://leetcode.com/problems/symmetric-tree/

# Solutions -

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def isTreeSymmetric(self, rootleft, rootright):
        if rootleft is None and rootright is None:
            return True

        if rootleft is None or rootright is None:
            return False

        if rootleft.val != rootright.val:
            return False

        return self.isTreeSymmetric(rootleft.left, rootright.right) \
            and self.isTreeSymmetric(rootleft.right, rootright.left)
    

    def isSymmetric(self, root) -> bool:
        return self.isTreeSymmetric(root.left, root.right)

    