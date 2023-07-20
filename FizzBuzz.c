/*
Fizz Buzz

Solution
Given an integer n, return a string array answer (1-indexed) where:

answer[i] == "FizzBuzz" if i is divisible by 3 and 5.
answer[i] == "Fizz" if i is divisible by 3.
answer[i] == "Buzz" if i is divisible by 5.
answer[i] == i (as a string) if none of the above conditions are true.
 
https://leetcode.com/explore/interview/card/top-interview-questions-easy/102/math/743/

Example 1:
Input: n = 3
Output: ["1","2","Fizz"]

Example 2:
Input: n = 5
Output: ["1","2","Fizz","4","Buzz"]

Example 3:
Input: n = 15
Output: ["1","2","Fizz","4","Buzz","Fizz","7","8","Fizz","Buzz","11","Fizz","13","14","FizzBuzz"]

Constraints:
1 <= n <= 10^4
*/

// Note: The returned array must be malloced, assume caller calls free().

#include <stdio.h>
#include <stdlib.h>

#define INT_STR_SIZE 10

char ** fizzBuzz(int n, int* returnSize){

    *returnSize = n;
    char** answer = (char**) malloc(sizeof(char*) * n);
    
    for (int i = 1; i <= n; i++) {
        answer[i-1] = (char*) malloc(sizeof(char) * INT_STR_SIZE);        
        
        if (i % 3 == 0 && i % 5 == 0)   sprintf(answer[i-1], "%s", "FizzBuzz");
        else if (i % 3 == 0)            sprintf(answer[i-1], "%s", "Fizz");
        else if (i % 5 == 0)            sprintf(answer[i-1], "%s", "Buzz");
        else                            sprintf(answer[i-1], "%d", i);
    }
    return answer;    
}

int main() {
    int n = 3;
    char** answer = fizzBuzz(n, &n);
    for (int i = 0; i < n; i++) {
        printf("%s \n", answer[i]);
    }
    free(answer);
    return 0;
}