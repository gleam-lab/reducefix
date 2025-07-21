#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

const int MAXN = 2e5 + 5;

int parent[MAXN];
set<int>* adj[MAXN];

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
    
    if (adj[u]->size() < adj[v]->size()) swap(u, v);
    
    for (int x : *adj[v]) {
        adj[u]->insert(x);
    }
    delete adj[v];
    parent[v] = u;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N, Q;
    cin >> N >> Q;
    
    for (int i = 1; i <= N; ++i) {
        parent[i] = i;
        adj[i] = new set<int>();
        adj[i]->insert(i);
    }
    
    while (Q--) {
        int cmd;
        cin >> cmd;
        if (cmd == 1) {
            int u, v;
            cin >> u >> v;
            unite(u, v);
        } else {
            int v, k;
            cin >> v >> k;
            v = find(v);
            if (adj[v]->size() < k) {
                cout << -1 << '\n';
            } else {
                auto it = adj[v]->end();
                advance(it, -k);
                cout << *it << '\n';
            }
        }
    }
    
    for (int i = 1; i <= N; ++i) {
        if (adj[i] != nullptr) {
            delete adj[i];
        }
    }
    
    return 0;
}