class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        vector<int> res(people.size());
        vector<pair<int, int>> peoples(people.size());
        priority_queue<int, vector<int>, std::greater<int>> pq;

        // Sort people by time, sort flowers by start time
        for(int i = 0 ; i < people.size() ; ++i) peoples[i] = {i, people[i]};
        sort(peoples.begin(), peoples.end(), 
            [](const auto& lhs, const auto& rhs) -> bool { return lhs.second < rhs.second; });
        sort(flowers.begin(), flowers.end(), 
            [](const auto& lhs, const auto& rhs) -> bool { return lhs[0] < rhs[0]; });
        
        // For each people
        int fr_idx = 0;
        for(const auto& [ppl_idx, time]: peoples){
            // - Pop all flowers until heap.top() >= people[i]
            while(!pq.empty() && pq.top() < time) pq.pop();

            // - Traverse flowers until people[i] >= flowers[i].start
            // - Push all flowers in heap (min heap for end time)
            while(fr_idx < flowers.size() && time >= flowers[fr_idx][0]){
                if(time <= flowers[fr_idx][1]) pq.push(flowers[fr_idx][1]);
                fr_idx++;
            }
            res[ppl_idx] = pq.size();
        }

        return res;
    }
};