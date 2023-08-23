class Solution {
public:
    string reorganizeString(string s) {
        string ret(s.size(), ' ');
        int counter[26];
        priority_queue<pair<int, char>> pq;

        memset(counter, 0, sizeof(counter));

        for(auto ch: s) counter[ch - 'a']++;
        for(int i = 0 ; i < 26 ; ++i)
            if(auto cnt = counter[i]; cnt > 0) pq.push({cnt, i + 'a'});

        // Edge case
        if(pq.top().first > (s.size() / 2 + s.size() % 2)) return "";

        char prev = ' ';
        for(int i = 0 ; i < s.size() ; ++i){
            auto [cnt, ch] = pq.top();
            pq.pop();
            if(prev == ch){
                auto p = make_pair(cnt, ch);
                cnt = pq.top().first;
                ch = pq.top().second;
                pq.pop();
                pq.push(p);
            }
            if(--cnt > 0){
                pq.push({cnt, ch});
            }
            ret[i] = prev = ch;
        }

        return ret;
    }
};