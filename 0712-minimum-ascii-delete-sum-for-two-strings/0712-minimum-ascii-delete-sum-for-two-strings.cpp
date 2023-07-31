class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        /* DP 
        Def: dp[i][j]: the minimum sum of delete characters to make s1[:i] and s2[:j] equal
        Transition:
            dp[i][j] = min(ascii(s1[i]) + dp[i-1][j], ascii(s2[j]) + dp[i][j-1])
            if s1[i] == s2[j]: dp[i][j] = min(dp[i][j], dp[i-1][j-1])
        TC: O(n^2)
        SC: O(n^2)
        */
        auto size1 = s1.size(), size2 = s2.size();

        int dp[1001][1001];
        memset(dp, 0, sizeof(dp));

        // Init dp
        for(int i = 0 ; i < size1 ; ++i)
            dp[i+1][0] += dp[i][0] + s1[i];
        for(int j = 0 ; j < size2 ; ++j)
            dp[0][j+1] += dp[0][j] + s2[j];

        for(int i = 0 ; i < size1 ; ++i){
            for(int j = 0 ; j < size2 ; ++j){
                dp[i+1][j+1] = min(s1[i] + dp[i][j+1], s2[j] + dp[i+1][j]);
                if (s1[i] == s2[j]) dp[i+1][j+1] = min(dp[i+1][j+1], dp[i][j]);
            }
        }

        return dp[size1][size2];
    }
};