class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {
        /* DP 
        Def: dp1[i]: # of subarrays ending at nums[i] s.t. its maximum value is in the range [left, right]
             dp2[i]: # of subarrays ending at nums[i] s.t. its maximum value is less than left
        Transition
            nums[i] < left: 
                dp1[i] = dp1[i-1] 
                dp2[i] = dp2[i-1] + 1
            nums[i] in [left, right]: 
                dp1[i] = dp1[i-1]   {..., nums[i]}
                         + 1        {nums[i]}
                         + dp2[i-1] {..., nums[i]}
                dp2[i] = 0
            nums[i] > right: 
                dp1[i] = 0
                dp2[i] = 0
        */
        int count = 0;
        int dp1 = 0, dp2 = 0;

        for(auto num: nums){
            if(num > right) dp1 = dp2 = 0;
            else if(num < left) dp2++;
            else{
                dp1 = dp1 + 1 + dp2;
                dp2 = 0;
            }
            count += dp1;
        }

        return count;
    }
};