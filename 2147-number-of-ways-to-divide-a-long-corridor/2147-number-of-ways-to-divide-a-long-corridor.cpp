class Solution {
public:
    int numberOfWays(string corridor) {
        /* DP
        Def: dp[i][seats]: # of ways to divide corridor where the last division is occupied with `seats` seats (seats = 0, 1, 2)
        Transition:
            Plant:
                seats = 0: dp[i][0] = dp[i - 1][0] + dp[i - 1][2]
                seats = 1: dp[i][1] = dp[i - 1][1]
                seats = 2: dp[i][2] = dp[i - 1][2]
            Seat:
                seats = 0: dp[i][0] = 0
                seats = 1: dp[i][1] = dp[i - 1][0] + dp[i - 1][2]
                setas = 2: dp[i][2] = dp[i - 1][1]
        TC: O(n)
        SC: O(n) -> O(1)
        */
        auto sol_dp = [&]() -> int {
            int MOD = 1e9 + 7;
            int dp[100001][3];

            memset(dp, 0, sizeof(dp));
            dp[0][0] = 1;
            for(int i = 0 ; i < corridor.size() ; ++i){
                if(corridor[i] == 'P'){
                    dp[i + 1][0] = (dp[i][0] + dp[i][2]) % MOD;
                    dp[i + 1][1] = dp[i][1];
                    dp[i + 1][2] = dp[i][2];
                } else {
                    dp[i + 1][0] = 0;
                    dp[i + 1][1] = (dp[i][0] + dp[i][2]) % MOD;
                    dp[i + 1][2] = dp[i][1];
                }
            }

            return dp[corridor.size()][2];
        };

        auto sol_optim_dp = [&]() -> int {
            int MOD = 1e9 + 7;
            int dp[3];
            memset(dp, 0, sizeof(dp));
            dp[0] = 1;

            for(int i = 0 ; i < corridor.size() ; ++i){
                int tmp[3];
                if(corridor[i] == 'P'){
                    tmp[0] = (dp[0] + dp[2]) % MOD;
                    tmp[1] = dp[1];
                    tmp[2] = dp[2];
                } else {
                    tmp[0] = 0;
                    tmp[1] = (dp[0] + dp[2]) % MOD;
                    tmp[2] = dp[1];
                }
                dp[0] = tmp[0], dp[1] = tmp[1], dp[2] = tmp[2];
            }

            return dp[2];
        };
        
        return sol_optim_dp();
    }
};