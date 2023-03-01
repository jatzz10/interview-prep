# Problem - https://leetcode.com/problems/binary-tree-inorder-traversal/

# Solutions

# Approach 1

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:

    def inorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        nodes_list = []
        self.traversal(root, nodes_list)
        return nodes_list

    def traversal(self, root, nodes_list):
        if root != None:
            self.traversal(root.left, nodes_list)
            nodes_list.append(root.val)
            self.traversal(root.right, nodes_list)