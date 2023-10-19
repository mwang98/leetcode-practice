/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class NestedIterator {
public:
    vector<NestedInteger> stack;
    NestedIterator(vector<NestedInteger> &nestedList) {
        reverse(nestedList.begin(), nestedList.end());
        for(const auto& ni: nestedList){
            stack.push_back(ni);
        }
    }
    
    int next() {
        auto res = stack.back().getInteger();
        stack.pop_back();
        return res;
    }
    
    bool hasNext() {
        int i = 0 ; 
        while(!stack.empty()){
            auto ni = stack.back();

            // Base case
            if(ni.isInteger()) return true;

            // Recursive
            stack.pop_back();
            auto nestedList = ni.getList();
            reverse(nestedList.begin(), nestedList.end());
            for(const auto nni: nestedList){
                stack.push_back(nni);
            }

        }

        return false;
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */