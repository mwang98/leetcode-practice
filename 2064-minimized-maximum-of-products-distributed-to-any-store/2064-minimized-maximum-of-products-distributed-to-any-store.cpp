class Solution {
public:
    int minimizedMaximum(int n, vector<int>& quantities) {
        /* Binary search for a value */
        int left = 1, right = *max_element(quantities.begin(), quantities.end()) + 1;

        auto checker = [&](int max_num) -> bool {
            int n_dist = 0;
            for(auto q: quantities){
                n_dist += (q % max_num != 0);
                n_dist += q / max_num;
            }
            return n_dist <= n;
        };

        while(left < right){    
            auto mid = (left + right) / 2;
            if(checker(mid)) right = mid;
            else left = mid + 1;
        }
        return left;
    }
};