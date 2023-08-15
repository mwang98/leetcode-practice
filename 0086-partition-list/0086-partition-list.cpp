/*
 * @lc app=leetcode id=86 lang=cpp
 *
 * [86] Partition List
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
class Solution {
public:
    ListNode* head_less = nullptr;
    ListNode* head_greater = nullptr;

    auto appendLessList(ListNode* tail, ListNode* new_node) -> ListNode*{
        if (head_less == nullptr || tail == nullptr) head_less = new_node;
        else tail->next = new_node;
        new_node->next = nullptr;
        return new_node;
    }
    auto appendGreaterList(ListNode* tail, ListNode* new_node) -> ListNode* {
        if (head_greater == nullptr || tail == nullptr) head_greater = new_node;
        else tail->next = new_node;
        new_node->next = nullptr;
        return new_node;
    }
    ListNode* partition(ListNode* head, int x) {
        if (head == nullptr) return head;

        auto tail_less = head_less;
        auto tail_greater = head_greater;

        auto curr = head;
        auto next = head->next;
        while(curr){
            if (curr->val < x) tail_less = appendLessList(tail_less, curr);
            else tail_greater = appendGreaterList(tail_greater, curr);
            if (next == nullptr) break;
            curr = next;
            next = next->next;
        }

        if (tail_less) tail_less->next = head_greater;
        return head_less != nullptr ? head_less : head_greater;
    }
};
// @lc code=end
