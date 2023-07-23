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
                    root->left = l_root;
                    root->right = r_root;
                    ret.push_back(root);
                }
            }
        }
        return cache[n] = move(ret);
    }
};
// @lc code=end

