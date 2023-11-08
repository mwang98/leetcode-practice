class Solution {
public:
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        /* Key: 
            (1) Every node can be a root (tree property)
            (2) Leaf node should merge with its parent if its value is not k-divisible
        */
        vector<bool> visited(n, false);
        vector<vector<int>> adj(n);
        int res = 0;

        // Build adj list
        for(auto& e: edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        function<long(int)> dfs = [&](int node) -> long {
            // Base case
            if(visited[node]) return 0;

            // Recursive case
            visited[node] = true;
            long sum_val = values[node];
            for(auto next: adj[node]){
                if(visited[next]) continue;
                sum_val += dfs(next);
            }

            res += sum_val % k == 0;
            return sum_val % k == 0 ? 0 : sum_val;
        };

        dfs(0);
        return res;
    }
};