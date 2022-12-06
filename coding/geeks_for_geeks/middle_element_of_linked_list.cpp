// GeeksForGeeks problem link - https://practice.geeksforgeeks.org/problems/finding-middle-element-in-a-linked-list

// Linked list structure
struct Node {
  int data;
  struct Node *next;
};

// Solutions -

// 1. Traverse twice
class Solution1 {
    public:
    int getMiddle(Node *head)
    {
        if (head == NULL) {
            return -1;
        }
        
        struct Node* current = head;
        int count = 0;
        
        while(current != NULL) {
            count++;
            current = current->next;
        }
        
        current = head;
        for (int i = 0; i < count/2; i++) {
            current = current->next;
        }
        
        return current->data;
    }
};
// Time Complexity - O(N)
// Space Complexity - O(N)
// Auxiliary space - O(1)


// 2. Two pointers
class Solution2 {
    public:
    int getMiddle(Node *head)
    {
        if (head == NULL) {
            return -1;
        }
        
        struct Node* slow = head;
        struct Node* fast = head;
        
        while(fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        return slow->data;
    }
};
// Time Complexity - O(N)
// Space Complexity - O(N)
// Auxiliary space - O(1)
