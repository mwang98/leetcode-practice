class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        /* Greedy

        */
        int n_deletions = 0;
        auto n_strs = strs.size();
        auto str_len = strs[0].size();
        vector<bool> need_compare(n_strs, true);
        need_compare[0] = false;

        for(int i = 0 ; i < str_len ; ++i){
            char prev = ' ';
            vector<bool> tmp_need_compare = need_compare;

            for(int j = 0 ; j < n_strs ; ++j){
                if(need_compare[j]){
                    if(prev < strs[j][i]){
                        tmp_need_compare[j] = false;
                    } else if(prev > strs[j][i]){
                        n_deletions++;
                        tmp_need_compare = need_compare;
                        break;
                    }
                }
                prev = strs[j][i];
            }
            need_compare = tmp_need_compare;
        }

        return n_deletions;
    }
};