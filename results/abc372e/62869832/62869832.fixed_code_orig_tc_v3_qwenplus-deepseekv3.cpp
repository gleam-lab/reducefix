#include<bits/stdc++.h>
using namespace std;

const int MAXN = 200005;
const int K = 10;

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
    
    vector<int> merged;
    merge(component[u].rbegin(), component[u].rend(),
          component[v].rbegin(), component[v].rend(),
          back_inserter(merged), greater<int>());
    
    if (merged.size() > K) {
        merged.resize(K);
    }
    
    component[u].assign(merged.rbegin(), merged.rend());
    parent[v] = u;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N, Q;
    cin >> N >> Q;
    
    for (int i = 1; i <= N; i++) {
        parent[i] = i;
        component[i].push_back(i);
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
                cout << component[root][component[root].size() - v] << "\n";
            }
        }
    }
    
    return 0;
}