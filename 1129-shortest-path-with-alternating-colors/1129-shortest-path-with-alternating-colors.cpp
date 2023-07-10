/*
 * @lc app=leetcode id=1129 lang=cpp
 *
 * [1129] Shortest Path with Alternating Colors
 */

// @lc code=start
#include <vector>
#include <queue>
using namespace std;
enum COLOR {
    Blue = 0,
    Red = 1
};
class Solution {
   public:
    bool visited[100][2];
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        vector<vector<int>> red_adj(n);
        vector<vector<int>> blue_adj(n);
        vector<int> ret(n, -1);
        queue<pair<int, COLOR>> q;

        q.push({0, COLOR::Blue});
        q.push({0, COLOR::Red});
        visited[0][COLOR::Blue] = visited[0][COLOR::Red] = true;

        for(const auto& edge: redEdges)
            red_adj[edge[0]].push_back(edge[1]);
        for (const auto& edge : blueEdges)
            blue_adj[edge[0]].push_back(edge[1]);

        int level = 0;
        while (!q.empty()) {
            for (int i = 0, size = q.size(); i < size; ++i){
                auto [node, color] = q.front();
                q.pop();

                if (ret[node] == -1) ret[node] = level;

                auto& adj = color == COLOR::Blue ? red_adj : blue_adj;
                auto nxt_color = color == COLOR::Blue ? COLOR::Red : COLOR::Blue;

                for (auto nxt_node : adj[node]) {
                    if (visited[nxt_node][nxt_color]) continue;
                    q.push({nxt_node, nxt_color});
                    visited[nxt_node][nxt_color] = true;
                }
            }

            level++;
        }

        return ret;
    }
};
// @lc code=end

