#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 5;
int parent[MAXN];
vector<int> top[MAXN];

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
    
    if (top[u].size() < top[v].size()) {
        swap(u, v);
    }
    
    parent[v] = u;
    
    vector<int> merged;
    merge(top[u].rbegin(), top[u].rend(),
          top[v].rbegin(), top[v].rend(),
          back_inserter(merged), greater<int>());
    
    if (merged.size() > 10) {
        merged.resize(10);
    }
    
    top[u].assign(merged.rbegin(), merged.rend());
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N, Q;
    cin >> N >> Q;
    
    for (int i = 1; i <= N; ++i) {
        parent[i] = i;
        top[i] = {i};
    }
    
    while (Q--) {
        int op, u, v;
        cin >> op >> u >> v;
        
        if (op == 1) {
            unite(u, v);
        } else {
            int root = find(u);
            if (v > top[root].size()) {
                cout << "-1\n";
            } else {
                cout << top[root][top[root].size() - v] << '\n';
            }
        }
    }
    
    return 0;
}