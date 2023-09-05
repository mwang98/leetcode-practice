/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int maxSumBST(TreeNode* root) {
        /*  How to determin valid BST using its subtree? 
        Given lmin, lmax, rmin, rmax, val, lmax < val < rmin
        */
        int max_bst = 0;

        function<tuple<bool, int, int, int>(TreeNode*, bool)> dfs = [&](TreeNode* node, bool left) -> tuple<bool, int, int, int> {
            // return: valid BST, sum of value, min, max
            // Base case
            if(!node) return {true, 0, left ? INT_MIN : INT_MAX, left ? INT_MIN : INT_MAX};
            // Recursive case
            auto [l_valid, l_sum, l_min, l_max] = dfs(node->left, true);
            auto [r_valid, r_sum, r_min, r_max] = dfs(node->right, false);

            if(!l_valid || !r_valid) return {false, 0, 0, 0};
            if(!(l_max < node->val && node->val < r_min)) return {false, 0, 0, 0};
            auto sum = l_sum + node->val + r_sum;

            max_bst = max(max_bst, sum);
            return {true, sum, l_min == INT_MIN ? node->val : l_min, r_max == INT_MAX ? node->val : r_max };
        };

        dfs(root, true);
        return max_bst;
    }
};