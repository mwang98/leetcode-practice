/*
 * @lc app=leetcode id=894 lang=cpp
 *
 * [894] All Possible Full Binary Trees
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
#include <vector>
#include <unordered_map>
using namespace std;
class Solution {
   public:
    unordered_map<int, vector<TreeNode*>> cache;
    auto duplicate_tree(TreeNode* node) -> TreeNode* {
        // Base case
        if (node == nullptr) return nullptr;
        // Recursive case
        TreeNode* dup = new TreeNode();
        dup->left = duplicate_tree(node->left);
        dup->right = duplicate_tree(node->right);
        return dup;
    }

    vector<TreeNode*> allPossibleFBT(int n) {
        // Base case
        if (n == 1) return {new TreeNode()};
        if (cache.count(n)) return cache[n];
        // Recursive case
        n--;  //  one for root
        vector<TreeNode*> ret;
        for (int i = 1; i < n; i+=2){
            const auto& l_roots = allPossibleFBT(i);
            const auto& r_roots = allPossibleFBT(n - i);
            for(const auto& l_root: l_roots){
                for(const auto& r_root: r_roots){
                    TreeNode* root = new TreeNode();
                    root->left = duplicate_tree(l_root);
                    root->right = duplicate_tree(r_root);
                    ret.push_back(root);
                }
            }
        }
        return cache[n] = ret;
    }
};
// @lc code=end

