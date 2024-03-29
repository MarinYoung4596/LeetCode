/*
Given a 2D board and a word, find if the word exists in the grid.
The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once.

Example:
    board =
    [
        ['A','B','C','E'],
        ['S','F','C','S'],
        ['A','D','E','E']
    ]

    Given word = "ABCCED", return true.
    Given word = "SEE", return true.
    Given word = "ABCB", return false.


Constraints:
    board and word consists only of lowercase and uppercase English letters.
    1 <= board.length <= 200
    1 <= board[i].length <= 200
    1 <= word.length <= 10^3
*/


// Runtime: 56 ms, faster than 76.85% of C++ online submissions for Word Search.
// Memory Usage: 11.4 MB, less than 74.43% of C++ online submissions for Word Search.
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        if (board.empty() || board[0].empty() || word.empty()) {
            return false;
        }
        vector<vector<bool>> stats(board.size(),
                                    vector<bool>(board[0].size(), false));
        for (auto i = 0; i < board.size(); ++i) {
            for (auto j = 0; j < board[0].size(); ++j) {
                auto stat = backtrack(board, word, 0, i, j, stats); // 从i,j 开始搜索
                if (stat) {
                    return true;
                }
            }
        }
        return false;
    }

private:
    // backtrack + dfs
    bool backtrack(
            const vector<vector<char>> &board,
            const string &word,
            int step,
            int row,
            int column,
            vector<vector<bool>> &visited) {
        if (step == word.size()) { // 到底
            return true;
        }
        if (row < 0 || row >= board.size()
                || column < 0 || column >= board[0].size()) { // 非法参数
            return false;
        }
        if (visited[row][column]) { // 已经遍历过
            return false;
        }
        if (word[step] != board[row][column]) { // 不相等
            return false;
        }
        visited[row][column] = true;
        auto stat1 = backtrack(board, word, step + 1, row, column - 1, visited); // 向左
        if (stat1) {
            return true;
        }
        auto stat2 = backtrack(board, word, step + 1, row, column + 1, visited); // 向右
        if (stat2) {
            return true;
        }
        auto stat3 = backtrack(board, word, step + 1, row - 1, column, visited); // 向上
        if (stat3) {
            return true;
        }
        auto stat4 = backtrack(board, word, step + 1, row + 1, column, visited); // 向下
        if (stat4) {
            return true;
        }
        visited[row][column] = false;

        return (stat1 || stat2 || stat3 || stat4);
    }
};
