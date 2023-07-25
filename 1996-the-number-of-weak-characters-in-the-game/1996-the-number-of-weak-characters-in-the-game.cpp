class Solution {
public:
    int numberOfWeakCharacters(vector<vector<int>>& properties) {
        /* Greedy + sorting */

        sort(properties.begin(), properties.end(), [](auto& p1, auto& p2){ 
            if(p1[0] == p2[0]) return p1[1] > p2[1]; // Important !!!
            return p1[0] < p2[0]; });

        int num_weaks = 0;
        int curr_max = 0;
        for(int i = properties.size() - 1 ; i >= 0 ; --i){
            if(properties[i][1] < curr_max) num_weaks++;
            curr_max = max(curr_max, properties[i][1]);
        }

        return num_weaks;
    }
};