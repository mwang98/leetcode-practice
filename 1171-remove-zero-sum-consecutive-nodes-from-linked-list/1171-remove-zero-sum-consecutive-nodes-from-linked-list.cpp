/*
 * @lc app=leetcode id=1171 lang=cpp
 *
 * [1171] Remove Zero Sum Consecutive Nodes from Linked List
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
#include <vector>
#include <unordered_map>
using namespace std;
class Solution {
public:
    ListNode* removeZeroSumSublists(ListNode* head) {
        /* one pass
        E.g., 0 (dummy) 1 2 3 -3 4
              0         1 3 6  3   (prefix sum is duplicate -> range sum == 0 found)
              --------------------
              0         1 2      4
        TC: O(n)
        SC: O(n)
        */
        unordered_map<int, pair<ListNode*, int>> val2node; // accumulate sum -> node, index
        auto dummy = new ListNode(0, head);

        int index = 0;
        int prefix_sum = 0;
        auto cursor = dummy;
        while(cursor){
            int val = prefix_sum = prefix_sum + cursor->val;

            if (val2node.count(val)) {
                auto [start, idx] = val2node[val];
                cursor = start->next = cursor->next;
                index = idx + 1;

                vector<int> val_to_remove;
                for(const auto& [val, pr]: val2node)
                    if (pr.second > idx) val_to_remove.push_back(val);
                for(auto val: val_to_remove)
                    val2node.erase(val);
            } else {
                val2node[prefix_sum] = make_pair(cursor, index++);
                cursor = cursor->next;
            }
        }

        return dummy->next;
    }
};
// @lc code=end

