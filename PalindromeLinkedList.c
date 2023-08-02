/*
Palindrome Linked List

Given the head of a singly linked list, return true if it is a palindrome or false otherwise.

https://leetcode.com/explore/interview/card/top-interview-questions-easy/93/linked-list/772/

Example 1:
Input: head = [1,2,2,1]
Output: true

Example 2:
Input: head = [1,2]
Output: false
 
Constraints:
The number of nodes in the list is in the range [1, 105].
0 <= Node.val <= 9
 
Follow up: Could you do it in O(n) time and O(1) space?
*/

#include <stdbool.h>
#include <stdlib.h>

// Definition for singly-linked list.
 struct ListNode {
    int val;
    struct ListNode *next;
 };

// Find the middle node of a linked-list
// If the size if odd, return node n/2 + 1
struct ListNode* getMiddleNode(struct ListNode* head, int listSize) {
    int targetIndex;
    if (listSize % 2 == 0)  targetIndex = listSize / 2;
    else                    targetIndex = listSize / 2 + 1;
    printf("Target Index: %d \n", targetIndex);

    for (int i = 0; i < targetIndex; i++) head = head->next;
    return head;
}

int findListSize(struct ListNode* head) {
    int i = 0;
    while (head != NULL) {
        head = head->next;
        i++;
    }
    return i;
}

// Reverse a linked-list from startNode to end of the list
// Returns a pointer to the last node in the list
struct ListNode* reverseList(struct ListNode* startNode) {
    struct ListNode* prevPtr = NULL;
    struct ListNode* currPtr = startNode;
    struct ListNode* nextPtr;

    while (currPtr != NULL) {
        nextPtr         = currPtr->next;
        currPtr->next   = prevPtr;
        prevPtr         = currPtr;
        currPtr         = nextPtr;
    }
    return prevPtr;
}

bool checkPalindrome(struct ListNode* head, struct ListNode* end) {
    while (end != NULL) {
        if (head->val != end->val)  return false;
        else {
            head = head->next;
            end  = end->next;  
        }
    }
    return true;
}

bool isPalindrome(struct ListNode* head){
    int listSize = findListSize(head);
    if (listSize == 1) return true;
    struct ListNode* middle = getMiddleNode(head, listSize);
    struct ListNode* end = reverseList(middle);
    return checkPalindrome(head, end); 
}