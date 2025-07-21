#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200005;
vector<int> top[MAXN]; // Stores top 10 largest vertices in each component's root
int fa[MAXN];

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
    if (top[u].size() < top[v].size()) swap(u, v);
    for (int num : top[v]) {
        top[u].push_back(num);
    }
    sort(top[u].rbegin(), top[u].rend());
    if (top[u].size() > 10) {
        top[u].resize(10);
    }
    fa[v] = u;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, Q;
    cin >> N >> Q;
    for (int i = 1; i <= N; ++i) {
        fa[i] = i;
        top[i].push_back(i);
    }
    while (Q--) {
        int op, u, v;
        cin >> op >> u >> v;
        if (op == 1) {
            unite(u, v);
        } else {
            int root = find(u);
            if (v > top[root].size()) {
                cout << "-1\n";
            } else {
                cout << top[root][v - 1] << '\n';
            }
        }
    }
    return 0;
}