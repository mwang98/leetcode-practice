/*
 * @lc app=leetcode id=1638 lang=cpp
 *
 * [1638] Count Substrings That Differ by One Character
 */

// @lc code=start
#include <string>
using namespace std;
class Solution {
public:
    int countSubstrings(string s, string t) {
        /* DP
        Def:
            dp0[i][j]: the number of substrings endding with s[i] and t[j] are equal
            dp1[i][j]: the number of substrings endding with s[i] and t[j] are differd by 1
        Transition
            s[i] == t[j]
                dp0[i][j] = 1 + dp0[i-1][j-1]
                dp1[i][j] = dp1[i-1][j-1]
            s[i] != t[j]
                dp0[i][j] = 0
                dp1[i][j] = 1 + dp0[i-1][j-1]
        */
        int dp0[101][101];
        int dp1[101][101];
        int ans = 0;
        memset(dp0, 0, sizeof(dp0));
        memset(dp1, 0, sizeof(dp1));

        for (int i = 0; i < s.size(); ++i){
            for (int j = 0; j < t.size(); ++j){
                if(s[i] == t[j]){
                    dp0[i + 1][j + 1] = 1 + dp0[i][j];
                    dp1[i + 1][j + 1] = dp1[i][j];
                } else {
                    dp0[i + 1][j + 1] = 0;
                    dp1[i + 1][j + 1] = 1 + dp0[i][j];
                }
                ans += dp1[i + 1][j + 1];
            }
        }

        return ans;
    }
};
// @lc code=end