class Solution {
public:
    long long maxRunTime(int n, vector<int>& batteries) {
        /* Binary search for running time 
        TC: O(nlogk) where k is the sum of battery power
        SC: O(1)
        */
        auto checker = [&](long long running_time) -> bool{
            long long available_power = 0;
            for(auto& power: batteries) available_power += min((long long)power, running_time);
            return available_power >= running_time * n;
        };

        long long left = 0, right = accumulate(batteries.begin(), batteries.end(), 0L) + 1;
        while(left < right){
            auto mid = (left + right) / 2;
            if(checker(mid)) left = mid + 1;
            else right = mid;
        }

        return left - 1;
    }
};