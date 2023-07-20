
/*
Merge Sorted Array

You are given two integer arrays nums1 and nums2, sorted in non-decreasing order, and two integers m and n, 
representing the number of elements in nums1 and nums2 respectively.

Merge nums1 and nums2 into a single array sorted in non-decreasing order.

The final sorted array should not be returned by the function, but instead be stored inside the array nums1. 
To accommodate this, nums1 has a length of m + n, where the first m elements denote the elements that should be merged, 
and the last n elements are set to 0 and should be ignored. nums2 has a length of n.

https://leetcode.com/explore/interview/card/top-interview-questions-easy/96/sorting-and-searching/587/

*/

#include <stdio.h>

void shiftRight(int* nums1, int nums1Size, int index);

/**
 * @brief 
 * 
 * @param nums1     First sorted array
 * @param nums1Size Size of the nums1 (m + n)
 * @param m         Number of elements in nums1
 * @param nums2     Second sorted array
 * @param nums2Size Size of the nums1 
 * @param n         Number of elements in nums2
 */
void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n){
    int i = 0;
    int j = 0;
    while (i < m && j < n) {
        if (nums1[i] >= nums2[j]) {
            shiftRight(nums1, nums1Size, i);
            nums1[i] = nums2[j];
            i++;
            j++;
            m++;
        } 
        else {
            i++;
        }
    }

    // Clean up remaining numbers
    while (i < m) {
        i++;
    }
    while (j < n) {
        nums1[i] = nums2[j];
        i++;
        j++;
    }

}

void shiftRight(int* nums1, int nums1Size, int index) {
    for (int i = nums1Size - 1; i > index; i--) {
        nums1[i] = nums1[i - 1];
    }
}

int main() {
    int nums1[] = {1,2,3,0,0,0};
    int nums1Size = 6;
    int m = 3;
    int nums2[] = {2,5,6};
    int nums2Size = 3;
    int n = 3;

    merge(nums1, nums1Size, m, nums2, nums2Size, n);

    for (int i = 0; i < nums1Size; i++) {
        printf("%d \n", nums1[i]);
    }
}

/*
                0 1 2 3 4 5                   0 1 2
Input: nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
Output:        [1,2,2,3,5,6]

Explanation: The arrays we are merging are [1,2,3] and [2,5,6].
The result of the merge is [1,2,2,3,5,6] with the underlined elements coming from nums1.
*/
