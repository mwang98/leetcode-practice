class Solution {
public:
    vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
    int target_path_len = 0;
    int n_ways = 0;
    void backtrack(vector<vector<int>>& grid, int x, int y, int level){
        auto n_rows = grid.size(), n_cols = grid[0].size();
        // Base case
        if(grid[x][y] == 2){
            n_ways += level == target_path_len;
            return;
        }
        // Recursive case
        auto tmp = grid[x][y];
        grid[x][y] = -1;

        for(const auto& [dx, dy]: directions){
            auto nx = x + dx, ny = y + dy;
            if(nx >= 0 && nx < n_rows && ny >= 0 && ny < n_cols && (grid[nx][ny] == 0 || grid[nx][ny] == 2))        
                backtrack(grid, nx, ny, level + 1);
        }

        grid[x][y] = tmp;
    }

    int uniquePathsIII(vector<vector<int>>& grid) {
        auto n_rows = grid.size(), n_cols = grid[0].size();

        int start_x, start_y;
        target_path_len = n_rows * n_cols - 1; // exclude start
        for(int i = 0 ; i < n_rows ; ++i){
            for(int j = 0 ; j < n_cols ; ++j){
                target_path_len -= grid[i][j] == -1;
                if(grid[i][j] == 1){
                    start_x = i, start_y = j;
                }
            }
        }

        backtrack(grid, start_x, start_y, 0);
        return n_ways;
    }
};