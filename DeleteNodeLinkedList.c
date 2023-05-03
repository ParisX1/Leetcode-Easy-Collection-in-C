/**
There is a singly-linked list head and we want to delete a node node in it.

You are given the node to be deleted node. You will not be given access to the first node of head.

All the values of the linked list are unique, and it is guaranteed that the given node node is not the last node in the linked list.

Delete the given node. Note that by deleting the node, we do not mean removing it from memory. We mean:
* The value of the given node should not exist in the linked list.
* The number of nodes in the linked list should decrease by one.
* All the values before node should be in the same order.
* All the values after node should be in the same order.
 */

#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
 };

void deleteNode(struct ListNode* node) {
    while (node->next->next != NULL) {
        
        node->val = node->next->val;
        node = node->next;
    }
    node->val = node->next->val;
    node->next = NULL;
}

int main() {

    struct ListNode one; 
    struct ListNode two;
    struct ListNode three;
    struct ListNode four;

    one.val = 4;
    two.val = 5;
    three.val = 1;
    four.val = 9;
    one.next = &two;
    two.next = &three;
    three.next = &four;
    
    deleteNode(&two);
    return 0;
}

/*
Input: head = [4,5,1,9], node = 5
Output: [4,1,9]
*/