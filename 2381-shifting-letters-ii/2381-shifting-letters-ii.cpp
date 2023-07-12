/*
 * @lc app=leetcode id=2381 lang=cpp
 *
 * [2381] Shifting Letters II
 */

// @lc code=start
#include <string>
#include <vector>
using namespace std;
class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
       /* Line sweep algo 
        Line sweep:
        (1) update a range of interval with a value in O(1)
        (2) compute final answer after all updates using prefix sum O(n)
        TC: O(n)
        SC: O(n)
       */
        vector<int> line(s.size() + 1, 0);

        for(const auto& shift: shifts){
            auto start = shift[0], end = shift[1], direction = shift[2];
            if (direction == 0) {  // backward
                line[start]--;
                line[end + 1]++;
            } else{ // forward
                line[start]++;
                line[end + 1]--;
            }
        }


        for (int i = 0; i < s.size(); ++i){
            if (i > 0) line[i] += line[i - 1];
            int offset = ((s[i] - 'a' + line[i]) % 26 + 26) % 26;
            s[i] = 'a' + offset;
        }

        return s;
    }
};
// @lc code=end