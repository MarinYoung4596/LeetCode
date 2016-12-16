/*
121. Best Time to Buy and Sell Stock

Say you have an array for which the ith element is the price of a given stock on day i.

If you were only permitted to complete at most one transaction (ie, buy one and sell one share of the stock), design an algorithm to find the maximum profit.

*/

class Solution {
public:
    /*
    1st Solution: Bruce-Force:
    TLE in super long test cases
    find the largest and smallest pairs in the array without changing their order
     */
    int maxProfit_1(vector<int>& prices) {
        const auto n = prices.size();
        int res = 0;
        for (auto i = 1; i < n; ++i)
            for (auto j =0; j < i; ++j)
                res = max(res, prices[i]-prices[j]);
        return res;
    }
    
    /*
    2nd solution: Dynamic Programming
     */
    int maxProfit(vector<int>& prices)
    {
        if (prices.empty()) return 0;
        const auto n = prices.size();
        vector<int> dp(n, 0); // maximum profit
        int minimum = prices[0];
        for (auto i = 1; i < n; ++i)
        {
            dp[i] = max(dp[i-1], prices[i]-minimum);
            minimum = min(minimum, prices[i]);
        }
        return dp[n-1];
    }
};