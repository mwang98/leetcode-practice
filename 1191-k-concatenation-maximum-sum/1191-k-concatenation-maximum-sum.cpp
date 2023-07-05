/*
 * @lc app=leetcode id=1191 lang=cpp
 *
 * [1191] K-Concatenation Maximum Sum
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution {
public:
    int MOD = 1e9 + 7;
    int kConcatenationMaxSum(vector<int>& arr, int k) {
        /* DP
        Case1: sum(arr) > 0: a1 a2 a3 | .... | a1 a2 a3
                (k-2) * sum(arr) + maximum sum of subarray: a1 a2 a3 a1 a2 a3
        Case2: sum(arr) <= 0 : a1 a2 a3 a1 a2 a3
                maximum sum of subarray: a1 a2 a3 a1 a2 a3

        Def: dp[i]: the maximum sum of subarray ending with arr[i]
        Transition:
            dp[i] = arr[i] + dp[i-1] if dp[i-1] >= 0 else 0
        */
        long long dp = 0;
        long long max_subarray_sum = 0;
        long long arr_sum = accumulate(arr.begin(), arr.end(), 0L);

        for (int i = 0; i < min(2, k) * arr.size(); ++i) {
            dp = arr[i % arr.size()] + (dp >= 0 ? dp : 0);
            max_subarray_sum = max(max_subarray_sum, dp);
        }

        if (arr_sum > 0) max_subarray_sum = (max_subarray_sum + (arr_sum * max(k - 2, 0)) % MOD) % MOD;
        return max_subarray_sum;
    }
};
// @lc code=end
