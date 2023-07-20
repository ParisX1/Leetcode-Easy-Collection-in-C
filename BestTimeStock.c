/*
Best Time to Buy and Sell Stock

You are given an array prices where prices[i] is the price of a given stock on the ith day.

You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.

Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.

https://leetcode.com/explore/interview/card/top-interview-questions-easy/97/dynamic-programming/572/ 

Example 1:
Input: prices = [7,1,5,3,6,4]
Output: 5
Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
Note that buying on day 2 and selling on day 1 is not allowed because you must buy before you sell.

Example 2:
Input: prices = [7,6,4,3,1]
Output: 0
Explanation: In this case, no transactions are done and the max profit = 0.

Constraints:
1 <= prices.length <= 10^5
0 <= prices[i] <= 10^4
*/

/**
 * This is a dynamic programming problem, so the key is to update the values in linear time and avoid O(n^2) operations
 * The key insight is that we can update the minimum value to "buy" as we go -> if there is a new value at time i that 
 * is less than the previous minimum then you use that value as the new "buy" value.  Now all we need to do is check
 * if selling at time i (given we bought at the current minimum) would produce a profit greater than the current
 * maximum profit value.
 */

int maxProfit(int* prices, int pricesSize){
    int maxProfit = 0;              // Current maximum profit 
    int lowestValue = prices[0];    // Lowest value found
    int currentProfit;              // Profit if you bought at lowestValue and sold at the current price
    for (int i = 1; i < pricesSize; i++) {
        currentProfit = prices[i] - lowestValue;
        if (currentProfit > maxProfit) maxProfit = currentProfit;   // If sell now would increase profit, update maxProfit
        if (prices[i] < lowestValue) lowestValue = prices[i];       // If the current price is lower than the previous minimum, update lowestValue
    }
    return maxProfit;
}