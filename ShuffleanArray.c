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

void copyArray(int* sourceArr, int* targetArr, int size) {
    for (int i = 0; i < size; i++) {
        targetArr[i] = sourceArr[i];
    }
}

/*
* Initializes the object with the integer array nums
*/
Solution* solutionCreate(int* nums, int numsSize) {
    Solution* solutionPtr = (Solution*) malloc(sizeof(Solution)); 
    
    // Allocate memory for struct Arrays
    int* origArr = (int*) malloc(sizeof(int) * numsSize);
    int* currArr = (int*) malloc(sizeof(int) * numsSize);

    // Copy values from nums[] into struct arrays
    copyArray(nums, origArr, numsSize);
    copyArray(origArr, currArr, numsSize);
    
    // Set struct values
    solutionPtr->arraySize = numsSize;
    solutionPtr->originalArray = origArr;
    solutionPtr->currentArray = currArr;
    return solutionPtr;
}

/*
* Resets the array to its original configuration 
*/
int* solutionReset(Solution* obj, int* retSize) {
    *retSize = obj->arraySize;
    copyArray(obj->originalArray, obj->currentArray, *retSize);
    return obj->currentArray;
}

/**
 * Returns a random shuffling of the array
 * Uses Algorithm for "Randomly permuting arrays" - CLRS (3rd Ed) p126
 * For use of rand() see C Programming A Modern Approach (2nd Ed) by King pp172-193
 */
int* solutionShuffle(Solution* obj, int* retSize) {
    *retSize = obj->arraySize;
    //srand((unsigned) time(NULL)); // Removed or would not pass Leetcode - all random numbers were the same!
    int randomIndex;
    int temp;
    int* arrayPtr = obj->currentArray;
    for (int i = 0; i < *retSize - 1; i++) {
        randomIndex = rand() % ((*retSize - i)) + i;
        //printf("%d\n", randomIndex);
        temp = arrayPtr[i];
        arrayPtr[i] = arrayPtr[randomIndex];
        arrayPtr[randomIndex] = temp;
    }
    return obj->currentArray;
}

void solutionFree(Solution* obj) {
    free(obj->currentArray);
    free(obj->originalArray);
    free(obj);
}

////////////// Driver code below //////////////

void printArray(int* objArray, int* retSize) {
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