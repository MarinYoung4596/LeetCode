/*****************************************************************
*   Copyright (C) 2023 All rights reserved.
*
*   @file:    40.CombinationSumII.cpp
*   @author:  marinyoung@163.com
*   @date:    2023/01/02 22:06:28
*   @brief:

Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sum to target.

Each number in candidates may only be used once in the combination.

Note: The solution set must not contain duplicate combinations.


Example 1:
    Input: candidates = [10,1,2,7,6,1,5], target = 8
    Output:
    [
        [1,1,6],
        [1,2,5],
        [1,7],
        [2,6]
    ]

Example 2:
    Input: candidates = [2,5,2,1,2], target = 5
    Output:
    [
        [1,2,2],
        [5]
    ]


Constraints:
    1 <= candidates.length <= 100
    1 <= candidates[i] <= 50
    1 <= target <= 30

*****************************************************************/

// First Solution: backtrack
class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> subres;
        // dedup
        std::sort(candidates.begin(), candidates.end());  // important
        backtrack(candidates, result, subres, target, 0);
        return result;
    }

private:
    void backtrack(const vector<int> &candidates,
                   vector<vector<int>> &result,
                   vector<int> &subres,
                   int target,
                   int index) {
        if (target == 0) {
            result.push_back(subres);
            return;
        }

        for (auto i = index; i < candidates.size(); ++i) {
            auto &num = candidates[i];
            if (i > index && num == candidates[i - 1]) { // dedup
                continue;
            }
            if (num > target) {
                break; // 1 <= candidates[i] <= 50, 因为没有负数，提前跳出循环, 减少搜索次数
            }
            subres.push_back(num);
            backtrack(candidates, result, subres, target - num, i + 1);
            subres.pop_back();
        }
    }
};
