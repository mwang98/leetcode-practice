/*
 * @lc app=leetcode id=1312 lang=cpp
 *
 * [1312] Minimum Insertion Steps to Make a String Palindrome
 */

// @lc code=start
#include <string>
using namespace std;
class Solution {
public:
    int minInsertions(string s) {
        /* DP
        Def: dp[i][j]: the minimum insertion to make s[i:j] palindromic
        Transition
            s[i] == s[j]: dp[i+1][j-1]
            s[i] != s[j]
                insert s[i]: 1 + dp[i+1][j]
                insert s[j]: 1 + dp[i][j-1]
        */
        int dp[500][500];
        memset(dp, 0, sizeof(dp));
        auto size = s.size();

        for (int i = size - 1; i >= 0; --i){
            for (int j = i; j < size; ++j){
                // Base case
                if (i == j) dp[i][j] = 0;
                else if(s[i] == s[j]) dp[i][j] = dp[i + 1][j - 1];
                else dp[i][j] = 1 + min(dp[i + 1][j], dp[i][j - 1]);
            }
        }

        return dp[0][size - 1];
    }
};
// @lc code=end

