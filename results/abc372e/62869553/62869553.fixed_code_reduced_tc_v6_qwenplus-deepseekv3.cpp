#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200005;
const int K = 10;

int parent[MAXN];
vector<int> top[MAXN];

int find(int u) {
    while (parent[u] != u) {
        parent[u] = parent[parent[u]];
        u = parent[u];
    }
    return u;
}

void unite(int u, int v) {
    u = find(u);
    v = find(v);
    if (u == v) return;
    
    if (top[u].size() < top[v].size()) {
        swap(u, v);
    }
    
    vector<int> merged;
    merge(top[u].rbegin(), top[u].rend(), 
          top[v].rbegin(), top[v].rend(), 
          back_inserter(merged), greater<int>());
    
    if (merged.size() > K) {
        merged.resize(K);
    }
    top[u].assign(merged.begin(), merged.end());
    parent[v] = u;
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
                cout << top[root][v-1] << "\n";
            }
        }
    }
    
    return 0;
}