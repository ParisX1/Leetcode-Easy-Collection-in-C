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

#define QUEUE_SIZE 1024

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
* Return an array of arrays of size *returnSize.  You need to set this value
* The sizes of the arrays are returned as *returnColumnSizes array.  You need to set these values
*/
int** levelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes){
    
    int** returnArray = NULL;
    
    Queue queue;
    initializeQueue(&queue);
    enqueue(&queue, root);
    
    returnSize = (int*) malloc(sizeof(int));
    *returnSize = 0;
    returnColumnSizes = (int**) malloc(sizeof(int*));
    
    struct TreeNode* nodePtr = NULL;
    while (queue.queueSize > 0) {
        
        *returnSize++;
        
        int* currentRowSize = (int*) malloc(sizeof(int));
        *currentRowSize = queue.queueSize;
        
        // (int*) reallocarray(intersectTable, arraySize, sizeof(int));
        
        returnColumnSizes = reallocarray(&returnColumnSizes, *returnSize, sizeof(int));
        //realloc(&returnColumnSizes, *returnSize);
        returnColumnSizes[*returnSize - 1] = currentRowSize;
        
        int* currentRowValueArray = (int*) malloc(sizeof(int) * *currentRowSize);
        for (int i = 0; i < *currentRowSize; i++) {
            nodePtr = dequeue(&queue);
            currentRowValueArray[i] = nodePtr->val;
            if (nodePtr->left != NULL)   enqueue(&queue, nodePtr->left);
            if (nodePtr->right != NULL)  enqueue(&queue, nodePtr->right);
        }
        
        realloc(&returnArray, *returnSize);
        returnArray[*returnSize - 1] = currentRowValueArray;
        
    }
    
    return returnArray;
    
}