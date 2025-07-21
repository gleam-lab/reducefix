#include <bits/stdc++.h>

using namespace std;

struct Node {
    int x, y;
};

struct Query {
    int type, x, y;
};

struct DisjointSet {
    vector<int> parent, rank;

    DisjointSet(int n) : parent(n), rank(n, 0) {
        for(int i = 0; i < n; ++i)
            parent[i] = i;
    }

    int find(int u) {
        if(u != parent[u])
            parent[u] = find(parent[u]);
        return parent[u];
    }

    void unite(int u, int v) {
        u = find(u);
        v = find(v);
        if(u != v) {
            if(rank[u] > rank[v])
                parent[v] = u;
            else {
                parent[u] = v;
                if(rank[u] == rank[v])
                    rank[v]++;
            }
        }
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int h, w, q;
    cin >> h >> w >> q;

    DisjointSet ds(h*w + 2);
    vector<Node> nodes(h*w + 2);
    vector<bool> destroyed(h*w + 2, false);

    for(int i = 0; i < h; ++i) {
        for(int j = 0; j < w; ++j) {
            nodes[i*w + j] = {i, j};
        }
    }

    vector<Query> queries(q);
    for(int i = 0; i < q; ++i) {
        int type, x, y;
        cin >> type >> x >> y;
        --x, --y;
        queries[i] = {type, x, y};
    }

    int ans = h*w;
    for(auto& query : queries) {
        int type = query.type, x = query.x, y = query.y;
        int idx = x*w + y;
        
        if(type == 1) {
            if(!destroyed[idx]) {
                destroyed[idx] = true;
                --ans;
            } else {
                int rootX = ds.find(x*w);
                int rootY = ds.find((x+1)*w);
                int rootZ = ds.find(y+1);
                
                if(rootX != rootY && !destroyed[rootY]) {
                    ds.unite(rootX, rootY);
                    destroyed[rootY] = true;
                    --ans;
                }
                if(rootX != rootZ && !destroyed[rootZ]) {
                    ds.unite(rootX, rootZ);
                    destroyed[rootZ] = true;
                    --ans;
                }
                if(rootY != rootZ && !destroyed[rootZ]) {
                    ds.unite(rootY, rootZ);
                    destroyed[rootZ] = true;
                    --ans;
                }
            }
        }
    }

    cout << ans << '\n';

    return 0;
}