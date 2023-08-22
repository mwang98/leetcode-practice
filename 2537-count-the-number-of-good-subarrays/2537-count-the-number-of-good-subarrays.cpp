class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        /* Sliding window 
        Move right: subarray is not good
        Move left: subarray is good, accumulate # of subarrays
        */
        unordered_map<int, int> counter;

        long long n_subarrs = 0;
        int n_pairs = 0;
        int left = 0, right = 0;

        auto get_pairs = [](int n_dup) -> long long {
            if(n_dup <= 1) return 0;
            return (0L + n_dup) * (n_dup - 1) / 2;
        };

        while(right < nums.size()){
            auto cnt = counter[nums[right++]]++;
            n_pairs += get_pairs(cnt + 1) - get_pairs(cnt);

            while(left < nums.size() && n_pairs >= k){
                n_subarrs += (nums.size() - right + 1);
                auto cnt = counter[nums[left++]]--;
                n_pairs += get_pairs(cnt - 1) - get_pairs(cnt);
            }
        }

        return n_subarrs;
    }
};