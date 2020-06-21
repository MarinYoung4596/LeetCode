/*
119. Pascal's Triangle II.
Given an index k, return the kth row of the Pascal's triangle.

For example, given k = 3,
Return [1,3,3,1].

Note:
Could you optimize your algorithm to use only O(k) extra space?
*/

#include <vector>


void clearAndSave(vector<int> &preRow, int row[], int nRow, vector<vector<int> > &res)
{
    preRow.clear();
    for (int i = 0; i < nRow; i++)
        preRow.push_back(row[i]);
    res.push_back(preRow);
}

vector<vector<int> > generate(int numRows)
{
    vector<vector<int> > res;
    int row[numRows];
    vector<int> preRow;
    for (int i = 1; i <= numRows; i++)
    {
        if (i == 1)
        {
            row[0] = 1;
            clearAndSave(preRow, row, i, res);
            continue;
        }
        if (i == 2)
        {
            row[0] = row[i-1] = 1;
            clearAndSave(preRow, row, i, res);
            continue;
        }
        // i >= 3
        row[0] = row[i-1] = 1;
        for (int j = 1; j < (i+1)/2; j++)
            row[j] = row[i-1-j] = preRow[j-1] + preRow[j];
        clearAndSave(preRow, row, i, res);
    }
    return res;
}


vector<int> getRow(int rowIndex) 
{
    vector<vector<int> > pascalTriangle;
    pascalTriangle = generate(rowIndex+1);
    return pascalTriangle[rowIndex];
}


// second solution
class Solution {
public:
    vector<int> getRow(int k) {
        vector<int> res(k+1, 0);
        
        res[k] = 1;
        for (auto i = 0; i <= k; ++i)
        {
            for (auto j = k-1; j > 0; --j)
                res[j] += res[j-1];
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