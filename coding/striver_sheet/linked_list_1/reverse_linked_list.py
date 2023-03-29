# Problem - https://leetcode.com/problems/reverse-linked-list

# Solution
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def reverseList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        current = head
        previous = next_node = None

        while current:
            next_node = current.next
            current.next = previous
            previous = current
            current = next_node

        head = previous

        return head
# Time complexity - O(n)
# Space comlexity - O(n)
# Auxiliary space - O(n)