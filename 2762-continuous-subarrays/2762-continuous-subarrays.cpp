class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        /* Monotonic Queue + sliding windwon */

        long long res = 0;
        deque<int> min_queue; // increasing O(1) find minimum 
        deque<int> max_queue; // decreasing O(1) find maximum 
        int left = 0, right = 0;

        while(right < nums.size()){
            auto num = nums[right];
            int max_idx = -1; // largest invalid index for max queue
            int min_idx = -1; // largest invalid index for min queue

            // Pop max element (non-continuous element)
            while(!max_queue.empty() && nums[max_queue.front()] > num + 2){
                max_idx = max_queue.front();
                max_queue.pop_front();
            }
            // Maintain monotonicity
            while(!max_queue.empty() && nums[max_queue.back()] < num)
                max_queue.pop_back();
            max_queue.push_back(right);
            
            // Pop min element (non-continuous element)
            while(!min_queue.empty() && nums[min_queue.front()] < num - 2){
                min_idx = min_queue.front();
                min_queue.pop_front();
            }
            // Maintain monotonicity
            while(!min_queue.empty() && nums[min_queue.back()] > num)
                min_queue.pop_back();
            min_queue.push_back(right);

            left = max(left, max(min_idx, max_idx) + 1);
            right++;

            res += (right - left);
        }

        return res;
    }
};