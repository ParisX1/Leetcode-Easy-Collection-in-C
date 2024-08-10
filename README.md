# Leetcode Easy - Using C
My solutions to [Leetcode Easy Collection Top Interview Questions](https://leetcode.com/explore/interview/card/top-interview-questions-easy/). Fifty "Easy" Leetcode problems solved in the C programming language.

These were completed in preparation for Georgia Tech's [Graduate Introduction to Operating Systems](https://omscs.gatech.edu/cs-6200-introduction-operating-systems).  Although not an algorithms class, it heavily uses C, and so Leetcode seemed a good way to practice C coding.

## References
If you're ever actually interested in delving into the exciting world of algorithm design in C, below are the resources I utilised for this exercise.

Specific page references can be found in the _Notable Implementations_ section below.

* C Programming A Modern Approach _2nd Ed_, King (2008)
* The C Programming Language _2nd Ed_, Kerninghan & Ritchie (1988)
* Algorithms in C Parts 1-4 _3rd Ed_, Sedgewick (1998)
* Introduction to Algorithms _3rd Ed_, CLRS (2009)
* The Standard C Library, Plauger (1992)

## Notable Implementations

_Note: titles link to Leetcode problem; solution files are linked at the bottom of each problem._

### [Binary Tree Level Order Traversal](https://leetcode.com/explore/interview/card/top-interview-questions-easy/94/trees/628/)

Return the values for a level order traversal of a binary tree.  The returned array is an array of arrays, so each level is a nested array.

This question probably took the longest to complete.  I setup the queue first, tested it and then come back to finish the problem as the last to complete.  I was working over two days to get it passing.  The issues were around getting pointers to pointers working correctly, with malloc() and realloc().  Also reallocarray() wouldn't work on windows, which is what I was testing on.

#### Key Features
* Requires the creation of a queue data structure
* Dynamic creation of arrays based on number of, and the size of each, sub-array
* Malloc() used to allocate memory and the realloc() to dynamically resize
* For a detailed discussion, see _Algorithms in C_ Chapter Five, especially Ch 5.6 on tree traversal

[Link to solution](./BinaryTreeLevelOrderTraversal.c)

### [Valid Sudoku](https://leetcode.com/explore/interview/card/top-interview-questions-easy/92/array/769/)
Check if the given state of a 9 x 9 Sudoku board is valid.

#### Key Features
* For testing, char** (pointer to 2d char arrays) are created.  This requires heap allocation to pass the pointer-pointers (char**) into functions
* The char** is malloc'd and then each row is instantiated using: board[x] = (char[]) {...}

[Link to solution](./ValidSudoku.c)

### [Intersection of Two Arrays II](https://leetcode.com/explore/interview/card/top-interview-questions-easy/92/array/674/)
Given two integer arrays, return an array of their intersection.  "Intersection" meaning when an element of the first array is also contained in the second array (in any order).

#### Key Features
* "Hash map" counting instances of each number found
* Malloc and realloc (_reallocarray_ actually) to dynamically resize the results array

[Link to solution](./IntersectionofTwoArraysII.c)

### [Longest Common Prefix](https://leetcode.com/explore/interview/card/top-interview-questions-easy/127/strings/887/)
Find the longest common n chars in an array of strings.  Ie find the longest common prefix.

#### Key Features
* Array of string is of type char**
* Input array is instantiated using malloc() and each string assigned within the array using strdup()
* The result is returned as a char*, so used malloc and stored in a buffer with a string terminating char

[Link to solution](./LongestCommonPrefix.c)

### [Plus One](https://leetcode.com/explore/interview/card/top-interview-questions-easy/92/array/559/)
Increase the value of a number, represented by an array, by one.  Needs to allow for carry-over and thus resizing the array.

#### Key Features
* Implements realloc to resize an array

[Link to solution](./PlusOne.c)

### [Valid Anagram](https://leetcode.com/explore/interview/card/top-interview-questions-easy/127/strings/882/)
Is one string the anagram of another.

#### Key Features
* Implements a polynomial hashing for each char.  We loop over each string and add/sub the hashing values at string1[i], string2[i] so that the resulting sum is zero if the two strings are valid anagrams.

[Link to solution](./ValidAnagram.c)

### [Hamming Distance](https://leetcode.com/explore/interview/card/top-interview-questions-easy/99/others/762/)
Take two ints and calculate where the values differ in their binary representations.

#### Key Features
* Uses bit shifting

[Link to solution](./HammingDistance.c)

### [Shuffle an Array](https://leetcode.com/explore/interview/card/top-interview-questions-easy/98/design/670/)
Pretty simple idea: randomly shuffle the values in an array.

#### Key Features
* Two arrays held in a struct - original and current
* Functions to set, shuffle and reset the arrays
* Malloc used to allocate memory for the struct and the two arrays
* Free is used to reset function
* The shuffle function (from CLRS) used rand(), though srand() didn't work for the random seed and needed to be removed to pass LC tester (or all random numbers were the same!)

[Link to solution](./ShuffleanArray.c)

### [Valid Parentheses](https://leetcode.com/explore/interview/card/top-interview-questions-easy/99/others/721/)
Implemented a stack, following the general outline from Sedgewick's _Algorithms in C_.

The problem is to check if a string of parentheses are outlined in the "correct" order.

#### Key Features
* Stack implementation using linked list
* Static variable to head node.  This was the key insight from Sedgewick
* Includes a lot of checks for invalid pop/push operations, eg a pop when the stack is empty
* Needed quite a few tests to pass LC

[Link to solution](./ValidParentheses.c)

### [Single Number](https://leetcode.com/explore/interview/card/top-interview-questions-easy/92/array/549/)
Good reference code for structs, a simple hash table, and passing pointers to the struct array between methods.

The problem is to take an int array where all the numbers in an array are included twice, except for one, which is included twice.  Return the number that is included only once.

This is supposed to be implemented using XOR operations, but the version implemented here uses a simple hash table.

#### Key Features
* (Simplified) Hash table implementation
* Creates structs to hold information for the hash table entries
* An array of structs constitutes the hash table
* Pointers to the array is passed into functions to add to, and retrieve data from, the hash table

[Link to solution](./SingleNumber-Hash.c)

### [Fizz Buzz](https://leetcode.com/explore/interview/card/top-interview-questions-easy/102/math/743/)
This was actually harder than expected to complete in C.  You need to dynamically allocate (malloc) space for each of the strings.

The problem is to take an int n, and save into an array FIZZ/BUZZ for each number 1..n.

#### Key Features
* Create an array of string -> ie an array of pointers to char pointers.  The array is of type char**
* malloc for the base array of char* pointers
* malloc for each of the strings
* Uses sprintf to create the strings and return pointers.  See C Programming A Modern Approach (King) p783

[Link to solution](./FizzBuzz.c)
