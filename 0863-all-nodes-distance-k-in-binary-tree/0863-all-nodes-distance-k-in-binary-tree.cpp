/*
 * @lc app=leetcode id=863 lang=cpp
 *
 * [863] All Nodes Distance K in Binary Tree
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include <vector>
#include <queue>
using namespace std;
class Solution {
   public:
    TreeNode* node2parent[501];
    bool visited[501];
    void build_parent(TreeNode* node, TreeNode* parent) {
        if (node == nullptr) return;
        node2parent[node->val] = parent;
        build_parent(node->left, node);
        build_parent(node->right, node);
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        build_parent(root, nullptr);
        memset(visited, 0, sizeof(visited));

        int level = 0;
        queue<TreeNode*> q;
        vector<int> ret;

        q.push(target);
        visited[target->val] = true;

        while(!q.empty()){
            for (int i = 0, size = q.size(); i < size; ++i){
                auto node = q.front();
                q.pop();

                if (level == k) ret.push_back(node->val);
                // Add children
                if(node->left && !visited[node->left->val]){
                    q.push(node->left);
                    visited[node->left->val] = true;
                }
                if (node->right && !visited[node->right->val]) {
                    q.push(node->right);
                    visited[node->right->val] = true;
                }
                // Add parent
                if(node2parent[node->val] && !visited[node2parent[node->val]->val]){
                    q.push(node2parent[node->val]);
                    visited[node2parent[node->val]->val] = true;
                }
            }

            if (level++ == k) break;
        }

        return ret;
    }
};
// @lc code=end

