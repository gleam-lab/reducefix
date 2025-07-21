#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 200005;

vector<int> as[MAX_N];
int fa[MAX_N];

int find_fa(int x) {
    if (fa[x] != x) {
        fa[x] = find_fa(fa[x]);
    }
    return fa[x];
}

void merge(int u, int v) {
    u = find_fa(u);
    v = find_fa(v);
    if (u == v) return;
    if (as[u].size() < as[v].size()) {
        swap(u, v);
    }
    vector<int> merged;
    merged.reserve(as[u].size() + as[v].size());
    merge(as[u].begin(), as[u].end(), as[v].begin(), as[v].end(), back_inserter(merged), greater<int>());
    if (merged.size() > 10) {
        merged.resize(10);
    }
    as[u] = merged;
    fa[v] = u;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, Q;
    cin >> N >> Q;

    for (int i = 1; i <= N; ++i) {
        fa[i] = i;
        as[i] = {i};
    }

    while (Q--) {
        int op, u, v;
        cin >> op >> u >> v;
        if (op == 1) {
            merge(u, v);
        } else {
            int root = find_fa(u);
            if (as[root].size() < v) {
                cout << -1 << '\n';
            } else {
                cout << as[root][v - 1] << '\n';
            }
        }
    }

    return 0;
}