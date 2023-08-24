class Solution {
public:
    vector<long long> minOperations(vector<int>& nums, vector<int>& queries) {
        sort(nums.begin(), nums.end());
        
        vector<long long> prefix_sum(nums.size() + 1, 0);
        vector<long long> results(queries.size(), 0);

        // Build prefix sum
        for(int i = 0 ; i < nums.size() ; ++i) prefix_sum[i + 1] = prefix_sum[i] + nums[i];
        prefix_sum.push_back(prefix_sum.back()); // avoid boundary condition

        // Define binary search
        auto search = [&](int target) -> int {
            int left = 0, right = nums.size();
            while(left < right){
                auto mid = (left + right) / 2;
                if(nums[mid] <= target) left = mid + 1;
                else right = mid;
            }
            return left - 1;
        };

        for(int i = 0 ; i < queries.size() ; ++i){
            long long target = queries[i];
            auto idx = search(target) + 1; // [0, nums.size()]
            auto less_sum = prefix_sum[idx] - prefix_sum[0];
            auto great_sum = prefix_sum.back() - prefix_sum[idx];

            results[i] += target * idx - less_sum;
            results[i] += -target * (nums.size() - idx) + great_sum;
        }

        return results;
    }
};