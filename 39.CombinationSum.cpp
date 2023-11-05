/*****************************************************************
*   Copyright (C) 2022  All rights reserved.
*
*   @file:    39.CombinationSum.cpp
*   @author:  marinyoung@tencent.com
*   @date:    2022/11/19 21:06:32
*   @brief:

Given an array of distinct integers candidates and a target integer target, return a list of all unique combinations of candidates where the chosen numbers sum to target. You may return the combinations in any order.
The same number may be chosen from candidates an unlimited number of times. Two combinations are unique if the frequency of at least one of the chosen numbers is different.
The test cases are generated such that the number of unique combinations that sum up to target is less than 150 combinations for the given input.

Example 1:
    Input: candidates = [2,3,6,7], target = 7
    Output: [[2,2,3],[7]]
    Explanation:
        2 and 3 are candidates, and 2 + 2 + 3 = 7. Note that 2 can be used multiple times.
        7 is a candidate, and 7 = 7.
        These are the only two combinations.

Example 2:
    Input: candidates = [2,3,5], target = 8
    Output: [[2,2,2,2],[2,3,3],[3,5]]

Example 3:
    Input: candidates = [2], target = 1
    Output: []

Constraints:
    1 <= candidates.length <= 30
    2 <= candidates[i] <= 40
    All elements of candidates are distinct.
    1 <= target <= 40

*****************************************************************/

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        std::sort(candidates.begin(), candidates.end()); // 这个很重要
        vector<vector<int>> result;
        vector<int> subres;
        backtrack(candidates, result, subres, target, 0);
        return result;
    }

private:
    void backtrack(const vector<int> &candidates,
                   vector<vector<int> &result,
                   vector<int> &subres,
                   int target,
                   int index) {
        if (target == 0) {
            result.push_back(subres);
            return;
        }
        for (auto i = index; i < candidates.size(); ++i) {
            if ((target - candidates[i]) < 0) {  // <0 break
                break;
            }
            subres.push_back(candidates[i]);
            backtrack(candidates, result, subres, target - candidates[i], i); // 下次 可用可不用，所以不是 i+1
            subres.pop_back();
        }
    }
};
