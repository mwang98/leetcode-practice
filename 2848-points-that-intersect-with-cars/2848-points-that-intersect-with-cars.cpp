class Solution {
public:
    int numberOfPoints(vector<vector<int>>& nums) {
        sort(nums.begin(), nums.end(), [](const auto& v1, const auto& v2) -> bool {
            return v1[0] < v2[0];
        });

         int res = 0;
         int start = nums[0][0];
         int end = nums[0][1];

         nums.push_back({ INT_MAX, INT_MAX - 1 });

        for(int i = 1; i < nums.size() ; ++i){
             auto nxt_start = nums[i][0], nxt_end = nums[i][1];
             if(nxt_start <= end) end = max(end, nxt_end);
             else {
                 res += (end - start + 1);
                 start = nxt_start;
                 end = nxt_end;
             }
         }

         return res;
    }
};