#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200005;
const int K = 10;

int parent[MAXN];
vector<int> topKList[MAXN];

int find(int x) {
    if (parent[x] != x)
        parent[x] = find(parent[x]);
    return parent[x];
}

void unite(int x, int y) {
    int px = find(x);
    int py = find(y);
    if (px == py) return;

    // Always attach smaller tree to larger one
    parent[py] = px;
    // Merge the top-K lists
    vector<int> merged;
    merged.insert(merged.end(), topKList[px].begin(), topKList[px].end());
    merged.insert(merged.end(), topKList[py].begin(), topKList[py].end());

    // Sort and keep top K largest values
    sort(merged.begin(), merged.end(), greater<int>());
    if (merged.size() > K)
        merged.resize(K);
    topKList[px] = merged;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, Q;
    cin >> N >> Q;

    // Initialize DSU and topKList
    for (int i = 1; i <= N; ++i) {
        parent[i] = i;
        topKList[i].push_back(i);
    }

    while (Q--) {
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
            if ((int)topKList[root].size() < k)
                cout << -1 << '\n';
            else
                cout << topKList[root][k - 1] << '\n';
        }
    }

    return 0;
}