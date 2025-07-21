#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200005;
int parent[MAXN];
vector<int> component[MAXN];

int find(int u) {
    if (parent[u] != u) {
        parent[u] = find(parent[u]);
    }
    return parent[u];
}

void unite(int u, int v) {
    u = find(u);
    v = find(v);
    if (u == v) return;
    
    if (component[u].size() < component[v].size()) {
        swap(u, v);
    }
    
    parent[v] = u;
    component[u].insert(component[u].end(), component[v].begin(), component[v].end());
    component[v].clear();
    sort(component[u].rbegin(), component[u].rend());
    if (component[u].size() > 10) {
        component[u].resize(10);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N, Q;
    cin >> N >> Q;
    
    for (int i = 1; i <= N; i++) {
        parent[i] = i;
        component[i] = {i};
    }
    
    while (Q--) {
        int op, u, v;
        cin >> op >> u >> v;
        
        if (op == 1) {
            unite(u, v);
        } else {
            int root = find(u);
            if (v > component[root].size()) {
                cout << "-1\n";
            } else {
                cout << component[root][v-1] << "\n";
            }
        }
    }
    
    return 0;
}