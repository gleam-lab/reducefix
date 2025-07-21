#include <iostream>
#include <vector>
#include <set>
#include <unordered_map>

using namespace std;

typedef long long int ll;

struct DSU {
    vector<int> parent, rank;

    DSU(int n) : parent(n), rank(n, 1) {
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
        }
    }

    int find(int u) {
        if (parent[u] != u) {
            parent[u] = find(parent[u]);
        }
        return parent[u];
    }

    void unite(int u, int v) {
        int pu = find(u), pv = find(v);
        if (pu != pv) {
            if (rank[pu] > rank[pv]) {
                parent[pv] = pu;
            } else if (rank[pu] < rank[pv]) {
                parent[pu] = pv;
            } else {
                parent[pv] = pu;
                rank[pu]++;
            }
        }
    }
};

struct Graph {
    unordered_map<int, set<int>> adjacencyList;
    DSU dsu;

    Graph(int n) : dsu(n) {}

    void addEdge(int u, int v) {
        u = dsu.find(u);
        v = dsu.find(v);
        if (u != v) {
            dsu.unite(u, v);
            adjacencyList[u].insert(v);
            adjacencyList[v].insert(u);
        }
    }

    int getKthLargest(int u, int k) {
        u = dsu.find(u);
        auto& neighbors = adjacencyList[u];
        if (neighbors.size() < k) {
            return -1;
        }
        auto it = next(neighbors.rbegin(), k - 1);
        return *it;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;
    
    Graph g(n + 1);

    while (q--) {
        int type;
        cin >> type;
        if (type == 1) {
            int u, v;
            cin >> u >> v;
            g.addEdge(u, v);
        } else {
            int u, k;
            cin >> u >> k;
            cout << g.getKthLargest(u, k) << '\n';
        }
    }

    return 0;
}