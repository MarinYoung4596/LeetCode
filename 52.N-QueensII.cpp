/*
52. N-Queens II

Follow up for N-Queens problem.

Now, instead outputting board configurations, return the total number of distinct solutions.


     | a | b | c | d | e | f | g | h |
     —————————————————————————————————
8    |   |   |   | x |   |   |   |   |
7    |   |   |   |   |   |   | x |   |
6    |   |   | x |   |   |   |   |   |
5    |   |   |   |   |   |   |   | x |
4    |   | x |   |   |   |   |   |   |
3    |   |   |   |   | x |   |   |   |
2    | x |   |   |   |   |   |   |   |
1    |   |   |   |   |   | x |   |   |
     —————————————————————————————————
*/



class Solution {
public:
    int totalNQueens(int n) {
        vector<int> columns(n, 0);
        int solution = 0;

        dfs(columns, 0, solution);

        return solution;
    }

private:
    void dfs(vector<int> &columns, const int curr, int &solution) {
        if (curr == columns.size()) { // to the end of the row
            solution++;
            return;
        }
        for (auto j = 0; j < columns.size(); ++j) { // column
            columns[curr] = j; // put queen at [curr][j]
            bool _is_valid = isValid(columns, curr, j); // not conflict with previous queen
            if (_is_valid) {
                dfs(columns, curr+1, solution); // to the next row
            }
        }
    }

    bool isValid(const vector<int> &columns, const int row, const int column) {
        for (auto i = 0; i < row; ++i) {// get the column of the queen in each row
            if (columns[i] == column || /* same column */
                    abs(row - i) == abs(columns[i] - column) /* catercorner */) {
                return false;
            }
        }
        return true;
    }
};