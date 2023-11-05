/*
Find the contiguous subarray within an array (containing at least one number) which has the largest product.

For example, given the array [2,3,-2,4],
the contiguous subarray [2,3] has the largest product = 6.
*/

#include <vector>

// Dynamic Programming:
// Time Complexity: O(N), Space Complexity: O(1)
// https://leetcode.com/discuss/19795/share-my-c-solution-maybe-is-the-simplest-solution
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        const int N = nums.size();
        int front_product = 1;
        int back_product = 1;
        int res = INT_MIN;
        for (int i = 0; i < N; i++) {
            front_product *= nums[i];
            back_product *= nums[N - 1 - i];
            res = max(res, max(front_product, back_product));
            front_product = front_product == 0 ? 1 : front_product;
            back_product = back_product == 0 ? 1 : back_product;
        }
        return res;
    }
};

// Second Solution
// Time Complexity: O(N), Space Complexity: O(N)
// http://www.1point3acres.com/bbs/thread-105035-1-1.html
// http://www.cnblogs.com/bakari/p/4007368.html
// if nums[i] is negative, then nums[i] * minimum_negative = maximum_positive
// if nums[i] is positive, then nums[i] * maximum_positive = maximum_positive
class Solution2 {
public:
    int maxProduct(vector<int>& nums) {
        const int N = nums.size();
        vector<int> max_dp(N);
        vector<int> min_dp(N);
        int res;
        res = max_dp[0] = min_dp[0] = nums[0];
        for (int i = 1; i < N; i++) {
            max_dp[i] = max(min_dp[i - 1] * nums[i], max_dp[i - 1] * nums[i]);  // 可能有正负数
            max_dp[i] = max(max_dp[i], nums[i]);

            min_dp[i] = min(min_dp[i - 1] * nums[i], max_dp[i - 1] * nums[i]);
            min_dp[i] = min(min_dp[i], nums[i]);

            res = max(res, max_dp[i]);
        }
        return res;
    }
};