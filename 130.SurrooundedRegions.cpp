/*
130. Surrounded Regions

Given a 2D board containing 'X' and 'O' (the letter O), capture all regions surrounded by 'X'.

A region is captured by flipping all 'O's into 'X's in that surrounded region.

For example,
    X X X X
    X O O X
    X X O X
    X O X X
    After running your function, the board should be:
    X X X X
    X X X X
    X X X X
    X O X X

*/

// FROM:
// https://github.com/soulmachine/leetcode

class Solution {
public:
//1、把所有边上的不能被X包围的O换成P
//2、把里面的被X包围的O换成X
//3、把P换回O
    void solve(vector<vector<char>>& board) {
        if (board.empty()) {
            return;
        }
        const auto m = board.size(); // row
        const auto n = board[0].size(); // column

        for (int i = 0; i < n; ++i) {
            bfs(board, 0, i);// top -> bottom
            bfs(board, m - 1, i); // bottom -> top
        }
        for (int j = 1; j < m - 1; ++j) {
            bfs(board, j, 0); // right -> left
            bfs(board, j, n - 1); // left -> right
        }
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                } else if (board[i][j] == 'P') {
                    board[i][j] = 'O'; // recover
                }
            }
        }
    }


private:
    void bfs(vector<vector<char>> &board, int i, int j) {
        queue<pair<int, int>> q;
        const auto m = board.size();
        const auto n = board[0].size();

        auto state_is_valid = [&](const pair<int, int> &s)->bool {
            const int x = s.first;
            const int y = s.second;
            if (x < 0 || x >= m || y < 0 || y >= n || board[x][y] != 'O') {
                return false;
            }
            return true; // 0 <= x,y < m && board[x][y] == 'O'
        };

        auto state_extend = [&](const pair<int, int> &s) {
            vector<pair<int, int>> result;
            const int x = s.first;
            const int y = s.second;
            const pair<int, int> new_states[4] = {
                {x - 1, y}, /*up*/
                {x + 1, y}, /*down*/
                {x, y - 1}, /*left*/
                {x, y + 1}  /*right*/
            };
            for (auto k = 0; k < 4; ++k) {
                if (state_is_valid(new_states[k])) {
                    board[new_states[k].first][new_states[k].second] = 'P'; // change state
                    result.push_back(new_states[k]); // save valid coordinates
                }
            }
            return result;
        };

        pair<int,int> start = {i, j};
        if (state_is_valid(start)) {
            board[i][j] = 'P';
            q.push(start);
        }
        while (!q.empty()) {
            auto curr = q.front();
            q.pop();
            auto new_states = state_extend(curr);
            for (auto &s : new_states) {
                q.push(s);
            }
        }
    }
};