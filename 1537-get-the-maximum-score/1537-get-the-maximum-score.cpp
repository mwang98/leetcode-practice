class Solution {
public:
    int maxSum(vector<int>& nums1, vector<int>& nums2) {
        /* Two pointers
        */
        int mod = 1e9 + 7;
        int ptr1 = 0, ptr2 = 0;
        int idx = 0; // ptr for cross points 
        int res = 0;

        // Handle edge case: add dummy value
        nums1.push_back(INT_MAX);
        nums2.push_back(INT_MAX);

        // Find all crossing points
        auto findCrossPoints = [&]() -> vector<pair<int, int>> {
            int ptr1 = 0, ptr2 = 0;
            vector<pair<int, int>> res;

            while(ptr1 < nums1.size() && ptr2 < nums2.size()){
                if(nums1[ptr1] == nums2[ptr2]) {
                    res.emplace_back(ptr1++, ptr2++);
                } 
                else if(nums1[ptr1] < nums2[ptr2]) ptr1++;
                else ptr2++;
            }

            return res;
        };

        // Two pointers
        auto cross_points = findCrossPoints();
        while(ptr1 < nums1.size() && ptr2 < nums2.size() && idx < cross_points.size()){
            auto [m1, m2] = cross_points[idx++];
            long long sum1 = 0, sum2 = 0;
            while(ptr1 < m1) sum1 += nums1[ptr1++];
            while(ptr2 < m2) sum2 += nums2[ptr2++];
            
            // Do not compare values after modulo !!!
            res = (res + (max(sum1, sum2) % mod)) % mod;
        }

        return res % mod;
    }
};