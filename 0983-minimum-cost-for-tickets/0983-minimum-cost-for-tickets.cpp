/*
 * @lc app=leetcode id=983 lang=cpp
 *
 * [983] Minimum Cost For Tickets
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution {
   public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        /* DP
        Def: dp[i]: minimum cost of traveling at day `i`
        Transition:
            i in days:
                dp[i] = min(
                    dp[i-1] + costs[0]   # buy 1-day pass
                    dp[i-7] + costs[7]   # buy 7-day pass
                    dp[i-30] + costs[30] # buy 30-day pass
                )
            i not in days (no need to buy ticket)
                dp[i] = dp[i-1]
        */
        int dp[366];
        
        auto last_day = days[days.size() - 1];
        dp[0] = 0;
        int index = 0;
        for (int i = 1; i <= last_day; ++i) {
            if (i < days[index]) {  // no need to travel
                dp[i] = dp[i - 1];
            } else {
                dp[i] = min(dp[i - 1] + costs[0],
                        min(dp[max(i-7, 0)] + costs[1],
                            dp[max(i-30, 0)] + costs[2]));
                index++;
            }
        }

        return dp[last_day];
    }
};
// @lc code=end

