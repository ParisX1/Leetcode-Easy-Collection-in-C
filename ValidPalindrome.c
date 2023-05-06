/*
Valid Palindrome

A phrase is a palindrome if, after converting all uppercase letters into lowercase letters and removing all non-alphanumeric characters, it reads the same forward and backward. Alphanumeric characters include letters and numbers.

Given a string s, return true if it is a palindrome, or false otherwise.

Constraints:
1 <= s.length <= 2 * 10^5
s consists only of printable ASCII characters.

https://leetcode.com/explore/interview/card/top-interview-questions-easy/127/strings/883/

Example 1:
Input: s = "A man, a plan, a canal: Panama"
Output: true
Explanation: "amanaplanacanalpanama" is a palindrome.

Example 2:
Input: s = "race a car"
Output: false
Explanation: "raceacar" is not a palindrome.

Example 3:
Input: s = " "
Output: true
Explanation: s is an empty string "" after removing non-alphanumeric characters.
Since an empty string reads the same forward and backward, it is a palindrome.
*/

#include <stdbool.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

bool isPalindrome(char * s){

    //if (s == "" || s == " " || s == NULL) {return true;} // Check for empty string
    //if (strcmp(s, " ") == 0) {return true;} // Check for empty string
    //if (strlen(s) == 1) {return true;} // Check for single char string

    int i = 0;
    int j = 0;
    char charLeft;
    char charRight;

    // Move j to end of string
    while (s[j+1] != '\0') {j++;}

    // Loop over string
    while (i < j) {
        while (isalnum(s[i]) == 0 && i < j) {i++;}
        while (isalnum(s[j]) == 0 && i < j) {j--;}
        
        if (i < j) {
            charLeft = tolower(s[i]);
            charRight = tolower(s[j]);
            if (charLeft != charRight) {return false;} 
            i++;
            j--;
        }
    }
    return true;
}

int main() {

    // Example 1
    char* s1 = "A man, a plan, a canal: Panama";
    printf("1. Result: %d | Expected: 1 \n" , isPalindrome(s1));

    // LC Test case
    char* s2 = ".,";
    printf("2. Result: %d | Expected: 1 \n" , isPalindrome(s2));

    // Example 3
    char* s3 = " ";
    printf("3. Result: %d | Expected: 1 \n" , isPalindrome(s3));

    // LC Test case
    char* s4 = "a.,";
    printf("4. Result: %d | Expected: 1 \n" , isPalindrome(s4));

    // LC Test case
    char* s5 = ".,";
    printf("5. Result: %d | Expected: 1 \n" , isPalindrome(s5));

    // LC Test case
    char* s6 = "0P";
    printf("5. Result: %d | Expected: 0 \n" , isPalindrome(s6));

    return 0;
}
