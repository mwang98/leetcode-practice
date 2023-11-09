class Solution {
public:
    int countHomogenous(string s) {
        // Sliding window
        // Move right: substr is homogenous
        // Move left: substr is no longer homonenous

        int res = 0;
        int MOD = 1e9 + 7;
        int left = 0, right = 0;
        while(right < s.size()){
            right++;

            auto prev_left = left;
            while(s[left] != s[right]){
                res = (res + (++left - prev_left)) % MOD;
            }
        }

        return res;
    }
};