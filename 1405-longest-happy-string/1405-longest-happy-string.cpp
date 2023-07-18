#include <queue>
#include <string>
using namespace std;

class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        string ret = "";
        vector<pair<int, char>> values = {{a, 'a'}, {b, 'b'}, {c, 'c'}};
        sort(values.begin(), values.end(), [](const auto& p1, const auto& p2) {return p1.first > p2.first;});

        int max_cnt = values[0].first, mid_cnt = values[1].first, min_cnt = values[2].first;

        if(mid_cnt + min_cnt < ((max_cnt + 1) / 2) - 1){
            ret += string(2, values[0].second);
            max_cnt -= 2;
            while(mid_cnt > 0 || min_cnt > 0){
                auto& cnt = mid_cnt > 0 ? mid_cnt : min_cnt;
                auto ch = mid_cnt > 0 ? values[1].second : values[2].second;
                ret += string(1, ch) + string(2, values[0].second);
                cnt -= 1;
            }
        } else {
            auto num_middles = ((max_cnt + 1) / 2) - 1;
            auto num_frees = mid_cnt + min_cnt - num_middles;

            ret += string(min(2, num_frees), '*');
            num_frees -= min(2, num_frees);
            
            while(num_frees > 0 || num_middles > 0 || max_cnt > 0){
                ret += string(min(1, max_cnt), values[0].second);
                max_cnt -= min(1, max_cnt);

                ret += string(min(2, num_frees), '*');
                num_frees -= min(2, num_frees);

                ret += string(min(1, max_cnt), values[0].second);
                max_cnt -= min(1, max_cnt);

                ret += string(min(1, num_middles), '*');
                num_middles -= min(1, num_middles);

                ret += string(min(1, num_frees), '*');
                num_frees -= min(1, num_frees);
            }

            for(int i = 0 ; i < ret.size() ; ++i){
                if(ret[i] != '*') continue;
                if(mid_cnt-- > 0) ret[i] = values[1].second;
                else if(min_cnt-- > 0) ret[i] = values[2].second;
            }
        }

        return ret;
    }
};