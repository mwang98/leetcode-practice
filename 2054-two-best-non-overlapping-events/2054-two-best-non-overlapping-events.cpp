class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        /* DP + binary search 
        Sort events by their start time
        Def: dp[i]: the maximum value given events[i:]
        Transition:
            dp[i] = max(dp[i+1], events[i].value)
            sum of values: events[i].value + dp[k] where events[k].startTime > events[i].endTime (binary search)
        */
        int ret = 0;
        int dp[100001];
        memset(dp, 0, sizeof(dp));
        events.push_back({INT_MAX, INT_MAX, 0});

        sort(events.begin(), events.end(), [](const auto& v1, const auto& v2) { return v1[0] < v2[0]; });
        auto search = [&](int start, int target){
            int left = start, right = events.size();
            while(left < right){
                auto mid = (left + right) / 2;
                if(events[mid][0] > target) right = mid;
                else left = mid + 1;
            }
            return left;
        };
        for(int i = events.size() - 2 ; i >= 0 ; --i){
            auto start = events[i][0], end = events[i][1], value = events[i][2];
            auto idx = search(i + 1, end);
            ret = max(ret, value + dp[idx]);
            dp[i] = max(value, dp[i+1]);
        }

        return ret;
    }
};