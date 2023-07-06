class DSU {
public:
    vector<int> parent;
    vector<int> rank;
    DSU(int n){
        parent.resize(n);
        rank.resize(n, 0);
        for(int i = 0 ; i < n ; ++i) parent[i] = i;
    } 
    int Find(int x){
        if(x != parent[x]) parent[x] = Find(parent[x]);
        return parent[x];
    }
    bool Union(int x, int y){
        auto px = Find(x), py = Find(y);
        if(px == py) return false;
        if(rank[px] < rank[py])
            parent[px] = py;
        else if(rank[px] > rank[py])
            parent[py] = px;
        else {
            parent[py] = px;
            rank[px]++;
        }
        return true;
    }
    int GetComponentNum(){
        unordered_set<int> set;
        for(int i = 1 ; i < parent.size() ; ++i)
            set.insert(Find(i));
        return set.size();
    }
};
class Solution {
public:
    int minimumCost(int n, vector<vector<int>>& connections) {
        /* Minimum spanning tree: Kruscal's algo */
        DSU dsu(n + 1);
        int cost = 0;

        sort(connections.begin(), connections.end(), [](const auto& c1, const auto& c2){ return c1[2] < c2[2]; });

        for(const auto& conn: connections){
            auto src = conn[0], tgt = conn[1], c = conn[2];
            if(dsu.Union(src, tgt)){
                cost += c;
            }
        }

        return dsu.GetComponentNum() == 1 ? cost : -1;
    }
};