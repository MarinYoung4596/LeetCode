/**
You are given coins of different denominations and a total amount of money amount. Write a function to compute the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.

Example 1:
coins = [1, 2, 5], amount = 11
return 3 (11 = 5 + 5 + 1)

Example 2:
coins = [2], amount = 3
return -1.

Note:
You may assume that you have an infinite number of each kind of coin.

 */

// First Solution: recursive, Time Limit Exceeded
class Solution {
public:
    // dp(n) = min{dp(n - coin) | coin \in coins}
    int coinChange(std::vector<int> &coins, int amount) {
        if (amount == 0) {
            return 0;
        } else if (amount < 0) {
            return -1;
        }
        int min_res = INT_MAX;
        for (const auto coin : coins) {
            auto sub_res = coinChange(coins, amount - coin);
            if (sub_res < 0) {
                continue;
            }
            min_res = std::min(min_res, 1 + sub_res);
        }
        return (min_res != INT_MAX) ? min_res : -1;
    }
};

// second solution:
class Solution2 {
public:
    int coinChange(std::vector<int> &coins, int amount) {
        if (amount < 1) {
            return 0;
        }
        std::sort(coins.begin(), coins.end()); // 从小到大，节省开销
        std::vector<int> dp(amount + 1, INT_MAX);
        for (const auto &coin : coins) {
            if (coin <= amount) {
                dp[coin] = 1;
            }
        }
        for (auto i = 1; i <= amount; ++i) {
            if (dp[i] == 1) {
                continue;
            }
            for (auto j = 0; j < coins.size() && coins[j] < i; ++j) {
                if (dp[i - coins[j]] != INT_MAX) {
                    dp[i] = min(dp[i], dp[i - coins[j]] + 1);
                }
            }
        }
        return dp[amount] != INT_MAX ? dp[amount] : -1;
    }
};
