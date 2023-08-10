class Solution {
public:
    bool dfs(vector<int>& nums, int target, int start, int end) {
        // Base case
        if(start >= end) return false;
        // Recursive case
        int mid = (start + end) / 2;
        if(nums[mid] == target) return true;
        if(nums[mid] > target){
            auto left = dfs(nums, target, start, mid);
            auto right = nums[start] >= nums[end-1] ? dfs(nums, target, mid + 1, end) : false;
            return left || right;
        } else {
            auto right = dfs(nums, target, mid + 1, end);
            auto left = nums[start] >= nums[end-1] ? dfs(nums, target, start, mid) : false;
            return left || right;
        }
        return false;
    }
    bool search(vector<int>& nums, int target) {
        return dfs(nums, target, 0, nums.size());
    }
};