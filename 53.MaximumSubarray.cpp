/*
53. Maximum Subarray, 最大连续数组的和

Find the contiguous subarray within an array (containing at least one number) which has the largest sum.

For example, given the array [−2,1,−3,4,−1,2,1,−5,4],
the contiguous subarray [4,−1,2,1] has the largest sum = 6.

More practice:
    If you have figured out the O(n) solution, try coding another solution using the divide and conquer approach, which is more subtle.
*/

#include <vector>

// First Solution:
// dp[j] = max{ dp[j - 1] + s[j], s[j] }; 1 <= j <= N
// TARGET = max{dp[j]}; 1 <= j <= N
// Time Complexity: O(N)
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        const auto n = nums.size();
        std::vector<int> dp(n, 0);

        dp[0] = nums[0];
        auto res = dp[0];
        for (auto i = 1; i < n; ++i) {
            dp[i] = max(dp[i - 1] + nums[i], nums[i]);
            res = max(res, dp[i]);
        }
        return res;
    }
};

// Second Solution: slidding window
class Solution {
public:
    int maxSubArray(vector<int> &nums) {
        auto left = 0;
        auto right = 0;
        auto max_sum = INT_MIN;
        auto window_sum = 0;
        while (right < nums.size()) {
            window_sum += nums[right];
            ++right;

            if (window_sum > max_sum) {
                max_sum = window_sum;
            }
            while (window_sum < 0) {
                window_sum -= nums[left];
                ++left;
            }
        }
        return max_sum;
    }
};
