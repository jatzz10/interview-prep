# Leetcode problem link - https://leetcode.com/problems/binary-tree-preorder-traversal/

# Solutions -

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def traverse(self, root, li):
        if root is None:
            return

        li.append(root.val)
        self.traverse(root.left, li)
        self.traverse(root.right, li)
    
    def preorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        li = []
        self.traverse(root, li)
        return li

        