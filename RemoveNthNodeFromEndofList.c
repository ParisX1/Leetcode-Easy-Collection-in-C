/*
Remove Nth Node From End of List
Given the head of a linked list, remove the nth node from the end of the list and return its head.

Example 1:
Input: head = [1,2,3,4,5], n = 2
Output: [1,2,3,5]

Example 2:
Input: head = [1], n = 1
Output: []

Example 3:
Input: head = [1,2], n = 1
Output: [1]

Constraints:

The number of nodes in the list is sz.
1 <= sz <= 30
0 <= Node.val <= 100
1 <= n <= sz
 
Follow up: Could you do this in one pass? No...

https://leetcode.com/explore/interview/card/top-interview-questions-easy/93/linked-list/603/

*/

#include <stdlib.h>
#include <stdio.h>

struct Node {
    int val;
    struct Node *next;
 };
 
struct Node* removeNthFromEnd(struct Node* head, int n){
    int size = 0;
    int i = 1;
    struct Node* nodePtr = head;
       
    // Find size of the list
    while (nodePtr != NULL) {
        nodePtr = nodePtr->next;
        size++;
    }
    printf("Size: %d \n", size);
    
    // If size = 1, remove the node
    if (size == 1) {
        head = NULL;
    }
    // If size > 1 && we are removing the first element
    else if (n == size) {
        head = head->next;
    }
    else {
        // Go to n-1th node
        nodePtr = head;
        while (i < (size - n)) {
            nodePtr = nodePtr->next;
            i++;
        }
        printf("Current node value: %d \n", nodePtr->val);

        // Move the next pointer
        nodePtr->next = nodePtr->next->next;
    }
    return head;
}