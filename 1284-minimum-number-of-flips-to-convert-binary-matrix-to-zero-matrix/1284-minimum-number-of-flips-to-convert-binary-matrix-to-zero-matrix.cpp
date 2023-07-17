/*
 * @lc app=leetcode id=1284 lang=cpp
 *
 * [1284] Minimum Number of Flips to Convert Binary Matrix to Zero Matrix
 */

// @lc code=start
#include <vector>
#include <string>
#include <queue>
#include <unordered_set>
using namespace std;
class Solution {
public:
    int n_rows, n_cols;
    string encode_matrix(vector<vector<int>>& mtx) {
        string ret = "";
        for (int i = 0; i < mtx.size(); ++i)
            for (int j = 0; j < mtx[0].size(); ++j)
                ret += to_string(mtx[i][j]);
        return ret;
    }
    string myswap(string board, int i, int j) {
        swap(board[i], board[j]);
        return board;
    }
    string get_next_mtx(string mtx, int idx) {
        auto complement = [](char val) { return val == '0' ? '1' : '0'; };
        int row = idx / n_cols, col = idx % n_cols;

        mtx[idx] = complement(mtx[idx]);
        if(row - 1 >= 0) mtx[(row - 1) * n_cols + col] = complement(mtx[(row - 1) * n_cols + col]);
        if(row + 1 < n_rows) mtx[(row + 1) * n_cols + col] = complement(mtx[(row + 1) * n_cols + col]);
        if(col - 1 >= 0) mtx[row * n_cols + col - 1] = complement(mtx[row * n_cols + col - 1]);
        if(col + 1 < n_cols) mtx[row * n_cols + col + 1] = complement(mtx[row * n_cols + col + 1]);
        return mtx;
    }
    int minFlips(vector<vector<int>>& mat) {
        n_rows = mat.size();
        n_cols = mat[0].size();

        queue<string> q;
        unordered_set<string> visited;

        vector<vector<int>> e_mtx(n_rows, vector<int>(n_cols, 0));
        auto src_mat = encode_matrix(mat);
        auto tgt_mat = encode_matrix(e_mtx);

        q.push(src_mat);
        visited.insert(src_mat);

        int n_flips = 0;
        while (!q.empty()) {
            for(int i = 0 , size = q.size(); i < size ; ++i){
                auto mtx = q.front();
                q.pop();

                if (mtx == tgt_mat) return n_flips;

                for (int i = 0; i < n_rows * n_cols; i++){
                    auto nxt_mtx = get_next_mtx(mtx, i);
                    if (visited.count(nxt_mtx)) continue;

                    visited.insert(nxt_mtx);
                    q.push(nxt_mtx);
                }
            }
            n_flips++;
        }

        return -1;
    }
};
// @lc code=end

