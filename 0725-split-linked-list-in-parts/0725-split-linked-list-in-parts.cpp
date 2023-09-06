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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
       function<int(ListNode*)> countList = [&](ListNode* node) -> int {
           return node ? 1 + countList(node->next) : 0;
       };

       auto n_nodes = countList(head);
       vector<int> n_splits(k, n_nodes / k);
       for(int i = 0 ; i < n_nodes % k ; ++i) n_splits[i]++;

       vector<ListNode*> res(k, nullptr);
        for(int i = 0 ; i < k ; ++i){
            auto num = n_splits[i];
            res[i] = head;
            while(num > 0){
                auto tmp = head;
                head = head->next;
                if(--num == 0) tmp->next = nullptr;
            }
        }

        return res;
    }
};