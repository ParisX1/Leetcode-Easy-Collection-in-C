/*
You are a product manager and currently leading a team to develop a new product. 
Unfortunately, the latest version of your product fails the quality check. 
Since each version is developed based on the previous version, all the versions after a bad version are also bad.

Suppose you have n versions [1, 2, ..., n] and you want to find out the first bad one, 
which causes all the following ones to be bad.

You are given an API bool isBadVersion(version) which returns whether version is bad. 
Implement a function to find the first bad version. You should minimize the number of calls to the API.

https://leetcode.com/explore/interview/card/top-interview-questions-easy/96/sorting-and-searching/774/

Example 1:
Input: n = 5, bad = 4
Output: 4
Explanation:
call isBadVersion(3) -> false
call isBadVersion(5) -> true
call isBadVersion(4) -> true
Then 4 is the first bad version.

Example 2:
Input: n = 1, bad = 1
Output: 1
*/

#include <stdio.h>
#include <stdbool.h>

#define NUMS 4      // Total range of numbers to check 1..n
#define BAD_NUM 4   // The first 

/**
 * @brief Our "contract" given by the probem: is this version number
 * good or bad.
 * 
 * @param version the number to check if it is a "bad" version
 * @return true if bad version
 * @return false if good version
 */
bool isBadVersion(int version) {
    return version >= BAD_NUM;
}

/**
 * @brief find the first "bad" number using binary search
 * i will stop at the last "good" and j will stop at the first "bad"
 * 
 * @param n the number of number to check (1..n)
 * @return int the first "bad number"
 */
int firstBadVersion(int n) {
    if (isBadVersion(1)) return 1;
    long long int i = 1;
    long long int j = n;
    long long int mid = (i + j) / 2;
    while (i < j) {
        if (i == mid) return j;
        if (isBadVersion(mid)) j = mid;
        else (i = mid);
        mid = (i + j) / 2;
    }
    return j;
}

int main() {
    int result = firstBadVersion(NUMS);
    printf("%d", result);
    return 0;
}

/*
n = 5
mid = 2;

 1 2 3 4 5
[g g g b b]

----------

 1 2
[b b]

*/