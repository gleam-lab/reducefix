#include <bits/stdc++.h>
using namespace std;

const int K_MAX = 10;
int N, Q;
vector<int> parent, rank_;
vector<vector<int>> top_nodes;

// Find with path compression
int find(int x) {
    if (parent[x] != x)
        parent[x] = find(parent[x]);
    return parent[x];
}

// Merge two sets while keeping top K values
void unite(int x, int y) {
    int px = find(x);
    int py = find(y);
    if (px == py) return;

    // Union by rank
    if (rank_[px] < rank_[py])
        swap(px, py);

    parent[py] = px;
    if (rank_[px] == rank_[py])
        rank_[py]++;

    // Merge top_k lists
    vector<int> merged;
    auto& lx = top_nodes[px];
    auto& ly = top_nodes[py];

    int i = 0, j = 0;
    while ((i < lx.size() || j < ly.size()) && merged.size() < K_MAX) {
        if (j >= ly.size() || (i < lx.size() && lx[i] > ly[j])) {
            merged.push_back(lx[i++]);
        } else {
            merged.push_back(ly[j++]);
        }
    }

    top_nodes[px] = merged;
}

// Add an edge between u and v
void add_edge(int u, int v) {
    unite(u, v);
}

// Query: get k-th largest node in the component containing v
int query_kth_largest(int v, int k) {
    auto p = find(v);
    if (top_nodes[p].size() < k)
        return -1;
    return top_nodes[p][k - 1];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> Q;

    parent.resize(N + 1);
    rank_.resize(N + 1);
    top_nodes.resize(N + 1);

    for (int i = 1; i <= N; ++i) {
        parent[i] = i;
        rank_[i] = 0;
        top_nodes[i] = {i};
    }

    while (Q--) {
        int t;
        cin >> t;
        if (t == 1) {
            int u, v;
            cin >> u >> v;
            add_edge(u, v);
        } else {
            int v, k;
            cin >> v >> k;
            cout << query_kth_largest(v, k) << "\n";
        }
    }

    return 0;
}