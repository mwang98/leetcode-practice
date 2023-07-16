class Solution {
public:
    long long numberOfWeeks(vector<int>& milestones) {
        /* Greedy */
        long long sum_works = accumulate(milestones.begin(), milestones.end(), 0l);
        int max_works = *max_element(milestones.begin(), milestones.end());

        sum_works -= max_works;
        if(sum_works >= max_works) return sum_works + max_works;
        return sum_works * 2 + 1;   
    }   
};