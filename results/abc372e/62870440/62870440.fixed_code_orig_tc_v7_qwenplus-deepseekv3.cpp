#include<bits/stdc++.h>
using namespace std;

const int MAXN = 200005;
vector<int> adj[MAXN];
int parent[MAXN];
vector<int> component[MAXN];

int find(int u) {
    if (parent[u] != u) {
        parent[u] = find(parent[u]);
    }
    return parent[u];
}

void unite(int u, int v) {
    int rootU = find(u);
    int rootV = find(v);
    if (rootU == rootV) return;
    
    if (component[rootU].size() < component[rootV].size()) {
        swap(rootU, rootV);
    }
    
    parent[rootV] = rootU;
    component[rootU].insert(component[rootU].end(), component[rootV].begin(), component[rootV].end());
    component[rootV].clear();
    
    sort(component[rootU].rbegin(), component[rootU].rend());
    if (component[rootU].size() > 10) {
        component[rootU].resize(10);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N, Q;
    cin >> N >> Q;
    
    for (int i = 1; i <= N; ++i) {
        parent[i] = i;
        component[i] = {i};
    }
    
    while (Q--) {
        int op, u, v;
        cin >> op >> u;
        if (op == 1) {
            cin >> v;
            unite(u, v);
        } else {
            int k;
            cin >> k;
            int root = find(u);
            if (k <= component[root].size()) {
                cout << component[root][k-1] << '\n';
            } else {
                cout << "-1\n";
            }
        }
    }
    
    return 0;
}