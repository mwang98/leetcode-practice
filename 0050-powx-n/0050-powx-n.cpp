class Solution {
public:
    unordered_map<int, double> cache;
    double dfs(double x, int n){
        // Base case
        if(cache.count(n)) return cache[n];
        if(n == 0) return cache[n] = 1;
        if(n == 1) return cache[n] = x;
        if(n == -1) return cache[n] = 1.0/x;
        // Recursive case
        return cache[n] = dfs(x, n / 2) * dfs(x, n - n / 2);
    }
    double myPow(double x, int n) {
        return dfs(x, n);
    }
};