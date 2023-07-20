/*
Longest Common Prefix

Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string "".

https://leetcode.com/explore/interview/card/top-interview-questions-easy/127/strings/887/ 

Example 1:
Input: strs = ["flower","flow","flight"]
Output: "fl"

Example 2:
Input: strs = ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.

Constraints:

1 <= strs.length <= 200
0 <= strs[i].length <= 200
strs[i] consists of only lowercase English letters.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define BUFFER_SIZE 256
#define STRING_TERMINATOR '\0'

char * longestCommonPrefix(char ** strs, int strsSize){
    int strOffset = 0;
    char* result = (char*) malloc(sizeof(char) * BUFFER_SIZE);
    char currentChar;
    //printf("%d",strsSize);
    
    bool matchFound = true;
    bool terminatorFound = false;
    
    while (matchFound && !terminatorFound) {
        int i = 0;
        currentChar = strs[i][strOffset];
        while (i < strsSize && !terminatorFound) {
            if (strs[i][strOffset] != currentChar)        matchFound = false; 
            if (strs[i][strOffset] == STRING_TERMINATOR)  terminatorFound = true;
            i++;
        }
        if (matchFound && !terminatorFound) result[strOffset] = currentChar;
        strOffset++;
    }
    result[strOffset-1] = STRING_TERMINATOR;
    //printf("%s", result);
    return result;
}

int main() {
    int strsSize = 3;
    char** strs = (char**) malloc(strsSize * sizeof(char*)); 
    strs[0] = strdup("flower");
    strs[1] = strdup("flow");
    strs[2] = strdup("flight");
    
    char* result = longestCommonPrefix(strs, strsSize);
    printf("%s \n", result);
}