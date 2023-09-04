#include<cmath>
class Solution {
public:
    vector<int> minOperationsQueries(int n, vector<vector<int>>& edges, vector<vector<int>>& queries) {
        // Define variables
        int WEIGHTS = 26;
        vector<vector<pair<int, int>>> adj(n);  // adjacency list
         // weights[node][w]: # of occurence of `w` in the path from root to `node`
        vector<vector<int>> weights(n, vector<int>(WEIGHTS + 1, 0));
        vector<int> depths(n, 0); // depth of node

        // Variable for binary lifting
        int N_NODE = n, LOG_N_NODE = ceil(log2(N_NODE));
        int timer = 0;
        vector<int> tin(N_NODE), tout(N_NODE);
        vector<vector<int>> up(N_NODE, vector<int>(LOG_N_NODE + 1));

        // Aux func
        auto is_ancestor = [&](int u, int v) -> bool{
            return tin[u] <= tin[v] && tout[u] >= tout[v];
        };
        function<void(int, int)> dfs = [&](int node, int parent) -> void{
            tin[node] = ++timer;
            
            depths[node] = depths[parent] + 1;
            up[node][0] = parent; 
            for(int j = 1 ; j <= LOG_N_NODE ; ++j){
                up[node][j] = up[ up[node][j-1] ][j-1];
            }
            
            for(auto [neighbor, weight]: adj[node]){
                if(neighbor == parent) continue;
                weights[neighbor] = weights[node];
                weights[neighbor][weight]++;
                dfs(neighbor, node);
            }

            tout[node] = ++timer;
        };

        auto find_lca = [&](int u, int v) -> int{
            if(is_ancestor(u, v)) return u;
            if(is_ancestor(v, u)) return v;
            
            for(int j = LOG_N_NODE ; j >= 0 ; --j){
                if(auto ancestor = up[u][j]; !is_ancestor(ancestor, v))
                    u = ancestor;
            }
            
            return up[u][0];
        };

        // Build graph
        for(auto& e: edges){
            adj[e[0]].push_back({e[1], e[2]});
            adj[e[1]].push_back({e[0], e[2]});
        }

        // Init weights & depths
        weights[0] = vector<int>(WEIGHTS + 1, 0);
        depths[0] = -1;
        dfs(0, 0);

        // Execute queries
        vector<int> ret;
        for(auto& q: queries){
            int u = q[0], v = q[1];
            int lca = find_lca(u, v);

            // 排容原理
            int path_len = depths[u] + depths[v] - 2 * depths[lca];

            int max_z = 0;
            for(int z = 1; z <= WEIGHTS ; ++z){
                int num_z = weights[u][z] + weights[v][z] - 2 * weights[lca][z];
                max_z = max(max_z, num_z);
            }

            ret.push_back(path_len - max_z);
        }

        return ret;
    }   
};