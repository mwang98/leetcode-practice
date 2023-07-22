class Solution {
public:
    int minimumOperations(vector<int>& nums, int start, int goal) {
        /* BFS 
        TC: O(1000)
        SC: O(1000)
        */
        queue<int> q;
        bool visited[1001];

        memset(visited, false, sizeof(visited));
        q.push(start);

        // Edge case
        if(start == goal) return 0;

        int n_ops = 1;
        while(!q.empty()){
            for(int i = 0, size = q.size() ; i < size ; ++i){
                auto val = q.front();
                q.pop();

                for(auto num: nums){
                    for(auto nxt_val: {val + num, val - num, val ^ num}){
                        if(nxt_val == goal) return n_ops;
                        if(0 <= nxt_val && nxt_val <= 1000 && !visited[nxt_val]){
                            q.push(nxt_val);
                            visited[nxt_val] = true;
                        }
                    }
                }
            }
            n_ops++;
        }

        return -1;
    }
};