#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200005;
vector<int> as[MAXN]; // Each component's root stores top 10 largest vertices
int fa[MAXN];
int N, Q;

int find(int x) {
    if (fa[x] != x) {
        fa[x] = find(fa[x]);
    }
    return fa[x];
}

void merge(int u, int v) {
    u = find(u);
    v = find(v);
    if (u == v) return;
    if (as[u].size() < as[v].size()) {
        swap(u, v);
    }
    // Merge v's top 10 into u's top 10
    vector<int> merged;
    merged.reserve(as[u].size() + as[v].size());
    merged.insert(merged.end(), as[u].begin(), as[u].end());
    merged.insert(merged.end(), as[v].begin(), as[v].end());
    sort(merged.begin(), merged.end(), greater<int>());
    if (merged.size() > 10) {
        merged.resize(10);
    }
    as[u] = merged;
    fa[v] = u;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
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
            int root = find(u);
            if (as[root].size() < v) {
                cout << -1 << '\n';
            } else {
                cout << as[root][v - 1] << '\n';
            }
        }
    }
    return 0;
}