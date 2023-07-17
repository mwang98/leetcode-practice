/*
 * @lc app=leetcode id=773 lang=cpp
 *
 * [773] Sliding Puzzle
 */

// @lc code=start
#include <vector>
#include <unordered_set>
#include <queue>
#include <string>
using namespace std;
class Solution {
public:
    string encode_board(vector<vector<int>>& board){
        string ret = "";
        for (int i = 0; i < board.size(); ++i)
            for (int j = 0; j < board[0].size(); ++j)
                ret += to_string(board[i][j]);
        return ret;
    }
    string myswap(string board, int i, int j){
        swap(board[i], board[j]);
        return board;
    }
    vector<string>
        get_next_boards(string board) {
        vector<string> ret;
        int zero_idx = board.find('0');
        int row = zero_idx / 3, col = zero_idx % 3;

        if(row == 0) ret.push_back(myswap(board, zero_idx, zero_idx + 3));
        else ret.push_back(myswap(board, zero_idx, zero_idx - 3));
        if (col - 1 >= 0) ret.push_back(myswap(board, zero_idx, zero_idx - 1));
        if (col + 1 < 3) ret.push_back(myswap(board, zero_idx, zero_idx + 1));
        return ret;
    }

    int slidingPuzzle(vector<vector<int>>& board) {
        /* BFS */
        unordered_set<string> visited;
        queue<string> q;

        auto src_board = encode_board(board);
        auto tgt_board = "123450";
        visited.insert(src_board);
        q.push(src_board);

        int n_swaps = 0;
        while (!q.empty()) {
            for (int i = 0, size = q.size(); i < size; ++i){
                auto board = q.front();
                q.pop();

                if (board == tgt_board) return n_swaps;
                for (const auto& nxt_board : get_next_boards(board)){
                    if(visited.count(nxt_board) == 0){
                        visited.insert(nxt_board);
                        q.push(nxt_board);
                    }
                }
            }

            n_swaps++;
        }

        return -1;
    }
};
// @lc code=end

