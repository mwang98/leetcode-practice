class Node{
public:
    int val;
    int user = 0;
    bool is_locked;
    vector<int> children;
    Node(){}
    Node(int v): val(v), is_locked(false){}
};
class LockingTree {
    int root_;
    vector<int> parent_;
    vector<Node> nodes_;
public:
    LockingTree(vector<int>& parent): parent_(parent) {
        /* O(n) */
        nodes_.resize(parent.size());

        for(int i = 0 ; i < nodes_.size() ; ++i) nodes_[i] = Node(i);
        for(int i = 0 ; i < parent.size() ; ++i){
            if(parent[i] == -1) root_ = i;
            else nodes_[parent[i]].children.push_back(i);
        }
    }
    
    bool lock(int num, int user) {
        /* O(1) */
        if(nodes_[num].is_locked) return false;
        nodes_[num].is_locked = true;
        nodes_[num].user = user;
        return true;
    }
    
    bool unlock(int num, int user) {
        /* O(1) */
        if(!nodes_[num].is_locked || nodes_[num].user != user) return false;
        nodes_[num].is_locked = false;
        return true;
    }
    
    bool upgrade(int num, int user) {
        /* O(n) */
        if(at_least_one_ancestor_islocked(num)) return false;
        bool has_locked_descendants = false;
        for(auto& child: nodes_[num].children){
            has_locked_descendants |= at_least_one_descendant_islocked(child);
            if(has_locked_descendants) break;
        }
        if(!has_locked_descendants) return false;

        unlock_all_descendant(num);

        nodes_[num].is_locked = true;
        nodes_[num].user = user;

        return true;
    }

    bool at_least_one_ancestor_islocked(int num){
        /* O(n) */
        if(num == root_) return nodes_[root_].is_locked;
        return nodes_[num].is_locked || at_least_one_ancestor_islocked(parent_[num]);
    }

    bool at_least_one_descendant_islocked(int num){
        /* O(n) */
        if(nodes_[num].is_locked) return true;
        for(auto& child: nodes_[num].children) if(at_least_one_descendant_islocked(child)) return true;
        return false;
    }

    void unlock_all_descendant(int num){
        /* O(n) */
        nodes_[num].is_locked = false;
        for(auto& child: nodes_[num].children) unlock_all_descendant(child);
    }
};

/**
 * Your LockingTree object will be instantiated and called as such:
 * LockingTree* obj = new LockingTree(parent);
 * bool param_1 = obj->lock(num,user);
 * bool param_2 = obj->unlock(num,user);
 * bool param_3 = obj->upgrade(num,user);
 */