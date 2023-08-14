class Solution {
public:
    int balancedString(string s) {
        unordered_map<char, int> counter;
        unordered_map<char, int> target = {{'Q', 0}, {'W', 0}, {'E', 0}, {'R', 0}};
        unordered_map<char, int> current = {{'Q', 0}, {'W', 0}, {'E', 0}, {'R', 0}};
        int left = 0, right = 0;
        int min_substr = INT_MAX;

        auto satisfy = [&]() -> bool{
            for(auto [key, val]: current)
                if(val < target[key]) return false;
            return true;
        };

        for(auto ch: s) counter[ch]++;
        for(auto [key, val]: counter){
            if(val > (s.size() / 4)) target[key] = val - (s.size() / 4);
        }

        while(right < s.size()){
            current[s[right++]]++;
            while(satisfy()){
                min_substr = min(min_substr, right - left);
                current[s[left++]]--;
            }
        }

        return min_substr;

    }
};