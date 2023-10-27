typedef pair<int, int> PII;
class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        // Greedy:
        // 
        // Sort by start day
        sort(events.begin(), events.end(), [](const auto& lhs, const auto& rhs) -> bool {
            if(lhs[0] != rhs[0]) return lhs[0] < rhs[0];
            return lhs[1] < rhs[1];
        });
        
        priority_queue<int, vector<int>, greater<int>> pq; // min heap for end time

        int idx = 0; // index for events
        int res = 0;
        int timestamp = -1;

        while(!pq.empty() || idx < events.size()){
            // Update timestamp
            if(pq.empty()) { // no events candidates
                timestamp = events[idx][0];
            }

            // Push all events that start before `timestamp`
            while(idx < events.size() && events[idx][0] <= timestamp){
                pq.push(events[idx++][1]);
            }

            // Pop the event with the earliest end time
            pq.pop();
            timestamp++;
            res++;

            // Pop out out-of-date events
            while(!pq.empty() && pq.top() < timestamp)
                pq.pop();
        }   

        return res;
    }
};