/*
Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

For example, given n = 3, a solution set is:

[
  "((()))",
  "(()())",
  "(())()",
  "()(())",
  "()()()"
]

*/

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        string subres;
        backtrack(result, subres, n, 0, 0);
        return result;
    }

private:
    void backtrack(vector<string> &result,
                   string &subres,
                  int n, int left, int right) {
        if (right > left || left > n || right > n) {
            return;
        }
        if (left == right && left == n) {
            result.push_back(subres);
            return;
        }
        subres.push_back('('); // 左括号
        backtrack(result, subres, n, left + 1, right);
        subres.pop_back();

        subres.push_back(')'); // 右括号
        backtrack(result, subres, n, left, right + 1);
        subres.pop_back();
    }
};