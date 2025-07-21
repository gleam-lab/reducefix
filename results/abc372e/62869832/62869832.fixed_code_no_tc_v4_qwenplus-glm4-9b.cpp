#include <bits/stdc++.h>
using namespace std;
vector<int> g[200005];
int parent[200005];
int size[200005];
int n, q;

void findSet(int v) {
    if (parent[v] != v) {
        parent[v] = findSet(parent[v]);
    }
    return parent[v];
}

void unite(int v, int u) {
    v = findSet(v);
    u = findSet(u);
    if (v != u) {
        parent[u] = v;
        size[v] += size[u];
    }
}

int connectedVertices(int v) {
    v = findSet(v);
    return size[v];
}

int main() {
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        parent[i] = i;
        size[i] = 1;
    }
    int type, u, v;
    while (q--) {
        cin >> type >> u >> v;
        if (type == 1) {
            unite(u, v);
        } else if (type == 2) {
            if (connectedVertices(v) < v) {
                cout << -1 << endl;
            } else {
                cout << v << endl;
            }
        }
    }
    return 0;
}