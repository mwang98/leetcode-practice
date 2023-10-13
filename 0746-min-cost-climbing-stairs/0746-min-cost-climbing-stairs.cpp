class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        /* DP 
        Def: dp[i]: minimum cost of stepping on `i`-th stair
        Transition:
            - 1 step: cost[i - 1] + dp[i - 1]
            - 2 steps: cost[i - 2] + dp[i-2]
        */

        // Define variables
        int dp[1001];
    
        // Initialize dp table
        memset(dp, 0, sizeof(dp));

        // Initial conditions for dp

        // Bottom up
        for(int i = 2 ; i <= (int)cost.size() ; ++i){
            dp[i] = min(dp[i - 1] + cost[i - 1], dp[i - 2] + cost[i - 2]);
        }

        return dp[cost.size()];
    }
};