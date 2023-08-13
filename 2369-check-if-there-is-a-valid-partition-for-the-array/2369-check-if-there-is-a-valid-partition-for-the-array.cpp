class Solution {
public:
    bool sol_naiive(vector<int>& nums){
        /* DP
        Def: dp[i]: whether nums[:i] has at least one valid partition
        Transition:
            (1) 2 equal elements: dp[i-2]
            (2) 3 equal elements: dp[i-3]
            (3) 3 consecutive increasing elements: dp[i-3]
        TC: O(n)
        SC: O(n) -> O(1)
        */
        bool dp[100001];
        memset(dp, 0, sizeof(dp));
        dp[0] = true;

        for(int i = 0 ; i < nums.size() ; ++i){
            if((i - 2) + 1 >= 0 && (nums[i] == nums[i-1])) dp[i + 1] |= dp[i - 1];
            if((i - 3) + 1 >= 0 && (nums[i] == nums[i-1] && nums[i-1] == nums[i - 2]))
                dp[i + 1] |= dp[i - 2];
            if((i - 3) + 1 >= 0 && (nums[i] == 1 + nums[i-1] && nums[i-1] == 1 + nums[i - 2]))
                dp[i + 1] |= dp[i - 2];
        }
        return dp[nums.size()];
    }
    bool validPartition(vector<int>& nums) {
        bool dp0 = false, dp1 = true, dp2 = true, dp3 = true;
        for(int i = 0 ; i < nums.size() ; ++i){
            if((i - 2) + 1 >= 0 && (nums[i] == nums[i-1])) dp0 |= dp2;
            if((i - 3) + 1 >= 0 && (nums[i] == nums[i-1] && nums[i-1] == nums[i - 2]))
                dp0 |= dp3;
            if((i - 3) + 1 >= 0 && (nums[i] == 1 + nums[i-1] && nums[i-1] == 1 + nums[i - 2]))
                dp0 |= dp3;
            
            dp3 = dp2;
            dp2 = dp1;
            dp1 = dp0;
            dp0 = false;
        }

        return dp1;
    }
};