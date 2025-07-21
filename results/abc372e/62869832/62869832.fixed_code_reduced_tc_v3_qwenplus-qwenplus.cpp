#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 5;
const int K = 10;

int parent[MAXN];
vector<int> topKVertices[MAXN];

int find(int x) {
    if (parent[x] != x)
        parent[x] = find(parent[x]);
    return parent[x];
}

void unite(int x, int y) {
    int fx = find(x);
    int fy = find(y);
    if (fx == fy) return;

    // Union by size
    if (topKVertices[fx].size() < topKVertices[fy].size())
        swap(fx, fy);

    // Merge top-K lists
    vector<int> merged;
    merged.reserve(K * 2);
    merged.insert(merged.end(), topKVertices[fx].begin(), topKVertices[fx].end());
    merged.insert(merged.end(), topKVertices[fy].begin(), topKVertices[fy].end());

    // Sort descending and keep top-K
    sort(merged.begin(), merged.end(), greater<int>());
    merged.resize(min(K, (int)merged.size()));

    // Update the larger set
    topKVertices[fx] = merged;

    // Point smaller set to larger set
    parent[fy] = fx;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, Q;
    cin >> N >> Q;

    // Initialize DSU
    for (int i = 1; i <= N; ++i) {
        parent[i] = i;
        topKVertices[i].push_back(i);
    }

    while (Q--) {
        int type;
        cin >> type;
        if (type == 1) {
            int u, v;
            cin >> u >> v;
            unite(u, v);
        } else {
            int v, k;
            cin >> v >> k;
            int root = find(v);
            if ((int)topKVertices[root].size() < k)
                cout << -1 << '\n';
            else
                cout << topKVertices[root][k - 1] << '\n';
        }
    }

    return 0;
}