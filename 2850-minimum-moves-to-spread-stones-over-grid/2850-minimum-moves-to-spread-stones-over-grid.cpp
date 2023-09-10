class Solution {
public:
    int minimumMoves(vector<vector<int>>& grid) {
        // Brute force
        vector<pair<int, int>> more_stones, no_stones;
        int min_moves = INT_MAX;

        for(int i = 0 ; i < 3 ; ++i){
            for(int j = 0 ; j < 3 ; ++j){
                if(grid[i][j] == 0) no_stones.push_back({i, j});
                else if(grid[i][j] > 1){
                    for(int k = 0 ; k < grid[i][j] - 1; ++k){
                        more_stones.push_back({i, j});
                    }
                }
            }
        }

        function<void(int, int, int)> backtrack = [&](int idx, int mask, int moves){
            // Base case
            if(idx == no_stones.size()){
                min_moves = min(min_moves, moves);
                return;
            }
            // Recursive case
            auto [tgt_x, tgt_y] = no_stones[idx];

            for(int i = 0 ; i < more_stones.size() ; ++i){
                if(mask & 1 << i) continue;
                auto [src_x, src_y] = more_stones[i];
                backtrack(idx + 1, mask | 1 << i, moves + abs(src_x - tgt_x) + abs(src_y - tgt_y));
            }
        };

        backtrack(0, 0, 0);
        return min_moves;
    }
};