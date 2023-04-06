# Problem - https://leetcode.com/problems/remove-linked-list-elements

# Solutions

# Approach 1: Iterative
class Solution:
    def removeElements(self, head: Optional[ListNode], val: int) -> Optional[ListNode]:
        current = head
        previous = None

        while current:
            if current.val == val:
                if current == head:
                    previous = current.next
                    head = previous
                else:
                    previous.next = current.next
            
            else:
                previous = current
            current = current.next

        return head
# Time Complexity - O(n)
# Space Complexity (auxiliary) - O(1)


# Approach 2: Recursive
class Solution:
    def traverse(self, head, current, previous, val):
        if current is None:
            return head

        if current.val == val:
            if current == head:
                previous = current.next
                head = previous
            else:
                previous.next = current.next
        else:
            previous = current

        return self.traverse(head, current.next, previous, val)

    def removeElements(self, head: Optional[ListNode], val: int) -> Optional[ListNode]:
        return self.traverse(head, head, None, val)
# Time Complexity - O(n)
# Space Complexity (auxiliary) - O(n) [due to recursion call stack]