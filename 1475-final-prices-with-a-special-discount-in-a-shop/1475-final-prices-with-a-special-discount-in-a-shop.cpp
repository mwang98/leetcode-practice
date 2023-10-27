class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        // Monotonic stack
        // When to push: add new price
        // When to pop: stack has prices larger then current price (not good choices)

        vector<int> stack; // decreasing stack
        vector<int> res(prices.size());

        for(int i = prices.size() - 1 ; i >= 0 ; --i){
            auto price = prices[i];

            // Pop: remove prices larger than current price
            while(!stack.empty() && price < stack.back())
                stack.pop_back();

            // Compute discount
            res[i] = price - (!stack.empty() ? stack.back() : 0);

            // Push: add price
            stack.push_back(price);
        }

        return res;
    }
};