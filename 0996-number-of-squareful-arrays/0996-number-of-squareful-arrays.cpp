class Solution {
public:
    int numSquarefulPerms(vector<int>& nums) {
        /* Bitmask DP 
        Def: dp[i][mask]: # of permutation of `nums` that is squareful, given the value `nums[i]` as previous value and `mask` elements are select
        Transition:
            for all j that
                (1) nums[j] not selected
                (2) nums[j] is different from all nums[k] where 0 <= k < j
                (3) nums[i] + nums[j] is perfect square

                dp[i][mask] += dp[j][mask | 1 << j];

        TC: O(n^2 * 2^n)
        SC: O(n * 2^n)
        */

        int dp[12][1 << 12];
        memset(dp, -1, sizeof(dp));

        sort(nums.begin(), nums.end()); // Handle duplicate case for permutation

        auto is_perfect_square = [](int x) -> bool {
            int sr = sqrt(x);
            return (sr * sr == x);
        };
        
        function<int(int, int)> topdown = [&](int i, int mask) -> int {
            // Base case
            if(dp[i][mask] != -1) return dp[i][mask];
            if(mask == (1 << nums.size()) - 1) return 1; // all elements are used
            
            // Recursive case
            int prev = -1;
            dp[i][mask] = 0;
            for(int j = 0 ; j < nums.size() ; ++j){
                if(mask & (1 << j) || nums[j] == prev || !is_perfect_square(nums[i] + nums[j])) continue;
                dp[i][mask] += topdown(j, mask | (1 << j));
                prev = nums[j];
            }

            return dp[i][mask];
        };


        int res = 0;
        int prev = -1;
        for(int i = 0 ; i < nums.size() ; ++i){
            if(nums[i] == prev) continue;
            res += topdown(i, 1 << i);
            prev = nums[i];
        }

        return res;
    }
};