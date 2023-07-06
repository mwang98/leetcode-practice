class Solution {
public:
    bool isValidPalindrome(string s, int k) {
        /* DP
        Def: dp[i][j][k]: whether s[i:j] is a k-palindrome
        Transition:
            s[i] == s[j]
                dp[i][j][k] = dp[i+1][j-1][k]
            s[i] != s[j]
                dp[i][j][k] = dp[i+1][j][k-1] || dp[i][j-1][k-1]
        
        == Find palindromic subsequence with length >= N-k
        Def: dp[i][j]: the longest palindromic subseq of s[i:j]
        Transition:
            s[i] == s[j]
                dp[i][j] = dp[i+1][j-1] + 2
            s[i] != s[j]
                dp[i][j] = max(dp[i+1][j], dp[i][j-1])
        */
        int dp[1000][1000];
        memset(dp, 0, sizeof(dp));
        auto size = s.size();
        for(int i = size - 1 ; i >=0 ; --i){
            for(int j = i ; j < size ; ++j){
                if(i == j) dp[i][j] = 1;
                else{
                    if(s[i] == s[j])
                        dp[i][j] = dp[i+1][j-1] + 2;
                    else
                        dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
                }
            }
        }

        return dp[0][size-1] >= size - k;
    }
};