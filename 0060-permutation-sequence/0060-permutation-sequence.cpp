class Solution {
public:
    string getPermutation(int n, int k) {
        auto naiive_sol = [&]() -> string {
            // O(n!)
            vector<string> permutations;
            string tmp = "";

            function<void(int, string& res)> backtrack = [&](int mask, string& res) -> void {
                // Base case
                if(mask == (1 << n) - 1) {
                    permutations.push_back(res);
                    return;
                }
                // Recursive case
                for(int i = 0 ; i < n ; ++i){
                    if(mask & (1 << i)) continue;
                    res.push_back('1' + i);
                    backtrack(mask | 1 << i, res);
                    res.pop_back();
                }
            };

            backtrack(0, tmp);
            return permutations[k - 1];
        };

        auto lookup_sol = [&]() -> string{
            // Build factorial lookup
            vector<int> fact(10, 1);
            for(int i = 2 ; i <= 9 ; ++i) fact[i] = fact[i-1] * i;

            k--; // 1-based -> 0-based
            int mask = 0;
            string res = "";

            // O(n^2)
            while(mask != (1 << n) - 1){
                auto base = fact[n - res.size() - 1];
                auto group = k / base;
                k %= base;

                for(int i = 0 ; i < n ; ++i) {
                    // Skip number already selected
                    if(mask & 1 << i) continue;

                    if(group-- == 0) {
                        res.push_back('1' + i);
                        mask |= 1 << i;
                        break;
                    }
                }
            }

            return res;
        };


        return lookup_sol();
    }
};