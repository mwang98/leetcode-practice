/*
 * @lc app=leetcode id=1094 lang=cpp
 *
 * [1094] Car Pooling
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<pair<int, int>> locations(trips.size() * 2);
        for (int i = 0; i < trips.size(); ++i){
            locations[i] = {trips[i][1], trips[i][0]};
            locations[i+trips.size()] = {trips[i][2], -trips[i][0]};
        }
        sort(locations.begin(), locations.end(), [](const auto& p1, const auto& p2) { 
            if(p1.first != p2.first) return p1.first < p2.first;
            return p1.second < p2.second;
        });

        int curr_pessengers = 0;
        for (const auto& [loc, n_pass]: locations){
            curr_pessengers += n_pass;
            if (curr_pessengers > capacity) return false;
        }
        return true;
    }
};
// @lc code=end

