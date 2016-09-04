/*
54. Spiral Matrix

Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order. 

For example,
 Given the following matrix: 
[
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
]


You should return [1,2,3,6,9,8,7,4,5]. 

*/

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        const auto m = matrix.size();
        if (0 == m) return res;
        /*if (1 == m) return matrix[0];*/
        
        const auto n = matrix[0].size();
        /*if (1 == n)
        {
            for (auto &i : matrix) 
                res.push_back(i[0]);
            return res;
        }*/
            
        
        for (auto start = 0; (2 * start) < m && (2 * start) < n; ++start)
        {
            auto row_end = m - 1 - start;
            auto column_end = n - 1 - start;
            
            if (start == row_end)
            {
                for (auto i = start; i <= column_end; ++i)
                    res.push_back(matrix[start][i]);
                return res;
            }
            if (start == column_end)
            {
                for (auto i = start; i <= row_end; ++i)
                    res.push_back(matrix[i][start]);
                return res;
            }
            
            for (int i = start; i < column_end; ++i)
                res.push_back(matrix[start][i]);
            for (int i = start; i < row_end; ++i)
                res.push_back(matrix[i][column_end]);
            for (int i = column_end; i > start; --i)
                res.push_back(matrix[row_end][i]);
            for (int i = row_end; i > start; --i)
                res.push_back(matrix[i][start]);
            
            
        }
        return res;
    }
};