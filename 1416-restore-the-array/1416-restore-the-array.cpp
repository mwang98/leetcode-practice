#include <cmath>
class Solution {
public:
    int numberOfArrays(string s, int k) {
        /* DP
        Def: dp[:i]: # of ways to restore array on s[:i]
        Transition:
            for j in range(1, log(k))
                if s[j:i] is in the range of [1, k]
                    dp[i] += dp[j]
        TC: O(n * logk)
        SC: O(n)
        */
        int MOD = 1e9 + 7;
        int dp[100001];
        memset(dp, 0, sizeof(dp));

        string k_str = to_string(k);
        int k_len = floor(log(k) + 1);
        dp[0] = 1;

        auto str_cmp = [](const string& s1, const string& s2) -> bool {
            if(s1.size() > s2.size()) return true;
            if(s1.size() < s2.size()) return false;
            return s1 >= s2;
        };

        for(int i = 0 ; i < s.size() ; ++i){
            for(int j = max(0, i - k_len) ; j <= i ; ++j){
                if(s[j] == '0') continue; // no leading zero
                auto val = s.substr(j, i - j + 1);
                if(str_cmp(k_str, val)) dp[i + 1] = (dp[i + 1] + dp[j]) % MOD;
            }
        }

        return dp[s.size()];
    }
};