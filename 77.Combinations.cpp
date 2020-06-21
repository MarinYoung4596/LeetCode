/*
Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.

Example:

Input: n = 4, k = 2
Output:
[
  [2,4],
  [3,4],
  [2,3],
  [1,2],
  [1,3],
  [1,4],
]

*/

class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        std::vector<std::vector<int>> result;
        std::vector<int> subres;
        backtrack(result, subres, n, k, 1);
        return result;
    }

private:
    void backtrack(std::vector<std::vector<int>> &result,
                   std::vector<int> &subres,
                  int n, int k, int start) {
        if (subres.size() == k) {
            result.push_back(subres);
            return;
        }
        for (auto i = start; i <= n; ++i) {
            subres.push_back(i);
            backtrack(result, subres, n, k, i + 1);
            subres.pop_back();
        }
    }
};