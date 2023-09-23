class Solution {
public:
    int longestStrChain(vector<string>& words) {
        /* DP 
        Def: dp[i]: longest word chain ending at words[i]
        Transition:
            dp[i] = 1 + max(dp[j]) for all j where words[j] is a predecessor of words[i] (hashamp)
        TC: O(nlogn)
        SC: O(n)
        */
        int res = 0;
        int dp[1001];

        // Init dp table
        memset(dp, 0 ,sizeof(dp));
        dp[0] = 1;

        sort(words.begin(), words.end(), [](const auto& lhs, const auto& rhs) { 
            return lhs.size() < rhs.size(); 
        });
        unordered_map<string, int> lookup; // words[i], i

        for(int i = 0 ;  i < words.size() ; ++i){
            int longest_chain = 0;
            const auto& str = words[i];
            for(int j = 0 ; j < words[i].size() ; ++j){
                string s = str.substr(0, j) + str.substr(j + 1, str.size() - j - 1);
                if(!lookup.count(s)) continue;
                longest_chain = max(longest_chain, dp[lookup[s] + 1]);
            }

            dp[i + 1] = longest_chain + 1;
            lookup[str] = i;
            res = max(res, dp[i + 1]);
        }

        return res;
        
    }
};