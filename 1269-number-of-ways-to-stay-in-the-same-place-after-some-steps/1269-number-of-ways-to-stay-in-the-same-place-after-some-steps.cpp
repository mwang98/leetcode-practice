class Solution {
public:
    int MOD = 1e9 + 7;
    int max_pos = 0;
    int dp[501][501];
    int dfs(int pos, int step){
        // Base case
        if(dp[pos][step] != -1) return dp[pos][step];
        if(step == 0) return dp[pos][step] = pos == 0;
        // Recursive case
        dp[pos][step] = dfs(pos, step-1);
        if(pos + 1 <= max_pos) dp[pos][step] = (dp[pos][step] + dfs(pos + 1, step-1)) % MOD;
        if(pos -1 >= 0) dp[pos][step] = (dp[pos][step] + dfs(pos - 1, step-1)) % MOD;
        return dp[pos][step];
    }
    int numWays(int steps, int arrLen) {
        /* DP 
        Def: dp[pos][step]: the number of ways to get back to 0 from `pos` with exactly `step` steps
        Transition:
            Stay:       dp[pos][step-1]
            From right: dp[pos+1][step-1]
            From left:  dp[pos-1][step-1]
        Optimize trick: `pos` is never greater than `steps`
        */
        max_pos = min(arrLen - 1, steps);

        for(int i = 0 ; i < 501 ; ++i)
            for(int j = 0 ; j < 501 ; ++j) dp[i][j] = -1;

        return dfs(0, steps);
    }
};