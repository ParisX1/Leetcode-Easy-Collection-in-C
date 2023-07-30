/*
Min Stack

Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

Implement the MinStack class:

MinStack() initializes the stack object.
* void push(int val) pushes the element val onto the stack.
* void pop() removes the element on the top of the stack.
* int top() gets the top element of the stack.
* int getMin() retrieves the minimum element in the stack.
You must implement a solution with O(1) time complexity for each function.

https://leetcode.com/explore/interview/card/top-interview-questions-easy/98/design/562/

Example 1:
Input
["MinStack","push","push","push","getMin","pop","top","getMin"]
[[],[-2],[0],[-3],[],[],[],[]]

Output
[null,null,null,null,-3,null,0,-2]

Explanation
MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.getMin(); // return -3
minStack.pop();
minStack.top();    // return 0
minStack.getMin(); // return -2

Constraints:
* -2^31 <= val <= 2^31 - 1
* Methods pop, top and getMin operations will always be called on non-empty stacks.
* At most 3 * 104 calls will be made to push, pop, top, and getMin.
*/

#define MIN_STACK_SIZE 30000

typedef struct {
    int* stackArray;    // Min Heap Stack 
    int* minArray;      // Stack of min values - each index is the min to that point
    int topIndex;       // Top of stack
} MinStack;

MinStack* minStackCreate() {
    MinStack* minStack      = (MinStack*) malloc(sizeof(MinStack));
    minStack->stackArray    = (int*) malloc(sizeof(int) * MIN_STACK_SIZE);
    minStack->minArray      = (int*) malloc(sizeof(int) * MIN_STACK_SIZE);
    minStack->topIndex      = 0;
    return minStack;
}

// This could be improved by using realloc() or reallocarray().  Though might be slower when pushing
void minStackPush(MinStack* obj, int val) {
    
    obj->stackArray[obj->topIndex] = val;
    
    int currentMin;
    if (obj->topIndex == 0) currentMin = val;
    else                    currentMin = obj->minArray[obj->topIndex-1];
        
    if (val <= currentMin)  obj->minArray[obj->topIndex] = val;
    else                    obj->minArray[obj->topIndex] = currentMin;
    
    obj->topIndex = obj->topIndex + 1;
}

// This could be improved by using realloc() or reallocarray()
void minStackPop(MinStack* obj) {
    obj->topIndex = obj->topIndex - 1;
}

int minStackTop(MinStack* obj) {
    return obj->stackArray[obj->topIndex - 1];
}

int minStackGetMin(MinStack* obj) {
    return obj->minArray[obj->topIndex-1];
}

void minStackFree(MinStack* obj) {
    free(obj->stackArray);
    free(obj->minArray);
    free(obj);
}

/**
 * Your MinStack struct will be instantiated and called as such:
 * MinStack* obj = minStackCreate();
 * minStackPush(obj, val);
 
 * minStackPop(obj);
 
 * int param_3 = minStackTop(obj);
 
 * int param_4 = minStackGetMin(obj);
 
 * minStackFree(obj);
*/