/*
 * @lc app=leetcode id=875 lang=cpp
 *
 * [875] Koko Eating Bananas
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        /* Binary search for answer */
        auto checker = [&](int speed) -> bool {
            // O(n): whether it can eat all bananas within h hourse using `speed`
            int hours = 0;
            for(auto num: piles)
                hours += (num / speed) + ((num % speed > 0));
            return hours <= h;
        };

        int left = 1;
        int right = *max_element(piles.begin(), piles.end());

        while(left < right){
            auto mid = (left + right) / 2;
            if (checker(mid)) right = mid;
            else left = mid + 1;
        }

        return left;
    }
};
// @lc code=end

