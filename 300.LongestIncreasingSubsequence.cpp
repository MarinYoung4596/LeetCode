/*
300. Longest Increasing Subsequence

Given an unsorted array of integers, find the length of longest increasing subsequence. 

For example,
 Given [10, 9, 2, 5, 3, 7, 101, 18],
 The longest increasing subsequence is [2, 3, 7, 101], therefore the length is 4. Note that there may be more than one LIS combination, it is only necessary for you to return the length. 

Your algorithm should run in O(n2) complexity. 

Follow up: Could you improve it to O(n log n) time complexity? 

*/

class Solution {
public:
    // dynamic programming
    // LIS[i] = max{(LIS[j] + 1) | j < i && a[j]<=a[i]} 
    int lengthOfLIS(vector<int>& nums) {
        if (nums.empty()) return 0;
        const auto len = nums.size();
        vector<int> dp(len, 1);
        auto res = 1;
        
        for (auto i = 0; i < len; ++i)
        {
            for (auto j = 0; j < i; ++j)
            {
                if (nums[j] >= nums[i]) continue;
                dp[i] = max(dp[i], dp[j]+1); // if dp[j] <= dp[i]
            }
            res = max(dp[i], res);
        }
        return res;
    }
};