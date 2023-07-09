/*
 * @lc app=leetcode id=1600 lang=cpp
 *
 * [1600] Throne Inheritance
 */

// @lc code=start
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;
class Node {
public:
    string name;
    bool is_alive = true;
    vector<Node*> children;
    Node(string n) : name(n){}
};
class ThroneInheritance {
   public:
    shared_ptr<Node> root;
    unordered_map<string, shared_ptr<Node>> mp;
    ThroneInheritance(string kingName) : root(make_shared<Node>(kingName)) {
        mp[kingName] = root;
    }

    void birth(string parentName, string childName) {
        mp[childName] = make_shared<Node>(childName);
        mp[parentName]->children.push_back(mp[childName].get());
    }

    void death(string name) {
        mp[name]->is_alive = false;
    }

    vector<string> getInheritanceOrder() {
        vector<string> order;
        helper(root.get(), order);
        return order;
    }

private:
    void helper(Node* node, vector<string>& order){
        if (node->is_alive) order.push_back(node->name);
        for (auto child : node->children) helper(child, order);
    }
};

/**
 * Your ThroneInheritance object will be instantiated and called as such:
 * ThroneInheritance* obj = new ThroneInheritance(kingName);
 * obj->birth(parentName,childName);
 * obj->death(name);
 * vector<string> param_3 = obj->getInheritanceOrder();
 */
// @lc code=end

