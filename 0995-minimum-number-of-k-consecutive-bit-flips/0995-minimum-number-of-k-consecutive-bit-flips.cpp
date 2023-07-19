class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        /* Greedy + Line sweep 
        Greedy: always flip 0 to 1 when traversing nums from left to right
        Line sweep: perform O(1) updates the interval + use prefix sum to get the actual upate
        TC: O(n)
        SC: O(n)
        */
        int count = 0; // count actual flips
        int flips = 0; // prefix sum
        vector<int> line(nums.size() + 1, 0);

        for(int i = 0 ; i < nums.size() ; ++i){
            flips += line[i]; // get actual value by prefix sum
            if((nums[i] + flips) % 2) continue;
            if(i + k > nums.size()) return -1;

            line[i + k]--;
            flips++;
            count++;
        }

        return count;
    }
};