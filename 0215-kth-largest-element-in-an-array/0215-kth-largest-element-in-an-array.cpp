class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> pq; // max queue
        for(auto num : nums){
            if(pq.size() == k && -pq.top() < num) pq.pop();
            if(pq.size() < k) pq.push(-num);
        }

        return -pq.top();
    }
};