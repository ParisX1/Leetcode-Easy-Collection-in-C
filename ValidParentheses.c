/*
Valid Parentheses

Solution
Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', 
determine if the input string is valid.

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

struct Node {
    char bracket;
    struct Node* next;
};

static struct Node* head;

bool isOpenBracket(char nodeBracket);
bool isStackEmpty();
void pushStack( char nodeBracket);
char popStack();
char getExpectedBracket(char currentChar);

bool isValid(char * s){
    
    if (s[1] == STR_END) return false; // Check for list of size one

    char sChar;         // Current char from the input string
    char stackChar;     // Head char at top of stack
    char expectedChar;  // Expected char that opens a closing sChar bracket
    
    head = NULL; // Init stack
    
    int i = 0;
    while (s[i] != STR_END) {
        sChar = s[i];
        if (isOpenBracket(sChar)) {
            pushStack(sChar);
        }
        else {
            // sChar is close bracket
            if (head == NULL) return false; // Check for empty stack
            stackChar = popStack();
            expectedChar = getExpectedBracket(sChar);
            if (stackChar != expectedChar) return false;
        }
        i++;
    }

    return head == NULL; // Stack should be empty if all brackets closed
} 

bool isOpenBracket(char nodeBracket) {
    return nodeBracket == '(' || nodeBracket == '[' || nodeBracket == '{';
}

bool isStackEmpty() {
    return head == NULL;
}

/**
 * @brief   Push a new node to the top of the stack, creating a new
 *          head node.  Allocate memory for the new node.
 * 
 * @param head the current head of the stack
 * @param nodeBracket the bracket value to create the new node
 */
void pushStack(char nodeBracket) {
    struct Node* node = (struct Node*) malloc(sizeof(struct Node));
    
    if (head == NULL) {
        // Create head node
        head = node;
        head->bracket = nodeBracket;
        head->next = NULL;
    }
    else {
        // Add to stack
        node->bracket = head->bracket;
        node->next = head->next;
        head->bracket = nodeBracket;
        head->next = node;
    }
}

/**
 * @brief   Pop the top node node (head) from the stack, free the head node
 *          from memory and return the char value
 * 
 * @param head the head node
 * @return char bracket value for the head node popped
 */
char popStack() {
    char returnChar = head->bracket;
    struct Node* nodePtr = head->next;
    free(head);
    head = nodePtr;

    //if (head->next == NULL) head == NULL;

    return returnChar;
}

/**
 * @brief   Get the pair bracket expected from a closing bracket.
 *          Ie the bracket that opens a closing bracket.
 * 
 * @param currentChar the closing bracket from the input string
 * @return  char expected as the top bracket on the stack
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
    char* s4 = "((";
    char* s5 = "){";

    bool isValid_s1 = isValid(s1);
    bool isValid_s2 = isValid(s2);
    bool isValid_s3 = isValid(s3);
    bool isValid_s4 = isValid(s4);
    bool isValid_s5 = isValid(s5);

    printf("s1 Output: %d | Expected: 1 \n", isValid_s1);
    printf("s2 Output: %d | Expected: 0 \n", isValid_s2);
    printf("s3 Output: %d | Expected: 1 \n", isValid_s3);
    printf("s4 Output: %d | Expected: 0 \n", isValid_s4);
    printf("s5 Output: %d | Expected: 0 \n", isValid_s5);

    return 0;
}

/*
Notes
You only add the open brackets to the stack.  Once you find a closing
bracket, you pop from the stack and compare.

I think it might be useful to implement a proper stack structure with 
isempty, to setup the first node.  push and pop.
*/