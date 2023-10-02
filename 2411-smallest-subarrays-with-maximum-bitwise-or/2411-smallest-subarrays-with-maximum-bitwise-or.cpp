class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& nums) {
        /* Sliding window */
        vector<int> res(nums.size());
        int counter[30];
        memset(counter, 0, sizeof(counter));

        auto addToCounter = [&](int val) -> void {
            for(int i = 0 ; i < 30 && val > 0; ++i){
                counter[i] += val % 2;
                val /= 2;
            }
        };

        auto subtractFromCounter = [&](int val) -> void {
            for(int i = 0 ; i < 30 && val > 0; ++i){
                counter[i] -= val % 2;
                val /= 2;
            }
        };

        auto canShrink = [&](int val) -> bool {
            for(int i = 0 ; i < 30 && val > 0 ; ++i){
                // Make sure counter retain the largest value
                if(val % 2 && counter[i] < 2) return false;
                val /= 2;
            }

            return true;
        };

        int left = nums.size() - 1, right = nums.size() - 1;
        while(left >= 0){
            addToCounter(nums[left]);

            while(right > left && canShrink(nums[right]))
                subtractFromCounter(nums[right--]);

            res[left] = right - left + 1;
            left--;
        }

        return res;
    }
};