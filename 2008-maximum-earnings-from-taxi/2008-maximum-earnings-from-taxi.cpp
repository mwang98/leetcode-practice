class Solution {
public:
    long long maxTaxiEarnings(int n, vector<vector<int>>& rides) {
        /* DP 
        Sort the rides by start time
        Def: dp[i]: the maximum earnings given rides[i:]
        Transition
            Not to take: dp[i+1]
            Take the ride: dp[k] + (rides[i].end - rides[i].start + rides[i].tips) where rides[k].start > rides[i].end
        TC: O(nlogn)
        SC: O(n)
        */
        long long dp[30001];
        memset(dp, 0 , sizeof(dp));

        sort(rides.begin(), rides.end(), [](const auto& v1, const auto& v2) { return v1[0] < v2[0]; });

        auto search = [&](int start, int target){
            int left = start, right = rides.size();
            while(left < right){
                auto mid = (left + right) / 2;
                auto nxt_start = rides[mid][0];
                if(nxt_start >= target) right = mid;
                else left = mid + 1;
            }
            return left;
        };

        for(int i = rides.size() - 1 ; i >= 0 ; --i){
            auto start = rides[i][0], end = rides[i][1], tips = rides[i][2];
            auto gain_not_take = dp[i+1];
            auto gain_take = dp[search(i + 1, end)] + (end - start + tips);
            dp[i] = max(gain_take, gain_not_take);
        }

        return dp[0];
    }
};