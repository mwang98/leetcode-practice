class Solution {
public:
    int numberOfWays(int numPeople) {
        /* DP
          Def: dp[n]: # of handshake combinations
          Transition:
          (1) Shake with right one: dp[n - 2]
          (2) Shake with left one: dp[n - 2]
          (3) Shake with the farest one: dp[(n - 2) / 2] * dp[(n - 2) / 2]
          ....
        */

        int MOD = 1e9 + 7;
        int dp[1001];
        
        memset(dp, 0, sizeof(dp));
        dp[0] = 1;

        for(int i = 2 ; i <= numPeople ; i += 2){
            for(int j = 1 ; j < i ; j += 2){
                auto l_num = j - 1;
                auto r_num = i - j - 1;
                dp[i] = ((long long)dp[l_num] * dp[r_num] + dp[i]) % MOD;
            }
        }

        return dp[numPeople];
    }
};