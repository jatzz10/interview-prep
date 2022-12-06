// GeeksForGeeks problem link - https://practice.geeksforgeeks.org/problems/nth-node-from-end-of-linked-list

// Linked list structure
struct Node {
  int data;
  struct Node *next;
};

// Solutions -

// 1. Traverse the linked list twice
int getNthFromLast1(Node *head, int n) {
    int count = 0;
    struct Node* curr = head;

    while (curr != NULL) {
        curr = curr->next;
        count++;
    }
    
    if (count < n)
        return -1;
    
    curr = head;
    for (int i = 1; i < count+1-n; i++)
        curr=curr->next;
    
    return curr->data;
}
// Time Complexity - O(N)
// Space Complexity - O(N)
// Auxiliary space - O(1)


// 2. Traverse once and store data sequentially in vector
int getNthFromLast2(Node *head, int n) {
    vector<int> vec;
    int count = 0;
    struct Node* curr = head;
    while (curr != NULL) {
        vec.push_back(curr->data);
        curr = curr->next;
        count++;
    }
    
    return count-n > -1 ? vec[count-n] : -1;
}
// Time Complexity - O(N)
// Space Complexity - O(N)
// Auxiliary space - O(N)


// 3. Two pointers
int getNthFromLast3(Node *head, int n) {
    struct Node* slow = head;
    struct Node* fast = head;
    int count = 1;
    
    while (fast != NULL) {
        if (count > n) {
            slow = slow->next;
        }
        fast = fast->next;
        count++;
    }
    
    return count > n ? slow->data : -1;
// Time Complexity - O(N)
// Space Complexity - O(N)
// Auxiliary space - O(1)

/*
- Approach 2 uses some auxiliary space (extra space) as compared to other two approaches
- Approach 3 will be a bit faster than approach 1, since it traverses the list only once
- Though, it can be argued that approach 3 uses slightly more memory than approch 2, because of additional memory required to store one extra pointer
*/
