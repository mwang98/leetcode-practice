class Solution {
public:
    int dp[10][2048];
    int compute_dist(const vector<int>& worker, const vector<int>& bike){
        return abs(worker[0] - bike[0]) + abs(worker[1] - bike[1]);
    }
    int topdown(int i, int mask, vector<vector<int>>& workers, vector<vector<int>>& bikes){
        // Base case
        if(i == workers.size()) return 0;
        if(dp[i][mask] != INT_MAX) return dp[i][mask];
        // Recursive case
        for(int j = 0 ; j < bikes.size() ; ++j){
            if((1 << j) & mask) continue;
            dp[i][mask] = min(dp[i][mask], 
                              compute_dist(workers[i], bikes[j]) + topdown(i + 1, mask | (1 << j), workers, bikes));
        }

        return dp[i][mask];
    }
    int assignBikes(vector<vector<int>>& workers, vector<vector<int>>& bikes) {
        /* Bitmask DP 
        Def: dp[i][mask]: the smallest sum of distances given bikes[mask] were assigned to workers[i:]
        Transition:
            Select bike[k]:
                dist(bike[k], worker[i]) + dp[i+1][mask | bike[k]]
        TC: O(n^2 * 2^m)
        SC: O(n * 2^m)
        */
        for(int i = 0 ; i < 10 ; ++i)
            for(int j = 0 ; j < 2048 ; ++j)
                dp[i][j] = INT_MAX;

        topdown(0, 0, workers, bikes);

        return dp[0][0];
    }
};