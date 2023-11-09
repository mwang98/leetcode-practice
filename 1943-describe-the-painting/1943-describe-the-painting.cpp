class Solution {
public:
    vector<vector<long long>> splitPainting(vector<vector<int>>& segments) {
        /*
            Line sweep: O(1) increment a range of array
        */
        // Find max end point
        int max_end = -1;
        for(auto& seg: segments) max_end = max(max_end, seg[1]);

        // Define variables
        vector<vector<long long>> res;
        vector<long long> line_sweep(max_end + 1, 0);
        vector<bool> end_positions(max_end + 1, false); // where ends happend
        
        // Build line sweep
        for(auto& seg: segments){
            auto start = seg[0], end = seg[1], val = seg[2];
            line_sweep[start] += val;
            line_sweep[end] -= val;
            end_positions[end] = true;
        }

        int prev = -1;
        long long sum_val = 0;
        for(int i = 1 ; i < line_sweep.size() ; ++i){
            if(line_sweep[i] == 0 && !end_positions[i]) continue;
            if(prev == -1) prev = i;
            else if(sum_val > 0) res.push_back({prev, i, sum_val});
            prev = i;    
            sum_val += line_sweep[i];
        }

        return res;
    }
};