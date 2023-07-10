/*
 * @lc app=leetcode id=987 lang=cpp
 *
 * [987] Vertical Order Traversal of a Binary Tree
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
#include <map>
using namespace std;
class Solution {
public:
    map<int, vector<pair<int, int>>> mp;
    void helper(TreeNode* node, int row = 0, int col = 0) {
        // Base case
        if (node == nullptr) return;
        // Recursive case
        mp[col].emplace_back(row, node->val);
        helper(node->left, row + 1, col - 1);
        helper(node->right, row + 1, col + 1);
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        helper(root);
        vector<vector<int>> ret;
        for (auto& [idx, vec]: mp){
            sort(vec.begin(), vec.end(), [](const auto& p1, const auto& p2) {
                if (p1.first < p2.first) return true;
                else if(p1.first == p2.first) return p1.second < p2.second;
                return false;
            });
            vector<int> tmp(vec.size());
            for (int i = 0; i < vec.size(); ++i) tmp[i] = (vec[i].second);
            ret.push_back(move(tmp));
        }
        return ret;
    }
};
// @lc code=end

