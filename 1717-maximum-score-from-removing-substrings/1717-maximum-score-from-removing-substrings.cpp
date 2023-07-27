enum Type{
    AB = 0,
    BA
};

class Solution {
public:
    int maximumGain(string s, int x, int y) {
        s += 'z'; // signal to clear whole stack
        int gain = 0;
        vector<char> stack, tmp_stack;

        Type greedy = x > y ? Type::AB : Type::BA;
        int min_point = x > y ? y : x;
        int max_point = x > y ? x : y;

        for(auto ch: s){
            // Clear stack
            if(ch != 'a' && ch != 'b'){
                for(auto ch: stack){
                    if(!tmp_stack.empty() && ch != tmp_stack.back()){
                        gain += min_point;
                        tmp_stack.pop_back();
                    } else tmp_stack.push_back(ch);
                }
                tmp_stack.clear();
                stack.clear();
                continue;
            }
            // Handle substring starting with `a`, `b`
            if(stack.empty() || stack.back() == ch) stack.push_back(ch);
            else if((greedy == Type::AB && ch == 'b') || (greedy == Type::BA && ch == 'a')){
                gain += max_point;
                stack.pop_back();
            } else stack.push_back(ch);
        }

        return gain;
    }
};