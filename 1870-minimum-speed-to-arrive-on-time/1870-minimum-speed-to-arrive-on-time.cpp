class Solution {
public:
    int MAX_VAL = 1e7 + 1;
    int minSpeedOnTime(vector<int>& distances, double hour) {
        /* Binary search for value */
        auto checker = [&](int speed){
            double total_time = 0;
            for(int i = 0 ; i < distances.size() ; ++i){
                double time = (0.0 + distances[i]) / speed;
                if(i == distances.size() - 1) total_time += time;
                else total_time += ceil(time);
            }
            return total_time <= hour;
        };

        int left = 1, right = MAX_VAL;
        while(left < right){
            auto mid = (left + right) / 2;
            if(checker(mid)) right = mid;
            else left = mid + 1;
        }

        return left != MAX_VAL ? left : -1;
    }
};