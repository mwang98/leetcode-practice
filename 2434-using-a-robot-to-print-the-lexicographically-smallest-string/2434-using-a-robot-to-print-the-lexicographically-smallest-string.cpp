class Solution {
public:
    string robotWithString(string s) {
        // Stack + greedy
        // Greedy choice: always searching for the smallest char after the current position

        // Define variables
        vector<char> stack;
        vector<int> dp(s.size()); // dp[i]: the index of the smallest element in s[i:]
        string res = "";

        // Build dp table
        dp[dp.size() - 1] = dp.size() - 1;
        for(int i = dp.size() - 2 ; i >= 0 ; --i){
            dp[i] = s[i] <= s[dp[i + 1]] ? i : dp[i + 1];
        }

        int curr_idx = 0;       // current indx
        int next_idx = dp[0];   // index for the next smallest char
        for(int i = 0 ; i < s.size() ; ++i){
            if(i < next_idx) continue;

            // Pop queued chars which are smaller or equal to the current smallest char
            while(!stack.empty() && stack.back() <= s[i]) {
                res.push_back(stack.back());
                stack.pop_back();
            }

            // Push chars which are greater than the current smallest char
            while(curr_idx < i) stack.push_back(s[curr_idx++]);

            curr_idx++; // skip the smallest char
            next_idx = i + 1 < dp.size() ? dp[i + 1] : dp.size(); // update index of next smallest char

            res.push_back(s[i]);
        }


        while(!stack.empty()) {
            res.push_back(stack.back());
            stack.pop_back();
        }
        
        return res;
    }
};