/*****************************************************************
*   Copyright (C) 2023 All rights reserved.
*
*   @file:    632.SmallestRangeCoveringElementsFromKLists.cpp
*   @author:  marinyoung@163.com
*   @date:    2023/11/01 19:08:22
*   @brief:

You have k lists of sorted integers in non-decreasing order. Find the smallest range that includes at least one number from each of the k lists.

We define the range [a, b] is smaller than range [c, d] if `b - a < d - c` or `a < c` if `b - a == d - c`.


Example 1:
    Input: nums = [[4,10,15,24,26],[0,9,12,20],[5,18,22,30]]
    Output: [20,24]
    Explanation:
        List 1: [4, 10, 15, 24,26], 24 is in range [20,24].
        List 2: [0, 9, 12, 20], 20 is in range [20,24].
        List 3: [5, 18, 22, 30], 22 is in range [20,24].

Example 2:
    Input: nums = [[1,2,3],[1,2,3],[1,2,3]]
    Output: [1,1]


Constraints:
    nums.length == k
    1 <= k <= 3500
    1 <= nums[i].length <= 50
    -10^5 <= nums[i][j] <= 10^5
    nums[i] is sorted in non-decreasing order.

*****************************************************************/


class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        // 所有子数组 merge，保留来源 index
        vector<pair<int, int>> items;
        for (auto i = 0; i < nums.size(); ++i) {
            for (auto x : nums[i]) {
                items.push_back(make_pair(x, i));
            }
        }
        // 排序
        sort(items.begin(), items.end(), [&](const auto &lhs, const auto &rhs) {
            if (lhs.first != rhs.first) {
                return lhs.first < rhs.first;
            } else {
                return lhs.second < rhs.second;
            }
        });
        // 滑动窗口
        vector<int> coverage(nums.size(), 0);
        auto left = 0;
        auto right = 0;
        auto res_left = -1;
        auto res_right = -1;
        while (right < items.size()) {
            const auto &r_item = items[right];
            ++coverage[r_item.second];
            ++right;

            while (is_valid(coverage)) {
                // 更新result
                const auto &l_item = items[left];
                auto delta = r_item.first - l_item.first;
                if (res_left == -1 || delta < (res_right - res_left)) {
                    res_left = l_item.first;
                    res_right = r_item.first;
                }
                // 满足条件后才收缩
                ++left;
                --coverage[l_item.second];
            }
        }
        return {res_left, res_right};
    }

private:
    bool is_valid(vector<int> &bucket) {
        for (auto x : bucket) {
            if (x == 0) {
                return false;
            }
        }
        return true;
    }
};