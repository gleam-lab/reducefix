#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int N = 2e5 + 5;

int parent[N];
vector<int> component[N];

int find(int u) {
    if (parent[u] != u) {
        parent[u] = find(parent[u]);
    }
    return parent[u];
}

void merge(int u, int v) {
    u = find(u);
    v = find(v);
    if (u == v) return;
    
    if (component[u].size() < component[v].size()) {
        swap(u, v);
    }
    
    parent[v] = u;
    for (int x : component[v]) {
        component[u].push_back(x);
    }
    sort(component[u].rbegin(), component[u].rend());
    if (component[u].size() > 10) {
        component[u].resize(10);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, q;
    cin >> n >> q;
    
    for (int i = 1; i <= n; i++) {
        parent[i] = i;
        component[i] = {i};
    }
    
    while (q--) {
        int type;
        cin >> type;
        if (type == 1) {
            int u, v;
            cin >> u >> v;
            merge(u, v);
        } else {
            int v, k;
            cin >> v >> k;
            v = find(v);
            if (k > component[v].size()) {
                cout << "-1\n";
            } else {
                cout << component[v][k-1] << "\n";
            }
        }
    }
    
    return 0;
}