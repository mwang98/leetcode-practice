/*
 * @lc app=leetcode id=2024 lang=cpp
 *
 * [2024] Maximize the Confusion of an Exam
 */

// @lc code=start
#include <string>
using namespace std;
class Solution {
   public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        /* Sliding window
        |    | -> optimal sol
          ||   -> never become a sol (since it's shorter)
        TC: O(n)
        SC: O(1)
        */
        int max_consec = 0;

        // Consecutive T
        int left = 0, right = 0;
        int tmp_k = k;
        while (right < answerKey.size()) {
            tmp_k -= answerKey[right++] == 'F';
            while (left < answerKey.size() && tmp_k < 0) {
                tmp_k += answerKey[left++] == 'F';
            }
            max_consec = max(max_consec, right - left);
        }

        // Consecutive F
        left = right = 0;
        tmp_k = k;
        while (right < answerKey.size()) {
            tmp_k -= answerKey[right++] == 'T';
            while (left < answerKey.size() && tmp_k < 0) {
                tmp_k += answerKey[left++] == 'T';
            }
            max_consec = max(max_consec, right - left);
        }

        return max_consec;
    }
};
// @lc code=end