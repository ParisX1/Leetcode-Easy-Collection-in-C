# Leetcode Easy - Using C
Solutions to Leetcode Easy "Top Interview Questions" in C

[Leetcode Easy Collection Top Interview Questions](https://leetcode.com/explore/interview/card/top-interview-questions-easy/)  

These were completed in preparation for Georgia Tech's _Graduate Introduction to Operating Systems_ class, summer 2023.  Although the class is not an algorithms class, it heavily uses C, and so Leetcode seemed a good way to practice C coding.  

[CS6200: Introduction to Operating Systems](https://omscs.gatech.edu/cs-6200-introduction-operating-systems)

Notes / references for various algorithms below.

## Intersection of Two Arrays II  
Given two integer arrays, return an array of their intersection.  "Intersection" meaning when an element of the first array is also contained in the second array (in any order).  

### Key Features
* "Hash map" counting instances of each number found
* Malloc and realloc (_reallocarray_ actually) to dynamically resize the results array


## Longest Common Prefix
Find the longest common n chars in an array of strings.  Ie find the longest common prefix.

### Key Features
* Array of string is of type char**
* Input array is instantiated using malloc() and each string assigned within the array using strdup()
* The result is returned as a char*, so used malloc and stored in a buffer with a string terminating char

## Plus One
Increase the value of a number, represented by an array, by one.  Needs to allow for carry-over and thus resizing the array.

### Key Features
* Implements realloc to resize an array

## Valid Anagram
Is one string the anagram of another.

### Key Features
* Implements a polynomial hashing for each char.  We loop over each string and add/sub the hashing values at string1[i], string2[i] so that the resulting sum is zero if the two strings are valid anagrams.

## Hamming Distance
Take two ints and calculate where the values differ in their binary representations.

### Key Features
* Uses bit shifting  

## Shuffle an Array
Pretty simple idea: randomly shuffle the values in an array.

### Key Features
* Two arrays held in a struct - original and current
* Functions to set, shuffle and reset the arrays
* Malloc used to allocate memory for the struct and the two arrays
* Free is used to reset function
* The shuffle function (from CLRS) used rand(), though srand() didn't work for the random seed and needed to be removed to pass LC tester (or all random numbers were the same!)

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
* C Programming A Modern Approach _2nd Ed_, King (2008)
* The C Programming Language _2nd Ed_, Kerninghan & Ritchie (1988)
* Algorithms in C Parts 1-4 _3rd Ed_, Sedgewick (1998)
* Introduction to Algorithms _3rd Ed_, CLRS (2009)
* The Standard C Library, Plauger (1992)
