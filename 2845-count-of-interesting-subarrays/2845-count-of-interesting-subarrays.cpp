class Solution {
public:

    long long countInterestingSubarrays(vector<int>& nums, int mod, int k) {
        unordered_map<long long, long long> table;    
        vector<int> prefix_sum;

        for(int i = 0 ; i < nums.size() ; ++i)
            nums[i] = (nums[i] % mod) == k;

        prefix_sum = nums;
        prefix_sum[0] %= mod;
        for(int i = 1 ; i < prefix_sum.size() ; ++i){
            prefix_sum[i] = (prefix_sum[i] + prefix_sum[i - 1]) % mod;
        }

        // Build map & Compute subarrays
        long long n_subarrs = 0;
        table[0] = 1;

        for(int i = 0 ; i < prefix_sum.size() ; ++i){
            // (prefix_sum[i] - target) % mod == k
            // target == prefix_sum[j] where j < i
            auto target = (prefix_sum[i] + mod - k) % mod;
            n_subarrs += table[target];

            // Add new prefix sum
            table[prefix_sum[i]]++;
        }

        return n_subarrs;
    }
};