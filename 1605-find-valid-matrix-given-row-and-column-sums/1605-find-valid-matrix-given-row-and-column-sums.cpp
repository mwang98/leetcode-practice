enum Type{
    ROW = 0,
    COL
};

typedef tuple<Type, int, int> tp; // Type, index, sum

class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        auto n_rows = rowSum.size(), n_cols = colSum.size();
        auto comp = [](const auto& t1, const auto& t2) -> bool { return get<2>(t1) > get<2>(t2); };

        vector<vector<int>> ret(n_rows, vector<int>(n_cols, -1));
        vector<bool> row_visited(n_rows, false);
        vector<bool> col_visited(n_cols, false);
        priority_queue<tp, vector<tp>, decltype(comp)> pq(comp);

        for(int i = 0 ; i < n_rows ; ++i) pq.push({Type::ROW, i, rowSum[i]});
        for(int i = 0 ; i < n_cols ; ++i) pq.push({Type::COL, i, colSum[i]});

        while(!pq.empty()){
            auto [type, idx, sum_val] = pq.top();
            pq.pop();

            if(type == Type::ROW){
                if(row_visited[idx]) continue;
                for(int i = 0 ; i < n_cols ; ++i){
                    if(ret[idx][i] != -1) continue;
                    if(sum_val > 0){
                        ret[idx][i] = sum_val;
                        colSum[i] -= sum_val;
                        sum_val = 0;
                        pq.push({Type::COL, i, colSum[i]});
                    } else ret[idx][i] = sum_val;
                }
                row_visited[idx] = true;                
            } else {
                if(col_visited[idx]) continue;
                for(int i = 0 ; i < n_rows ; ++i){
                    if(ret[i][idx] != -1) continue;
                    if(sum_val > 0){
                        ret[i][idx] = sum_val;
                        rowSum[i] -= sum_val;
                        sum_val = 0;
                        pq.push({Type::ROW, i, rowSum[i]});
                    } else ret[i][idx] = sum_val;
                }
                col_visited[idx] = true;
            }
        }
        
        return ret;
    }
};