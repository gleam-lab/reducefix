#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

const int N = 2e5 + 5;

int parent[N];
vector<int> comp[N];

void init() {
    for (int i = 0; i < N; i++) {
        parent[i] = i;
        comp[i].push_back(i);
    }
}

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
    
    if (comp[u].size() < comp[v].size()) {
        swap(u, v);
    }
    
    parent[v] = u;
    comp[u].insert(comp[u].end(), comp[v].begin(), comp[v].end());
    sort(comp[u].rbegin(), comp[u].rend());
    if (comp[u].size() > 10) {
        comp[u].resize(10);
    }
    comp[v].clear();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    init();
    
    int n, q;
    cin >> n >> q;
    
    while (q--) {
        int type;
        cin >> type;
        if (type == 1) {
            int u, v;
            cin >> u >> v;
            unite(u, v);
        } else {
            int v, k;
            cin >> v >> k;
            v = find(v);
            if (comp[v].size() < k) {
                cout << -1 << '\n';
            } else {
                cout << comp[v][k-1] << '\n';
            }
        }
    }
    
    return 0;
}