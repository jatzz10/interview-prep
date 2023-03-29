# Problem - 

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

# Approach 1 - Store nodes in hash map
class Solution:
    def getIntersectionNode(self, headA: ListNode, headB: ListNode) -> Optional[ListNode]:
        hm = {}

        current = headA
        while current:
            hm[current] = True
            current = current.next

        current = headB
        while current:
            if current in hm:
                return current
            current = current.next

        return None
# Time complexity - O(m+n) where m and n are no. of nodes in listA and listB respectively
# Space comlexity - O(m+n)
# Auxiliary space - O(m+n)


# Approach 2 - Two pointers
class Solution:
    def getIntersectionNode(self, headA: ListNode, headB: ListNode) -> Optional[ListNode]:
        currentA = headA
        currentB = headB

        while currentA != currentB:
            currentA = headB if currentA is None else currentA.next
            currentB = headA if currentB is None else currentB.next

        return currentA
# Time complexity - O(m+n) where m and n are no. of nodes in l_listA and l_listB respectively
# Space comlexity - O(m+n)
# Auxiliary space - O(1)
