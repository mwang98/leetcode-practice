class Solution {
public:
    int max_score = -1;
    int counter[26];
    int scores[26];
    bool is_enough(const string& str){
        int tmp[26];
        memset(tmp, 0, sizeof(tmp));
        for(auto l: str) tmp[l - 'a']++;
        for(int i = 0 ; i < 26 ; ++i) if(tmp[i] > counter[i]) return false;
        return true;
    }
    int get_score(const string& str){
        int ret = 0;
        for(auto ch: str) ret += scores[ch - 'a'];
        return ret;
    }
    void modify_counter(const string& str, int unit){
        for(auto ch: str) counter[ch - 'a'] += unit;
    }

    void backtrack(vector<string>& words, int idx = 0, int score = 0){
        max_score = max(max_score, score);
        // Base case
        if(idx == words.size()) return;
        // Recursive case
        for(int i = idx ; i < words.size() ; ++i){
            auto word = words[i];
            if(is_enough(word)){
                modify_counter(word, -1);
                backtrack(words, i + 1, score + get_score(word));
                modify_counter(word, 1);
            }
        }
    }
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        /* Backtracking */
        memset(counter, 0, sizeof(counter));
        for(auto l: letters) counter[l - 'a']++;
        for(int i = 0 ; i < score.size() ; ++i) scores[i] = score[i];
        backtrack(words);
        return max_score;
    }
};