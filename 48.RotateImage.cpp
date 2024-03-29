/*
48. Rotate Image

You are given an n x n 2D matrix representing an image.
Rotate the image by 90 degrees (clockwise).

Follow up: could you do this in-place?
*/

class Solution {
  public:
    // recursive solution
    void rotate(vector<vector<int>> &matrix) {
        int N = matrix.size();
        rotate(matrix, N, 0, N - 1);
    }

  private:
    void rotate(vector<vector<int>> &matrix, int N, int start, int end) {
        if (N <= 1 || start >= end) {
            return;
        }
        for (auto i = start; i < end; ++i) {
            // right rotate : clockwise
            auto tmp                         = matrix[start][i];
            matrix[start][i]                 = matrix[end - (i - start)][start];
            matrix[end - (i - start)][start] = matrix[end][end - (i - start)];
            matrix[end][end - (i - start)]   = matrix[i][end];
            matrix[i][end]                   = tmp;
        }
        rotate(matrix, N - 2, start + 1, end - 1);
    }
};