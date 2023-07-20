/*
First Unique Character in a String

Given a string s, find the first non-repeating character in it and return its index. 
If it does not exist, return -1.

https://leetcode.com/explore/interview/card/top-interview-questions-easy/127/strings/881/

Example 1:
Input: s = "leetcode"
Output: 0

Example 2:
Input: s = "loveleetcode"
Output: 2

Example 3:
Input: s = "aabb"
Output: -1
*/

#include <stdio.h>

int firstUniqChar(char * s){
    int i = 0;
    int j;
        
    while(s[i] != '\0') {
        j = 0;
        while(s[j] != '\0') {
            if (s[i] == s[j] && i != j) {
                break;
                }
            j++;
        }
        if (s[j] == '\0') {return i;}
        i++;
    }
    return -1;
}

int main() {
    int firstUnique = firstUniqChar("leetcode");
    printf("%d", firstUnique);
    return 0;
}