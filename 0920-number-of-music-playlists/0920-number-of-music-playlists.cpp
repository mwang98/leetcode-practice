class Solution {
public:
    int MOD = 1e9 + 7;
    int dp[101][101];
    int numMusicPlaylists(int n, int goal, int k) {
        /* DP 
        Def: dp[goal][j]: the number of possible playlist with length = `goal` using `j` songs
        Transition:
        (1) Add new song:
            # of choices: n - (j - 1)
            dp[goal-1][j-1] * (n - j + 1)
        (2) Replay old song:
            # of choice: j - k
            dp[goal-1][j] * (j - k)
        */
        memset(dp, 0, sizeof(dp));
        // for(int g = 0 ; g < n ; ++g) dp[g][0] = 0; // goal = i with zero books
        // for(int j = 1 ; j < n ; ++j) dp[0][j] = 0; // goal = 0 with j books
        dp[0][0] = 1;

        for(int g = 0 ; g < goal ; ++g){
            for(int j = 0 ; j < n ; ++j){
                dp[g+1][j+1] = (((0L + dp[g][j]) * (n - j)) % MOD +
                                ((0L + dp[g][j+1]) * max(0,  j + 1 - k)) % MOD) % MOD;
            }
        }
        return dp[goal][n];
    }
};