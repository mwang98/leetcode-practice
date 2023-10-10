class Solution {
public:
    int minOperations(vector<int>& nums) {
        // Sorting + (Binary search | Sliding window)

        // Define variables
        int size = nums.size();
        int res = size;
        int left = 0, right = 0;
        unordered_map<int, int> counter; // counter(dict): keep track of # of elements within a sliding window 

        // Sort `nums` array
        sort(nums.begin(), nums.end());

        // Slilding window: 
        // Move right pointer: increment by 1
        // Move left pointer: rolling until nums[right] > nums[left] + (len - 1)
        while(right < size){
            auto rval = nums[right++];
            counter[rval]++;

            while(left < right && rval - nums[left] > size - 1){
                auto lval = nums[left++];
                if(--counter[lval] == 0) counter.erase(lval);
            }

             // Compute # of operations needed
             // # of ops = len - size(counter)
             res = min(res, size - (int)counter.size());

             // Early stop
             if(res == 0) return 0;
        }
        
        return res;

    }
};