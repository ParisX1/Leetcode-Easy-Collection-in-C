# Leetcode
Solutions to Leetcode Easy "Top Interview Questions" in c

[Leetcode Easy Collection Top Interview Questions](https://leetcode.com/explore/interview/card/top-interview-questions-easy/)  

These were completed in preparation for Georgia Tech's _Graduate Introduction to Operating Systems_ class, summer 2023.  Although the class is not an algorithms class, it heavily uses c, and so Leetcode seemed a good way to practice c coding.

Notes / references for various algorithms below.

## Valid Parentheses
Implemented a stack, following the general outline from Sedgewick's _Algorithms in C_.  

The problem is to check if a string of parentheses are outlined in the "correct" order.

### Key Features
* Stack implementation using linked list
* Static variable to head node.  This was the key insight from Sedgewick
* Includes a lot of checks for invalid pop/push operations, eg a pop when the stack is empty
* Needed quite a few tests to pass LC

## Single Number Hash
Good reference code for structs, a simple hash table, and passing pointers to the struct array between methods.

The problem is to take an int array where all the numbers in an array are included twice, except for one, which is included twice.  Return the number that is included only once.

This is supposed to be implemented using XOR operations, but the version implemented here uses a simple hash table.

### Key Features
* (Simplified) Hash table implmentation
* Creates structs to hold information for the hash table entries
* An array of structs constitutes the hash table
* Pointers to the array is passed into functions to add to, and retrieve data from, the hash table

## Fizz Buzz
This was actually really hard for me to do in c.  You need to dynamically allocate (malloc) space for each of the strings.

The problem is to take an int n, and save into an array FIZZ/BUZZ for each number 1..n.

### Key Features
* Create an array of string -> ie an array of pointers to char pointers.  The array is of type char**
* malloc for the base array of char* pointers
* malloc for each of the strings
* Uses sprintf to create the strings and return pointers.  See C Programming A Modern Approach (King) p783

# References
* C Programming A Modern Approach _2nd ed_, King (2008)
* The C Programming Language _2nd ed_, Kerninghan & Ritchie (1988)
* Algorithms in C _3rd ed_ Parts 1-4, Sedgewick (1998)

