class Solution {
public:
    bool is_row_set[10000];
    bool is_col_set[10000];
    int num_row_set = 0;
    int num_col_set = 0;
    long long matrixSumQueries(int n, vector<vector<int>>& queries) {
        long long sum_val = 0;
        memset(is_row_set, 0, sizeof(is_row_set));
        memset(is_col_set, 0, sizeof(is_col_set));
        // Iterate from last query to the first
        for(int i = queries.size() - 1 ; i >= 0 ; i--){
            auto idx = queries[i][1], val = queries[i][2];
            if(queries[i][0]){ // col
                if(!is_col_set[idx]){
                    is_col_set[idx] = true;
                    num_col_set++;
                    sum_val += val * (n - num_row_set);
                }
            } else{ // row
                 if(!is_row_set[idx]){
                    is_row_set[idx] = true;
                    num_row_set++;
                    sum_val += val * (n - num_col_set);
                }
            }
        }
        return sum_val;
    }
};