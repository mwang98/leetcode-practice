/*
 * @lc app=leetcode id=1262 lang=cpp
 *
 * [1262] Greatest Sum Divisible by Three
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution {
   public:
    int maxSumDivThree(vector<int>& nums) {
        /* DP
        Def: dp[i][mod]: the maximum possible sum of elements in `nums[:i]` with sum % 3 = `mod`
        Transition
            nums[i] % 3 == 0: dp[i][0] = max(dp[i-1][0], nums[i] + dp[i-1][0])
                              dp[i][1] = max(dp[i-1][1], nums[i] + dp[i-1][1])
                              dp[i][2] = max(dp[i-1][2], nums[i] + dp[i-1][2])
            nums[i] % 3 == 1: dp[i][0] = max(dp[i-1][0], nums[i] + dp[i-1][2])
                              dp[i][1] = max(dp[i-1][1], nums[i] + dp[i-1][0])
                              dp[i][2] = max(dp[i-1][2], nums[i] + dp[i-1][1])
            nums[i] % 3 == 2: dp[i][0] = max(dp[i-1][0], nums[i] + dp[i-1][1])
                              dp[i][1] = max(dp[i-1][1], nums[i] + dp[i-1][2])
                              dp[i][2] = max(dp[i-1][2], nums[i] + dp[i-1][0])
         */
        int dp[3];
        int max_sum = 0;
        memset(dp, 0, sizeof(dp));

        for (int i = 0; i < nums.size(); ++i){
            int tmp[3];
            if (nums[i] % 3 == 0) {
                tmp[0] = max(dp[0], dp[0] % 3 == 0 ? nums[i] + dp[0] : 0);
                tmp[1] = max(dp[1], dp[1] % 3 == 1 ? nums[i] + dp[1] : 0);
                tmp[2] = max(dp[2], dp[2] % 3 == 2 ? nums[i] + dp[2] : 0);
            } else if(nums[i] % 3 == 1){
                tmp[0] = max(dp[0], dp[2] % 3 == 2 ? nums[i] + dp[2] : 0);
                tmp[1] = max(dp[1], dp[0] % 3 == 0 ? nums[i] + dp[0] : 0);
                tmp[2] = max(dp[2], dp[1] % 3 == 1 ? nums[i] + dp[1] : 0);
            } else if (nums[i] % 3 == 2) {
                tmp[0] = max(dp[0], dp[1] % 3 == 1 ? nums[i] + dp[1] : 0);
                tmp[1] = max(dp[1], dp[2] % 3 == 2 ? nums[i] + dp[2] : 0);
                tmp[2] = max(dp[2], dp[0] % 3 == 0 ? nums[i] + dp[0] : 0);
            }
            for (int i = 0; i < 3; ++i) dp[i] = tmp[i];
            max_sum = max(max_sum, dp[0]);
        }

        return max_sum;
    }
};
// @lc code=end

