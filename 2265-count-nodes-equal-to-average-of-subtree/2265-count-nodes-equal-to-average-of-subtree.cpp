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
    int averageOfSubtree(TreeNode* root) {
        int res = 0;

        function<pair<int, int>(TreeNode*)> dfs = [&](TreeNode* node) -> pair<int, int> {
            // Given `node`, return [# of nodes, sum of values of node in its subtree]
            // Base case
            if(node == nullptr) return {0, 0};
            // Recursive case
            auto [l_num, l_sum] = dfs(node->left);
            auto [r_num, r_sum] = dfs(node->right);
            res += ((l_sum + r_sum + node->val) / (l_num + r_num + 1)) == node->val;
            return {l_num + r_num + 1, l_sum + r_sum + node->val};
        };
        
        dfs(root);
        return res;
    }
};