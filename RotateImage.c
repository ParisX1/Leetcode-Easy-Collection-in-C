/*
Rotate Image

You are given an n x n 2D matrix representing an image, rotate the image by 90 degrees (clockwise).

You have to rotate the image in-place, which means you have to modify the input 2D matrix directly. DO NOT allocate another 2D matrix and do the rotation.

https://leetcode.com/explore/interview/card/top-interview-questions-easy/92/array/770/

Example 1:
Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
Output: [[7,4,1],[8,5,2],[9,6,3]]

Example 2:
Input: matrix = [[5,1,9,11],[2,4,8,10],[13,3,6,7],[15,14,12,16]]
Output: [[15,13,2,5],[14,3,4,1],[12,6,8,9],[16,7,10,11]]

Constraints:
* n == matrix.length == matrix[i].length
* 1 <= n <= 20
* -1000 <= matrix[i][j] <= 1000
*/

#include <stdio.h>
#include <stdlib.h>

/*
Discussion:
* Move around the outside of the square, swapping each "edge" one value at a time
* Only need to consider n-1 values of the outer surface
* Then we move "in" one onion layer and rotate each inner square, with a shrinking range of values to cover
*/
void rotate(int** matrix, int matrixSize, int* matrixColSize){
   
    int currVal;
    int swapVal;
    
    int currentRow;
    int currentCol;
    int swapRow;
    int swapCol;
    
    // Peel back each layer of the "square onion"
    for (int i = 0; i < matrixSize / 2; i++) {
        
        // Loop over each value in the row
        for (int j = i; j < matrixSize - 1 - i; j++) {
            
            currentRow = i;
            currentCol = j;
            swapVal = matrix[currentRow][currentCol];
            
            // Swap around the surface of the square (four sides)
            for (int counter = 0; counter < 4; counter++) {
                
                swapRow = currentCol;
                swapCol = matrixSize - 1 - currentRow;
                
                currVal = swapVal;
                swapVal = matrix[swapRow][swapCol];

                matrix[swapRow][swapCol] = currVal;
                
                currentRow = swapRow;
                currentCol = swapCol;
            }
        }
    }
}

int main() {
    int matrix01Size = 3;
    int** matrix01 = (int**) malloc(sizeof(int*) * matrix01Size);
    matrix01[0] = (int[]) {1,2,3};
    matrix01[1] = (int[]) {4,5,6};
    matrix01[2] = (int[]) {7,8,9};

    rotate(matrix01, matrix01Size, &matrix01Size);

    for (int i = 0; i < matrix01Size; i++){
        for (int j = 0; j < matrix01Size; j++) printf("%d ", matrix01[i][j]);
        printf("\n");
    }

    return 0;
}