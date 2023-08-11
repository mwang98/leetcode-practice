class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        int left = 0, right = 0;
        long long sum = 0;
        int max_freq = 0;

        sort(nums.begin(), nums.end());

        while(right < nums.size()){
            sum += nums[right++];
            while(sum + k < (0L + (right - left)) * nums[right - 1]){
                sum -= nums[left++];
            }
            max_freq = max(max_freq, right - left);
        }

        return max_freq;
    }
};