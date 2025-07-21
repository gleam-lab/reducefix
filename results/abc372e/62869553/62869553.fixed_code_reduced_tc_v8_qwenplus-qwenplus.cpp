#include <bits/stdc++.h>
using namespace std;

const int K_LIMIT = 10;

int N, Q;
vector<int> root_data[200005]; // Each root keeps track of top 10 nodes
int parent[200005];
int size[200005];

// Find with path compression
int find(int x) {
    if (parent[x] != x) {
        parent[x] = find(parent[x]);
    }
    return parent[x];
}

// Merge two sets ensuring we preserve top K_LIMIT elements
void unite(int x, int y) {
    int fx = find(x);
    int fy = find(y);
    if (fx == fy) return;

    // Always merge smaller set into larger one
    if (size[fx] < size[fy]) swap(fx, fy);

    // Append the top elements from fy to fx
    for (int val : root_data[fy]) {
        root_data[fx].push_back(val);
    }

    // Sort and retain only top K_LIMIT elements
    sort(root_data[fx].begin(), root_data[fx].end(), greater<int>());
    if (root_data[fx].size() > K_LIMIT)
        root_data[fx].resize(K_LIMIT);

    // Update DSU
    parent[fy] = fx;
    size[fx] += size[fy];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> Q;

    // Initialize DSU and root data
    for (int i = 1; i <= N; ++i) {
        parent[i] = i;
        size[i] = 1;
        root_data[i].push_back(i); // Start with itself
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
            if (k <= root_data[root].size()) {
                cout << root_data[root][k - 1] << '\n';
            } else {
                cout << "-1\n";
            }
        }
    }

    return 0;
}