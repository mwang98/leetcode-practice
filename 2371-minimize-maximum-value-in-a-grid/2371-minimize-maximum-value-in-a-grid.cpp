class Solution {
public:
    vector<vector<int>> minScore(vector<vector<int>>& grid) {
        /* Topological sort */
        // Define variables
        int n_rows = grid.size(), n_cols = grid[0].size();
        vector<vector<int>> adj_list(n_rows * n_cols);
        queue<int> q;
        vector<int> indegrees(n_rows * n_cols, 0);

        vector<vector<int>> res(n_rows, vector<int>(n_cols));

        // Define helper function
        auto encode = [&](int x, int y) -> int {
            return x * n_cols + y;
        };
        auto decode = [&](int node) -> pair<int, int> {
            return {node / n_cols, node % n_cols};
        };

        auto getRow = [&](int row_idx) -> vector<pair<int, int>> {
            vector<pair<int, int>> res(n_cols);
            for(int i = 0 ; i < n_cols ; ++i) res[i] = {grid[row_idx][i], i};
            return res;
        };
        auto getCol = [&](int col_idx) -> vector<pair<int, int>> {
            vector<pair<int, int>> res(n_rows);
            for(int i = 0 ; i < n_rows ; ++i) res[i] = {grid[i][col_idx], i};
            return res;
        };

        // Build adjacency graph & indegrees
        for(int x = 0 ; x < n_rows ; ++x){
            auto row = getRow(x);
            sort(row.begin(), row.end());
            for(int i = 0 ; i < row.size() - 1 ; ++i){
                auto [tmp1, idx1] = row[i];
                auto [tmp2, idx2] = row[i + 1];
                adj_list[encode(x, idx1)].push_back(encode(x, idx2));
                indegrees[encode(x, idx2)]++;
            }
        }

        
        for(int y = 0 ; y < n_cols ; ++y){
            auto col = getCol(y);
            sort(col.begin(), col.end());
            for(int j = 0 ; j < col.size() - 1 ; ++j){
                auto [tmp1, idx1] = col[j];
                auto [tmp2, idx2] = col[j + 1];
                adj_list[encode(idx1, y)].push_back(encode(idx2, y));
                indegrees[encode(idx2, y)]++;
            }
        }

        // Initialize queue
        for(int i = 0 ; i < indegrees.size() ; ++i){
            if(indegrees[i] == 0) q.push(i);
        }

        // Execute in topological order
        int level = 1;
        while(!q.empty()){
            for(int i = 0, size = q.size() ; i < size ; ++i){
                auto idx = q.front();
                q.pop();

                // Assign to result matrix
                auto [x, y] = decode(idx);
                res[x][y] = level;

                // Push neighbors
                for(auto nidx: adj_list[idx]){
                    if(--indegrees[nidx] == 0){
                        q.push(nidx);
                    }
                }
            }
            level++;
        }

        return res;
    }
};