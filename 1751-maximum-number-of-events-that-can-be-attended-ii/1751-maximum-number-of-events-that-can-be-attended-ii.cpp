/*
 * @lc app=leetcode id=1751 lang=cpp
 *
 * [1751] Maximum Number of Events That Can Be Attended II
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution {
public:
    int maxValue(vector<vector<int>>& events, int k) {
        /* DP
        Def: dp[i][k]: the maximum value gained from attending events[:i] with k (maximum number of attended events)
        Transition:
            1) Attend: dp[i][k] = value[i] + dp[idx-1][k-1] s.t. start[i] > end[idx]
            2) Not attend: dp[i][k] = dp[i-1][k]
        */
        auto n_events = events.size();
        vector<vector<int>> dp(n_events, vector<int>(k, 0));
        
        // Sort by end time
        sort(events.begin(), events.end(), [](const auto& v1, const auto& v2) { return v1[1] < v2[1]; });

        auto binary_search = [&](int start, int end, int target) {
            auto left = start, right = end;
            while(left < right){
                auto mid = (left + right) / 2;
                if (target > events[mid][1]) left = mid + 1;
                else right = mid;
            }
            return left - 1;
        };

        for (int i = 0; i < n_events; i++) {
            auto start = events[i][0], value = events[i][2];
            for (int j = 0; j < k; j++) {
                // Base case
                if (i == 0) dp[i][j] = value;
                else if (j == 0) dp[i][j] = max(dp[i - 1][j], value);
                else{
                    // Recursive case
                    auto prev_idx = binary_search(0, i, start);
                    dp[i][j] = max(dp[i - 1][j], value + (prev_idx >= 0 ? dp[prev_idx][j - 1] : 0));
                }
            }
        }

        return dp[n_events - 1][k - 1];
    }
};
// @lc code=end

