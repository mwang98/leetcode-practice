class Solution {
public:
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        /* DP
        Def: dp[i][j][n]: # of paths with sum % k equal to n
        Transition:
            dp[i][j][n] = dp[i-1][j][(n + k - grid[i][j]) % k] + 
                          dp[i][j-1][(n + k - grid[i][j]) % k]
        */

        // Define dp table & variables
        int n_rows = grid.size(), n_cols = grid[0].size();
        int MOD = 1e9 + 7;
        vector<vector<vector<int>>> dp(n_rows, vector<vector<int>>(n_cols, vector<int>(k, 0)));

        // Initialize dp table
        dp[0][0][ grid[0][0] % k ] = 1;

        // Bottom up
        for(int i = 0 ; i < n_rows ; ++i){
            for(int j = 0 ; j < n_cols; ++j){
                for(int n = 0 ; n < k ; ++n){
                    if(i == 0 && j == 0) continue;
                    auto prev_n = (n + k * (grid[i][j] / k + 1) - grid[i][j]) % k;
                    if(j > 0){
                        dp[i][j][n] = (dp[i][j][n] + dp[i][j-1][prev_n]) % MOD; // from left
                    }
                    if(i > 0){
                        dp[i][j][n] = (dp[i][j][n] + dp[i-1][j][prev_n]) % MOD; // from top
                    }
                }
            }
        }

        return dp[n_rows - 1][n_cols - 1][0];
    }
};