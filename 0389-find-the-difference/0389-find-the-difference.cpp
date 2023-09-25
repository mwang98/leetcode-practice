class Solution {
public:
    char findTheDifference(string s, string t) {
        int freq[26];
        memset(freq, 0, sizeof(freq));

        for(auto ch: t) freq[ch - 'a']++;
        for(auto ch: s) --freq[ch - 'a'];

        for(int i = 0 ; i < 26 ; ++i) if(freq[i]) return i + 'a';

        return ' ';
    }
};