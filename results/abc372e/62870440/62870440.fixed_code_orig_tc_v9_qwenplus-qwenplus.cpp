#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 5;
const int K_MAX = 10;

int parent[MAXN];
set<int> components[MAXN];

int find(int x) {
    while (parent[x] != x)
        x = parent[x];
    return x;
}

void unite(int x, int y) {
    int fx = find(x);
    int fy = find(y);
    if (fx == fy)
        return;
    
    // Always merge smaller set into larger one
    if (components[fx].size() < components[fy].size())
        swap(fx, fy);
    
    // Merge the two sets efficiently
    for (int node : components[fy]) {
        components[fx].insert(node);
        parent[node] = fx;
    }
    components[fy].clear();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int N, Q;
    cin >> N >> Q;

    // Initialize DSU
    for (int i = 1; i <= N; ++i) {
        parent[i] = i;
        components[i].insert(i);
    }

    while (Q--) {
        int type;
        cin >> type;
        if (type == 1) {
            int u, v;
            cin >> u >> v;
            unite(u, v);
        } else if (type == 2) {
            int v, k;
            cin >> v >> k;
            int root = find(v);
            if (components[root].size() < k) {
                cout << -1 << '\n';
            } else {
                // Get the k-th largest element
                auto it = components[root].end();
                advance(it, -k);
                cout << *it << '\n';
            }
        }
    }

    return 0;
}