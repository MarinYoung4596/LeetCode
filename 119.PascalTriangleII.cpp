/*
Given an index k, return the kth row of the Pascal's triangle.

For example,
    given k = 3,
    Return [1,3,3,1].

Note: Could you optimize your algorithm to use only O(k) extra space?
*/

#include <vector>

class Solution {
private:
    void clearAndSave(vector<int> &pre_row,
                      int row[], int n_row,
                      vector<vector<int> > &res) {
        pre_row.clear();
        for (int i = 0; i < n_row; i++) {
            pre_row.push_back(row[i]);
        }
        res.push_back(pre_row);
    }

    vector<vector<int>> generate(int numRows) {
        vector<vector<int> > res;
        int row[numRows];
        vector<int> pre_row;
        for (int i = 1; i <= numRows; i++) {
            if (i == 1) {
                row[0] = 1;
                clearAndSave(pre_row, row, i, res);
                continue;
            }
            if (i == 2) {
                row[0] = row[i-1] = 1;
                clearAndSave(pre_row, row, i, res);
                continue;
            }
            // i >= 3
            row[0] = row[i-1] = 1;
            for (int j = 1; j < (i+1)/2; j++) {
                row[j] = row[i-1-j] = pre_row[j-1] + pre_row[j];
            }
            clearAndSave(pre_row, row, i, res);
        }
        return res;
    }

public:
    vector<int> getRow(int rowIndex) {
        vector<vector<int>> pascalTriangle;
        pascalTriangle = generate(rowIndex + 1);
        return pascalTriangle[rowIndex];
    }
};

// second solution
class Solution2 {
public:
    vector<int> getRow(int k) {
        vector<int> res(k+1, 0);
        res[k] = 1;
        for (auto i = 0; i <= k; ++i) {
            for (auto j = k-1; j > 0; --j) {
                res[j] += res[j-1];
            }
            res[0] = 1;
        }
        return res;
        /*
        k = 3;
        i   |   0   1   2   3
        ---------------------
        0   |   1   0   0   1
        1   |   1   1   0   1
        2   |   1   1   1   1
        3   |   1   2   2   1
        */
    }
};