/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};
*/

class Solution {
public:
    Node* head = nullptr;
    auto dfs(Node* node, bool is_root = false) -> pair<Node*, Node*>{
        // Return the smallest and the largest node in the subtree with `node` as a root
        // Base case
        if(node == nullptr) return {nullptr, nullptr};
        // Recursive case
        auto [l_s, l_l] = dfs(node->left);
        auto [r_s, r_l] = dfs(node->right);

        if(l_l) l_l->right = node;
        if(r_s) r_s->left = node;
        node->left = l_l; // largest of left child
        node->right = r_s; // smallest of right child
        
        if(is_root){
            if(!l_s) l_s = node;
            if(!r_l) r_l = node;
            
            head = l_s;
            l_s->left = r_l;
            r_l->right = l_s;
        }
        
        if(l_s && r_l) return {l_s, r_l};
        else if(l_s) return {l_s, node};
        else if(r_l) return {node, r_l};
        return {node, node};
    }
    Node* treeToDoublyList(Node* root) {
        dfs(root, true);
        return head;
    }
};