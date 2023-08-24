class Solution {
public:
    int minimumEffort(vector<vector<int>>& tasks) {
        /* Greedy + sorting (Sort by difference) */
        sort(tasks.begin(), tasks.end(), [](const auto& v1, const auto& v2) { 
            return (v1[1] - v1[0]) > (v2[1] - v2[0]); 
        });

        int ret = 0;
        int curr_effort = 0;
        for(const auto& task: tasks){
            auto actual = task[0], minimum = task[1];
            if(curr_effort < minimum){
                ret += (minimum - curr_effort);
                curr_effort = minimum;
            }
            curr_effort -= actual;
        }

        return ret;
    }
};