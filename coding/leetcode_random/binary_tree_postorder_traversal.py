# Leetcode problem link - https://leetcode.com/problems/binary-tree-postorder-traversal/

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

        self.traverse(root.left, li)
        self.traverse(root.right, li)
        li.append(root.val)
    
    def postorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        li = []
        self.traverse(root, li)
        return li

        