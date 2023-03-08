# Problem - https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree

# Solutions

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

# Approach - Iterative
class Solution1:
    def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
        while root:
            if root.val < p.val and root.val < q.val:
                root = root.right
            elif root.val > p.val and root.val > q.val:
                root = root.left
            else:
                return root
# Time complexity - O(h) where h = height of tree
# Space complexity - O(n) where n = nodes of tree
# Auxiliary space - O(1)


# Approach - Recursive
class Solution2:
    def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
        if root is None:
            return

        if root.val < p.val and root.val < q.val:
            return self.lowestCommonAncestor(root.right, p, q)
        elif root.val > p.val and root.val > q.val:
            return self.lowestCommonAncestor(root.left, p, q)
        else:
            return root
# Time complexity - O(h) where h = height of tree
# Space complexity - O(n)
# Auxiliary space - O(h) [each recursion call takes some memory in stack]