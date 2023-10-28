class Solution {
public:
    int compress(vector<char>& chars) {
        int idx = 0; // index allow to fill
        char prev = chars[0];
        int cnt = 1; // # of consecutive chars

        for(int i = 1 ; i < chars.size() ; ++i){
            if(chars[i] == prev) {
                cnt++;
            } else {
                // Record previous char
                auto tmp = chars[i];
                chars[idx++] = prev;
                if(cnt != 1) {
                    if(cnt / 1000) {
                        chars[idx++] = '0' + cnt / 1000; cnt %= 1000;
                        chars[idx++] = '0' + cnt / 100; cnt %= 100;
                        chars[idx++] = '0' + cnt / 10; cnt %= 10;
                        chars[idx++] = '0' + cnt;
                    } else if(cnt / 100) {
                        chars[idx++] = '0' + cnt / 100; cnt %= 100;
                        chars[idx++] = '0' + cnt / 10; cnt %= 10;
                        chars[idx++] = '0' + cnt;
                    } else if(cnt / 10) {
                        chars[idx++] = '0' + cnt / 10; cnt %= 10;
                        chars[idx++] = '0' + cnt;
                    } else if(cnt) {
                        chars[idx++] = '0' + cnt;
                    }
                }
                prev = tmp;
                cnt = 1;
            }
        }

        chars[idx++] = prev;
        if(cnt == 1) return idx;
        if(cnt / 1000) {
            chars[idx++] = '0' + cnt / 1000; cnt %= 1000;
            chars[idx++] = '0' + cnt / 100; cnt %= 100;
            chars[idx++] = '0' + cnt / 10; cnt %= 10;
            chars[idx++] = '0' + cnt;
        } else if(cnt / 100) {
            chars[idx++] = '0' + cnt / 100; cnt %= 100;
            chars[idx++] = '0' + cnt / 10; cnt %= 10;
            chars[idx++] = '0' + cnt;
        } else if(cnt / 10) {
            chars[idx++] = '0' + cnt / 10; cnt %= 10;
            chars[idx++] = '0' + cnt;
        } else if(cnt) {
            chars[idx++] = '0' + cnt;
        }
        return idx;
    }
};