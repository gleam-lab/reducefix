#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200005;
vector<int> as[MAXN];
int fa[MAXN];
int n, q;

int find(int x) {
    if (fa[x] != x) {
        fa[x] = find(fa[x]);
    }
    return fa[x];
}

void unite(int u, int v) {
    u = find(u);
    v = find(v);
    if (u == v) return;
    if (as[u].size() < as[v].size()) {
        swap(u, v);
    }
    fa[v] = u;
    as[u].insert(as[u].end(), as[v].begin(), as[v].end());
    sort(as[u].rbegin(), as[u].rend());
    if (as[u].size() > 10) {
        as[u].resize(10);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> q;
    for (int i = 1; i <= n; ++i) {
        fa[i] = i;
        as[i] = {i};
    }

    while (q--) {
        int op, u, v;
        cin >> op >> u >> v;
        if (op == 1) {
            unite(u, v);
        } else {
            int root = find(u);
            if (v > as[root].size()) {
                cout << -1 << '\n';
            } else {
                cout << as[root][v - 1] << '\n';
            }
        }
    }

    return 0;
}