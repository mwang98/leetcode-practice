class Solution {
public:
    int treeDiameter(vector<vector<int>>& edges) {
        /* Tree Diameter = find centroid (BFS + topological order) */
        int n_nodes = edges.size() + 1;
        queue<int> q;
        vector<vector<int>> adj_list(n_nodes);
        vector<int> in_degree(n_nodes, 0);
        vector<bool> visited(n_nodes, false);
        int level = 0;
        int n_visited = 0;

        if(n_nodes == 1) return 0;

        for(const auto& edge: edges){
            adj_list[edge[0]].push_back(edge[1]);
            adj_list[edge[1]].push_back(edge[0]);
            in_degree[edge[0]]++;
            in_degree[edge[1]]++;
        }

        for(int i = 0 ; i < in_degree.size() ; ++i)
            if(in_degree[i] == 1){
                q.push(i);
                visited[i] = true;
            }

        while(n_visited < n_nodes - 2){
            for(int i = 0, size = q.size() ; i < size ; ++i){
                auto node = q.front();
                q.pop();
                n_visited++;

                for(const auto& nxt: adj_list[node]){
                    if(!visited[nxt]){
                        in_degree[nxt]--;
                        if(in_degree[nxt] == 1){
                            q.push(nxt);
                            visited[nxt] = true;
                        }
                    }
                }
            }
            level++;
        }

        return level * 2 + ((q.size() % 2 == 0) ? 1 : 0);
    }
};