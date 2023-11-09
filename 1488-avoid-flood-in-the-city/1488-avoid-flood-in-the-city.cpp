typedef pair<int, int> PII;
class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        /*
            Priority Queue: (the next day it will be filled, lakeId) - min heap
            DP: build "the next day it will be filled"
            TC: O(nlogn)
            SC: O(n)
        */
        // Define variables
        priority_queue<PII, vector<PII>, greater<PII>> pq; // min heap
        vector<int> dp(rains.size(), INT_MAX);
        unordered_map<int, int> record; // lakeId, filled day
        unordered_set<int> full_lakes;  // lake full of water
        vector<int> res(rains.size(), -1);

        // Build dp table
        for(int i = rains.size() - 1 ; i >= 0 ; --i){
            auto lakeId = rains[i];
            if(lakeId == 0) continue; // skip dry day
            if(record.count(lakeId)) dp[i] = record[lakeId];
            record[lakeId] = i;
        }

        for(int i = 0 ; i < rains.size() ; ++i){
            auto lakeId = rains[i];
            if(lakeId > 0) { // Fill water
                if(full_lakes.count(lakeId)) return {}; // flood
                pq.push({dp[i], lakeId});
                full_lakes.insert(lakeId);

            } else { // dry
                if(pq.empty()) {
                    // No lake to drain, just assign an arbitrary lake
                    res[i] = 1;
                } else {
                    // Select lake with the closest next-filled time
                    auto [tmp, lakeId] = pq.top(); pq.pop(); 
                    full_lakes.erase(lakeId);
                    res[i] = lakeId;
                }
            }
        }

        return res;
    }
};