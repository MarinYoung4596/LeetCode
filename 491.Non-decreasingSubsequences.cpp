/*****************************************************************
*   Copyright (C) 2023 All rights reserved.
*
*   @file:    491.Non-decreasingSubsequences.cpp
*   @author:  marinyoung@163.com
*   @date:    2023/09/10 22:58:22
*   @brief:

Given an integer array nums, return all the different possible non-decreasing subsequences of the given array with at least two elements. You may return the answer in any order.


Example 1:
    Input: nums = [4,6,7,7]
    Output: [[4,6],[4,6,7],[4,6,7,7],[4,7],[4,7,7],[6,7],[6,7,7],[7,7]]

Example 2:
    Input: nums = [4,4,3,2,1]
    Output: [[4,4]]


Constraints:
    1 <= nums.length <= 15
    -100 <= nums[i] <= 100

*****************************************************************/

#include "util.h"
#include <vector>
#include <unordered_set>

using std::vector;
using std::unordered_set;

class Solution {
public:
    vector<vector<int>> findSubsequences(const vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> candidate;
        backtrack(nums, 0, candidate, result);
        return result;
    }

private:
    void backtrack(const vector<int> &nums,
                   int index,
                   vector<int> &candidate,
                   vector<vector<int>> &result) {
        if (candidate.size() >= 2) {  // TIPS 1：这里条件不要求到末尾，如第一个case，【4，6】没有遍历到末尾，也算候选
            result.push_back(candidate);
            // TIPS 2 ：因此这里也不用立马return
        }
        unordered_set<int> cur_selected;
        for (auto i = index; i < nums.size(); ++i) {
            if (!candidate.empty() && candidate.back() > nums[i]) {
                continue;
            }
            if (cur_selected.count(nums[i]) > 0) {
                continue;
            }
            cur_selected.insert(nums[i]);  // 防止本次遍历选则了重复的元素

            candidate.push_back(nums[i]);
            backtrack(nums, i + 1, candidate, result);
            candidate.pop_back();
        }
    }
};

int main() {
    Solution obj;
    vector<vector<int>> test_cases = {
        {4, 4, 3, 2, 1},
        {4, 4},
        {4, 6, 7, 7}
    };
    for (const auto &nums : test_cases) {
        print_gap();
        auto ret = obj.findSubsequences(nums);
        print_matrix(ret);
    }
}
