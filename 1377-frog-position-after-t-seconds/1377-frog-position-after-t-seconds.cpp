class Solution {
public:
    vector<vector<int>> adj_list;
    bool visited[101];
    queue<pair<int, double>> q;

    double frogPosition(int n, vector<vector<int>>& edges, int t, int target) {
        adj_list.resize(n + 1);
        memset(visited, false, sizeof(visited));

        for(const auto& edge: edges){
            adj_list[edge[0]].push_back(edge[1]);
            adj_list[edge[1]].push_back(edge[0]);
        }
        
        auto get_child_num = [&](const auto& children) -> int {
            auto ret = 0;
            for(auto child: children) ret += !visited[child];
            return ret;
        };
        
        int level = 0;
        double ans = 0;
        q.push({1, 1});
        visited[1] = true;

        while(!q.empty() && level <= t){
            for(int i = 0, size = q.size() ; i < size ; ++i){
                auto [node, prob] = q.front();
                q.pop();

                auto num_children = get_child_num(adj_list[node]);
                for(auto child: adj_list[node]){
                    if(!visited[child]){
                        visited[child] = true;
                        q.push({child, prob / num_children});
                    }
                }

                // Arrive at the exactly time `t` or have no children
                if(node == target && (level == t || num_children == 0)) return prob;
            }
            level++;
        }

        return ans;
    }
};