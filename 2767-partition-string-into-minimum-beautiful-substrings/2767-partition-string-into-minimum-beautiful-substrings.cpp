class Solution {
public:
    string str;
    int INIT_PART = 16;
    int min_partitions = 16;
    unordered_set<string> power5 {"11110100001001", "110000110101", "1001110001",
                                  "1111101", "11001", "101", "1"};

    void backtrack(int i = 0, int n_part = 0){
        // Base case
        if(i == str.size()){
            min_partitions = min(min_partitions, n_part); 
            return;
        } else if(str[i] == '0') return; // leading zero

        // Recursive case
        for(int j = i + 1 ; j <= str.size() ; ++j){
            if(power5.count(str.substr(i, j - i))){
                cout << str.substr(i, j - i) << endl;
                backtrack(j, n_part + 1);
            }
        }
    }
    int sol_backtrack(string s) {
        str = s;
        backtrack();

        return min_partitions == INIT_PART ? -1 : min_partitions;
    }
    int sol_dp(string s) {
        /* DP
        Def: dp[i] = the minimum number of substring in such partition of s[:i)
        Transition:
            dp[i] = min(dp[i], dp[k] + 1) where s[k+1], ..., s[i] is power of 5
        TC: O(n^2)
        SC: O(n)
        */
        // Edge case
        if(s[0] == '0') return -1;

        // Init dp table
        int dp[16];
        for(int i = 0 ; i < 16 ; ++i) dp[i] = INIT_PART;
        dp[0] = 0, dp[1] = 1;

        for(int i = 1 ; i < s.size() ; ++i){
            for(int k = 0 ; k <= i ; ++k){
                if(power5.count(s.substr(k, i + 1 - k))){
                    dp[i + 1] = min(dp[i + 1], dp[k] + 1);
                }
            }
        }

        return dp[s.size()] == INIT_PART ? -1 : dp[s.size()];
    }
    int minimumBeautifulSubstrings(string s) {
        return sol_dp(s);
    }
};