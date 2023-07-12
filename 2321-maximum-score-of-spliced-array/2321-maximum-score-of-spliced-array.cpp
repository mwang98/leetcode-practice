/*
 * @lc app=leetcode id=2321 lang=cpp
 *
 * [2321] Maximum Score Of Spliced Array
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution {
   public:
    int maximumsSplicedArray(vector<int>& nums1, vector<int>& nums2) {
        /* DP
        Def:
            dp[0][i]: the maximum sum of `nums1` with subarray ending at nums1[i] (nums1[?:i]) swapped with `nums2`
            dp[1][i]: the maximum sum of `nums2` with subarray ending at nums2[i] (nums2[?:i]) swapped with `nums1`
        Transition:
            sum_1, sum_2
            dp[0][i] = (nums2[i] - nums1[i]) + max(sum_1,      # start a new subarray
                                                   dp[0][i-1]) # continuously the subarray
            dp[1][i] = (nums1[i] - nums2[i]) + max(sum_2,      # start a new subarray
                                                   dp[1][i-1]) # continuously the subarray
        */
        int dp[2];
        auto sum_1 = dp[0] = accumulate(nums1.begin(), nums1.end(), 0);
        auto sum_2 = dp[1] = accumulate(nums2.begin(), nums2.end(), 0);
        int max_score = max(sum_1, sum_2);

        for (int i = 0; i < nums1.size() ; ++i){
            auto tmp_0 = (nums2[i] - nums1[i]) + max(sum_1, dp[0]);
            auto tmp_1 = (nums1[i] - nums2[i]) + max(sum_2, dp[1]);
            dp[0] = tmp_0;
            dp[1] = tmp_1;
            max_score = max(max_score, max(dp[0], dp[1]));
        }

        return max_score;
    }
};
// @lc code=end

