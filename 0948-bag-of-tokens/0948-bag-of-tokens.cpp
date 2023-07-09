/*
 * @lc app=leetcode id=948 lang=cpp
 *
 * [948] Bag of Tokens
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(), tokens.end());
        int score = 0;
        int left = 0, right = tokens.size() - 1;

        while(left <= right){
            if(power >= tokens[left]){
                power -= tokens[left];
                score++;
                left++;
            } else {
                if(score < 1) return 0; // gain power only if `score` is at least one
                power += (tokens[right] - tokens[left]);
                right--;
                left++;
            }
        }

        return score;
    }
};
// @lc code=end

