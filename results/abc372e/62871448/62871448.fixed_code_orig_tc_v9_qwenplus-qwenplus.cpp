#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 5;
const int K = 10;

int parent[MAXN];
vector<int> top[MAXN]; // Stores up to K largest vertices in the set

// Find with path compression
int find(int x) {
    if (parent[x] != x)
        parent[x] = find(parent[x]);
    return parent[x];
}

// Merge two sets and maintain top K largest elements
void unite(int x, int y) {
    int rootX = find(x);
    int rootY = find(y);

    if (rootX == rootY)
        return;

    // Always attach smaller tree to larger tree
    if (top[rootX].size() < top[rootY].size())
        swap(rootX, rootY);

    // Merge the top elements
    vector<int> merged;
    int i = 0, j = 0;
    while (i < top[rootX].size() && j < top[rootY].size() && merged.size() < K) {
        if (top[rootX][i] > top[rootY][j])
            merged.push_back(top[rootX][i++]);
        else
            merged.push_back(top[rootY][j++]);
    }

    while (i < top[rootX].size() && merged.size() < K)
        merged.push_back(top[rootX][i++]);

    while (j < top[rootY].size() && merged.size() < K)
        merged.push_back(top[rootY][j++]);

    // Update the new root
    parent[rootY] = rootX;
    top[rootX] = merged;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, Q;
    cin >> N >> Q;

    // Initialize DSU and top arrays
    for (int i = 1; i <= N; ++i) {
        parent[i] = i;
        top[i] = {i}; // Initially each node contains itself
    }

    for (int q = 0; q < Q; ++q) {
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
            if (k <= top[root].size())
                cout << top[root][k - 1] << '\n';
            else
                cout << "-1\n";
        }
    }

    return 0;
}