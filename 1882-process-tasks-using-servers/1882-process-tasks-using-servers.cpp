typedef pair<int, int> PII;

class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        int timestamp = 0;
        int task_idx = 0;
        vector<int> res(tasks.size());
        priority_queue<PII, vector<PII>, greater<PII>> pq_free_server; // min heap: (weight, idx)
        priority_queue<PII, vector<PII>, greater<PII>> pq_working_server; // min heap: (finished time, idx)

        // Init free server list
        for(int i = 0 ; i < servers.size() ; ++i) 
            pq_free_server.push({servers[i], i});
        
        // Execute each task 
        while(task_idx < tasks.size()){
            // No available server -> fastforward to most recent finished time
            if(pq_free_server.empty()){
                auto [earliest_done_time, tmp] = pq_working_server.top();
                timestamp = earliest_done_time;
            } 

            // Release working servers
            while(!pq_working_server.empty() && pq_working_server.top().first <= timestamp){
                auto [tmp, server_id] = pq_working_server.top();
                pq_working_server.pop();
                pq_free_server.push({servers[server_id], server_id});
            }

            // Allocate servers to tasks
            while(task_idx <= timestamp && task_idx < tasks.size() && !pq_free_server.empty()){
                auto [tmp, server_id] = pq_free_server.top();
                pq_free_server.pop();
                pq_working_server.push({timestamp + tasks[task_idx], server_id});
                res[task_idx] = server_id;
                task_idx++;
            }

            timestamp++;
        }

        return res;
    }
};