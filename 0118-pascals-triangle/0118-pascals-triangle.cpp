class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        if(numRows == 1) return {{1}};

        vector<vector<int>> res = {{1}, {1, 1}};
        for(int i = 2 ; i < numRows ; ++i){
            vector<int> row = {1};
            for(int j = 1 ; j < i ; ++j)
                row.push_back(res[i-1][j-1] + res[i-1][j]);
            row.push_back(1);
            res.push_back(row);
        }

        return res;
    }
};