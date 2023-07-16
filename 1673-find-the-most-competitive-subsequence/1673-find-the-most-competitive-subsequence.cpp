/*
 * @lc app=leetcode id=1673 lang=cpp
 *
 * [1673] Find the Most Competitive Subsequence
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        vector<int> mono_stack; // monotonically increasing

        int n_remains = nums.size();
        for (auto num : nums) {
            n_remains--;

            while (!mono_stack.empty() &&
                       mono_stack.back() > num &&
                       mono_stack.size() + n_remains >= k)
                mono_stack.pop_back();
            mono_stack.push_back(num);
        }

        return vector<int>(mono_stack.begin(), mono_stack.begin() + k);
    }
};
// @lc code=end

