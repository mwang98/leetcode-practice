/*
 * @lc app=leetcode id=209 lang=cpp
 *
 * [209] Minimum Size Subarray Sum
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        /* Sliding window 
        |    | -> optimal solution (subarray with sum >= target)
          | |  -> not a solution since sum is < target (if not, right pointer will not move)
        */
        int min_length = INT_MAX;
        int sum_val = 0;
        int left = 0, right = 0;
        while(right < nums.size()){
            sum_val += nums[right++];
            while(left < right && sum_val >= target){
                min_length = min(min_length, right - left);
                sum_val -= nums[left++];
            }
        }

        return min_length == INT_MAX ? 0 : min_length;
    }
};
// @lc code=end

