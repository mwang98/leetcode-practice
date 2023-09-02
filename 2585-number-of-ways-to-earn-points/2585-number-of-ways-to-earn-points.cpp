class Solution {
public:
    int MOD = 1e9 + 7;
    int dp[1001][50];
    int topdown(vector<vector<int>>& types, int target, int i = 0){
        // Base case
        if(target == 0) return 1;
        if(i == types.size() || target < 0) return 0;
        if(dp[target][i] != -1) return dp[target][i];
        // Recursive case
        dp[target][i] = 0;
        int count = types[i][0], mark = types[i][1];
        for(int n = 0 ; n <= count ; ++n){
            dp[target][i] = (0L + dp[target][i] + topdown(types, target - n * mark, i + 1)) % MOD;
        }
        return dp[target][i];
    }
    int waysToReachTarget(int target, vector<vector<int>>& types) {
        /* DP
        Def: dp[target][i]: # of ways of earn `target` points using types[i:] of questions
        Transition:
            for n in range(n_question):
                dp[target][i] += dp[target - marks[i] * n][i + 1];
        TC: O(target * n)
        SC: O(target * n)
        */
        for(int i = 0 ; i < 1001 ; ++i)
            for(int j = 0 ; j < 50 ; ++j)
                dp[i][j] = -1;

        return topdown(types, target);
    }
};