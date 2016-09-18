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
    int numTrees(int n) {
        assert(n > 0);
        // dp(n) = SIGMA (i:0-->n-1) ( dp[i]*dp[n-1-i] )
        int *dp = new int[n+1];
        memset(dp, 0, (n+1)*sizeof(int));
        dp[0] = dp[1] = 1;
        for (auto i = 2; i <= n; ++i)
        {
            for (auto j = 0; j < i; ++j)
                dp[i] += dp[j]*dp[i-1-j];
        }
        int res = dp[n];
        delete [] dp;
        dp = nullptr;
        return res;
    }
};