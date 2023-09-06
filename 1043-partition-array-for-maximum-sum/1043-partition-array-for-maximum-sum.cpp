class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        /* DP
        Def: dp[i]: maximum sum of partitioned array on a given arr[:i]
        Transition:
            max_val = max(arr[i-k : i])
            for j in range(i - k + 1, i + 1):
                dp[i] = max(dp[i], max_val * (i - j) + d[j])
        TC: O(nk)
        SC: O(n) -> O(k)
        */

        int dp[501];
        memset(dp, 0, sizeof(dp));

        for(int i = 0 ; i < arr.size() ; ++i){
            int curr_max = 0;
            int max_val = 0;

            for(int j = i ; j >= max(0, i - k + 1) ; --j){
                curr_max = max(curr_max, arr[j]);
                dp[i + 1] = max(dp[i + 1], dp[j] + curr_max * (i - j + 1));
            }
        }

        return dp[arr.size()];
    }
};