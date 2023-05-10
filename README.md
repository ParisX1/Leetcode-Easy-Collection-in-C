# Leetcode
My Leetcode Solutions in c

These are currently in c in preparation for GIOS, summer 2023

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


