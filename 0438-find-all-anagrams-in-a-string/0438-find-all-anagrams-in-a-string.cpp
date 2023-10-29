class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        // Sliding window
        // TC: O(n)
        // SC: O(26) for counting freq of a substring

        int left = 0, right = 0;
        unordered_map<char, int> s_cnt, p_cnt;
        vector<int> res;

        // Substring of s has character not in p
        auto hasInvalidChar = [&]() -> bool {
            for(auto [ch, cnt]: s_cnt) 
                if(p_cnt.count(ch) == 0) return true;
            return false;
        };

        // s counter has too many characters
        auto tooManyChar = [&]() -> bool {
            for(auto [ch, cnt]: s_cnt)
                if(cnt > p_cnt[ch]) return true;
            return false;
        };

        // Build freq counter of p
        for(auto ch: p) p_cnt[ch]++;

        while(right < s.size()){
            s_cnt[s[right++]]++;

            if(hasInvalidChar()) {
                s_cnt.clear();
                left = right;
                continue;
            }

            while(tooManyChar()) {
                s_cnt[s[left++]]--;
            }

            if(s_cnt == p_cnt) {
                res.push_back(left);
                s_cnt[s[left++]]--;
            }
        }

        return res;
    }
};