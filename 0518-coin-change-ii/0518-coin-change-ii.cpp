class Solution {
public:
    int change(int amount, vector<int>& coins) {
        /* DP
        Def: dp[amount][j]: the number of combinations that make up the `amount` using coins[:j]
        Transition:
            (1) use coins[j]: dp[amount - coin[j]][j]
            (2) not use: dp[amount][j-1]
        TC: O(amount * coin.size)
        SC: O(amount * coin.size)
        */
        int dp[5001][301];
        memset(dp, 0, sizeof(dp));
        // Init
        for(int j = 0 ; j < 301 ; ++j) dp[0][j] = 1;

        for(int i = 1 ; i <= amount ; ++i){
            for(int j = 0 ; j < coins.size() ; ++j){
                dp[i][j + 1] = dp[i][j];
                if(i >= coins[j]) dp[i][j + 1] += dp[i - coins[j]][j + 1];
            }
        }

        return dp[amount][coins.size()];
    }
};