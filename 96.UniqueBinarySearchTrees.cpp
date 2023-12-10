/*
96. Unique Binary Search Trees

Given n, how many structurally unique BST's (binary search trees) that store values 1...n?

For example,
    Given n = 3, there are a total of 5 unique BST's.
       1         3     3      2      1
        \       /     /      / \      \
         3     2     1      1   3      2
        /     /       \                 \
       2     1         2                 3

*/

// First Solution: dp
class Solution {
public:
    // dp[n] = \sum_{0}^{n-1} {dp[i] * dp[n - 1 - i]}
    int numTrees(int n) {
        assert(n > 0);

        vector<int> dp(n + 1, 0);
        for (auto i = 0; i <= n; ++i) {
            if (i < 2) {
                dp[i] = 1;
            }
            for (auto j = 0; j < i; ++j) {
                dp[i] += dp[j] * dp[i - 1 - j];  // 以 i 为root 的子树数量 = 左子树数量 * 右子树数量
            }
        }
        return dp[n];
    }
};

// Second Solution: recursive
class Solution2 {
public:
    int numTrees(int n) {
        vector<vector<int>> cache(n + 1, vector<int>(n + 1, 0));
        return count(1, n, cache);
    }

private:
    // 在 [low, high] 区间内能组成的 BST 数量
    int count(int low, int high, vector<vector<int>> &cache) {
        if (low > high) {
            return 1;
        }
        if (cache[low][high] != 0) {  // 直接返回暂存的结果,减少计算量(重复子树)
            return cache[low][high];
        }
        auto result = 0;
        for (auto i = low; i <= high; ++i) {
            // 以 i 作为 root 节点
            auto left_num = count(low, i - 1);
            auto right_num = count(i + 1, high);
            result += left_num * right_num;
        }
        cache[low][high] = result;  // 暂存结果
        return result;
    }
};
