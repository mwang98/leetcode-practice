class Solution {
public:
    int maxDistance(vector<int>& position, int m) {
        /* Binary search for a target value: `Force` */
        sort(position.begin(), position.end());

        auto checker = [&](int force){
            int n_balls = 1;
            int prev = position[0];
            for(auto pos: position){
                if(pos - prev >= force){
                    prev = pos;
                    n_balls++;
                }
            }
            return n_balls >= m;
        };

        int left = 1, right = *max_element(position.begin(), position.end());
        while(left < right){
            auto mid = (left + right) / 2;
            if(checker(mid)) left = mid + 1;
            else right = mid;
        }

        return left - 1;
    }
};