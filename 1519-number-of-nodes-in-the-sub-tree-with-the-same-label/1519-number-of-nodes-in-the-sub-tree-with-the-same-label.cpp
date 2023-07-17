/*
 * @lc app=leetcode id=1519 lang=cpp
 *
 * [1519] Number of Nodes in the Sub-Tree With the Same Label
 */

// @lc code=start
#include <string>
#include <vector>
using namespace std;
class Solution {
   public:
    vector<vector<int>> adj_list;
    vector<bool> visited;
    vector<int> ret;
    string labels;

    vector<int> dfs(int node) {
        vector<int> counter(26, 0);
        counter[labels[node] - 'a']++;

        for (auto nxt : adj_list[node]) {
            if (visited[nxt]) continue;
            visited[nxt] = true;

            vector<int> nxt_cnt(move(dfs(nxt)));
            for (int i = 0; i < nxt_cnt.size(); ++i)
                counter[i] += nxt_cnt[i];
        }

        ret[node] = counter[labels[node] - 'a'];
        return counter;
    }

    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string lb) {
        labels = lb;
        visited.resize(n, false);
        adj_list.resize(n);
        ret.resize(n);

        for (const auto& edge : edges) {
            adj_list[edge[0]].push_back(edge[1]);
            adj_list[edge[1]].push_back(edge[0]);
        }

        visited[0] = true;
        dfs(0);

        return ret;
    }
};
// @lc code=end
