class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        /* BFS on node & state 
        TC: O(2^n * n)
        SC: O(2^n * n)
        */
        queue<pair<int, int>> q; // node, bitmask (record state)
        bool seen[12][1 << 12];

        memset(seen, 0, sizeof(seen));
        for(int i = 0 ; i < graph.size() ; ++i) q.push({i, 1 << i});

        int level = 0;
        while(!q.empty()){
            for(int i = 0, size = q.size() ; i < size ; ++i){
                auto [node, mask] = q.front(); q.pop();
                
                if(mask == ((1 << graph.size()) - 1)){ // visit all nodes
                    return level;
                }

                for(auto nxt: graph[node]){
                    if(seen[nxt][mask | 1 << nxt]) continue;
                    seen[nxt][mask | 1 << nxt] = true;
                    q.push({nxt, mask | 1 << nxt});
                }
            }

            level++;
        }

        return -1;
    }
};