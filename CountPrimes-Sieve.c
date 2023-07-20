/*
Count Primes

Given an integer n, return the number of prime numbers that are strictly less than n.

https://leetcode.com/explore/interview/card/top-interview-questions-easy/102/math/744/
*/

#include <stdbool.h>
#include <stdio.h>
#include <math.h>

bool isPrime(int numberToCheck, bool* sieve);

int countPrimes(int n){
    int sqrtN = sqrt(n);
    bool sieve[n + 1]; // Use base 1 addressing; sieve[2] is true / false for "2 is prime?"
    int countPrimes = 0;
    
    // Set default sieve values to true
    for (int i = 0; i <= n; i++) {
        sieve[i] = true;
    }

    // Set all non-primes to false in sieve
    for (int i = 2; i <= sqrtN; i++) {
        int j = i * 2;
        while (j <= n) {
            sieve[j] = false;
            j += i;
        }
    }

    // Count primes in sieve
    for (int i = 2; i < n; i++) {
        if (sieve[i] == true) {countPrimes++;}
    }

    return countPrimes;
}

bool isPrime(int numberToCheck, bool* sieve) {
    int sqrtNumber = sqrt(numberToCheck);
    if (numberToCheck % 2 == 0) {return false;}
    for (int i = 3; i < sqrtNumber; i+=2) {
        if (sieve[i] == true){
            if (numberToCheck % i == 0) {return false;}
        }
    }
    return true;
}


int main() {
    printf("Calc: %d  | Correct: 4 \n", countPrimes(10));
    printf("Calc: %d  | Correct: 0 \n", countPrimes(2));
    printf("Calc: %d  | Correct: ? \n", countPrimes(4999792));
    printf("Calc: %d  | Correct: 0 \n", countPrimes(0));
    return 0;
}



/*
Input: n = 10
Output: 4
Explanation: There are 4 prime numbers less than 10, they are 2, 3, 5, 7.
*/