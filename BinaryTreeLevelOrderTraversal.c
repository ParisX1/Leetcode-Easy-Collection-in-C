/*
Binary Tree Level Order Traversal

Given the root of a binary tree, return the level order traversal of its nodes' values. (i.e., from left to right, level by level).

https://leetcode.com/explore/interview/card/top-interview-questions-easy/94/trees/628/

Example 1:
Input: root = [3,9,20,null,null,15,7]
Output: [[3],[9,20],[15,7]]

Example 2:
Input: root = [1]
Output: [[1]]
Example 3:

Input: root = []
Output: []

Constraints:
The number of nodes in the tree is in the range [0, 2000].
-1000 <= Node.val <= 1000
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

#include <stdio.h>
#include <stdlib.h>

#define QUEUE_SIZE 2048

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

typedef struct {
    struct TreeNode* queueArray[QUEUE_SIZE];
    int queueSize;
    int queueFront;
    int queueBack;
    
} Queue;

void initializeQueue(Queue *queue) {
    for (int i = 0; i < QUEUE_SIZE; i++) queue->queueArray[i] = NULL;
    queue->queueSize = 0;
    queue->queueFront = 0;
    queue->queueBack = 0;
}

void clearQueue(Queue* queue) {
    for (int i = 0; i < QUEUE_SIZE; i++) queue->queueArray[i] = NULL;
    queue->queueSize = 0;
    queue->queueFront = 0;
    queue->queueBack = 0;
}

void enqueue(Queue* queue, struct TreeNode* node) {
    if (node != NULL) {
        queue->queueArray[queue->queueBack] = node;
        queue->queueSize++;
        queue->queueBack++;
        //printQueue(queue);
    }
}

struct TreeNode* dequeue(Queue* queue) {
    struct TreeNode* returnNode = queue->queueArray[queue->queueFront];
    queue->queueArray[queue->queueFront] = NULL;
    queue->queueFront++;
    queue->queueSize--;
    return returnNode;
}

void printQueue(Queue queue) {
    printf("Array values: ");
    for (int i = 0; i < queue.queueSize; i++) printf("%d ", queue.queueArray[i]->val);
    printf("\nSize: %d ", queue.queueSize);
    printf("\nFront: %d ", queue.queueFront);
    printf("\nBack: %d \n\n", queue.queueBack);
}

/*
* returnSize:           Return an array of arrays of size *returnSize.  You need to set this value
* returnColumnSizes:    The sizes of the arrays are returned as *returnColumnSizes array.  
                        You need to set these values
*/
int** levelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes){
    
    *returnColumnSizes = malloc(sizeof(int));
    int** returnArray = malloc(sizeof(int*));
    *returnArray = malloc(sizeof(int));
    
    Queue queue;
    initializeQueue(&queue);
    enqueue(&queue, root);
    
    *returnSize = 0;
    *returnColumnSizes = 0;
    
    struct TreeNode* nodePtr = NULL;
    while (queue.queueSize > 0) {
        
        (*returnSize)++;

        int currentRowSize = queue.queueSize;
        
        *returnColumnSizes = realloc(*returnColumnSizes, *returnSize * sizeof(int));
        (*returnColumnSizes)[*returnSize - 1] = currentRowSize;
        
        returnArray = realloc(returnArray, sizeof(int*) * (*returnSize));

        returnArray[*returnSize - 1] = (int*) malloc(sizeof(int) * currentRowSize);
        for (int i = 0; i < currentRowSize; i++) {
            nodePtr = dequeue(&queue);
            returnArray[*returnSize - 1][i] = nodePtr->val;
            if (nodePtr->left != NULL)   enqueue(&queue, nodePtr->left);
            if (nodePtr->right != NULL)  enqueue(&queue, nodePtr->right);
        }
    }
    
    return returnArray;
}

/* Driver Code for Testing */

int main() {

    struct TreeNode node1;
    struct TreeNode node2;
    struct TreeNode node3;
    struct TreeNode node4;
    struct TreeNode node5;

    node1.val = 3;
    node2.val = 9;
    node3.val = 20;
    node4.val = 15;
    node5.val = 7;

    node1.left  = &node2;
    node1.right = &node3;
    node2.left  = NULL;
    node2.right = NULL;
    node3.left  = &node4;
    node3.right = &node5;
    node4.left  = NULL;
    node4.right  = NULL;
    node5.left  = NULL;
    node5.right  = NULL;
  
    int returnSize;
    int* returnColumnSizes;
    int** resultArray = levelOrder(&node1, &returnSize, &returnColumnSizes);
    
    for (int i = 0; i < returnSize; i++) {
        for (int j = 0; j < returnColumnSizes[i]; j++) {
            printf("%d ", resultArray[i][j]);
        }
        printf("\n");
    }

    return 0;
}