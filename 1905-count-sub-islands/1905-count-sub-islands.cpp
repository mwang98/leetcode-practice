class DSU {
public:
    vector<int> parent;
    vector<int> rank;
    DSU(int n) {
        parent.resize(n);
        rank.resize(n);
        for(int i = 0 ; i < n ; ++i) parent[i] = i;
    }
    auto Find(int x) -> int {
        if(parent[x] != x) parent[x] = Find(parent[x]);
        return parent[x];
    }
    auto Union(int x, int y) -> bool {
        int px = Find(x), py = Find(y);

        if(px == py) return false;
        if(rank[px] < rank[py]) parent[px] = py;
        else if(rank[px] > rank[py]) parent[py] = px;
        else {
            parent[py] = px;
            ++rank[px];
        }
        return true;
    }
};

class Solution {
public:
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        auto n_rows = grid1.size(), n_cols = grid1[0].size();
        vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
        int res = 0;

        DSU dsu(n_rows * n_cols);
        vector<vector<bool>> visited(n_rows, vector<bool>(n_cols, false));

        // Encode
        auto encode = [&](int x, int y) -> int {
            return x * n_cols + y;
        };
        
        // Build DSU
        for(int x = 0 ; x < n_rows ; ++x){
            for(int y = 0 ; y < n_cols ; ++y){
                if(grid1[x][y] == 0) continue;

                for(auto [dx, dy]: directions){
                    auto nx = x + dx, ny = y + dy;
                    if(!(0 <= nx && nx < n_rows && 0 <= ny && ny < n_cols)) continue;
                    if(grid1[nx][ny] == 0) continue;
                    dsu.Union(encode(x, y), encode(nx, ny));
                }
            }
        }

        // Define DFS function: whether island in grid2 is sub-island
        function<bool(int, int, int)> dfs = [&](int x, int y, int group) -> bool {
            // Base case
            if(dsu.Find(encode(x, y)) != group) return false;
            if(visited[x][y]) return false;

            // Recursive case
            visited[x][y] = true;
            bool res = true;
            for(auto [dx, dy]: directions){
                auto nx = x + dx, ny = y + dy;

                if(!(0 <= nx && nx < n_rows && 0 <= ny && ny < n_cols) ||
                   grid2[nx][ny] == 0 ||
                   visited[nx][ny]) continue;

                // Important !!! Keep traversing no matter the result is true/false
                // Make sure every cell on an island are traversed at once
                if (!dfs(nx, ny, group)) res = false;
            }
            return res;
        };


        for(int x = 0 ; x < n_rows ; ++x){
            for(int y = 0 ; y < n_cols ; ++y){
                if(grid1[x][y] == 0 || grid2[x][y] == 0) continue;

                res += dfs(x, y, dsu.Find(encode(x, y)));
            }
        }

        return res;
    }
};