/*****************************************************************
*   Copyright (C) 2023 All rights reserved.
*
*   @file:    650.2KeysKeyboard.cpp
*   @author:  marinyoung@163.com
*   @date:    2023/10/19 21:56:58
*   @brief:

There is only one character 'A' on the screen of a notepad. You can perform one of two operations on this notepad for each step:

    Copy All: You can copy all the characters present on the screen (a partial copy is not allowed).
    Paste: You can paste the characters which are copied last time.

Given an integer n, return the minimum number of operations to get the character 'A' exactly n times on the screen.


Example 1:
    Input: n = 3
    Output: 3
    Explanation: Initially, we have one character 'A'.
        In step 1, we use Copy All operation.
        In step 2, we use Paste operation to get 'AA'.
        In step 3, we use Paste operation to get 'AAA'.

Example 2:
    Input: n = 1
    Output: 0


Constraints:
    1 <= n <= 1000

*****************************************************************/


class Solution {
public:
    int minSteps(int n) {
        vector<int> dp(n + 1, 0);
        dp[1] = 0;

        for (auto i = 2; i <= n; ++i) {
            dp[i] = i;  // 最多 i 次（第一次 copy，其余全 paste 一个 A）
            for (auto j = 2; j * j <= i; ++j) {
                if (i % j != 0) {
                    continue;
                }
                dp[i] = dp[j] + dp[i / j];
            }
        }
        return dp[n];
    }
};

class Solution2 {
public:
    int minSteps(int n) {
        vector<int> dp(n + 1, 0);
        for (auto i = 2; i <= n; ++i) {
            dp[i] = INT_MAX;
            for (auto j = 1; j * j <= i; ++j) {
                if (i % j != 0) {
                    continue;
                }
                dp[i] = min(dp[i], dp[j] + i / j);  // 当前有 j 个 A, 粘贴 i/j 次，就有了 i 个 A
                dp[i] = min(dp[i], dp[i / j] + j);  // 当前有 i/j 个 A，粘贴 j 次，就有了 i 个 A
            }
        }
        return dp[n];
    }
}