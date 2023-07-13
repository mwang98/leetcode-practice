/*
 * @lc app=leetcode id=1028 lang=cpp
 *
 * [1028] Recover a Tree From Preorder Traversal
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
#include <string>
#include <vector>
using namespace std;
class Solution {
public:
    TreeNode* recoverFromPreorder(string traversal) {
        traversal += '-';
        vector<pair<int, TreeNode*>> stack;

        int depth = 0;
        int value = 0;
        for (int i = 0; i < traversal.size(); ++i) {
            if (traversal[i] == '-'){
                // Insert node
                if (traversal[i - 1] != '-') {
                    auto node = new TreeNode(value);

                    // Pop deeper nodes
                    while (!stack.empty() && stack.back().first >= depth)
                        stack.pop_back();

                    // Connect parent to node
                    if (!stack.empty()){
                        auto parent = stack.back().second;
                        if (parent->left == nullptr) parent->left = node;
                        else parent->right = node;
                    }

                    stack.push_back({depth, node});

                    value = depth = 0;
                }
                depth++;
            } else {
                value = value * 10 +(traversal[i] - '0');
            }
        }

        return stack.front().second;
    }
};
// @lc code=end

