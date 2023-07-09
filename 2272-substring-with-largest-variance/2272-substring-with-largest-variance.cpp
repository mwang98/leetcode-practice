/*
 * @lc app=leetcode id=2272 lang=cpp
 *
 * [2272] Substring With Largest Variance
 */

// @lc code=start
#include <string>
#include <vector>
using namespace std;
class Solution {
   public:
    int counter[26];
    int max_sub_sum = 0;
    void compute_maximum_subarray_sum(string s, int major, int minor){
        // s = a a b  c c, major = a, minor = b
        //   = 1 1 -1 0 0

        // Kadanes's algo
        // Def: dp[i] = maximum subarray sum ending with s[i]
        // Transition: dp[i] = s[i] + max(dp[i-1], 0)

        int major_cnt = 0, minor_cnt = 0;
        int minor_remain = counter[minor];
        for (auto ch : s) {
            if (ch - 'a' == major) {
                major_cnt++;
            } else if (ch - 'a' == minor) {
                minor_cnt++;
                minor_remain--;
            }

            if (major_cnt > 0 && minor_cnt > 0)
                max_sub_sum = max(max_sub_sum, major_cnt - minor_cnt);
            if (major_cnt < minor_cnt && minor_remain > 0)
                major_cnt = minor_cnt = 0;
        }
    }
    int largestVariance(string s) {
        memset(counter, 0, sizeof(counter));
        for (auto ch : s) counter[ch - 'a']++;

        for (int i = 0; i < 26; ++i) {
            for (int j = 0; j < 26; ++j) {
                if (i == j || counter[i] == 0 || counter[j] == 0) continue;
                compute_maximum_subarray_sum(s, i, j);
            }
        }

        return max_sub_sum;
    }
};
// @lc code=end
