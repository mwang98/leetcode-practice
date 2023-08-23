class Solution {
public:
    int max_cycle = -1;
    int visited[100000]; // 0: unvisited, 1: visiting, 2: visited

    void dfs(vector<int>& edges, unordered_map<int ,int>& path, int node, int level){
        // Base case
        if(visited[node] == 2) return;
        if(visited[node] == 1){
            max_cycle = max(max_cycle, level - path[node]);
            return;
        }
        // Recursive case
        if(edges[node] != -1){
            visited[node] = 1;
            path[node] = level;
            dfs(edges, path, edges[node], level + 1);
        }
        visited[node] = 2;
    }

    int longestCycle(vector<int>& edges) {
        memset(visited, 0, sizeof(visited));
        for(int i = 0 ; i < edges.size() ; ++i){
            if(visited[i] == 0){
                unordered_map<int, int> path;
                dfs(edges, path, i, 0);
            }
        }
        return max_cycle;
    }
};