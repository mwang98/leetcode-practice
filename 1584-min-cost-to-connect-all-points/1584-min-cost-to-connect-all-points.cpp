typedef pair<int, int> Node;
typedef tuple<int, int, int> Edge;

class DSU{
public:
    vector<int> parent;
    vector<int> rank;
    DSU(int n){
        parent.resize(n);
        rank.resize(n);
        for(int i = 0 ; i < n ; ++i) parent[i] = i;
    }

    int Find(int x){
        if(x != parent[x]) parent[x] = Find(parent[x]);
        return parent[x];
    }

    bool Union(int x, int y){
        auto px = Find(x), py = Find(y);
        if(px == py) return false;

        if(rank[px] > rank[py]){
            parent[py] = parent[px];
        } else if(rank[py] > rank[px]){
            parent[px] = parent[py];
        } else{
            parent[px] = parent[py];
            rank[py]++;
        }
        return true;
    }
};

class Solution {
public:
    int compute_dist(Node& n1, Node& n2){
        return abs(n1.first - n2.first) + abs(n1.second - n2.second);
    }
    int minCostConnectPoints(vector<vector<int>>& points) {
        /* Minimum spanning tree using Kruscal
        TC: O(v^2 + eloge) = O(v^2 + (v^2)log(v^2)) = O(v^2logv)
        SC: O(v)
        */
        //
        auto comp = [](const auto& e1, const auto& e2) -> bool { return get<2>(e1) > get<2>(e2); };

        vector<Node> nodes(points.size());
        DSU dsu(nodes.size());
        priority_queue<Edge, vector<Edge>, decltype(comp)> pq(comp);

        // Build nodes
        for(int i = 0 ; i < points.size() ; ++i)
            nodes[i] = {points[i][0], points[i][1]};

        // Build edges
        for(int i = 0 ; i < nodes.size() ; ++i){
            for(int j = 0 ; j < nodes.size() ; ++j){
                if(i == j) continue;
                pq.push({i, j, compute_dist(nodes[i], nodes[j])});
            }
        }

        // Union Find
        int cost = 0;
        while(!pq.empty()){
            auto [n1, n2, weight] = pq.top();
            pq.pop();

            cost += dsu.Union(n1, n2) * weight;
        }

        return cost;
    }
};