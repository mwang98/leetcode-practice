/*
 * @lc app=leetcode id=97 lang=cpp
 *
 * [97] Interleaving String
 */

// @lc code=start
#include <string>
#include <vector>
using namespace std;
class Solution {
public:
    auto sol_naiive_dp(string s1, string s2, string s3)->bool{
        if (s1.size() == 0) return s2 == s3;
        if (s2.size() == 0) return s1 == s3;
        if (s1.size() + s2.size() != s3.size()) return false;

        vector<vector<bool>> dp(s1.size() + 1, vector<bool>(s2.size() + 1, false));

        // dp[i][j]: s3[:i+j) is an interleaving of s1[:i), s2[:j)
        // dp[i][j] = dp[i-1][j] if (s1[i-1] == s3[i+j-1]) || dp[i][j-1] if (s2[j-1] == s3[i+j-1])
        for (int i = 0; i <= s1.size(); ++i){
            for (int j = 0; j <= s2.size(); ++j) {
                if (i == 0 && j == 0) dp[i][j] = true;
                else if (j == 0) dp[i][j] = (s1[i - 1] == s3[i - 1]) && dp[i - 1][j];
                else if (i == 0) dp[i][j] = (s2[j - 1] == s3[j - 1]) && dp[i][j - 1];
                else{
                    if (s1[i - 1] == s3[i - 1 + j]) dp[i][j] = dp[i][j] | dp[i - 1][j];
                    if (s2[j - 1] == s3[i + j - 1]) dp[i][j] = dp[i][j] | dp[i][j - 1];
                }
            }
        }

        return dp[s1.size()][s2.size()];
    }

    auto sol_n_sc_dp(string s1, string s2, string s3) -> bool {
        if (s1.size() == 0) return s2 == s3;
        if (s2.size() == 0) return s1 == s3;
        if (s1.size() + s2.size() != s3.size()) return false;

        vector<bool> dp(s2.size() + 1, false);

        // dp[i][j]: s3[:i+j) is an interleaving of s1[:i), s2[:j)
        // dp[i][j] = dp[i-1][j] if (s1[i-1] == s3[i+j-1]) || dp[i][j-1] if (s2[j-1] == s3[i+j-1])
        // dp[i][j] only depends on dp[i-1][j] -> previous state   (dp[j])
        //                          dp[i][j-1] -> previous element (dp[j-1])
        for (int i = 0; i <= s1.size(); ++i) {
            for (int j = 0; j <= s2.size(); ++j) {
                if (i == 0 && j == 0) dp[j] = true;
                else if (j == 0) dp[j] = (s1[i - 1] == s3[i - 1]) && dp[j];
                else if (i == 0) dp[j] = (s2[j - 1] == s3[j - 1]) && dp[j - 1];
                else 
                    dp[j] = (s1[i - 1] == s3[i - 1 + j] && dp[j]) ||
                            (s2[j - 1] == s3[i + j - 1] && dp[j-1]);
            }
        }

        return dp[s2.size()];
    }

    bool isInterleave(string s1, string s2, string s3) {
        return sol_naiive_dp(s1, s2, s3);
    }
};
// @lc code=end
