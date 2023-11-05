/*****************************************************************
*   Copyright (C) 2023 All rights reserved.
*
*   @file:    216.CombinationSumIII.cpp
*   @author:  marinyoung@163.com
*   @date:    2023/10/06 23:53:14
*   @brief:

Find all valid combinations of k numbers that sum up to n such that the following conditions are true:
    Only numbers 1 through 9 are used.
    Each number is used at most once.

Return a list of all possible valid combinations. The list must not contain the same combination twice, and the combinations may be returned in any order.


Example 1:
    Input: k = 3, n = 7
    Output: [[1,2,4]]
    Explanation:
        1 + 2 + 4 = 7
        There are no other valid combinations.

Example 2:
    Input: k = 3, n = 9
    Output: [[1,2,6],[1,3,5],[2,3,4]]
    Explanation:
        1 + 2 + 6 = 9
        1 + 3 + 5 = 9
        2 + 3 + 4 = 9
        There are no other valid combinations.

Example 3:
    Input: k = 4, n = 1
    Output: []
    Explanation:
        There are no valid combinations.
        Using 4 different numbers in the range [1,9], the smallest sum we can get is 1+2+3+4 = 10 and since 10 > 1, there are no valid combination.


Constraints:
    2 <= k <= 9
    1 <= n <= 60

*****************************************************************/


class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> candidate;
        vector<vector<int>> result;
        backtrack(1, k, n, candidate, result);
        return result;
    }

private:
    void backtrack(int start,
                int k,
                int target,
                vector<int> &candidate,
                vector<vector<int>> &result) {
        if (candidate.size() == k && target == 0) {
            result.push_back(candidate);
            return;
        }
        if (target < 0 || candidate.size() > k || start > 9 || start > target) {
            return;
        }
        for (auto i = start; i <= 9; ++i) {
            if (i > target) {
                break;
            }
            target -= i;
            candidate.push_back(i);
            backtrack(i + 1, k, target, candidate, result);
            candidate.pop_back();
            target += i;
        }
    }
};