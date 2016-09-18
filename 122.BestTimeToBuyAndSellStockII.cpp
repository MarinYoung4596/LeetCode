/*
122. Best Time to Buy and Sell Stock II

Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete as many transactions as you like (ie, buy one and sell one share of the stock multiple times). However, you may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
*/

class Solution {
public:
    int maxProfit(vector<int>& prices) 
    {
        if (prices.size() < 2) return 0;
        
        int profit = 0;
        for (auto i = 1; i < prices.size(); ++i)
        {
            if (prices[i] > prices[i-1]) // 如果是负数则忽略不计
                profit += (prices[i]-prices[i-1]); // 只比较相邻两天 ，次数越多越好 
        }
        return profit;
    }
};