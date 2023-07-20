/*
Reverse String

Write a function that reverses a string. The input string is given as an array of characters s.
You must do this by modifying the input array in-place with O(1) extra memory.

https://leetcode.com/explore/interview/card/top-interview-questions-easy/127/strings/879/
*/

#include <stdio.h>

void reverseString(char* s, int sSize){
    char currentChar;
    for (int i = 0; i < sSize / 2; i++) {
        currentChar = s[i];
        s[i] = s[sSize - i - 1];
        s[sSize - i - 1] = currentChar;
    }
}

int main() {
    char s[5] = {'h','e','l','l','o'};
    reverseString(s, 5);
    printf(s);
}

/*
          0   1   2   3   4 
Input:  ["h","e","l","l","o"]
Output: ["o","l","l","e","h"]
*/