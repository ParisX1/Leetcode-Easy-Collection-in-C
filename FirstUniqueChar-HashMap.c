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
#include <stdbool.h>

const int HASH_SIZE = 26;
const int ALPHA_A = 97; // ASCII value for 'a'

int hashIndex(char character) {
    return (int) character - ALPHA_A;
}

int firstUniqChar(char * s){

    // Create HashMap
    int hashMap[HASH_SIZE];
    for (int i = 0; i < HASH_SIZE; i++) {
        hashMap[i] = 0;
    }
    
    // First pass of string: set hashmap values to true
    int i = 0;
    while(s[i] != '\0') {
        hashMap[hashIndex(s[i])] ++;
        i++;
    }


    // Second pass: check if any chars are unique
    i = 0;
    while(s[i] != '\0') {
        if (hashMap[hashIndex(s[i])] == 1) {return i;}
        i++;
    }
    return -1;
}

int main() {
    int firstUnique = firstUniqChar("loveleetcode");
    printf("%d", firstUnique);
    return 0;
}