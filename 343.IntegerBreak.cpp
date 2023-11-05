/*
Given a positive integer n, break it into the sum of at least two positive integers and maximize the product of those integers.

Return the maximum product you can get.

Example 1:
    Input: n = 2
    Output: 1
    Explanation: 2 = 1 + 1, 1 × 1 = 1.

Example 2:
    Input: n = 10
    Output: 36
    Explanation: 10 = 3 + 3 + 4, 3 × 3 × 4 = 36.


Constraints:
    2 <= n <= 58

Hint:
    1.There is a simple O(n) solution to this problem.
    2.You may check the breaking results of n ranging from 7 to 10 to discover the regularities.

*/

class Solution {
public:
    int integerBreak(int n) {
        if (n == 2 || n == 3) return n - 1;
        if (n == 4) return n;

        int res = 0;
        int minus3 = 2; // 3+1+1, 3+2
        int minus2 = 3; // 2+2+1, 2+3, 2+1+1+1
        int minus1 = 4; // 1+4, 1+3+1, 1+2+2, 1+2+1+1, 1+1+1+1+1+1
        for (auto i = 5; i <= n; ++i) {
            res = max(minus3 * 3, minus2 * 2);
            minus3 = minus2;
            minus2 = minus1;
            minus1 = res;
        }
        return res;
    }
};

class Solution2 {
public:
    // ref: https://blog.csdn.net/zhizhengguan/article/details/124453544
    // dp[i] = max(j * (i - j), j * dp[i - j])
    int integreBreak(int n) {
        if (n < 2) {
            return n;
        }
        std::vector<int> dp(n + 1, 0);
        dp[2] = 1;
        for (auto i = 3; i <= n; ++i) {
            for (auto j = 1; j < i; ++j) {
                dp[i] = std::max(dp[i],
                                  std::max(j * (i - j),    /* 不使用cache的最大值，直接用两数相乘 */
                                           j * dp[i - j])  /* 使用cache的最大值 */
                        );
            }
        }
        return dp[n];
    }
};
