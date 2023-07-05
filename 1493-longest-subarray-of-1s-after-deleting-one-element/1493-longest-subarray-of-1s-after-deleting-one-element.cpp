/*
 * @lc app=leetcode id=1493 lang=cpp
 *
 * [1493] Longest Subarray of 1's After Deleting One Element
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        /* Sliding window 
         |     |  if the answer is optimal (i.e., longest subarray)
           |  |      this answer is never optimal (it is shorter)
        */
        int ans = 0;
        int num_zeros = 0;
        int left = 0, right = 0;
        while(right < nums.size()){
            num_zeros += nums[right++] == 0;

            ans = max(ans, right - left - num_zeros);

            while (left < right && num_zeros > 1) {
                if (nums[left++] == 0) num_zeros--;
            }
        }

        return min(ans, (int)nums.size() - 1); // Must at least delete one element
    }
};
// @lc code=end

