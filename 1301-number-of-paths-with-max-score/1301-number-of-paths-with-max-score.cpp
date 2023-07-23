class Solution {
public:
    vector<int> pathsWithMaxScore(vector<string>& board) {
        /* DP 
        Def: dp_max[i][j]: the maximum score to reach board[i][j]
             dp_cnt[i][j]: the number of such paths to reach board[i][j]
        Transition
             max_path = max(dp_max[i+1][j], dp_max[i][j+1], dp_max[i+1][j+1])
             dp_max[i][j] = board[i][j] + max_path
             dp_cnt[i][j] = dp_cnt[i+1][j] * (dp_max[i+1][j] == max_path) + 
                            dp_cnt[i][j+1] * (dp_max[i][j+1] == max_path) + 
                            dp_cnt[i+1][j+1] * (dp_max[i+1][j+1] == max_path)
        TC: O(mn)
        SC: O(mn)
        */
        auto n_rows = board.size(), n_cols = board[0].size();
        int dp_max[100][100];
        int dp_cnt[100][100];
        int MOD = 1e9 + 7;
        memset(dp_max, 0, sizeof(dp_max));
        memset(dp_cnt, 0, sizeof(dp_cnt));

        board[0][0] = board[n_rows - 1][n_cols - 1] = '0';

        for(int i = n_rows - 1 ; i >= 0 ; --i){
            for(int j = n_cols - 1 ; j >=0 ; --j){
                if(i == n_rows - 1 && j == n_cols - 1){
                    dp_cnt[i][j] = 1; continue;
                }
                if(board[i][j] == 'X'){
                    dp_max[i][j] = -1; continue;
                }

                auto max1 = j + 1 < n_cols ? dp_max[i][j + 1] : -1, cnt1 = j + 1 < n_cols ? dp_cnt[i][j + 1] : -1;
                auto max2 = i + 1 < n_rows ? dp_max[i + 1][j] : -1, cnt2 = i + 1 < n_rows ? dp_cnt[i + 1][j] : -1;
                auto max3 = i + 1 < n_rows && j + 1 < n_cols ? dp_max[i + 1][j + 1] : -1, cnt3= i + 1 < n_rows && j + 1 < n_cols ? dp_cnt[i + 1][j + 1] : -1;
                auto max_val = max(max(max1, max2), max(max3, 0));

                dp_max[i][j] = max_val + (board[i][j] - '0');
                dp_cnt[i][j] =( ((cnt1 * (max1 == max_val) + cnt2 * (max2 == max_val)) % MOD) + cnt3 * (max3 == max_val)) % MOD;
            } 
        }

        return {(dp_cnt[0][0] > 0) * dp_max[0][0], dp_cnt[0][0]};
    }
};