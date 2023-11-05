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

// First Solution: recursive + cache
class Solution {
public:
    // dp(n) = min{dp(n - coin) | coin \in coins}
    int coinChange(vector<int> &coins, int amount) {
        cache.resize(amount + 1);

        dfs(coins, amount, 0);
        return cache[amount] != INT_MAX ? cache[amount] : -1;
    }

    int dfs(const vector<int> &coins, int amount, int coin_num) {
        if (amount < 0) {
            return -1;
        }
        if (amount == 0) {
            cache[amount] = std::min(cache[amount], coin_num);
            return cache[amount];
        }
        if (cache[amount] != INT_MAX) {
            return cache[amount];
        }
        for (auto coin : coins) {
            auto subres = dfs(coins, amount - coin, coin_num + 1);
            if (subres < 0) {
                continue;
            }
            cache[amount] = std::min(cache[amount], subres);
        }
        return cache[amount];
    }

private:
    vector<int> cache;
};

// second solution:  dp
class Solution2 {
public:
    int coinChange(vector<int> &coins, int amount) {
        if (amount < 1) {
            return 0;
        }
        std::sort(coins.begin(), coins.end()); // 从小到大，节省开销
        vector<int> dp(amount + 1, INT_MAX);
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


class Solution3 {
public:
    int coinChange(vector<int> &coins, int amount) {
        vector<int> dp(amount + 1, INT_MAX);

        dp[0] = 0;
        // 外层 for 循环在遍历所有状态的所有取值
        for (int i = 0; i <= amount; i++) {
            // 内层 for 循环在求所有选择的最⼩值
            for (int coin : coins) {
                // ⼦问题⽆解，跳过
                if (i - coin < 0) {
                    continue;
                }
                dp[i] = min(dp[i], 1 + dp[i - coin]);
            }
        }
        return (dp[amount] == amount + 1) ? -1 : dp[amount]
    }
};
