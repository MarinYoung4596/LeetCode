/*****************************************************************
*   Copyright (C) 2023 All rights reserved.
*
*   @file:    698.PartitionToKEqualSumSubsets.cpp
*   @author:  marinyoung@163.com
*   @date:    2023/02/13 19:40:29
*   @brief:

Given an integer array nums and an integer k, return true if it is possible to divide this array into k non-empty subsets whose sums are all equal.


Example 1:
    Input: nums = [4,3,2,3,5,2,1], k = 4
    Output: true
    Explanation: It is possible to divide it into 4 subsets (5), (1, 4), (2,3), (2,3) with equal sums.

Example 2:
    Input: nums = [1,2,3,4], k = 3
    Output: false

Constraints:
    1 <= k <= nums.length <= 16
    1 <= nums[i] <= 10^4
    The frequency of each element is in the range [1, 4].
*****************************************************************/


class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        if (k > nums.size()) {  // 预判断1
            return false;
        }
        auto vec_sum = std::accumulate(nums.begin(), nums.end(), 0);
        if (vec_sum % k != 0) {  // 预判断2
            return false;
        }
        auto avg = vec_sum / k;
        std::sort(nums.begin(), nums.end(), std::greater<int>());  // 剪枝1：提前降序，让命中剪枝3的条件尽可能靠前

        vector<int> buckets(k, 0);
        return backtrack(nums, avg, 0, buckets);
    }

private:
    bool backtrack(const vector<int>& nums, int avg,
                    int index, vector<int> buckets) {
        if (index == nums.size()) {
            for (auto item : buckets) {
                if (item != avg) {
                    return false;
                }
            }
            return true;
        }

        for (auto k = 0; k < buckets.size(); ++k) {
            if (k > 0 && buckets[k] == buckets[k - 1]) {  // 剪枝2：桶里元素之和相同跳过，去重
                continue;
            }
            if (buckets[k] + nums[index] > avg) { // 剪枝3：因为输入都是正整数，因此超出限制跳过
                continue;
            }
            buckets[k] += nums[index];
            auto ret = backtrack(nums, avg, index + 1, buckets);
            if (ret) {
                return true;
            }
            buckets[k] -= nums[index];
            if (buckets[k] == 0) {  // 剪枝4：后处理，已经循环过了一遍，buckets[k] 还是0，说明跟初始情况一样，没有进一步搜索的必要了
                return false;
            }
        }
        return false;
    }
};