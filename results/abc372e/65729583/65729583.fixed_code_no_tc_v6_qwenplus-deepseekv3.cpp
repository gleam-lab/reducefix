#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int N = 2e5 + 10;
int parent[N];
vector<int> vertices[N];

int Find(int u) {
    if (parent[u] != u) {
        parent[u] = Find(parent[u]);
    }
    return parent[u];
}

void Union(int u, int v) {
    u = Find(u);
    v = Find(v);
    if (u == v) return;
    
    if (vertices[u].size() < vertices[v].size()) {
        swap(u, v);
    }
    
    parent[v] = u;
    for (int x : vertices[v]) {
        vertices[u].push_back(x);
    }
    
    // Keep only top 10 elements to optimize memory
    sort(vertices[u].rbegin(), vertices[u].rend());
    if (vertices[u].size() > 10) {
        vertices[u].resize(10);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, q;
    cin >> n >> q;
    
    for (int i = 1; i <= n; ++i) {
        parent[i] = i;
        vertices[i] = {i};
    }
    
    while (q--) {
        int cmd;
        cin >> cmd;
        if (cmd == 1) {
            int u, v;
            cin >> u >> v;
            Union(u, v);
        } else {
            int v, k;
            cin >> v >> k;
            v = Find(v);
            if (vertices[v].size() < k) {
                cout << "-1\n";
            } else {
                cout << vertices[v][k-1] << '\n';
            }
        }
    }
    
    return 0;
}