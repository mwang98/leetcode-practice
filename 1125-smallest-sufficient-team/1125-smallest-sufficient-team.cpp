/*
 * @lc app=leetcode id=1125 lang=cpp
 *
 * [1125] Smallest Sufficient Team
 */

// @lc code=start
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;
class Solution {
   public:
    unordered_map<string, int> mapping;
    int req_skills_mask = 0;
    int dp[60][1 << 16];
    bool choice[60][1 << 16];

    int solve(vector<int>& people, int i = 0, int mask = 0) {
        // Base case
        if (i == people.size() && mask == req_skills_mask) return 0;
        if (i == people.size() && mask != req_skills_mask) return 17;
        if (dp[i][mask] != -1) return dp[i][mask];
        // Recursive case
        int n_not_select = solve(people, i + 1, mask);
        int n_select = 1 + solve(people, i + 1, mask | people[i]);
        
        if (n_select < n_not_select) choice[i][mask] = true;

        return dp[i][mask] = min(n_not_select, n_select);
    }
    vector<int> smallestSufficientTeam(vector<string>& req_skills, vector<vector<string>>& people) {
        /* Bitmask dp
        Def: dp[i][mask]: the size of smallest sufficient team with people[i:] given `mask` skills are satisfied
        Transition
            1) o select: dp[i+1][mask | people[i]]
            2) x select: dp[i+1][mask]
        */
       
        // Init dp table
        memset(choice, 0, sizeof(choice));
        for (int i = 0; i < 60; ++i)
            for (int j = 0; j < (1 << 16); ++j) dp[i][j] = -1;
        // Build mask
        vector<int> people_mask(people.size(), 0);
        req_skills_mask = (1 << req_skills.size()) - 1;
        for (int i = 0; i < req_skills.size(); ++i) mapping[req_skills[i]] = i;
        for (int i = 0; i < people.size(); ++i)
            for (const auto& skill : people[i])
                people_mask[i] = people_mask[i] | (1 << (mapping[skill]));
        // Solve
        solve(people_mask);
        vector<int> res;
        for (int i = 0, mask = 0; i < people_mask.size(); ++i) {
            if (choice[i][mask]) {
                mask |= people_mask[i];
                res.push_back(i);
            }
            if (mask == req_skills_mask) break;
        }
        return res;
    }
};
// @lc code=end
