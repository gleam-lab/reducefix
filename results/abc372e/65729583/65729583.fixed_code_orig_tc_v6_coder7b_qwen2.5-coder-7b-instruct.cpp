#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

typedef long long int ll;

struct UF {
    vector<int> parent, rank;
    
    UF(int n) : parent(n), rank(n, 1) {
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
        }
    }

    int find(int u) {
        return parent[u] == u ? u : parent[u] = find(parent[u]);
    }

    void unite(int u, int v) {
        u = find(u);
        v = find(v);
        if (u != v) {
            if (rank[u] < rank[v]) {
                swap(u, v);
            }
            parent[v] = u;
            rank[u] += rank[v];
        }
    }
};

class Solution {
public:
    vector<vector<int>> g;
    vector<multiset<int>> sets;

    Solution(int n) : g(n), sets(n) {}

    void addEdge(int u, int v) {
        g[u].push_back(v);
        g[v].push_back(u);
    }

    void dfs(int node, int parent, UF &uf) {
        uf.unite(node, parent);
        sets[uf.find(node)].insert(node);
        
        for (auto neighbor : g[node]) {
            if (neighbor != parent) {
                dfs(neighbor, node, uf);
            }
        }
    }

    int query(int node, int k) {
        auto &st = sets[UF().find(node)];
        if (k > st.size()) return -1;
        auto it = st.rbegin();
        advance(it, k - 1);
        return *it;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    UF uf(n);
    Solution sol(n);

    for (int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        sol.addEdge(u, v);
    }

    sol.dfs(1, 0, uf);

    for (int i = 0; i < q; ++i) {
        int type, u, k;
        cin >> type >> u >> k;
        if (type == 1) {
            sol.addEdge(u, v);
            sol.dfs(u, 0, uf);
        } else {
            cout << sol.query(u, k) << '\n';
        }
    }

    return 0;
}