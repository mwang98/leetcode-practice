enum Player{
    P1 = 0,
    P2
};
class Solution {
public:
    int dp[2][20][20];

    int topdown(vector<int>& nums, Player p, int start, int end){
        // Base case
        if(dp[p][start][end] != -1) return dp[p][start][end];
        if(start == end) return p == Player::P1 ? nums[start] : 0;
        // Recursive case
        if(p == Player::P1){
            auto score_front = nums[start] + topdown(nums, Player::P2, start + 1, end);
            auto score_back = nums[end] + topdown(nums, Player::P2, start, end - 1);
            return dp[p][start][end] = max(score_front, score_back);
        }
        auto score_front = topdown(nums, Player::P1, start + 1, end);
        auto score_back = topdown(nums, Player::P1, start, end - 1);
        return dp[p][start][end] = min(score_front, score_back);
    }

    bool PredictTheWinner(vector<int>& nums) {
        /* DP (state machine) 
        Def: dp[p][i][j]: the score Player1 can get for the `nums[i:j]` when playing by `p`
        Transition:
            Player1: 
                Select front: nums[i] + dp[p2][i+1][j]
                Select back:  nums[j] + dp[p2][i][j-1]
            Player2:
                Select front: dp[p1][i+1][j]
                Select back:  dp[p1][i][j-1]        
        */
        for(int i = 0 ; i < 2 ; ++i) for(int j = 0 ; j < 20 ; ++j) for(int k = 0 ; k < 20 ; ++k) dp[i][j][k] = -1;

        auto score_p1 = topdown(nums, Player::P1, 0, nums.size()-1);
        auto score_p2 = accumulate(nums.begin(), nums.end(), 0) - score_p1;
        return score_p1 >= score_p2;
    }
};