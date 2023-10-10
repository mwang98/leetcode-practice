class Solution {
public:
    vector<int> cycleLengthQueries(int n, vector<vector<int>>& queries) {
        // Computation on complete binary tree + LCA
        // Since Q (queries.size()) is 1e5, thus TC of each lookup should be O(1)
        vector<int> res;
        res.reserve(queries.size());
        
        // Get a path traversing from root to the target node
        // TC: O(n) = O(30) -> acceptable
        auto get_root2node_path = [&](int node) -> vector<int>{
            vector<int> res;
            res.reserve(n);
            while(node){
                res.push_back(node);
                node = node >> 1;
            }
            return res;
        };

        // Execute queries
        for(const auto& q: queries){
            auto n1 = q[0], n2 = q[1];
            auto path1 = get_root2node_path(n1);
            auto path2 = get_root2node_path(n2);

            // Common nodes for these path
            int common_len = 0;
            int idx1 = path1.size() - 1, idx2 = path2.size() - 1;
            while(idx1 >=0 && idx2 >= 0){
                if(path1[idx1--] == path2[idx2--]) common_len++;
                else break;
            }

            res.push_back(path1.size() + path2.size() - 2 * common_len + 1);
        }

        return res;

    }
};