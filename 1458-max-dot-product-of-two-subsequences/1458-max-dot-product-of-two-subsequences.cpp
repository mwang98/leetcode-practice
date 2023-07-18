class Solution {
public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        /* DP 
        Def: dp[i][j]: the maximum dot product of two subsequences from nums1[:i] and nums2[:j]
        Transition:
            dp[i][j] = max(dp[i-1][j], dp[i][j-1], dp[i-1][j-1] + nums1[i] * nums2[j], nums1[i] * nums2[j])
        */
        int dp[500][500];
        auto m = nums1.size(), n = nums2.size();
        for(int i = 0 ; i < 500 ; ++i)
            for(int j = 0 ; j < 500 ; ++j)
                dp[i][j] = -1e9;


        for(int i = 0 ; i < m ; ++i){
            for(int j = 0 ; j < n ; ++j){
                dp[i][j] = nums1[i] * nums2[j];
                if(i > 0 && j > 0) dp[i][j] = max(dp[i][j], dp[i-1][j-1] + nums1[i] * nums2[j]);
                if(i > 0) dp[i][j] = max(dp[i][j], dp[i-1][j]);
                if(j > 0) dp[i][j] = max(dp[i][j], dp[i][j-1]);
            }
        }

        return dp[m-1][n-1];
    }
};