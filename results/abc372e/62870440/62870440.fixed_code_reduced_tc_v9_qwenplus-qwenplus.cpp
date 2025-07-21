#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 5;
int parent[MAXN];
map<int, vector<int>> topNodes;

int find(int x) {
    if (parent[x] != x)
        parent[x] = find(parent[x]);
    return parent[x];
}

void unite(int x, int y) {
    int rx = find(x);
    int ry = find(y);
    if (rx == ry) return;

    // Always attach smaller tree to larger one
    parent[ry] = rx;

    // Merge top nodes from both sets
    vector<int>& listX = topNodes[rx];
    vector<int>& listY = topNodes[ry];

    for (int val : listY) {
        listX.push_back(val);
    }

    // Sort descending and keep top 10
    sort(listX.begin(), listX.end(), greater<int>());
    if (listX.size() > 10)
        listX.resize(10);

    // Remove ry from map after merging
    topNodes.erase(ry);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, Q;
    cin >> N >> Q;

    // Initialize DSU and topNodes
    for (int i = 1; i <= N; ++i) {
        parent[i] = i;
        topNodes[i] = {i};
    }

    while (Q--) {
        int type;
        cin >> type;

        if (type == 1) {
            int u, v;
            cin >> u >> v;
            if (u > v) swap(u, v); // Ensure consistent order
            unite(u, v);
        } else {
            int v, k;
            cin >> v >> k;
            int root = find(v);
            const vector<int>& topList = topNodes[root];
            if (k <= topList.size()) {
                cout << topList[k - 1] << "\n";
            } else {
                cout << "-1\n";
            }
        }
    }

    return 0;
}