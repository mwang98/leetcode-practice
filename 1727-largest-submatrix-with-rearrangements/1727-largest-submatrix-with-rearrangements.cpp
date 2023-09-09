class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int n_rows = matrix.size(), n_cols = matrix[0].size();

        // Pre-compute: matrix[i][j] = # of consecutive 0 in column[j] ending at `i` pos
        for(int i = 0 ; i < n_rows ; ++i){
            for(int j = 0 ; j < n_cols ; ++j){
                if(matrix[i][j] == 0 || i == 0) continue;
                matrix[i][j] += matrix[i-1][j];
            }
        }

        // Sort
        int res = 0;
        for(int i = 0 ; i < n_rows ; ++i){
            sort(matrix[i].begin(), matrix[i].end());
            for(int j = 0 ; j < n_cols ; ++j){
                res = max(res, matrix[i][j] * (n_cols - j));
            }
        }

        return res;
    }
};