class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        sort(nums.begin(), nums.end(), [](const auto& lhs, const auto& rhs) {
            return lhs % 2 < rhs % 2;
        });
        return nums;
    }
};