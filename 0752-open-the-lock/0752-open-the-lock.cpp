class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        bool visited[10][10][10][10];
        unordered_set<string> not_allowed(deadends.begin(), deadends.end());
        queue<string> q;

        // Edge case
        if(not_allowed.count("0000")) return -1;

        memset(visited, false, sizeof(visited));
        visited[0][0][0][0] = true;
        q.push("0000");

        int level = 0;
        while(!q.empty()){
            for(int i = 0, size = q.size() ; i < size ; ++i){
                auto str = q.front();
                q.pop();

                if(str == target) return level;

                for(int i = 0 ; i < str.size() ; ++i){
                    auto tmp = str;
                    // Increment
                    tmp[i] = (tmp[i] - '0' + 1) % 10 + '0';
                    if(!visited[tmp[0] - '0'][tmp[1] - '0'][tmp[2] - '0'][tmp[3] - '0'] && 
                       not_allowed.count(tmp) == 0){
                        visited[tmp[0] - '0'][tmp[1] - '0'][tmp[2] - '0'][tmp[3] - '0'] = true;
                        q.push(tmp);
                    }
                    // Decrement
                    tmp = str;
                    tmp[i] = (tmp[i] - '0' + 10 - 1) % 10 + '0';
                    if(!visited[tmp[0] - '0'][tmp[1] - '0'][tmp[2] - '0'][tmp[3] - '0'] && 
                       not_allowed.count(tmp) == 0){
                        visited[tmp[0] - '0'][tmp[1] - '0'][tmp[2] - '0'][tmp[3] - '0'] = true;
                        q.push(tmp);
                    }
                }
            }
            level++;
        }

        return -1;
    }
};