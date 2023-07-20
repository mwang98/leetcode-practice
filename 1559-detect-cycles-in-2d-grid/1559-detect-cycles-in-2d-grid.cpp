class Solution {
public:
    vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
    bool dfs(int (*color)[500], vector<vector<char>>& grid, int ch, int x, int y, int px = -1, int py = -1){
        // Return true if cycle is detected
        // Base case
        if(color[x][y] == 2) return false;
        if(color[x][y] == 1) return true;
        // Recursive case
        if(ch + 'a' != grid[x][y]){
            color[x][y] = 2;
            return false;
        }

        color[x][y] = 1;
        for(const auto& [dx, dy]: directions){
            int nx = x + dx, ny = y + dy;
            if(nx >= 0 && nx < grid.size() && ny >= 0 && ny < grid[0].size() &&
               !(nx == px && ny == py)){
                   if(dfs(color, grid, ch, nx, ny, x, y)) return true;
            }
        }
        color[x][y] = 2;
        return false;
        
    }
    bool containsCycle(vector<vector<char>>& grid) {
        /* DFS: cycel detection using coloring */
        
        for(int ch = 0 ; ch < 26 ; ++ch){
            int color[500][500]; // 0: unvisited, 1: starting, 2: done
            memset(color, 0, sizeof(color));
            for(int x = 0 ; x < grid.size() ; x++){
                for(int y = 0 ; y < grid[0].size() ; ++y){
                    if(dfs(color, grid, ch, x, y)) return true;
                }
            }    

            cout << endl;
        }

        return false;
    }
};