/*
 * @lc app=leetcode id=2302 lang=cpp
 *
 * [2302] Count Subarrays With Score Less Than K
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution {
   public:
    long long countSubarrays(vector<int>& nums, long long k) {
        /* Sliding window 
            |     | ->  for each valid interval, there exists (right-left) subrrays
                        satisfy the constraints
        TC: O(n)
        SC: O(1)
        */
        long long score = 0;
        long long count = 0;
        int left = 0, right = 0;

        while (right < nums.size()) {
            auto sum_val = score / max(1, right - left);
            score = (sum_val + nums[right++]) * (right - left);

            while (left < right && score >= k) {
                score /= (right - left);
                score -= nums[left++];
                score *= (right - left);
            }

            count += (right - left);
        }

        return count;
    }
};
// @lc code=end
