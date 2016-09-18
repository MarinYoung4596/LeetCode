/*
240. Search a 2D Matrix II

Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:

Integers in each row are sorted in ascending from left to right.
Integers in each column are sorted in ascending from top to bottom.
For example,

Consider the following matrix:

[
  [1,   4,  7, 11, 15],
  [2,   5,  8, 12, 19],
  [3,   6,  9, 16, 22],
  [10, 13, 14, 17, 24],
  [18, 21, 23, 26, 30]
]
Given target = 5, return true.

Given target = 20, return false.
*/

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) 
    {
        return searchMatrix(matrix, target, 0, matrix.size() - 1, 0, matrix[0].size() - 1);
    }
    
private:
    bool searchInRow(const vector<vector<int>> &matrix, const int &target, const int &row, int minc, int maxc)
    {
        if (minc > maxc) return false;
        
        int mid = (minc + maxc) / 2;
        if (target > matrix[row][mid]) minc = mid + 1;
        else if (target < matrix[row][mid]) maxc = mid - 1;
        else return true;
        
        return searchInRow(matrix, target, row, minc, maxc);
    }
    
    bool searchInColumn(const vector<vector<int>> &matrix, const int &target, const int &column, int minr, int maxr)
    {
        if (minr > maxr) return false;
        
        int mid = (minr + maxr) / 2;
        if (target > matrix[mid][column]) minr = mid + 1;
        else if (target < matrix[mid][column]) maxr = mid - 1;
        else return true;
        
        return searchInColumn(matrix, target, column, minr, maxr);
    }
    
    bool searchMatrix(const vector<vector<int>> &matrix, const int &target,
                    int minr, int maxr, int minc, int maxc )
    {
        if (minc > maxc || minr > maxr) return false;
        if (minc == maxc) return searchInColumn(matrix, target, minc, minr, maxr);
        if (minr == maxr) return searchInRow(matrix, target, minr, minc, maxc);
        
        int left_bottom = matrix[maxr][minc];
        int right_top = matrix[minr][maxc];
        
        if (left_bottom == target || right_top == target) return true;
        
        if (target > right_top)  ++minr;
        else  --maxc;
        
        if (target > left_bottom) ++minc;
        else  --maxr;
        
        return searchMatrix(matrix, target, minr, maxr, minc, maxc);
    }
};