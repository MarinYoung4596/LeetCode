/*****************************************************************
*   Copyright (C) 2023 All rights reserved.
*
*   @file:    1696.JumpGameVI.cpp
*   @author:  marinyoung@163.com
*   @date:    2023/11/12 15:50:51
*   @brief:

You are given a 0-indexed integer array nums and an integer k.

You are initially standing at index 0. In one move, you can jump at most k steps forward without going outside the boundaries of the array. That is, you can jump from index i to any index in the range [i + 1, min(n - 1, i + k)] inclusive.

You want to reach the last index of the array (index n - 1). Your score is the sum of all nums[j] for each index j you visited in the array.

Return the maximum score you can get.


Example 1:
    Input: nums = [1,-1,-2,4,-7,3], k = 2
    Output: 7
    Explanation: You can choose your jumps forming the subsequence [1,-1,4,3] (underlined above). The sum is 7.

Example 2:
    Input: nums = [10,-5,-2,4,0,3], k = 3
    Output: 17
    Explanation: You can choose your jumps forming the subsequence [10,4,3] (underlined above). The sum is 17.

Example 3:
    Input: nums = [1,-5,-20,4,-1,3,-6,-3], k = 2
    Output: 0


Constraints:
    1 <= nums.length, k <= 10^5
    -10^4 <= nums[i] <= 10^4

*****************************************************************/


// First Solution: 暴力 DP
// 时间复杂度：O(N*k) ==> Time Limit Exceeded
class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        const int n = nums.size();
        vector<int> dp(n, INT_MIN);  // dp[i] 代表从下标0跳到下标 i，得到的结果最大值
        dp[0] = nums[0];
        for (auto i = 1; i < n; ++i) {
            for (auto j = max(0, i - k); j < i; ++j) {
                dp[i] = max(dp[i], dp[j] + nums[i]);
            }
        }
        return dp[n - 1];
    }
};


// Second Solution: dp + 单调栈
class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        const int n = nums.size();
        vector<int> dp(n, INT_MIN);  // dp[i] 代表从下标0跳到下标 i，得到的结果最大值
        dp[0] = nums[0];
        deque<int> window;
        window.push_back(0);
        for (auto i = 1; i < n; ++i) {
            while (!window.empty() && window.front() < i - k) { // 距离不满足条件
                window.pop_front();
            }
            dp[i] = max(dp[i], dp[window.front()] + nums[i]);
            while (!window.empty() && dp[window.back()] < dp[i]) { // 剔除 比当前 dp[i] 还要小的数字下标
                window.pop_back();
            }
            window.push_back(i);
        }
        return dp[n - 1];
    }
};
