/*
Implement strStr()

Solution
Given two strings needle and haystack, return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

https://leetcode.com/explore/interview/card/top-interview-questions-easy/127/strings/885/

Example 1:
Input: haystack = "sadbutsad", needle = "sad"
Output: 0
Explanation: "sad" occurs at index 0 and 6.
The first occurrence is at index 0, so we return 0.

Example 2:
Input: haystack = "leetcode", needle = "leeto"
Output: -1
Explanation: "leeto" did not occur in "leetcode", so we return -1.

Constraints:
1 <= haystack.length, needle.length <= 10^4
haystack and needle consist of only lowercase English characters.
*/

#include<stdio.h>
#include<stdbool.h>
#include<string.h>

bool checkMatch(char* haystackPtr, char * needle, int needleSize) {
    for (int i = 0; i < needleSize; i++) {
        if (*(haystackPtr + i) != *(needle + i)) return false;
    }
    return true;
}

int strStr(char * haystack, char * needle){
    int haystackSize = strlen(haystack);
    int needleSize = strlen(needle);
    char* haystackPtr = haystack;
    int index = 0;

    while (index <= (haystackSize - needleSize)) {
        //printf("%c \n", *(haystack + index));
        if (*haystackPtr == *needle) {
            if (checkMatch(haystackPtr, needle, needleSize)) return index;
        }
        index++;
        haystackPtr++;
    }
    return -1;
}

int main() {
    char* haystack = "sadbutsad";
    char* needle = "sad";
    int result = strStr(haystack, needle);
    printf("%d ", result);
    return 0;
}