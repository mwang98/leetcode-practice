class Leaderboard {
public:
    unordered_map<int, int> scores; // Player score: scores[playerId]
    map<int, int, greater<int>> score_counter;    // # of score in the leaderboard
    
    Leaderboard() {
        
    }
    
    void addScore(int playerId, int score) {
        // O(logn) where n is the # of score value
        score_counter[scores[playerId]]--;
        scores[playerId] += score;
        score_counter[scores[playerId]]++;
    }
    
    int top(int K) {
        // O(K)
        int res = 0;
        for(auto [score, cnt]: score_counter){
            if(K == 0) break;
            res += score * min(cnt, K);
            K -= min(cnt, K);
        }
        return res;
    }
    
    void reset(int playerId) {
        // O(logn) where n is the # of score value
        score_counter[scores[playerId]]--;
        scores[playerId] = 0;
        score_counter[scores[playerId]]++;
    }
};

/**
 * Your Leaderboard object will be instantiated and called as such:
 * Leaderboard* obj = new Leaderboard();
 * obj->addScore(playerId,score);
 * int param_2 = obj->top(K);
 * obj->reset(playerId);
 */