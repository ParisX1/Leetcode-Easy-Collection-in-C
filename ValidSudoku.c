/*
Valid Sudoku

Determine if a 9 x 9 Sudoku board is valid. Only the filled cells need to be validated according to the following rules:
1. Each row must contain the digits 1-9 without repetition.
2. Each column must contain the digits 1-9 without repetition.
3/ Each of the nine 3 x 3 sub-boxes of the grid must contain the digits 1-9 without repetition.

Note:
* A Sudoku board (partially filled) could be valid but is not necessarily solvable.
* Only the filled cells need to be validated according to the mentioned rules.

https://leetcode.com/explore/interview/card/top-interview-questions-easy/92/array/769/

Example 1:
Input: board = 
[["5","3",".",".","7",".",".",".","."]
,["6",".",".","1","9","5",".",".","."]
,[".","9","8",".",".",".",".","6","."]
,["8",".",".",".","6",".",".",".","3"]
,["4",".",".","8",".","3",".",".","1"]
,["7",".",".",".","2",".",".",".","6"]
,[".","6",".",".",".",".","2","8","."]
,[".",".",".","4","1","9",".",".","5"]
,[".",".",".",".","8",".",".","7","9"]]
Output: true

Example 2:
Input: board = 
[["8","3",".",".","7",".",".",".","."]
,["6",".",".","1","9","5",".",".","."]
,[".","9","8",".",".",".",".","6","."]
,["8",".",".",".","6",".",".",".","3"]
,["4",".",".","8",".","3",".",".","1"]
,["7",".",".",".","2",".",".",".","6"]
,[".","6",".",".",".",".","2","8","."]
,[".",".",".","4","1","9",".",".","5"]
,[".",".",".",".","8",".",".","7","9"]]
Output: false

Explanation: Same as Example 1, except with the 5 in the top left corner being modified to 8. Since there are two 8's in the top left 3x3 sub-box, it is invalid.

Constraints:
* board.length == 9
* board[i].length == 9
* board[i][j] is a digit 1-9 or '.'.
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define ASCII_ZERO_VALE 48
#define NO_VALUE '.'
#define BOARD_SIZE 9

typedef struct  {
    bool isNumberUsed[BOARD_SIZE + 1];
    bool isValid;
} BoardChecker;

void initBoardChecker(BoardChecker* checker) {
    for (int i = 0; i < BOARD_SIZE + 1; i++) checker->isNumberUsed[i] = false;
    checker->isValid = true;
}

int charAsInt(char numberAsChar) {
    return numberAsChar - ASCII_ZERO_VALE;
}

// Returns true if all the numbers in all rows are unique
bool checkRows(char** board) {
    BoardChecker checker;
    char currentChar;
    int currentValue;
    for (int row = 0; row < BOARD_SIZE; row++) {
        initBoardChecker(&checker);
        for (int col = 0; col < BOARD_SIZE; col++) {
            currentChar = board[row][col];
            if (currentChar != NO_VALUE) {
                currentValue = charAsInt(currentChar);
                if (currentValue < 1 || currentValue > BOARD_SIZE)  return false;
                if (checker.isNumberUsed[currentValue])             return false;
                else checker.isNumberUsed[currentValue] = true;
            }
        }
    }
    return true;
}

// Returns true if all the numbers in all cols are unique
bool checkColumns(char** board) {
    BoardChecker checker;
    char currentChar;
    int currentValue;
    for (int row = 0; row < BOARD_SIZE; row++) {
        initBoardChecker(&checker);
        for (int col = 0; col < BOARD_SIZE; col++) {
            currentChar = board[col][row];
            if (currentChar != NO_VALUE) {
                currentValue = charAsInt(currentChar);
                if (currentValue < 1 || currentValue > BOARD_SIZE)  return false;
                if (checker.isNumberUsed[currentValue])             return false;
                else checker.isNumberUsed[currentValue] = true;
            }
        }
    }
    return true;
}

// Returns true if all the numbers in all sub arrays are unique
bool checkSubArrays(char** board) {
    BoardChecker checker;
    char currentChar;
    int currentValue;
    int rowOffset = 0;
    int colOffset = 0;
    int subArraySize = sqrt(BOARD_SIZE); // subArraySize = 3
    for (int subArray = 0; subArray < BOARD_SIZE; subArray++) {
        initBoardChecker(&checker);
        rowOffset = (subArray / subArraySize) * subArraySize;
        for (int subArrayVal = 0; subArrayVal < BOARD_SIZE; subArrayVal++) {
            int row = MAX(subArrayVal / subArraySize, 0) + rowOffset;
            int col = (subArrayVal % subArraySize) + colOffset;
            /*
            printf("subarray: %d | ", subArray);
            printf("subarray value index: %d \n", subArrayVal);
            printf("row: %d | ", row);
            printf("col: %d \n", col);
            printf("row offset: %d | ", rowOffset);
            printf("col offset: %d \n", colOffset);
            printf("~~~ \n");
            */
            currentChar = board[row][col];
            if (currentChar != NO_VALUE) {
                currentValue = charAsInt(currentChar);
                if (currentValue < 1 || currentValue > BOARD_SIZE)  return false;
                if (checker.isNumberUsed[currentValue])             return false;
                else checker.isNumberUsed[currentValue] = true;
            }
        }
        colOffset = (colOffset + subArraySize) % BOARD_SIZE;
    }
    return true;
}

