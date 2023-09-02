class Solution {
public:
    vector<vector<int>> childrens;
    vector<int> subtree_size;
    vector<unsigned long long> scores;

    int get_size(int node) {
        subtree_size[node] = 1;
        for(auto nxt: childrens[node]) subtree_size[node] += get_size(nxt);
        return subtree_size[node];
    }

    int countHighestScoreNodes(vector<int>& parents) {
        int root = 0;
        int n_nodes = parents.size();
        unsigned long long max_score = 0;

        childrens.resize(n_nodes);
        subtree_size.resize(n_nodes);
        scores.resize(n_nodes);

        for(int i = 0 ; i < n_nodes ; ++i){
            if(auto parent = parents[i]; parent != -1)
                childrens[parent].push_back(i);
            else root = i;
        }

        get_size(root);

        for(int node = 0 ; node < n_nodes ; ++node){
            auto tree_sz = subtree_size[node];
            unsigned long long parent_sz = n_nodes - tree_sz;
            unsigned long long product = max(1ull, parent_sz);

            for(auto nxt: childrens[node])
                product *= subtree_size[nxt];
            
            max_score = max(max_score, product);
            scores[node] = product;
        }

        int ret = 0;
        for(int node = 0 ; node < n_nodes ; ++node)
            ret += scores[node] == max_score;

        return ret;
    }
};