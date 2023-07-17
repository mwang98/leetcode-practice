/*
 * @lc app=leetcode id=445 lang=cpp
 *
 * [445] Add Two Numbers II
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
using namespace std;
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        vector<int> stack1, stack2;
        auto curr1 = l1, curr2 = l2;

        while (curr1) {
            stack1.push_back(curr1->val);
            curr1 = curr1->next;
        }
        while (curr2) {
            stack2.push_back(curr2->val);
            curr2 = curr2->next;
        }

        ListNode* curr = nullptr;
        int carry = 0;
        while (carry || !stack1.empty() || !stack2.empty()) {
            int val = carry;
            if (!stack1.empty()){
                val += stack1.back();
                stack1.pop_back();
            }
            if (!stack2.empty()) {
                val += stack2.back();
                stack2.pop_back();
            }
            auto new_node = new ListNode(val % 10, curr);
            curr = new_node;
            carry = val / 10;
        }

        return curr;
    }
};
// @lc code=end

