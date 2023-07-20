typedef tuple<int, int, int, int> tp;
class Solution {
public:
    vector<vector<int>> highestRankedKItems(vector<vector<int>>& grid, vector<int>& pricing, vector<int>& start, int k) {
        auto comp = [&] (const auto& t1, const auto& t2) -> bool {
            auto [dist1, p1, r1, c1] = t1;
            auto [dist2, p2, r2, c2] = t2;
            if(dist1 != dist2) return dist1 < dist2;
            if(p1 != p2) return p1 < p2;
            if(r1 != r2) return r1 < r2;
            return c1 < c2;
        };
        auto n_rows = grid.size(), n_cols = grid[0].size();

        vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        priority_queue<tp, vector<tp>, decltype(comp)> pq(comp);
        queue<pair<int, int>> q;
        vector<bool> visited(n_rows * n_cols, false);

        int level = 0;
        q.push({start[0], start[1]});
        visited[start[0] * n_cols + start[1]] = true;
        while(!q.empty()){
            for(int i = 0, size = q.size() ; i < size ; ++i){
                auto [x, y] = q.front();
                auto price = grid[x][y];
                tp cell = {level, price, x, y};
                q.pop();

                if(pricing[0] <= price && price <= pricing[1]){
                    if (pq.size() < k) pq.push(cell);
                    else if (comp(cell, pq.top())){
                        pq.pop();
                        pq.push(cell);
                    }
                }
                
                for(const auto& [dx, dy]: directions){
                    auto nx = x + dx, ny = y + dy;
                    if(nx >= 0 && nx < n_rows && ny >= 0 && ny < n_cols && 
                       !visited[nx * n_cols + ny] && grid[nx][ny] != 0){
                        q.push({nx, ny});
                        visited[nx * n_cols + ny] = true;
                    }
                }
            }

            if(pq.size() == k) break;
            
            level++;
        } 

        vector<vector<int>> ret;
        while(!pq.empty()){
            auto [dist, price, x, y] = pq.top();
            pq.pop();
            ret.push_back({x, y});
        }
        reverse(ret.begin(), ret.end());

        return ret;
    }
};