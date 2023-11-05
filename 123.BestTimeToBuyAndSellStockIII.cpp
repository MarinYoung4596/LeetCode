/*
Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete at most two transactions.

Note: You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).

*/

// First Solution： Time Limit Exceeded! for ex-large inputs.
class Solution {
public:
    int maxProfit(vector<int>& prices) {  // at most two transactions
        if (prices.size() < 2) {
            return 0;
        }

        int profit = findMaxProfit(prices, 0, prices.size() - 1);
        for (auto i = 1; i < prices.size(); ++i) {
            int tmp = findMaxProfit(prices, 0, i) + findMaxProfit(prices, i + 1, prices.size() - 1);
            profit = max(profit, tmp);
        }
        return profit;
    }

private:
    int findMaxProfit(vector<int> &prices, int left, int right) {  // only one transactions
        if (right - left < 1) {
            return 0;
        }

        vector<int> dp(right - left + 1, 0);  // dp[i] 代表 i+left 结尾时的最大利润
        int min_price = prices[left];
        for (auto i = left + 1; i <= right; ++i) {
            dp[i - left] = max(dp[i - left - 1], prices[i] - min_price);

            min_price = min(min_price, prices[i]);  // 记录最低价格
        }
        return dp[right - left];
    }
};

// 改进的方法：减少函数调用的次数
class Solution2 {
public:
    int maxProfit(vector<int>& prices) {// at most two transactions
        const auto n = prices.size();
        if (n < 2) {
            return 0;
        }

        int profit = findMaxProfit(prices, 0, n - 1);
        for (auto i = 1; i < n; ++i) {
            while (i + 1 < n && prices[i] <= prices[i + 1]) {
                ++i; // 最长递增左序列
            }
            int leftProfit = findMaxProfit(prices, 0, i);

            while (i + 1 < n && prices[i] >= prices[i + 1]) {
                ++i; // 去除二者之间递减的部分（profit<=0），最长递增右序列
            }
            int rightProfit = findMaxProfit(prices, i, n - 1);

            profit = max(profit, leftProfit + rightProfit);
        }
        return profit;
    }

private:
    int findMaxProfit(vector<int> &prices, int left, int right) { // only one transactions
        if (right-left < 1) {
            return 0;
        }

        vector<int> dp(right - left + 1, 0);
        int min_price = prices[left];
        for (auto i = left + 1; i <= right; ++i) {
            dp[i - left] = max(dp[i - left - 1], prices[i] - min_price);

            min_price = min(min_price, prices[i]);
        }
        return dp[right - left];
    }
};
