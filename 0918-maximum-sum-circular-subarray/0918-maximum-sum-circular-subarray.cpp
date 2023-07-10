/*
 * @lc app=leetcode id=918 lang=cpp
 *
 * [918] Maximum Sum Circular Subarray
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution {
   public:
    int maxSubarraySumCircular(vector<int>& nums) {
        /* Kadane's algo */
        int dp_max = 0;
        int max_sum = -100000;
        int dp_min = 0;
        int min_sum = 100000;
        int total_sum = 0;

        for (int i = 0; i < nums.size(); ++i) {
            dp_max = nums[i] + max(dp_max, 0);
            max_sum = max(max_sum, dp_max);

            dp_min = nums[i] + min(dp_min, 0);
            min_sum = min(min_sum, dp_min);

            total_sum += nums[i];
        }
        
        if(total_sum == min_sum) return max_sum;
        return max(max_sum, total_sum - min_sum);
    }
};
// @lc code=end
