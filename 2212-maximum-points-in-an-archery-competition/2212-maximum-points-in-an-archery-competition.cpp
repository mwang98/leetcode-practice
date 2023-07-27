class Solution {
public:
    vector<int> maximumBobPoints(int numArrows, vector<int>& aliceArrows) {
        /* DP - Knapsack 
            Capacity: numArrows
            Gain: [0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11]
            Cost: [arrow + 1 for arrow in aliceArrows]
            Def: dp[i][c] = maximum points Bob can earned by selecting from `item[:i]` with `c` credit
            Transition:
                dp[i][c] = max(dp[i-1][c], gain[i] + dp[i-1][c-cost[i]])
        */
        // auto& costs = aliceArrows;
        vector<int> ret(12);
        int trace[12][100001];
        int dp[12][100001];
        memset(dp, 0, sizeof(dp));
        memset(trace, 0, sizeof(trace));


        for(int i = 1 ; i < 12 ; ++i){
            auto cost = aliceArrows[i] + 1;

            for(int credit = 0 ; credit <= numArrows ; ++credit){
                dp[i][credit] = dp[i - 1][credit];

                if(credit >= cost){
                    if(auto gain = i + dp[i - 1][credit - cost]; gain > dp[i][credit]){
                        dp[i][credit] = gain;
                        trace[i][credit] = 1; // select item
                    }
                }
            }
        }

        int credit = numArrows;
        for(int i = 11 ; i >= 0 ; --i){
            auto cost = aliceArrows[i] + 1;
            
            if(trace[i][credit]){
                ret[i] = cost;
                credit -= cost;
            }
            if(i == 0) ret[i] = credit; // always put remaining arrows to section 0 (gain nothing)
        }
        return ret;
    }
};