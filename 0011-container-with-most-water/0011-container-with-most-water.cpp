class Solution {
public:
    int maxArea(vector<int>& height) {
        /* Two ponters */
        int max_water = 0;
        int left = 0, right = height.size() - 1;

        while(left < right){
            int width = right - left;
            max_water = max(max_water, width * min(height[left], height[right]));

            if(height[left] < height[right]) left++;
            else right--;
        }

        return max_water;
    }
};