/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        auto size = mountainArr.length();

        // Get top index
        int top_idx = 0, top_val = 0;
        int left = 0, right = size;
        while(left < right){
            auto mid = (left + right) / 2;
            auto val = mountainArr.get(mid);

            top_idx = mid, top_val = val;

            if (mid == 0) left = mid + 1;
            else if (mid == size - 1) right = mid;
            else{
                auto l_val = mountainArr.get(mid - 1);
                auto r_val = mountainArr.get(mid + 1);
                if(l_val < val && val > r_val) break;
                else if (l_val < val) left = mid + 1;
                else right = mid;
            }
        }

        // Target is top
        if(target == top_val) return top_idx;
        // Target on left
        left = 0, right = top_idx;
        while(left < right){
            auto mid = (left + right) / 2;
            auto val = mountainArr.get(mid);
            if(target == val) return mid;
            else if(target < val) right = mid;
            else left = mid + 1;
        }
        // Target on right
        left = top_idx + 1, right = size;
        while(left < right){
            auto mid = (left + right) / 2;
            auto val = mountainArr.get(mid);
            if(target == val) return mid;
            else if(target < val) left = mid + 1;
            else right = mid;
        }

        return -1;
    }
};