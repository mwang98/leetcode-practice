/*
 * @lc app=leetcode id=1706 lang=cpp
 *
 * [1706] Where Will the Ball Fall
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution {
public:
    int cache[101][101];
    int dfs(vector<vector<int>>& grid, int x, int y){
        auto n_rows = grid.size(), n_cols = grid[0].size();
        // Base case
        if (x == n_rows) return y;
        if (cache[x][y] != n_cols) return cache[x][y];
        // Recursive case
        if(grid[x][y] == 1){
            if (y + 1 < n_cols && grid[x][y + 1] == 1)
                cache[x][y] = dfs(grid, x + 1, y + 1);
            else cache[x][y] = -1;
        }else{
            if (y - 1 >= 0 && grid[x][y - 1] == -1)
                cache[x][y] = dfs(grid, x + 1, y - 1);
            else cache[x][y] = -1;
        }
        return cache[x][y];
    }

    vector<int> findBall(vector<vector<int>>& grid) {
        auto n_rows = grid.size(), n_cols = grid[0].size();
        vector<int> ret(n_cols);
        for (int i = 0; i < 101; i++)
            for (int j = 0; j < 101; j++)
                cache[i][j] = n_cols;

        for (int i = 0; i < n_cols; ++i)
            ret[i] = dfs(grid, 0, i);

        return ret;
    }
};
// @lc code=end

