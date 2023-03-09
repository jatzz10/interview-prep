# Problem - https://leetcode.com/problems/kth-smallest-element-in-a-bst

# Solutions

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def traverse_tree(self, root, li):
        if root is None:
            return
        
        self.traverse_tree(root.left, li)
        li.append(root.val)
        self.traverse_tree(root.right, li)


    def kthSmallest(self, root: Optional[TreeNode], k: int) -> int:
        li = []
        self.traverse_tree(root, li)
        return li[k-1]
# Time complexity - O(N)
# Space complexity - O(N)
# Auxiliary space - O(N)