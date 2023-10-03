class Solution {
public:
    int minimumSize(vector<int>& nums, int maxOperations) {
        /* Binary search for value */
        auto checker = [&](int val) -> bool{
            int res = 0;
            for(auto num: nums){
                int n_ops = num / val + (num % val != 0);
                res += n_ops - 1;
            }
            return res <= maxOperations;
        };

        int left = 1, right = *max_element(nums.begin(), nums.end()) + 1;
        while(left < right){
            auto mid = (left + right) / 2;
            if(checker(mid)) right = mid;
            else left = mid + 1;
        }

        return left;
    }
};