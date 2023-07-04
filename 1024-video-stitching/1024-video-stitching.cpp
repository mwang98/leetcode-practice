/*
 * @lc app=leetcode id=1024 lang=cpp
 *
 * [1024] Video Stitching
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution {
public:
    int videoStitching(vector<vector<int>>& clips, int time) {
        /* Greedy 
        */
        // Sort by start time
        sort(clips.begin(), clips.end(), [](const auto& v1, const auto& v2) { return v1[0] < v2[0]; });

        // Binary search
        auto search = [&](int start, int target) -> int {
            // Search for the rightmost index s.t. `target` <= start time
            // E.g., target = 4
            // End time: 1, 1, 2, 2, 4, 4, 5
            //                          |
            int left = start, right = clips.size();
            while(left < right){
                auto mid = (left + right) / 2;
                if (clips[mid][0] <= target)
                    left = mid + 1;
                else
                    right = mid;
            }
            return left - 1;
        };

        int num_clips = 0;
        int start_idx = 0;
        int end_time = 0;
        while (true) {
            auto idx = search(start_idx, end_time);

            if (idx == start_idx - 1) return -1; // next clip not found

            auto clip_it = max_element(clips.begin() + start_idx, clips.begin() + idx + 1, [](const auto& v1, const auto& v2) { return v1[1] < v2[1]; });
            start_idx = distance(clips.begin(), clip_it) + 1;
            end_time = (*clip_it)[1];
            num_clips++;

            if (end_time >= time) return num_clips;  // reach the end
            if (start_idx == clips.size()) return -1; // clips not found
        }

        return num_clips;
    }
};
// @lc code=end

