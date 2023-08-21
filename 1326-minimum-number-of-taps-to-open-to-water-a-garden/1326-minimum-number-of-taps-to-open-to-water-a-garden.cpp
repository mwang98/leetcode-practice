class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        /* DP 
        Def: dp[i]: the minimum number of taps needed to cover [0: i]
        Transition:
        */
        int dp[1000001];
        for(int i = 0 ; i < 1000001 ; ++i) dp[i] = -1;

        for(int i = 0 ; i < ranges.size() ; ++i){
            auto prev = (i - ranges[i]) > 0 ? dp[i - ranges[i]] : 0;
            if (ranges[i] == 0 || prev == -1) continue;

            for(int dist = -ranges[i] ; dist <= ranges[i] ; ++dist){
                if(i + dist < 0) continue;
                if(dp[i + dist] == -1) dp[i + dist] = prev + 1;
                else dp[i + dist] = min(dp[i + dist], prev + 1);
            }
        }

        for(int i = 0 ; i <= n ; ++i) if(dp[i] == 0) return -1;
        return dp[n];
    }
};