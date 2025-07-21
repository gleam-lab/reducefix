#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200005;
int fa[MAXN];
vector<int> adj[MAXN];
set<int> comp[MAXN];

int find(int x) {
    return fa[x] == x ? x : fa[x] = find(fa[x]);
}

void unite(int u, int v) {
    u = find(u);
    v = find(v);
    if (u == v) return;
    
    if (comp[u].size() < comp[v].size()) {
        swap(u, v);
    }
    
    fa[v] = u;
    for (int x : comp[v]) {
        comp[u].insert(x);
    }
    comp[v].clear();
    
    while (comp[u].size() > 10) {
        comp[u].erase(comp[u].begin());
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N, Q;
    cin >> N >> Q;
    
    for (int i = 1; i <= N; i++) {
        fa[i] = i;
        comp[i].insert(i);
    }
    
    while (Q--) {
        int op, u, v;
        cin >> op >> u >> v;
        
        if (op == 1) {
            unite(u, v);
        } else {
            int root = find(u);
            if (comp[root].size() < v) {
                cout << "-1\n";
            } else {
                auto it = comp[root].end();
                advance(it, -v);
                cout << *it << "\n";
            }
        }
    }
    
    return 0;
}