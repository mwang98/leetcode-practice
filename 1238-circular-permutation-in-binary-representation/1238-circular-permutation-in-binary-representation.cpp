class Solution {
public:
    int n_val;
    bool visited[65536]; // 2^16
    bool backtrack(int val, vector<int>& result){
        // base case
        if(result.size() == 1 << n_val) return true;
        // recursive case
        for(int i = 0 ; i < n_val ; ++i){
            //     010
            // XOR 100 = 110
            auto new_val = val ^ (1 << i);
            if(!visited[new_val]){
                visited[new_val] = true;
                result.push_back(new_val);
                if(backtrack(new_val, result)) return true;
                visited[new_val] = false;
                result.pop_back();
            }
        }
        return false;
    }
    vector<int> circularPermutation(int n, int start) {
        /* Backtracking
        TC: O(n*2^n)
            Permutation length: 2^n
            Choice of each element: n-1
        SC: O(n*2^n)
        */
        n_val = n;
        vector<int> result;
        visited[start] = true;
        result.push_back(start);
    
        backtrack(start, result);
        return result;
    }
};