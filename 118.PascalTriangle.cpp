/*
Given numRows, generate the first numRows of Pascal's triangle.

For example, given numRows = 5, Return
[    [1],
   [1,1],
  [1,2,1],
 [1,3,3,1],
[1,4,6,4,1] ]

clear current row and save the data into preRow
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
  private:
    void clearAndSave(vector<int> &preRow, int row[], int nRow, vector<vector<int>> &res) {
        preRow.clear();
        for (int i = 0; i < nRow; i++) {
            preRow.push_back(row[i]);
        }
        res.push_back(preRow);
    }

  public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;
        int row[numRows];
        vector<int> preRow;
        for (int i = 1; i <= numRows; i++) {
            if (i == 1) {
                row[0] = 1;
                clearAndSave(preRow, row, i, res);
            } else if (i == 2) {
                row[0] = row[i - 1] = 1;
                clearAndSave(preRow, row, i, res);
            } else {
                row[0] = row[i - 1] = 1;
                for (int j = 1; j < (i + 1) / 2; j++) {
                    row[j] = row[i - 1 - j] = preRow[j - 1] + preRow[j];
                }
                clearAndSave(preRow, row, i, res);
            }
        }
        return res;
    }
};
