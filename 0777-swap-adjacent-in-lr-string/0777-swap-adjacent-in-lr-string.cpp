class Solution {
public:
    bool canTransform(string start, string end) {
        vector<pair<char, int>> s_arr;
        vector<pair<char, int>> e_arr;

        for(int i = 0 ; i < start.size() ; ++i) {
            if(start[i] == 'X') continue;
            s_arr.push_back({start[i], i});
        }
        for(int i = 0 ; i < end.size() ; ++i) {
            if(end[i] == 'X') continue;
            e_arr.push_back({end[i], i});
        }

        if(s_arr.size() != e_arr.size()) return false;

        for(int i = 0 ; i < s_arr.size() ; ++i){
            auto [s, s_pos] = s_arr[i];
            auto [e, e_pos] = e_arr[i];

            if(s != e) return false;

            if(s == 'L'){
                if(e_pos > s_pos) return false;
                if(e_pos == s_pos) continue;
                if(i - 1 >= 0 && s_arr[i - 1].first == 'R' && e_pos <= s_arr[i - 1].second) return false;
            } else {
                if(e_pos < s_pos) return false;
                if(e_pos == s_pos) continue;
                if(i + 1 < s_arr.size() && s_arr[i + 1].first == 'L' && e_pos >= s_arr[i + 1].second) return false;
            }
        }

        return true;

    }
};