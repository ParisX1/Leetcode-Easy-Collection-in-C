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

# define STR_END '\0'

char getExpectedBracket(char currentChar);
bool isOpenBracket(char nodeBracket);
bool isStackEmpty(struct Node* head);

struct Node {
    char bracket;
    struct Node* next;
};

bool isValid(char * s){
    
    // Create head node
    struct Node head;
    head.bracket = s[0];
    head.next = NULL;
    
    if (s[1] == STR_END) return false; // Check for list of size one

    // Create stack 
    int i = 1;
    
    while (s[i] != STR_END) {
    
    }


    /*
    while (s[i] != STR_END) {
       
        struct Node* node = (struct Node*) malloc(sizeof(struct Node));
        node->bracket = head.bracket;
        node->next = head.next;
        head.bracket = s[i];
        head.next = node;
        i++;
        
    }

    // Iterate over stack
    struct Node* nodePtr = &head;
    char currentChar;
    char expectedChar; 
    while (nodePtr->next != NULL) {
        currentChar = nodePtr->bracket;
        expectedChar = getExpectedBracket(currentChar);
        if (expectedChar == STR_END) return false;
        
        // Check next node matches
        nodePtr = nodePtr->next;
        currentChar = nodePtr->bracket;
        if (currentChar != expectedChar) return false;

        if (nodePtr->next != NULL) nodePtr = nodePtr->next;
    } 
    */

    return true;
} 

bool isOpenBracket(char nodeBracket) {
    return nodeBracket == '(' || nodeBracket == '[' || nodeBracket == '{';
}

bool isStackEmpty(struct Node* head) {
    return head == NULL;
}

void pushStack(struct Node* head, char nodeBracket) {
    struct Node* node = (struct Node*) malloc(sizeof(struct Node));
    node->bracket = head->bracket;
    node->next = head->next;
    head->bracket = nodeBracket;
    head->next = node;
}

/**
 * @brief get the expected next bracket expected from the stack
 * 
 * @param currentChar the current bracket from the stack
 * @return  char expected as the next bracket on the stack
 *          return '\0' if char is not found
 */
char getExpectedBracket(char currentChar) {
    if      (currentChar == '}')    return '{';
    else if (currentChar == ']')    return '[';
    else if (currentChar == ')')    return '(';
    else                            return STR_END;
}


int main() {
    char* s1 = "()[]{}";
    char* s2 = "(]";
    char* s3 = "{[]}";

    bool isValid_s1 = isValid(s1);
    bool isValid_s2 = isValid(s2);
    bool isValid_s3 = isValid(s3);

    printf("s1 Output: %d | Expected: 1 \n", isValid_s1);
    printf("s2 Output: %d | Expected: 0 \n", isValid_s2);
    printf("s3 Output: %d | Expected: 1 \n", isValid_s3);

    return 0;
}

/*
You only add the open brackets to the stack.  Once you find a closing
bracket, you pop from the stack and compare.

I think it might be useful to implement a proper stack structure with 
is empty, to setup the first node.  push and pop.

*/