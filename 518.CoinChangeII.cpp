/*****************************************************************
*   Copyright (C) 2023 All rights reserved.
*
*   @file:    518.CoinChangeII.cpp
*   @author:  marinyoung@163.com
*   @date:    2023/09/17 13:25:33
*   @brief:

You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.
Return the number of combinations that make up that amount. If that amount of money cannot be made up by any combination of the coins, return 0.

You may assume that you have an infinite number of each kind of coin.
The answer is guaranteed to fit into a signed 32-bit integer.


Example 1:
    Input: amount = 5, coins = [1,2,5]
    Output: 4
    Explanation: there are four ways to make up the amount:
        5=5
        5=2+2+1
        5=2+1+1+1
        5=1+1+1+1+1

Example 2:
    Input: amount = 3, coins = [2]
    Output: 0
    Explanation: the amount of 3 cannot be made up just with coins of 2.

Example 3:
    Input: amount = 10, coins = [10]
    Output: 1


Constraints:
    1 <= coins.length <= 300
    1 <= coins[i] <= 5000
    All the values of coins are unique.
    0 <= amount <= 5000

*****************************************************************


class Solution {
public:
    /*
        dp[i] 表示凑成零钱为 i 时的组合个数
        dp[i] = sum(dp[i - 1], dp[i - 2], ..)  即每种金额，刚好差一个硬币就能构成当前金额。
    */
    int change(int amount, vector<int>& coins) {
        // 注意：这里无需异常条件判别，比如 amount=0；返回的也是1；

        std::sort(coins.begin(), coins.end());
        vector<int> dp(amount + 1, 0);
        dp[0] = 1;
        for (auto coin : coins) {
            for (auto i = coin; i <= amount; ++i) {
                dp[i] += dp[i - coin];
            }
        }
        return dp[amount];
    }
};