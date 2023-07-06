/*
 * @lc app=leetcode id=2498 lang=cpp
 *
 * [2498] Frog Jump II
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution {
public:
    int maxJump(vector<int>& stones) {
        int max_dist = 0;
        int forward_prev = stones[0];
        int backward_prev = stones[0];

        for (int i = 1; i < stones.size(); i += 2){
            max_dist = max(max_dist, stones[i] - forward_prev);
            forward_prev = stones[i];
        }
        for (int i = 0; i < stones.size(); i += 2) {
            max_dist = max(max_dist, stones[i] - backward_prev);
            backward_prev = stones[i];
        }

        max_dist = max(max_dist, stones.back() - forward_prev);
        max_dist = max(max_dist, stones.back() - backward_prev);

        return max_dist;
    }
};
// @lc code=end

