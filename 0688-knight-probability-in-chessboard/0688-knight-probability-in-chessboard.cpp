class Solution {
public:
    vector<pair<int, int>> directions = {{1, 2}, {2, 1}, {1, -2}, {2, -1}, {-1, 2}, {-2, 1}, {-1, -2}, {-2, -1}};

    double knightProbability(int n, int k, int row, int column) {
        /* DP 
        Def: dp[move][i][j]: the probability of reaching (i, j) with `move` move
        Transition
            dp[move][i][j] = sum(dp[move-1][m][n]) / 8, where (m, n) is one of the eight possible cells
        TC: O(mnk)
        SC: O(mn)
        */
        vector<vector<double>> dp(n, vector<double>(n, 0));
        double prob = 1;
        dp[row][column] = 1;

        for(int move = 0 ; move < k ; ++move){
            vector<vector<double>> new_dp(n, vector<double>(n, 0));
            double new_prob = 0;

            for(int x = 0 ; x < n ; ++x){
                for(int y = 0 ; y < n ; ++y){
                    for(const auto& [dx, dy]: directions){
                        auto nx = x + dx, ny = y + dy;
                        if(nx >= 0 && nx < n && ny >= 0 && ny < n){
                            new_dp[x][y] += dp[nx][ny];
                        }
                    }
                    new_dp[x][y] /= 8;
                    new_prob += new_dp[x][y];
                }
            }

            dp = new_dp;
            prob = new_prob;
        }

        return prob;
    }
};