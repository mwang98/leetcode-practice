class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
        /* DP 
        Def: dp[i][state]: longest mountain subsequence ending wtih nums[i] where `state` = 0 (increasing), decreasing otherwise
        Transition:
            for all j < i
            (1) increasing:
                nums[j] < nums[i]: dp[i][0] = max(dp[j][0] + 1, dp[i][0])
                nums[j] > nums[i]: x
            (2) decreasing (need increase first !!!)
                nums[j] < nums[i]: x
                nums[j] > nums[i]: dp[i][1] = max(max(dp[j][0], dp[j][1]) + 1, dp[i][1])
        TC: O(n^2)
        SC: O(n)
        */
        int max_mountain_subseq = 1;
        int dp[1000][2];
        memset(dp, 0, sizeof(dp));

        for(int i = 1 ; i < nums.size() ; ++i){
            for(int state = 0 ; state < 2 ; ++state){
                for(int j = 0 ; j < i ; ++j){
                    if(state == 0 && nums[j] < nums[i]){
                        // dp[j][0]: only 1 element (neither increasing nor decreasing)
                        dp[i][state] = max(dp[i][state], 1 + max(1, dp[j][0]));
                    } else if(state == 1 && nums[j] > nums[i]){
                        if(dp[j][1] == 0){ // moutain not formed yet
                            // dp[j][0] = 1: already climb up
                            dp[i][state] = max(dp[i][state], dp[j][0] == 0 ? 0 : 1 + dp[j][0]);
                        }
                        else{ // mountain is formed
                            dp[i][state] = max(dp[i][state], 1 + max(dp[j][0], dp[j][1]));
                        }
                    } 
                }

                if(state == 1)
                    max_mountain_subseq = max(max_mountain_subseq, dp[i][state]);
            }
        }

        return nums.size() - max_mountain_subseq;
    }
};