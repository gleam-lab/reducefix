#include<bits/stdc++.h>
using namespace std;

const int MAXN = 200005;
vector<int> adj[MAXN];
int parent[MAXN], size[MAXN];

void init(int n) {
    iota(parent, parent + n + 1, 0); // Initialize parent array
    fill(size, size + n + 1, 1);     // Initialize size array
}

int find(int u) {
    if (u != parent[u])
        parent[u] = find(parent[u]); // Path compression
    return parent[u];
}

void unite(int u, int v) {
    u = find(u);
    v = find(v);
    if (u == v) return;
    
    if (size[u] > size[v]) swap(u, v); // Union by rank
    parent[u] = v;
    size[v] += size[u];
    adj[v].insert(adj[v].end(), adj[u].begin(), adj[u].end());
    sort(adj[v].begin(), adj[v].end(), greater<int>());
    adj[u].clear();
}

vector<int> getConnectedVertices(int v) {
    v = find(v);
    return adj[v];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;
    init(n);

    while (q--) {
        int op, ix, iy;
        cin >> op >> ix >> iy;
        if (op == 1) {
            unite(ix, iy);
        } else {
            vector<int> connected = getConnectedVertices(iy);
            if (connected.size() < ix) {
                cout << "-1\n";
            } else {
                cout << connected[ix - 1] << "\n";
            }
        }
    }

    return 0;
}