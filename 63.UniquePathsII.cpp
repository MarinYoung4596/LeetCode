/*
63. Unique Paths II

Follow up for "Unique Paths":
Now consider if some obstacles are added to the grids. How many unique paths would there be?
An obstacle and empty space is marked as 1 and 0 respectively in the grid.

For example,
There is one obstacle in the middle of a 3x3 grid as illustrated below.
[
  [0,0,0],
  [0,1,0],
  [0,0,0]
]
The total number of unique paths is 2.

Note: m and n will be at most 100.
*/

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if (obstacleGrid.empty()) return 0;
        
        const auto row = obstacleGrid.size();
        const auto col = obstacleGrid[0].size();
        int dp[row][col];
        memset(dp, 0, sizeof(dp));
        
        for (auto i = 0; i < row; ++i)
        {
            if (obstacleGrid[i][0]) break;
            dp[i][0] = 1;
        }
        for (auto j = 0; j < col; ++j)
        {
            if (obstacleGrid[0][j]) break;
            dp[0][j] = 1;
        }
        
        for (auto i = 1; i < row; ++i)
        {
            for (auto j = 1; j < col; ++j)
            {
                if (!obstacleGrid[i][j]) 
                {
                    dp[i][j] = dp[i-1][j] + dp[i][j-1];
                }
            }
        }
        return dp[row-1][col-1];
    }
};
