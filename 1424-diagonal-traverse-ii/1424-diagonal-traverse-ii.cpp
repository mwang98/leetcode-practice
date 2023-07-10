/*
 * @lc app=leetcode id=1424 lang=cpp
 *
 * [1424] Diagonal Traverse II
 */

// @lc code=start
#include <vector>
#include <deque>
using namespace std;
class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        /* BFS
        TC: sum(num.length for num in nums)
        SC: sum(num.length for num in nums)
        */
        int n_rows = nums.size();
        vector<int> ret;
        deque<pair<int, int>> q;  // (row_idx, pointer)

        q.push_back({0, 0});
        int curr_row = 0;
        while (!q.empty()) {
            for (int i = 0, size = q.size(); i < size; ++i){
                auto [r_idx, ptr] = q.front();
                q.pop_front();

                ret.push_back(nums[r_idx][ptr]);
                if (++ptr < nums[r_idx].size()) q.push_back({r_idx, ptr});
            }
            // Add the first element of the next row
            if (++curr_row < n_rows) q.push_front({curr_row, 0});
        }

        return ret;
    }
};
// @lc code=end

