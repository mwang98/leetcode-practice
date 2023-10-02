class Solution {
public:
    bool winnerOfGame(string colors) {
        // Key: Maximum number of removal "not" depends on other's removal 
        auto getRemoveNumber = [&](char tgt) -> int{
            int res = 0;
            for(int i = 1 ; i < colors.size() - 1 ; ++i){
                res += (colors[i-1] == colors[i] && colors[i] == colors[i+1] && colors[i] == tgt);
            }
            return res;
        };

        return getRemoveNumber('A') > getRemoveNumber('B');
    }
};