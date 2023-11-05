/*
718. Maximum Length of Repeated Subarray
https://leetcode.com/problems/maximum-length-of-repeated-subarray/

Given two integer arrays A and B, return the maximum length of an subarray that appears in both arrays.

Example 1:
Input:
A: [1,2,3,2,1]
B: [3,2,1,4,7]
Output: 3
Explanation: The repeated subarray with maximum length is [3, 2, 1].


Note:

1 <= len(A), len(B) <= 1000
0 <= A[i], B[i] < 100

*/

class Solution {
public:
    // 最长连续子串
    // dp[i][j] = (A[i] == B[j]) ? (dp[i-1][j-1] + 1) : dp[i][j]
    int findLength(vector<int>& A, vector<int>& B) {
        if (A.empty() || B.empty()) {
            return 0;
        }
        std::vector<std::vector<int>> dp(A.size(), std::vector<int>(B.size(), 0));
        // 初始化
        for (auto i = 0; i < A.size(); ++i) {
            dp[i][0] = A[i] == B[0] ? 1 : 0;
        }
        for (auto j = 0; j < B.size(); ++j) {
            dp[0][j] = A[0] == B[j] ? 1 : 0;
        }
        int max_len = INT_MIN;
        for (auto i = 1; i < A.size(); ++i) {
            for (auto j = 1; j < B.size(); ++j) {
                if (A[i] == B[j]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                } // 否则dp[i][j] = 0 因为子串连续
                max_len = std::max(max_len, dp[i][j]);
            }
        }
        return max_len;
    }
};