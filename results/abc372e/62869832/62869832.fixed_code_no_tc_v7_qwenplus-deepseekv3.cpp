#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200005;
vector<int> top[MAXN];
int fa[MAXN];

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
    if (top[u].size() < top[v].size()) {
        swap(u, v);
    }
    vector<int> merged;
    merge(top[u].begin(), top[u].end(), top[v].begin(), top[v].end(), back_inserter(merged), greater<int>());
    if (merged.size() > 10) {
        merged.resize(10);
    }
    top[u] = merged;
    fa[v] = u;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, q;
    cin >> n >> q;
    
    for (int i = 1; i <= n; ++i) {
        fa[i] = i;
        top[i] = {i};
    }
    
    while (q--) {
        int op, u, v;
        cin >> op >> u >> v;
        if (op == 1) {
            merge(u, v);
        } else {
            int root = find(u);
            if (v > (int)top[root].size()) {
                cout << -1 << '\n';
            } else {
                cout << top[root][v - 1] << '\n';
            }
        }
    }
    
    return 0;
}