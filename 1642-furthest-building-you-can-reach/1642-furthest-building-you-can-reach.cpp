class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        /* Binary search for index */
        // Define pointers
        int left = 0, right = heights.size();

        // Define checker function
        auto checker = [&](int idx) -> bool {
            // O(nlogn)
            long long n_bricks_need = 0;
            vector<int> diff;
            for(int i = 1 ; i <= idx ; ++i){
                if(heights[i] - heights[i - 1] > 0) diff.emplace_back(heights[i] - heights[i - 1]);
            }
            sort(diff.begin(), diff.end());
            for(int i = 0 ; i < (int)diff.size() - ladders ; ++i){
                n_bricks_need += diff[i];
            }
            return n_bricks_need <= bricks;
        };

        // O(nlog^2n)
        while(left < right){
            auto mid = (left + right) / 2;
            if(checker(mid)) left = mid + 1;
            else right = mid;
        }

        return left - 1;
    }
};