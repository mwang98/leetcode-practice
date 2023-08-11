class Solution {
public:
    string removeDuplicateLetters(string s) {
        /* Greedy 
        If s[i] > s[i+1] && s[i] will appear again laters, remove s[i] and keep s[i+1] will always lead to a smaller result in lexicographical order
        */
        vector<char> stack;
        bool seen[26];
        int last_occurrence[26];
        memset(seen, 0, sizeof(seen));
        for(int i = 0 ; i < 26 ; ++i) last_occurrence[i] = -1;
        for(int i = 0 ; i < s.size() ; ++i) last_occurrence[s[i] - 'a'] = i;
        
        for(int i = 0 ; i < s.size() ; ++i){
            if(seen[s[i] - 'a']) continue;
            while(!stack.empty() && 
                  s[i] < stack.back() &&
                  last_occurrence[stack.back() - 'a'] > i){
                seen[stack.back() - 'a'] = false;
                stack.pop_back();
            }
            stack.push_back(s[i]);
            seen[s[i] - 'a'] = true;
        }

        string ret = "";
        for(auto ch: stack) ret += ch;
        return ret;
    }
};