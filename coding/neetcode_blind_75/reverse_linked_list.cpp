// Leetcode problem link - https://leetcode.com/problems/reverse-linked-list

// Solutions -

// 1. Three pointers
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        struct ListNode *current = head;
        struct ListNode *prev = NULL, *next = NULL;

        while (current != NULL) {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        head = prev;
        
        return head;
    }
};
// Time Complexity - O(N)
// Space Complexity - O(N)
// Auxiliary space - O(1)
