/*
 * @lc app=leetcode id=1145 lang=cpp
 *
 * [1145] Binary Tree Coloring Game
 */

// @lc code=start
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
    int cache[101]; // number of elements in the subtree
    int x_player;
    int l_child, r_child;
    int dfs(TreeNode* node) {
        // Base case
        if (node == nullptr) return 0;
        if(node->val == x_player){
            l_child = node->left != nullptr ? node->left->val : -1;
            r_child = node->right != nullptr ? node->right->val : -1;
        }
        return cache[node->val] = 1 + dfs(node->left) + dfs(node->right);
    }
    bool btreeGameWinningMove(TreeNode* root, int n, int x) {
        x_player = x;
        dfs(root);
        int max_y_gain = n - cache[x];
        if (l_child != -1) max_y_gain = max(max_y_gain, cache[l_child]);
        if (r_child != -1) max_y_gain = max(max_y_gain, cache[r_child]);
        
        return max_y_gain > (n - max_y_gain);
    }
};
// @lc code=end
