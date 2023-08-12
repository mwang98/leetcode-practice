class Solution {
public:
    int dp[100][100];
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        memset(dp, 0, sizeof(dp));
        dp[0][0] = obstacleGrid[0][0] == 0;
        auto n_rows = obstacleGrid.size(), n_cols = obstacleGrid[0].size();

        for(int i = 0 ; i < n_rows ; ++i){
            for(int j = 0 ; j < n_cols ; ++j){
                if((i == 0 && j == 0) || obstacleGrid[i][j]) continue;
                dp[i][j] += (i - 1 >= 0) ? dp[i - 1][j] : 0;
                dp[i][j] += (j - 1 >= 0) ? dp[i][j - 1] : 0;
            }
        }

        return dp[n_rows - 1][n_cols - 1];
    }
};