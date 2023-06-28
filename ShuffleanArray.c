/*
Shuffle an Array

Solution
Given an integer array nums, design an algorithm to randomly shuffle the array. All permutations of the array should be equally likely as a result of the shuffling.

Implement the Solution class:

Solution(int[] nums) Initializes the object with the integer array nums.
int[] reset() Resets the array to its original configuration and returns it.
int[] shuffle() Returns a random shuffling of the array.
 
https://leetcode.com/explore/interview/card/top-interview-questions-easy/98/design/670/

Example 1:
Input
["Solution", "shuffle", "reset", "shuffle"]
[[[1, 2, 3]], [], [], []]
Output
[null, [3, 1, 2], [1, 2, 3], [1, 3, 2]]

Explanation
Solution solution = new Solution([1, 2, 3]);
solution.shuffle();    // Shuffle the array [1,2,3] and return its result.
                       // Any permutation of [1,2,3] must be equally likely to be returned.
                       // Example: return [3, 1, 2]
solution.reset();      // Resets the array back to its original configuration [1,2,3]. Return [1, 2, 3]
solution.shuffle();    // Returns the random shuffling of array [1,2,3]. Example: return [1, 3, 2]

 
Constraints:

1 <= nums.length <= 50
-10^6 <= nums[i] <= 10^6
All the elements of nums are unique.
At most 104 calls in total will be made to reset and shuffle.
*/

#include <stdio.h>
#include <time.h>
#include <stdlib.h>


typedef struct {
    int arraySize;
    int* originalArray;
    int* currentArray;

} Solution;

/*
* Initializes the object with the integer array nums
*/
Solution* solutionCreate(int* nums, int numsSize) {
    Solution* newSolutionPtr = (Solution*) malloc(sizeof(Solution));
    newSolutionPtr->arraySize = numsSize;
    newSolutionPtr->originalArray = nums;
    newSolutionPtr->currentArray = nums;
    return newSolutionPtr;
}

/*
* Resets the array to its original configuration 
*/
int* solutionReset(Solution* obj, int* retSize) {
    obj->currentArray = obj->originalArray;
    return obj->currentArray;
}

/**
 * Returns a random shuffling of the array
 */
int* solutionShuffle(Solution* obj, int* retSize) {
    srand(time(NULL));   
    int randomIndex;
    int temp;
    int* arrayPtr = obj->currentArray;
    for (int i = 0; i < *retSize; i++) {
        randomIndex = rand() % *retSize; 
        temp = arrayPtr[i];
        arrayPtr[i] = arrayPtr[randomIndex];
        arrayPtr[randomIndex] = temp;
    }
    return obj->currentArray;
}

void solutionFree(Solution* obj) {
    free(obj);
}

// Driver code below //

void printArray(int* objArray, int* retSize) {
    //int* arrayPtr = obj->currentArray;
    printf("~ Array ~\n");
    for (int i = 0; i < *retSize; i++) {
        printf("%d \n", objArray[i]);
    }
    printf("~~~\n\n");
}

int main() {

    int nums[] = {1, 2, 3};
    int numsSize = 3;

    Solution* obj = solutionCreate(nums, numsSize);
    printArray(obj->currentArray, &numsSize);
    int* param_1 = solutionReset(obj, &numsSize); 
    printArray(param_1, &numsSize);
    int* param_2 = solutionShuffle(obj, &numsSize);
    printArray(param_2, &numsSize);
    solutionFree(obj);
}

/**
 * Your Solution struct will be instantiated and called as such:
 * Solution* obj = solutionCreate(nums, numsSize);
 * int* param_1 = solutionReset(obj, retSize);
 * int* param_2 = solutionShuffle(obj, retSize);
 * solutionFree(obj);
*/