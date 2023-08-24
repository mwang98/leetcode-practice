class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        /* DP + hashmap
        Def: dp[i]: the number of binary trees we can make by using arr[:i] with arr[i] as root
        Transition: 
            dp[i] = 1 + dp[j] * dp[k] for j, k < i where arr[j] * arr[k] = arr[i]
        TC: O(n^2) 
        SC: O(n)
        */
        int MOD = 1e9 + 7;
        int ret = 0;
        unordered_map<int, int> val2idx; // (number, index) record all number available
        int dp[1000];

        for(int i = 0 ; i < 1000 ; ++i) dp[i] = 1;
        sort(arr.begin(), arr.end());

        for(int i = 0 ; i < arr.size() ; ++i){
            for(int j = 0 ; j < i ; ++j){
                if(auto val = arr[i] / arr[j]; val * arr[j] == arr[i] && val2idx.count(val)){
                    auto k = val2idx[val];
                    dp[i] = ((0L + dp[j]) * dp[k] + dp[i]) % MOD;
                }
            }
            ret = (ret + dp[i]) % MOD;
            val2idx[arr[i]] = i;
        }

        return ret;
    }
};