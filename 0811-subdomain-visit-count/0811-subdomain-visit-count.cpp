/*
 * @lc app=leetcode id=811 lang=cpp
 *
 * [811] Subdomain Visit Count
 */

// @lc code=start
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;
class Solution {
public:
    vector<string> split(const string& s) {
        vector<string> tokens;
        string temp;
        for (char c : s) {
            if (c == ' ' || c == '.') {
                if (!temp.empty()) {
                    tokens.push_back(temp);
                    temp.clear();
                }
            } else {
                temp += c;
            }
        }
        if (!temp.empty()) {
            tokens.push_back(temp);
        }
        return tokens;
    }

    vector<string> subdomainVisits(vector<string>& cpdomains) {
        unordered_map<string, int> counter;
        vector<string> ret;
        for (auto cp : cpdomains) {
            string str = "";
            auto tokens = split(cp);
            auto n_rep = stoi(tokens[0]);
            for (int i = tokens.size() - 1; i >= 1 ; --i) {
                str = i == (tokens.size() - 1) ? tokens[i] : (tokens[i]) + "." + str;
                counter[str] += n_rep;
            }
        }

        for(const auto& [key, val]: counter){
            ret.emplace_back(to_string(val) + " " + key);
        }

        return ret;
    }
};
// @lc code=end
