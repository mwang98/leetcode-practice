/*
 * @lc app=leetcode id=111 lang=cpp
 *
 * [111] Minimum Depth of Binary Tree
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
using namespace std;
class Solution {
   public:
    int get_mindepth(TreeNode* node){
        if (node == nullptr) return INT_MAX;
        int l_depth = get_mindepth(node->left);
        int r_depth = get_mindepth(node->right);
        return 1 + (l_depth == INT_MAX && r_depth == INT_MAX ? 0 : min(l_depth, r_depth));
    }
    int minDepth(TreeNode* root) {
        if (root == nullptr) return 0;
        return get_mindepth(root);
    }
};
// @lc code=end

