#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 5;
int parent[MAXN];
multiset<int, greater<int>> components[MAXN];

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
    
    if (components[u].size() < components[v].size()) {
        swap(u, v);
    }
    
    parent[v] = u;
    for (int x : components[v]) {
        components[u].insert(x);
    }
    components[v].clear();
    
    while (components[u].size() > 10) {
        components[u].erase(prev(components[u].end()));
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N, Q;
    cin >> N >> Q;
    
    for (int i = 1; i <= N; i++) {
        parent[i] = i;
        components[i].insert(i);
    }
    
    while (Q--) {
        int type, u, v;
        cin >> type >> u;
        if (type == 1) {
            cin >> v;
            unite(u, v);
        } else {
            int k;
            cin >> k;
            int root = find(u);
            if (components[root].size() < k) {
                cout << "-1\n";
            } else {
                auto it = components[root].begin();
                advance(it, k-1);
                cout << *it << "\n";
            }
        }
    }
    
    return 0;
}