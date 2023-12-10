/*
You are given an array prices where prices[i] is the price of a given stock on the ith day.

You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.

Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.


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

/*
    1st Solution: Bruce-Force:
    TLE in super long test cases
    find the largest and smallest pairs in the array without changing their order
*/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        const auto n = prices.size();
        int res = 0;
        for (auto i = 1; i < n; ++i) {
            for (auto j =0; j < i; ++j) {
                res = max(res, prices[i] - prices[j]);
            }
        }
        return res;
    }
};

/*
2nd solution: Dynamic Programming
    minimum: 缓存i之前的最小值
dp[i] = max(dp[i - 1], prices[i] - minimum);
Time Complexity: O(N), Space Complexity: O(N) ===> can be reduced to O(1)
*/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty()) {
            return 0;
        }
        const auto n = prices.size();
        vector<int> dp(n, 0); // maximum profit
        int minimum = prices[0];
        for (auto i = 1; i < n; ++i) {
            dp[i] = max(dp[i - 1], prices[i] - minimum);
            minimum = min(minimum, prices[i]);
        }
        return dp[n - 1];
    }
};
