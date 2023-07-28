class Solution {
public:
    int minNumberOperations(vector<int>& target) {
        /* Monotonic stack: increased stack 
            When to pop: val <= stack.back()
                Record: the maximum value in stack
            When to push:
                Clearing all elements in stack which is larger than val needs `max_val - val` operations
        */
        int num_ops = 0;
        vector<int> stack;
        stack.reserve(target.size());

        target.push_back(0); // clear all stack

        for(auto val: target){
            auto max_val = 0;
            while(!stack.empty() && val <= stack.back()){ // pop
                max_val = max(max_val, stack.back());
                stack.pop_back();
            }

            if(max_val > 0) num_ops += max_val - val;

            stack.push_back(val); // push
        }

        return num_ops; // the last element in the stack
    }
};