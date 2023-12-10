/*
There is a robot on an m x n grid. The robot is initially located at the top-left corner (i.e., grid[0][0]).
The robot tries to move to the bottom-right corner (i.e., grid[m - 1][n - 1]).
The robot can only move either down or right at any point in time.

Given the two integers m and n,
return the number of possible unique paths that the robot can take to reach the bottom-right corner.

The test cases are generated so that the answer will be less than or equal to `2 * 10^9`.



Example 1:
    ![pic](https://assets.leetcode.com/uploads/2018/10/22/robot_maze.png)
    Input: m = 3, n = 7
    Output: 28

Example 2:
    Input: m = 3, n = 2
    Output: 3
    Explanation: From the top-left corner, there are a total of 3 ways to reach the bottom-right corner:
        1. Right -> Down -> Down
        2. Down -> Down -> Right
        3. Down -> Right -> Down


Constraints:
    1 <= m, n <= 100
*/

#include <iostream>
#include <cstring>


// First Solution: Dynamic Programming
// dp[i][j] represents the unique paths from (1, 1) to (i, j)
// dp[i][j] = dp[i-1][j] + dp[i][j-1]
class Solution {
public:
    int uniquePaths(int m, int n) {
        memset(dp, 0, sizeof(dp));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 || j == 0) {
                    dp[i][j] = 1;
                    continue;
                }
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
        return dp[m - 1][n - 1];
    }

private:
    int dp[100][100];
};


// Second Solution: DFS search
// Time Limited Exceeded in big data
class Solution2 {
public:
    int uniquePaths(int m, int n) {
        if (m < 1 || n < 1) {
            return 0;
        }
        if (m == 1 || n == 1) {
            return 1;
        }
        return uniquePaths(m - 1, n) + uniquePaths(m, n - 1);
    }
}


int main(int argv, char **argc) {
    Solution obj;
    int m = 3, n = 7;

    std::cout << obj.uniquePaths(m, n) << std::endl;

    return 0;
}
