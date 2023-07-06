/*
 * @lc app=leetcode id=2075 lang=cpp
 *
 * [2075] Decode the Slanted Ciphertext
 */

// @lc code=start
#include <string>
using namespace std;
class Solution {
   public:
    auto get_num_cols(const string& encodedText, int rows) -> int {
        return encodedText.size() / rows;
    }
    void rm_tailing_space(string& text){
        text.erase(find_if(text.rbegin(), text.rend(), [](unsigned char ch) {
                       return !std::isspace(ch); 
                    }).base(),
                   text.end());
    }
    string decodeCiphertext(string encodedText, int rows) {
        auto cols = get_num_cols(encodedText, rows);
        string ret = "";

        for (int i = 0; i < cols; ++i) {
            for (int j = 0; j < rows; ++j) {
                auto idx = i + (j * (cols + 1));

                if (idx >= encodedText.size()) {
                    rm_tailing_space(ret);
                    return ret;
                }
                ret += encodedText[idx];
            }
        }

        rm_tailing_space(ret);
        return ret;
    }
};
// @lc code=end
