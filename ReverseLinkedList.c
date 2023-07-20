/*
Reverse Linked List

Solution
Given the head of a singly linked list, reverse the list, and return the reversed list.

https://leetcode.com/explore/interview/card/top-interview-questions-easy/93/linked-list/560/

Example 1:

Input: head = [1,2,3,4,5]
Output: [5,4,3,2,1]

Example 2:
Input: head = [1,2]
Output: [2,1]

Example 3:
Input: head = []
Output: []
 

Constraints:
The number of nodes in the list is the range [0, 5000].
-5000 <= Node.val <= 5000

Follow up: A linked list can be reversed either iteratively or recursively. Could you implement both?
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include <stddef.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* reverseList(struct ListNode* head){       
    struct ListNode* prevPtr = NULL;
    struct ListNode* nextPtr = head;
    while(head != NULL) {
        nextPtr = head->next;
        head->next = prevPtr;
        prevPtr = head;
        head = nextPtr;
    }
    return prevPtr;
}

////////////// Driver code below //////////////

int main() {

    struct ListNode third =     {3, NULL};
    struct ListNode second =    {2, &third};
    struct ListNode first =     {1, &second}; 
    
    printf("Original List:\t");
    struct ListNode* listNodePtr = &first;
    while (listNodePtr != NULL) {
        printf("%d ", listNodePtr->val);
        listNodePtr = listNodePtr->next;
    }

    listNodePtr = reverseList(&first);
   
    printf("\nReverse List:\t");
    while (listNodePtr != NULL) {
        printf("%d ", listNodePtr->val);
        listNodePtr = listNodePtr->next;
    }

    return 0;
}