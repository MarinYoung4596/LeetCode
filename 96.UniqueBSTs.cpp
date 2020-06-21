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

class Solution {
public:
    // dp[n] = \sum_{0}^{n-1} {dp[i] * dp[n - 1 - i]}
    int numTrees(int n) {
        assert(n > 0);
        std::vector<int> dp(n + 1, 0);
        dp[0] = dp[1] = 1;
        for (auto i = 0; i <= n; ++i) {
            if (i < 2) {
                dp[i] = 1;
            }
            for (auto j = 0; j < i; ++j) {
                dp[i] += dp[j] * dp[i - 1 - j];
            }
        }
        return dp[n];
    }
};
