class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        auto computeGood = [](int cnt) -> int {
            return (cnt * (cnt - 1)) / 2;
        };

        int res = 0;
        unordered_map<int, int> counter;
        for(auto num: nums) counter[num]++;
        for(auto [tmp, cnt]: counter) res += computeGood(cnt);

        return res;
    }
};