class Solution {
public:
    int shortestSequence(vector<int>& rolls, int k) {
        // Greedy
        int seq_len = 0;
        int idx = 0 ;
        unordered_set<int> records; // value appears in the interval rolls (idx1:idx2]
                                    // where idx1 = the minimum index s.t. sequence of len k -1 is satisfied
                                    //       idx2 = the minimum index s.t. sequence of len k is satisfied

        while(idx < rolls.size()){
            records.insert(rolls[idx++]);

            // All values are collected
            if(records.size() == k) {
                seq_len++;
                records.clear();
            }
        }

        return seq_len + 1;
    }
};