/*
Pascal's Triangle

Solution
Given an integer numRows, return the first numRows of Pascal's triangle.

In Pascal's triangle, each number is the sum of the two numbers directly above it.

https://leetcode.com/explore/interview/card/top-interview-questions-easy/99/others/601/

Example 1:
Input: numRows = 5
Output: [[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]]

Example 2:
Input: numRows = 1
Output: [[1]]

Constraints:

1 <= numRows <= 30
*/

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** generate(int numRows, int* returnSize, int** returnColumnSizes){

    int** returnArr = (int**) malloc(numRows * sizeof(int*));   // Hold triangle values
    int* columnSizes = (int*) malloc(numRows * sizeof(int));    // Hold sizes of each row for returnColumnSizes
    
    int rowSize = 1;
    for (int i = 0; i < numRows; i++) {
        columnSizes[i] = rowSize;
        returnArr[i] = (int*) malloc(rowSize * sizeof(int));
        for (int j = 0; j < rowSize; j++) {
            if (j == 0 || j == rowSize - 1)  returnArr[i][j] = 1;
            else                             returnArr[i][j] = returnArr[i-1][j-1] + returnArr[i-1][j];
        }
        rowSize++;   
    }
    *returnSize = numRows;              // Required to specify the number of rows in the result
    *returnColumnSizes = columnSizes;   // Required to assign the array of row sizes
    return returnArr;
}