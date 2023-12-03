/*****************************************************************
*   Copyright (C) 2023 Baidu.com, Inc. All rights reserved.
*
*   @file:    41.FirstMissingPositive.cpp
*   @author:  yangnan09@baidu.com
*   @date:    2023/11/07 11:26:47
*   @brief:

Given an unsorted integer array nums, return the smallest missing positive integer.

You must implement an algorithm that runs in O(n) time and uses O(1) auxiliary space.


Example 1:
    Input: nums = [1,2,0]
    Output: 3
    Explanation: The numbers in the range [1,2] are all in the array.

Example 2:
    Input: nums = [3,4,-1,1]
    Output: 2
    Explanation: 1 is in the array but 2 is missing.

Example 3:
    Input: nums = [7,8,9,11,12]
    Output: 1
    Explanation: The smallest positive integer 1 is missing.


Constraints:
    1 <= nums.length <= 10^5
    -2^31 <= nums[i] <= 2^31 - 1

*****************************************************************/

/**
 * @brief  First Solution: 暴力
 * 时间复杂度：O(NlogN)；空间复杂度：O(N)
 */
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        unordered_set<int> num_set;
        vector<int> pos_nums;
        for (auto x : nums) {
            if (x <= 0 || num_set.count(x) > 0) {
                continue;
            }
            pos_nums.push_back(x); // 保留正数
            num_set.insert(x);  // 去重
        }
        std::sort(pos_nums.begin(), pos_nums.end());
        for (auto i = 0; i < pos_nums.size(); ++i) {
            if (pos_nums[i] > i + 1) {
                return i + 1;
            }
        }
        return pos_nums.size() + 1;
    }
};


/**
 * @brief Second Solution: 置换法（原地哈希）
 * 如果数组中包含 x∈[1,N]，那么恢复后，数组的第 i−1 个元素为 i。
 * 时间复杂度：O(N)；空间复杂度：O(1)
 */
class Solution2 {
public:
    int firstMissingPositive(vector<int>& nums) {
        const auto n = nums.size();
        for (auto i = 0; i < n; ++i) {
            while (nums[i] > 0 &&
                    nums[i] <= n &&
                    nums[i] != nums[nums[i] - 1]) {
                swap(nums[i], nums[nums[i] - 1]);
            }
        }
        for (auto i = 0; i < n; ++i) {
            if (nums[i] != i + 1) {
                return i + 1;
            }
        }
        return n + 1;
    }
};

/**
 * @brief Third Solution：原地哈希
 * 时间复杂度：O(N)；空间复杂度：O(1)
 */
class Solution3 {
public:
    int firstMissingPositive(vector<int>& nums) {
        const auto n = nums.size();
        for (auto i = 0; i < n; ++i) {
            if (nums[i] <= 0) {
                nums[i] = n + 1;  // 先把 <=0 的剔除，保证后续所有下标都合法
            }
        }
        for (auto i = 0; i < n; ++i) {
            auto idx = abs(nums[i]) - 1;    // 这里取绝对值，因为前面有可能被其他元素置为负数了
            if (idx < n) {
                nums[idx] = -1 * abs(nums[idx]);  // 符合条件的，再次置为负数
            }
        }
        for (auto i = 0; i < n; ++i) {
            if (nums[i] > 0) {  // > 0，说明当前位置没有被置为负数
                return i + 1;
            }
        }
        return n + 1;
    }
};