#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 5;
const int K_LIMIT = 10;

int parent[MAXN];
vector<int> topVertices[MAXN]; // Stores up to 10 largest vertices in descending order

// Find with path compression
int find(int x) {
    if (parent[x] != x)
        parent[x] = find(parent[x]);
    return parent[x];
}

// Union of two sets
void unite(int x, int y) {
    int rootX = find(x);
    int rootY = find(y);
    if (rootX == rootY) return;

    // Always merge smaller into larger for efficiency
    if (topVertices[rootX].size() < topVertices[rootY].size())
        swap(rootX, rootY);

    // Merge top vertices
    vector<int> merged;
    int i = 0, j = 0;
    while (merged.size() < K_LIMIT && (i < topVertices[rootX].size() || j < topVertices[rootY].size())) {
        if (j >= topVertices[rootY].size() || (i < topVertices[rootX].size() && topVertices[rootX][i] > topVertices[rootY][j]))
            merged.push_back(topVertices[rootX][i++]);
        else
            merged.push_back(topVertices[rootY][j++]);
    }

    // Remove duplicates
    vector<int> uniqueMerged;
    for (int v : merged) {
        if (uniqueMerged.empty() || v != uniqueMerged.back())
            uniqueMerged.push_back(v);
    }

    // Update the larger root
    topVertices[rootX] = uniqueMerged;
    parent[rootY] = rootX;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, Q;
    cin >> N >> Q;

    // Initialize DSU and topVertices
    for (int i = 1; i <= N; ++i) {
        parent[i] = i;
        topVertices[i].push_back(i);
    }

    for (int q = 0; q < Q; ++q) {
        int op;
        cin >> op;
        if (op == 1) {
            int u, v;
            cin >> u >> v;
            unite(u, v);
        } else {
            int v, k;
            cin >> v >> k;
            int root = find(v);
            if (k <= topVertices[root].size())
                cout << topVertices[root][k - 1] << '\n';
            else
                cout << "-1\n";
        }
    }

    return 0;
}