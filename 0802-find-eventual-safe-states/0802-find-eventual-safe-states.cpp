/*
 * @lc app=leetcode id=802 lang=cpp
 *
 * [802] Find Eventual Safe States
 */

// @lc code=start
#include <queue>
#include <vector>
using namespace std;
class Solution {
   public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        /* Topological sort (Kahn's algo) 
        Remove nodes from "source" to "sink"
        */
        auto n_nodes = graph.size();
        queue<int> q;
        vector<vector<int>> adj_list(n_nodes);
        vector<int> indegrees(n_nodes, 0);
        vector<bool> is_safe(n_nodes, false);
        vector<int> ret;

        for (int src = 0; src < graph.size(); ++src) {
            for (auto tgt : graph[src]) {
                adj_list[tgt].push_back(src);  // reverse edge direction
                indegrees[src]++;
            }
        }

        for (int node = 0; node < n_nodes; ++node)
            if (indegrees[node] == 0) q.push(node);

        while (!q.empty()) {
            for (int i = 0, size = q.size(); i < size; ++i) {
                auto node = q.front();
                q.pop();

                is_safe[node] = true;

                for (auto nxt : adj_list[node])
                    if (--indegrees[nxt] == 0) q.push(nxt);
            }
        }

        for (int i = 0; i < n_nodes; ++i)
            if (is_safe[i]) ret.push_back(i);

        return ret;
    }
};
// @lc code=end
