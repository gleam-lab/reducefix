#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 5;
const int K_MAX = 10;

int parent[MAXN];
vector<int> group[MAXN];

int find(int u) {
    return parent[u] == u ? u : parent[u] = find(parent[u]);
}

void unite(int u, int v) {
    int pu = find(u);
    int pv = find(v);
    if (pu == pv) return;

    // Always merge smaller into larger
    if (group[pu].size() < group[pv].size()) swap(pu, pv);

    // Merge top elements
    for (int x : group[pv]) {
        group[pu].push_back(x);
    }
    sort(group[pu].rbegin(), group[pu].rend());
    if (group[pu].size() > K_MAX) {
        group[pu].resize(K_MAX);
    }

    parent[pv] = pu;
    group[pv].clear();
}

void processQueries() {
    int N, Q;
    cin >> N >> Q;

    for (int i = 1; i <= N; ++i) {
        parent[i] = i;
        group[i].push_back(i);
    }

    for (int q = 0; q < Q; ++q) {
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
            if ((int)group[root].size() < k) {
                cout << -1 << "\n";
            } else {
                cout << group[root][k - 1] << "\n";
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    processQueries();
    return 0;
}