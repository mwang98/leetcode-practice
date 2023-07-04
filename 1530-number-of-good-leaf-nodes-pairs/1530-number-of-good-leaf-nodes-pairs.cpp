/*
 * @lc app=leetcode id=1530 lang=cpp
 *
 * [1530] Number of Good Leaf Nodes Pairs
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
using namespace std;
class Solution {
public:
    int counter = 0;
    int distance = 0;
    auto dfs(TreeNode* node) -> vector<int> {
        // Base case
        if (node == nullptr) return vector<int>(distance + 1, 0);
        // Recursive case
        vector<int> ret(distance + 1, 0);
        const auto& l_dist = dfs(node->left);
        const auto& r_dist = dfs(node->right);
        for (int i = 0; i < l_dist.size(); ++i) {
            for (int j = 0; j < r_dist.size(); ++j) {
                if (i + 1 + j + 1 <= distance)
                    counter += l_dist[i] * r_dist[j];
            }
        }

        // Leaf
        ret[0] = node->left == nullptr && node->right == nullptr;
        // Merge
        for (int i = 0; i < l_dist.size() - 1; ++i)
            ret[i + 1] = l_dist[i] + r_dist[i];
        return ret;
    }
    int countPairs(TreeNode* root, int d) {
        distance = d;
        dfs(root);
        return counter;
    }
};
// @lc code=end

