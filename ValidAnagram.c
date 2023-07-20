/*
Valid Anagram

Solution
Given two strings s and t, return true if t is an anagram of s, and false otherwise.

An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

https://leetcode.com/explore/interview/card/top-interview-questions-easy/127/strings/882/

Example 1:
Input: s = "anagram", t = "nagaram"
Output: true

Example 2:
Input: s = "rat", t = "car"
Output: false

Constraints:

1 <= s.length, t.length <= 5 * 10^4
s and t consist of lowercase English letters.
*/

#include <math.h>
#include <stdbool.h>
#include <string.h>
#define ALPHA_SIZE 26
#define ASCII_a 97
#define UNSIGNED_LONG_MAX 18446744073709551615 - 1

unsigned long hash(char charToHash);

bool isAnagram(char * s, char * t){
        
    int strLenS = strlen(s);
    int strLenT = strlen(t);
    
    if (strLenS != strLenT) return false;
    
    unsigned long letterSum = 0;
    for (int i = 0; i < strLenS; i++) {
        letterSum += hash(s[i]);
        letterSum -= hash(t[i]);
    }
    
    return letterSum == 0;
}

/*
* Polynomial hashing function 
*/
unsigned long hash(char charToHash) {
    unsigned long hashValue = charToHash + 3;
    hashValue += hashValue * 7;
    hashValue += (hashValue * hashValue  * hashValue) % UNSIGNED_LONG_MAX;
    return hashValue;
    //return (charToHash + 3) + (charToHash * 7) + (charToHash * charToHash * charToHash);
}