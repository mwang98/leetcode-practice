class Solution {
public:
    int threshold = 180;
    double dp[180][180];
    double topdown(int a, int b){
        // Base case
        if(a == 0 && b == 0) return 0.5;
        if(a == 0 || b == 0) return a == 0;
        if(dp[a][b] != -1) return dp[a][b];
        // Recursive case
        dp[a][b] = 0.25 * (topdown(max(0, a - 4), b) +
                           topdown(max(0, a - 3), max(0, b - 1)) +
                           topdown(max(0, a - 2), max(0, b - 2)) +
                           topdown(max(0, a - 1), max(0, b - 3)));
        return dp[a][b];
    }
    double soupServings(int n) {
        int m = ceil((0.0 + n) / 25);
        
        // Answer is too close to 1 (error < 1e-5)
        if (m > threshold) return 1;

        for(int i = 0 ; i < threshold ; ++i) 
            for(int j = 0 ; j < threshold ; ++j) 
                dp[i][j] = -1;

        return topdown(m, m);
    }
};