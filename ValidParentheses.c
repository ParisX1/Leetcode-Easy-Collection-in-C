/*
Valid Parentheses

Solution
Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Every close bracket has a corresponding open bracket of the same type.
 
https://leetcode.com/explore/interview/card/top-interview-questions-easy/99/others/721/

Example 1:
Input: s = "()"
Output: true

Example 2:
Input: s = "()[]{}"
Output: true

Example 3:
Input: s = "(]"
Output: false
 
Constraints:

1 <= s.length <= 10^4
s consists of parentheses only '()[]{}'.
*/

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

# define END_STR '\0'

struct ListNode {
    char bracket;
    struct ListNode* next;
};

bool isValid(char * s){
    
    // Create the head node
    struct ListNode head;
    head.bracket = s[0];
    head.next = NULL;
    
    if (s[1] == END_STR) return false; // Check for list of size one

    // Iterate to end of 
    int i = 1;
    while (s[i] != END_STR) {
        //printf("%d : %c \n", i, s[i]);
        //i++;

        struct ListNode* node = (struct ListNode*) malloc(sizeof(struct ListNode));
        node->bracket = head.bracket;
        node->next = head.next;
        head.bracket = s[i];
        head.next = node;

        i++;
    }


    return true;
}

int main() {
    char* s1 = "()[]{}";
    char* s2 = "(]";

    bool isValid_s1 = isValid(s1);
    //bool isValid_s2 = isValid(s2);

    printf("s1 Output: %d | Expected: 1 \n", isValid_s1);
    //printf("s2 Output: %d | Expected: 0 \n", isValid_s2);

    return 0;
}

// NEED TO IMPLEMENT USING A HEAP: LINKED LIST 