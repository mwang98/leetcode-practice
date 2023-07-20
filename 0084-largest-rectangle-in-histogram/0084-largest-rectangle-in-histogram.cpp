class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        /* Monotonic stack */
        int max_area = 0;
        vector<int> stack(1, {-1}); // index (increasing)

        for(int i = 0 ; i < heights.size() ; ++i){
            while(stack.size() > 1 && heights[stack.back()] >= heights[i]){
                auto curr_height = heights[stack.back()];
                stack.pop_back();

                auto curr_width = i - stack.back() - 1; // open-open interval
                max_area = max(max_area, curr_height * curr_width);
            }
            stack.push_back(i);
        }

        // Increasing
        while(stack.size() > 1){
            auto curr_height = heights[stack.back()]; 
            stack.pop_back();
            
            int curr_width = heights.size() - stack.back() - 1;
            max_area = max(max_area, curr_height * curr_width);
        }

        return max_area;
    }
};