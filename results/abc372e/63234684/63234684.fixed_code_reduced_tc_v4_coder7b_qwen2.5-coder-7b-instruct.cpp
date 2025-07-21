#include<bits/stdc++.h>
using namespace std;

class UnionFind {
public:
    vector<int> parent, rank, size, order;
    
    UnionFind(int n) {
        parent.resize(n+1);
        rank.resize(n+1, 0);
        size.resize(n+1, 1);
        iota(parent.begin(), parent.end(), 0);
        order.resize(n+1);
    }

    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    void unite(int x, int y) {
        x = find(x);
        y = find(y);
        
        if (x == y) return;

        if (rank[x] < rank[y]) {
            parent[x] = y;
            size[y] += size[x];
            order[y].insert(order[y].end(), order[x].begin(), order[x].end());
        } else if (rank[x] > rank[y]) {
            parent[y] = x;
            size[x] += size[y];
            order[x].insert(order[x].end(), order[y].begin(), order[y].end());
        } else {
            parent[x] = y;
            rank[y]++;
            size[y] += size[x];
            order[y].insert(order[y].end(), order[x].begin(), order[x].end());
        }
    }

    vector<int> getSortedSet(int x) {
        return order[find(x)];
    }
};

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int n, q;
    cin >> n >> q;

    UnionFind uf(n);
    vector<pair<int, pair<int, int>>> events;
    
    for (int i = 0; i < q; ++i) {
        int type, u, v;
        cin >> type >> u >> v;
        --u, --v;
        events.emplace_back(type, make_pair(u, v));
    }

    vector<int> ans(q, -1);
    unordered_map<int, int> pos;
    int j = 0;

    for (auto [type, uv] : events) {
        auto [u, v] = uv;
        if (type == 1) {
            uf.unite(u, v);
        } else {
            auto &sortedSet = uf.getSortedSet(v);
            int len = sortedSet.size();
            if (len >= v + 1) {
                ans[j] = sortedSet[len - v - 1] + 1;
            }
        }
        ++j;
    }

    for (auto x : ans) {
        cout << x << '\n';
    }

    return 0;
}