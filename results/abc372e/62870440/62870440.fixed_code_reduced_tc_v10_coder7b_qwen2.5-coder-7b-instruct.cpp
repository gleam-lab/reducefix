#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 5;
const int MAXK = 10;

vector<int> adj[MAXN];
set<int> s[MAXN];

void addEdge(int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void dfs(int node, int parent, int comp_id) {
    s[comp_id].insert(node);
    for (int neighbor : adj[node]) {
        if (neighbor != parent) {
            dfs(neighbor, node, comp_id);
        }
    }
}

void mergeComponents(int src_comp, int dest_comp) {
    for (int node : s[src_comp]) {
        s[dest_comp].insert(node);
    }
    s[src_comp].clear();
}

int getKthLargest(int comp_id, int k) {
    if (s[comp_id].size() < k) return -1;
    auto it = s[comp_id].rbegin();
    advance(it, k - 1);
    return *it;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    vector<int> parent(n + 1), rank(n + 1);
    iota(parent.begin(), parent.end(), 0);
    fill(rank.begin(), rank.end(), 1);

    function<int(int)> find = [&](int u) {
        if (parent[u] != u) parent[u] = find(parent[u]);
        return parent[u];
    };

    function<void(int, int)> unionSet = [&](int u, int v) {
        int pu = find(u), pv = find(v);
        if (pu == pv) return;
        if (rank[pu] > rank[pv]) swap(pu, pv);
        parent[pu] = pv;
        rank[pv] += rank[pu];
    };

    while (q--) {
        int type, u, v, k;
        cin >> type;
        if (type == 1) {
            cin >> u >> v;
            unionSet(u, v);
        } else {
            cin >> u >> k;
            int root = find(u);
            cout << getKthLargest(root, k) << '\n';
        }
    }

    return 0;
}