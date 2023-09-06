class Solution {
public:
    int minIncrements(int n, vector<int>& costs) {
        int max_cost = 0;
        int res = 0;

        function<int(int, int)> computePathCost = [&] (int node, int cost) -> int {
            // Base case: leaf node
            auto new_cost = cost + costs[node - 1];
            if(node > n / 2) 
                return new_cost;
            return max(computePathCost(2 * node, new_cost), 
                       computePathCost(2 * node + 1, new_cost));
        };

        function<int(int, int)> dfs = [&](int node, int cost) -> int{
            // Return: value needed to increment
            if(node > n / 2) return max_cost - (cost + costs[node - 1]);
            // Recursvie case
            auto l_incr = dfs(2 * node, cost + costs[node - 1]);
            auto r_incr = dfs(2 * node + 1, cost + costs[node - 1]);
            auto incr = min(l_incr, r_incr);
            res += (l_incr - incr) + (r_incr - incr);

            return incr;
        };
    
        max_cost = computePathCost(1, 0);
        dfs(1, 0);

        return res;
    }
};