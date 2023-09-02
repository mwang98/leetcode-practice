class Solution {
public:
    int minExtraChar(string s, vector<string>& dictionary) {
        /* DP 
        Def: dp[i]: minimum extracted characters of s[:i]
        Transition:
            Use s[i] to match string in dict:
                dp[i] = min(dp[i], dp[j]) for all j <= i where s[j:i] in `dictionary`
            Not use:
                dp[i] = dp[i - 1] + 1
        TC: O(n^2)
        SC: O(n)
        */
        int dp[51];
        unordered_set<string> dict(dictionary.begin(), dictionary.end());
        dp[0] = 0;

        for(int i = 0 ; i < s.size() ; ++i){
            // Not use s[i]
            dp[i + 1] = dp[i] + 1;
            // Use s[i] to match strings in dict
            for(int j = 0 ; j <= i ; ++j){
                auto sub = s.substr(j, i - j + 1);
                if(dict.count(sub)) dp[i + 1] = min(dp[i + 1], dp[j]);
            }
        }

        return dp[s.size()];
    }
};