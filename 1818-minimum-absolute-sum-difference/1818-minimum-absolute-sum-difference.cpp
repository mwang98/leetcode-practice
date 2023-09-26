class Solution {
public:
    int minAbsoluteSumDiff(vector<int>& nums1, vector<int>& nums2) {
        /* Binary search
        Binary search: for each num in `nums2`, find an elements in `nums1` to minimze its difference
        */
        int mod = 1e9 + 7;
        vector<int> sorted_nums1 = nums1;
        sort(sorted_nums1.begin(), sorted_nums1.end());

        auto find_min_diff = [&](int target) -> int {
            auto it = lower_bound(sorted_nums1.begin(), sorted_nums1.end(), target);
            int res = INT_MAX;
            if(it != sorted_nums1.end()) res = min(res, *it - target);
            if(it != sorted_nums1.begin()) res = min(res, target - *(--it));
            return res;
        };

        long long sum = 0;
        for(int i = 0 ; i < nums1.size() ; ++i){
            sum = sum + abs(nums1[i] - nums2[i]);
        }

        long long res = sum;
        for(int i = 0 ; i < nums1.size() ; ++i){
            auto min_diff = find_min_diff(nums2[i]);
            auto new_sum = sum - abs(nums1[i] - nums2[i]) + min_diff;
            res = min(res, new_sum);
        }

        return res % mod;

    }
};