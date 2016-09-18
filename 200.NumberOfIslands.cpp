/*
200. Number of Islands

Given a 2d grid map of '1's (land) and '0's (water), count the number of islands. An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

Example 1:

11110
11010
11000
00000
Answer: 1

Example 2:

11000
11000
00100
00011
Answer: 3

*/

class Solution {
public:
/*
对于一个为‘1’且未被访问过的位置，我们递归进入其上下左右位置上为‘1’的数，将其visited对应值赋为true，
继续进入其所有相连的邻位置，这样可以将这个连通区域所有的数找出来，并将其对应的visited中的值赋true，
找完次区域后，我们将结果res自增1，然后我们在继续找下一个为‘1’且未被访问过的位置，以此类推直至遍历
完整个原数组即可得到最终结果
*/
    int numIslands(vector<vector<char>>& grid)
    {
        if (grid.empty()) return 0;
        
        const auto m = grid.size();
        const auto n = grid[0].size();
        
        if (0 == n) return 0;
        
        int result = 0;
        
        for (auto i = 0; i < m; ++i)
        {
            for (auto j = 0; j < n; ++j)
            {
                if (grid[i][j] != '1') continue;
                
                ++result;
                dfs(grid, i, j);
            }
        }
        return result;
    }
    
private:
    void dfs(vector<vector<char>> &grid, int i, int j)
    {
        const auto m = grid.size();
        const auto n = grid[0].size();
        
        if (i < 0 || i >= m ||
            j < 0 || j >= n) return;
        
        if (grid[i][j] == '1')
        {
            grid[i][j] = '0'; // 已经访问过，置0
            dfs(grid, i - 1, j); // 访问上下左右四个方向  
            dfs(grid, i + 1, j);
            dfs(grid, i, j - 1);
            dfs(grid, i, j + 1);
        }
    }
};