class Solution {
public:
    vector<long long> countBlackBlocks(int m, int n, vector<vector<int>>& coordinates) {
        // Scan the matrix -> TLE
        // Scan coordinates with black cell & update counter
        
        vector<pair<int, int>> directions = {{-1, 0}, {0, -1}, {-1, -1}, {0, 0}};
        unordered_map<long long, int> counter; // block (represented by its top-left cell) -> # of black cells
        vector<long long> res(5, 0);
        
        auto encode = [&](int x, int y) -> long long {
            return (0L + x) * n + y;
        };

        for(const auto& coord: coordinates){
            int x = coord[0], y = coord[1];
            for(auto [dx, dy]: directions){
                int nx = x + dx, ny = y + dy;
                if(!(0 <= nx && nx < m - 1 && 0 <= ny && ny < n - 1)) continue;

                counter[encode(nx, ny)]++;
            }
        }

        res[0] = (0L + m - 1) * (n - 1) - counter.size();
        for(auto [tmp, cnt]: counter) res[cnt]++;

        return res;
    }
};