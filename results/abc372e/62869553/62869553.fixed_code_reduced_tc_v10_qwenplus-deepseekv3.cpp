#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200005;

vector<vector<int>> topK(MAXN, vector<int>());
int parent[MAXN];
int n, q;

int find(int u) {
    if (parent[u] != u)
        parent[u] = find(parent[u]);
    return parent[u];
}

void merge(int u, int v) {
    u = find(u);
    v = find(v);
    if (u == v) return;
    if (topK[u].size() < topK[v].size())
        swap(u, v);
    parent[v] = u;
    topK[u].insert(topK[u].end(), topK[v].begin(), topK[v].end());
    sort(topK[u].rbegin(), topK[u].rend());
    if (topK[u].size() > 10)
        topK[u].resize(10);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> q;
    for (int i = 1; i <= n; ++i) {
        parent[i] = i;
        topK[i] = {i};
    }

    while (q--) {
        int op, u, v;
        cin >> op >> u >> v;
        if (op == 1) {
            merge(u, v);
        } else {
            u = find(u);
            if (topK[u].size() < v) {
                cout << "-1\n";
            } else {
                cout << topK[u][v - 1] << "\n";
            }
        }
    }

    return 0;
}