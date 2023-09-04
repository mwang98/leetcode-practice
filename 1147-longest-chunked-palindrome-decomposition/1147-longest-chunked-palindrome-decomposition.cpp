class Solution {
public:
    int longestDecomposition(string text) {
        /* DP
        Def: dp[i][j]: the longest decomp of a given string `text[i:j]`
        Transition:
            enumerate all prefix & suffix of different length
            prefix = text[i: i+len], suffix = text[j-len: j]
            if(prefix == suffix)
                dp[i][j] = max(dp[i][j], 2 + dp[i+len][j-len])
        TC: O(n^2)
        SC: O(n^2)
        */

        int dp[1001][1001];
        memset(dp, -1, sizeof(dp));

        function<int(int, int)> topdown = [&](int i, int j) -> int {
            // Base case
            if(i > j) return 0;
            if(dp[i][j] != -1) return dp[i][j];
            // Recursive case
            int res = 1; // at least 1 partition
            for(int offset = 0 ; i + offset < j - offset ; ++offset){
                auto prefix = text.substr(i, offset + 1);
                auto suffix = text.substr(j - offset, offset + 1);
                if(prefix == suffix) res = max(res, 2 + topdown(i + offset + 1, j - offset - 1));
            }

            return dp[i][j] = res;
        };

        return topdown(0, text.size() - 1);
    }
};