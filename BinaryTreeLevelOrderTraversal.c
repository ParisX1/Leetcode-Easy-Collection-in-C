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
    int queueArray[QUEUE_SIZE];
    int queueSize;
    int queueFront;
    int queueBack;
    
} Queue;

void initializeQueue(Queue *queue) {
    for (int i = 0; i < QUEUE_SIZE; i++) queue->queueArray[i] = 0;
    queue->queueSize = 0;
    queue->queueFront = 0;
    queue->queueBack = 0;
}

void clearQueue(Queue* queue) {
    for (int i = 0; i < QUEUE_SIZE; i++) queue->queueArray[i] = 0;
    queue->queueSize = 0;
    queue->queueFront = 0;
    queue->queueBack = 0;
}

void enqueue(Queue* queue, int valToAdd) {
    queue->queueArray[queue->queueBack] = valToAdd;
    queue->queueSize++;
    queue->queueBack++;
    //printQueue(queue);
}

int dequeue(Queue* queue) {
    int returnVal = queue->queueArray[queue->queueFront];
    queue->queueArray[queue->queueFront] = 0;
    queue->queueFront++;
    queue->queueSize--;
    return returnVal;
}

void printQueue(Queue queue) {
    printf("Array values: ");
    for (int i = 0; i < queue.queueSize; i++) printf("%d ", queue.queueArray[i]);
    printf("\nSize: %d ", queue.queueSize);
    printf("\nFront: %d ", queue.queueFront);
    printf("\nBack: %d \n\n", queue.queueBack);
}

int** levelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes){
    Queue queue;
    initializeQueue(&queue);
    
    printf("~ Queue Initialized ~ \n");
    printQueue(queue);
    
    enqueue(&queue, 5);
    enqueue(&queue, 10);
    enqueue(&queue, 15);
    
    printf("~ Queue Values Added ~ \n");
    printQueue(queue);
    
    
    printf("~ Dequeue Values~ \n");
    printf("%d \n", dequeue(&queue));
    printf("%d \n", dequeue(&queue));
    printf("%d \n\n", dequeue(&queue));
    
    printf("~ Final Queue ~ \n");
    printQueue(queue);
    
    int* arr[] = {};
    return &arr;
    
}