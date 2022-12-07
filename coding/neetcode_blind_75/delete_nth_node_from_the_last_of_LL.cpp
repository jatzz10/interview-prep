// Leetcode problem link - https://leetcode.com/problems/remove-nth-node-from-end-of-list

// Solutions -

// 1. Two pointers
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        struct ListNode *slow = head, *fast = head, *prev = head;
        int count = 1;

        // find nth node from last
        while (fast != NULL) {
            prev = slow;
            if (count > n) {
                slow = slow->next;
            }
            fast = fast->next;
            count++;
        }

        // delete nth node
        if (count-n == 1) {
            head = slow->next;
        } else {
            prev->next = slow->next;
        }
        slow->next = NULL;

        return head;
    }
};
// Time Complexity - O(N)
// Space Complexity - O(N)
// Auxiliary space - O(1)
