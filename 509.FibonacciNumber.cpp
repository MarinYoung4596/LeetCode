/*
The Fibonacci numbers, commonly denoted F(n) form a sequence, called the Fibonacci sequence, such that each number is the sum of the two preceding ones, starting from 0 and 1. That is,
    F(0) = 0, F(1) = 1
    F(N) = F(N - 1) + F(N - 2), for N > 1.

Given N, calculate F(N).


Example 1:
    Input: 2
    Output: 1
    Explanation: F(2) = F(1) + F(0) = 1 + 0 = 1.

Example 2:
    Input: 3
    Output: 2
    Explanation: F(3) = F(2) + F(1) = 1 + 1 = 2.

Example 3:
    Input: 4
    Output: 3
    Explanation: F(4) = F(3) + F(2) = 2 + 1 = 3.


Note:
    0 ≤ N ≤ 30.
*/

// First Solution:
// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Fibonacci Number.
// Memory Usage: 6.2 MB, less than 9.33% of C++ online submissions for Fibonacci Number.
class Solution {
public:
    int fib(int N) {
        if (N < 1) {
            return 0;
        } else if (N < 2) {
            return 1;
        }
        vector<int> dp(N + 1, 0);
        dp[1] = 1;
        for (auto i = 2; i <= N; ++i) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return vec[N];
    }
};


// Second Solution
// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Fibonacci Number.
// Memory Usage: 5.9 MB, less than 94.85% of C++ online submissions for Fibonacci Number.
class Solution2 {
public:
    int fib(int N) {
        if (N < 1) {
            return 0;
        } else if (N < 2) {
            return 1;
        }
        int pre_pre = 0;
        int pre = 1;
        for (auto i = 2; i <= N; ++i) {
            auto cur = pre_pre + pre;
            pre_pre = pre;
            pre = cur;
        }
        return pre;
    }
};