bool isValidSudoku(char** board, int boardSize, int* boardColSize) {
    *boardColSize = boardSize;
    if (!checkRows(board)) return false;
    if (!checkColumns(board)) return false;
    if (!checkSubArrays(board)) return false;
    return true;
}

int main () {

    int boardSize = BOARD_SIZE;

    char** board01 = (char**) malloc(sizeof(char*) * BOARD_SIZE);
    board01[0] = (char[]) {'5','3','.','.','7','.','.','.','.'};
    board01[1] = (char[]) {'6','.','.','1','9','5','.','.','.'};
    board01[2] = (char[]) {'.','9','8','.','.','.','.','6','.'};
    board01[3] = (char[]) {'8','.','.','.','6','.','.','.','3'};
    board01[4] = (char[]) {'4','.','.','8','.','3','.','.','1'};
    board01[5] = (char[]) {'7','.','.','.','2','.','.','.','6'};
    board01[6] = (char[]) {'.','6','.','.','.','.','2','8','.'};
    board01[7] = (char[]) {'.','.','.','4','1','9','.','.','5'};
    board01[8] = (char[]) {'.','.','.','.','8','.','.','7','9'};

    char** board02 = (char**) malloc(sizeof(char*) * BOARD_SIZE);
    board02[0] = (char[]) {'8','3','.','.','7','.','.','.','.'};
    board02[1] = (char[]) {'6','.','.','1','9','5','.','.','.'};
    board02[2] = (char[]) {'.','9','8','.','.','.','.','6','.'};
    board02[3] = (char[]) {'8','.','.','.','6','.','.','.','3'};
    board02[4] = (char[]) {'4','.','.','8','.','3','.','.','1'};
    board02[5] = (char[]) {'7','.','.','.','2','.','.','.','6'};
    board02[6] = (char[]) {'.','6','.','.','.','.','2','8','.'};
    board02[7] = (char[]) {'.','.','.','4','1','9','.','.','5'};
    board02[8] = (char[]) {'.','.','.','.','8','.','.','7','9'};

    char** board03 = (char**) malloc(sizeof(char*) * BOARD_SIZE);
    board03[0] = (char[]) {'.','.','.','.','5','.','.','1','.'};
    board03[1] = (char[]) {'.','4','.','3','.','.','.','.','.'};
    board03[2] = (char[]) {'.','.','.','.','.','3','.','.','1'};
    board03[3] = (char[]) {'8','.','.','.','.','.','.','2','.'};
    board03[4] = (char[]) {'.','.','2','.','7','.','.','.','.'};
    board03[5] = (char[]) {'.','1','5','.','.','.','.','.','.'};
    board03[6] = (char[]) {'.','.','.','.','.','2','.','.','.'};
    board03[7] = (char[]) {'.','2','.','9','.','.','.','.','.'};
    board03[8] = (char[]) {'.','.','4','.','.','.','.','.','.'};

    printf("Board 1: %d \t Expected: 1\n", isValidSudoku(board01, BOARD_SIZE, &boardSize));
    printf("Board 2: %d \t Expected: 0\n", isValidSudoku(board02, BOARD_SIZE, &boardSize));
    printf("Board 3: %d \t Expected: 0\n", isValidSudoku(board03, BOARD_SIZE, &boardSize));

    return 0;
}

