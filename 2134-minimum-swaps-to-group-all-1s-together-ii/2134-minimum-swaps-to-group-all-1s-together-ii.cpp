/*
 * @lc app=leetcode id=2134 lang=cpp
 *
 * [2134] Minimum Swaps to Group All 1's Together II
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution {
public:
    int minSwaps(vector<int>& nums) {
        /* Sliding window ->
        x: Find maximum consecutive 0 (NOT VALID)
        v: Fixed window size (# of 1's), # of 0's in the window = # of swaps
        */
        int window_size = accumulate(nums.begin(), nums.end(), 0); // Window size

        int zero_in_window = window_size - accumulate(nums.begin(), nums.begin() + window_size, 0);
        int num_swaps = zero_in_window;

        for (int i = 0, size = nums.size(); i < size; ++i) nums.push_back(nums[i]);
        for (int i = window_size; i < nums.size(); ++i) {
            zero_in_window += nums[i] == 0;
            zero_in_window -= nums[i - window_size] == 0;
            num_swaps = min(num_swaps, zero_in_window);
        }

        return num_swaps;
    }
};
// @lc code=end

