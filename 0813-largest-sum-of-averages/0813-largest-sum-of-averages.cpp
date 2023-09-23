class Solution {
public:
    double largestSumOfAverages(vector<int>& nums, int k) {
        /* DP 
        Def: dp[i][k]: Given nums[:i] partitioned by k, the largest sum of averages
        Transition:
            (1) Create new partition: 
                dp[i][k] = nums[i] + dp[i-1][k-1]
            (2) Merge in previous partition
                dp[i][k] = sum(nums[d:i] / (i - d + 1) + dp[d][k-1]) (prefix sum for interval summation)
        TC: O(n^3)
        SC: O(n^2)
        */
        double dp[101][101];
        int pre_sum[101];

        // Init dp table
        memset(dp, 0, sizeof(dp));
        // Build prefix sum
        pre_sum[0] = 0;
        for(int i = 0 ; i < nums.size() ; ++i) pre_sum[i + 1] = pre_sum[i] + nums[i];

        for(int i = 0 ; i < nums.size() ; ++i){
            for(int j = 1 ; j <= k ; ++j){
                // 1 partition
                if(j == 1) dp[i + 1][j] = (0.0 + pre_sum[i + 1]) / (i + 1);
                else {
                    // Merge win previous partition
                    double max_avg = 0;
                    for(int d = 0 ; d <= i ; ++d){
                        double avg = (0.0 + pre_sum[i + 1] - pre_sum[d]) / (i + 1 - d);
                        max_avg = max(max_avg, avg + dp[d][j - 1]);
                    }
                    dp[i + 1][j] = max_avg;
                }
            }
        }

        return dp[nums.size()][k];
    }
};