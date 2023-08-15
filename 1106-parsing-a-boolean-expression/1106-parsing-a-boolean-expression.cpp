class Solution {
public:
    unordered_set<char> operations = {'&', '|', '!'};
    bool evaluate(const vector<bool>& subexprs, char op){
        bool ret = op == '|' ? false : true;
        if(op == '&') for(auto expr: subexprs) ret &= expr;
        else if(op == '|') for(auto expr: subexprs) ret |= expr;
        return op == '!' ? !subexprs[0] : ret;
    }

    bool parseBoolExpr(string expression) {
        vector<int> stack;

        for(auto ch: expression){
            if(operations.count(ch) || ch == '(') stack.push_back(ch);
            else if(ch == 't') stack.push_back(true);
            else if(ch == 'f') stack.push_back(false);
            else if(ch == ')'){
                vector<bool> subexprs;
                while(stack.back() != '('){
                    subexprs.push_back(stack.back());
                    stack.pop_back();
                }
                auto op = stack[stack.size() - 2];
                stack.pop_back(); // pop `(`
                stack.pop_back(); // pop operator
                stack.push_back(evaluate(subexprs, op));
            }
        }

        return stack[0];
    }
};