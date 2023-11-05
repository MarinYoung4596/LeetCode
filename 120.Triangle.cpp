/*
Given a triangle, find the minimum path sum from top to bottom. Each step you may move to adjacent numbers on the row below.

For example, given the following triangle
[
     [2],
    [3,4],
   [6,5,7],
  [4,1,8,3]
]

The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).

Note: Bonus point if you are able to do this using only O(n) extra space, where n is the total number of rows in the triangle.

*/
#include <cstring>
#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    int minimumTotal(vector<vector<int>> &triangle) {
        // dp[i][j] = T[i][j] + min{dp[i-1][j-1], dp[i-1][j], dp[i-1][j+1]}
        const int n = triangle.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));

        for (int j = 0; j < n; ++j) {
            dp[n - 1][j] = triangle[n - 1][j];
        }
        for (int i = n - 2; i >= 0; --i) {
            for (int j = 0; j <= i; ++j) {
                int tmp = min(dp[i + 1][j], dp[i + 1][j + 1]);
                dp[i][j] = triangle[i][j] + tmp;
            }
        }
        return dp[0][0];
    }
};

int main() {
    vector<int> level1 = {2};
    vector<int> level2 = {3, 4};
    vector<int> level3 = {6, 5, 7};
    vector<int> level4 = {4, 1, 8, 3};

    vector<vector<int>> res;
    res.push_back(level1);
    res.push_back(level2);
    res.push_back(level3);
    res.push_back(level4);

    Solution obj;
    cout << obj.minimumTotal(res) << endl;

    return 0;
}
