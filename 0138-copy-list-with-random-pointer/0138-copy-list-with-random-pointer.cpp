/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> mapping;

        function<Node*(Node*)> construct = [&](Node* node) -> Node*{
            // Base case
            if(!node) return nullptr;
            // Recursive case
            auto next_copied = construct(node->next);
            auto copied = new Node(node->val);
            copied->next = next_copied;
            copied->random = node->random; // construct after all nodes are copied
            mapping[node] = copied;
            return copied;
        };

        auto new_head = construct(head);
        auto curr = new_head;
        while(curr){
            if(curr->random)
                curr->random = mapping[curr->random];
            curr = curr->next;
        }

        return new_head;
    }
};