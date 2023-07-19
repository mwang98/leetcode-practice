class Solution {
public:
    int longestIdealString(string s, int k) {
        /* DP 
        Def: dp[i]: the longest ideal subseq ending with s[i]
        Transition:
            TC can be optimized through hash table where table[ch] = idx (store the largest = latest idx)
            dp[i] = 1 + dp[j] where the distance between nums[i] and nums[j] is <= k 
        TC: O(n * 25)
        SC: O(n + 26) -> O(26)
        */

        int hashtable[26]; // longest ideal subseq ending with `i + 'a'`
        int ret = 0;
        for(int i = 0 ; i < 26 ; ++i) hashtable[i] = -1;

        for(auto ch: s){
            int prev_subseq = 0;
            for(int j = ch - k ; j <= ch + k ; ++j){
                if(j < 'a' || j > 'z') continue;
                prev_subseq = max(prev_subseq, hashtable[j - 'a']);
            }
            hashtable[ch - 'a'] = 1 + prev_subseq;
            ret = max(ret, hashtable[ch - 'a']);
        }

        return ret;
    }
};