/*
62. Unique Paths
A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).

The robot can only move either *down* or *right* at any point in time. The robot is trying to reach 
the bottom-right corner of the grid (marked 'Finish' in the diagram below).

How many possible unique paths are there?

Note: m and n will be at most 100.
*/

#include <iostream>
#include <cstring>

class Solution {
public:
	// First Solution: Dynamic Programming
	// dp[i][j] represents the unique paths from (1, 1) to (i, j)
	// dp[i][j] = dp[i-1][j] + dp[i][j-1]
    int uniquePaths(int m, int n) 
    {
        memset(dp, 0, sizeof(dp));
    	for (int i = 0; i < m; i++)
	    {
		    for (int j = 0; j < n; j++)
		    {
			    if (i == 0 || j == 0)
			    {
				    dp[i][j] = 1;
				    continue;
			    }
			    dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
		    }
	    }
	    return dp[m-1][n-1];
    }
    
    // Second Solution: DFS search
	// Time Limited Exceeded in big data
	int uniquePaths2(int m, int n)
	{
		if (m < 1 || n < 1)
			return 0;
		if (m == 1 || n == 1)
			return 1;
		return uniquePaths2(m - 1, n) + uniquePaths2(m, n - 1);
	}
	
private:
    int dp[100][100];
};


int main(int argv, char **argc)
{
	Solution obj;
	int m = 3, n = 7;

	std::cout << obj.uniquePaths2(m, n) << std::endl;

	return 0;
}

