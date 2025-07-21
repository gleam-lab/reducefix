#include <bits/stdc++.h>
using namespace std;

#define INT long long
#define PB push_back
#define all(x) (x).begin(), (x).end()

using V = vector<int>;
using VV = vector<V>;
using VS = vector<string>;
using VVS = vector<VS>;
using VD = vector<INT>;

struct Edge {
    int to, cost;
    bool operator < (const Edge& other) const {
        return cost < other.cost;
    }
};

struct DSU {
    V<INT> parent, rank, sizes;

    DSU(int n) {
        parent.resize(n + 1);
        rank.resize(n + 1);
        sizes.resize(n + 1);
        iota(parent.begin(), parent.end(), 0);
        fill(rank.begin(), rank.end(), 0);
        fill(sizes.begin(), sizes.end(), 1);
    }

    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    bool unite(int x, int y) {
        int rootX = find(x), rootY = find(y);
        if (rootX == rootY) return false;
        if (rank[rootX] > rank[rootY]) {
            parent[rootY] = rootX;
            sizes[rootX] += sizes[rootY];
        } else {
            if (rank[rootX] == rank[rootY]) rank[rootY]++;
            parent[rootX] = rootY;
            sizes[rootY] += sizes[rootX];
        }
        return true;
    }

    INT size(int x) { return sizes[find(x)]; }
};

void solve() {
    INT n, m;
    cin >> n >> m;
    VD a(n + 1);
    VV<Edge> edges(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < m; ++i) {
        INT u, v, w;
        cin >> u >> v >> w;
        edges[u].PB({v, w});
        edges[v].PB({u, w});
    }
    DSU dsu(n + 1);
   sort(all(edges[1]));
    priority_queue<pair<INT, INT>, V<pair<INT, INT>>, greater<pair<INT, INT>>> pq;
    pq.emplace(a[1], 1);

    while (!pq.empty()) {
        auto [cost, u] = pq.top();
        pq.pop();
        if (dsu.find(u) != 1) continue;
        for (auto& [v, weight] : edges[u]) {
            INT next_cost = cost + a[v] + weight;
            if (dsu.find(u) != dsu.find(v)) {
                pq.emplace(next_cost, v);
            } else if (next_cost < cost) {
                pq.emplace(next_cost, v);
            }
        }
        dsu.unite(u, 1);
    }

    for (int i = 2; i <= n; ++i) {
        cout << (dsu.size(i) > 0 ? -1LL : INT_MAX) << " ";
    }
    cout << '\n';
}

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}