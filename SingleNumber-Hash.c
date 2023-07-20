/*
Single Number

Solution
Given a non-empty array of integers nums, every element appears twice except for one. Find that single one.

You must implement a solution with a linear runtime complexity and use only constant extra space.

https://leetcode.com/explore/interview/card/top-interview-questions-easy/92/array/549/

Example 1:
Input: nums = [2,2,1]
Output: 1

Example 2:
Input: nums = [4,1,2,1,2]
Output: 4

Example 3:
Input: nums = [1]
Output: 1

Constraints:
1 <= nums.length <= 3 * 10^4
-3 * 10^4 <= nums[i] <= 3 * 10^4
Each element in the array appears twice except for one element which appears only once.
*/

#include <stdio.h>
#include <stdbool.h>

struct HashEntry {
    int value;
    int count;
    bool set;
};

/**
 * @brief Get the count value from a hash entry
 * 
 * @param hashTable to search
 * @param valueToFind number for find the count for
 * @return int the number of times that value occurs
 */
int getHashIndex(int tableSize, int valueToHash){
    return valueToHash % tableSize;
}

/**
 * @brief   Add entry currentNumber into the hash table
 *          If the element is already in the table, the count
 *          field is incremented
 * 
 * @param hashTable hash table
 * @param tableSize size of table
 * @param currentNumber number to add
 */
void addHashEntry(struct HashEntry* hashTable, int tableSize, int currentNumber){

    int i = getHashIndex(tableSize, currentNumber);
    
    while (hashTable[i].value != currentNumber && hashTable[i].set == true) {
        i = (i + 1) % tableSize;
    }

    // Entry Found, increment counter
    if (hashTable[i].value == currentNumber) {
        hashTable[i].count++;
    }
    
    // Entry not found, add to table
    else {
        hashTable[i].value = currentNumber;
        hashTable[i].count++;
        hashTable[i].set = true;
    }
}

int singleNumber(int* nums, int numsSize){
    struct HashEntry hashTable[numsSize];
    int currentNumber;
    int hashTableIndex;

    // Set default hash table values
    for (int i = 0; i < numsSize; i++) {
        hashTable[i].value = 0;
        hashTable[i].count = 0;
        hashTable[i].set = false;
    }

    // Add entries to hash table
    for (int i = 0; i < numsSize; i++) {
        currentNumber = nums[i];
        addHashEntry(hashTable, numsSize, currentNumber);
    }

    // Check for the single entry
    for (int i = 0; i < numsSize; i++) {
        if (hashTable[i].count == 1) return hashTable[i].value;
    }
    return 0;
}

int main() {
    int nums[] = {-1, -1, -2};
    int count = 3;
    int result = singleNumber(nums, count);
    printf("%d", result);
}