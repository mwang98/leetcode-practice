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
class Solution {
public:
    ListNode* findTail(ListNode* node){
        if(node->next) return findTail(node->next);
        return node;
    }
    
    tuple<ListNode*, ListNode*, ListNode*> findMid(ListNode* head, ListNode* tail){
        ListNode *fast = head, *slow = head, *prev = nullptr;
        while(fast != tail && fast->next != tail){
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        return {prev, slow, slow->next}; // ... -> O -> MID -> O -> ...
    }

    TreeNode* construct(ListNode* head, ListNode* tail){
        // Base case
        if(head == nullptr || tail == nullptr) return nullptr;
        // Recursive case
        auto [left, mid, right] = findMid(head, tail);
        if(left) left->next = nullptr;
        if(mid) mid->next = nullptr;

        return new TreeNode(mid->val, construct(head, left), construct(right, tail));
    }

    TreeNode* sortedListToBST(ListNode* head) {
        // Edge case
        if(head == nullptr) return nullptr;
        return construct(head, findTail(head));
    }
};