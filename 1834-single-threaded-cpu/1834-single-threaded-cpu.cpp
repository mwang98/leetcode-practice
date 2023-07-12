/*
 * @lc app=leetcode id=1834 lang=cpp
 *
 * [1834] Single-Threaded CPU
 */

// @lc code=start
#include <vector>
#include <queue>
using namespace std;
class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        auto comp = [](const auto& p1, const auto& p2) -> bool {
            // first: index, second: processing time
            if (p1.second != p2.second) return p1.second > p2.second; // pop small process time
            return p1.first > p2.first; // pop small index
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(comp)> pq(comp);
        vector<int> ret;

        // Sort task by enqueueing time & processing time
        for (int i = 0; i < tasks.size(); ++i) tasks[i].push_back(i); // (enqueue, process, index)
        stable_sort(tasks.begin(), tasks.end(), [](const auto& t1, const auto& t2) {
            if(t1[0] != t2[0]) return t1[0] < t2[0];
            return t1[1] < t2[1];
        });

        int ptr = 1;
        unsigned long long current_time = tasks[0][0];
        pq.push({tasks[0][2], tasks[0][1]});

        while(!pq.empty()){
            auto [idx, process_time] = pq.top();
            pq.pop();
            ret.push_back(idx);

            current_time += process_time;
            while(ptr < tasks.size()){
                auto task = tasks[ptr];
                auto enqueue_time = task[0];
                if(enqueue_time <= current_time){
                    pq.push({task[2], task[1]});
                    ptr++;
                }
                else if(!pq.empty()) break;
                else if(ptr < tasks.size())
                    current_time = tasks[ptr][0];
            }
        }

        return ret;
    }
};
// @lc code=end

