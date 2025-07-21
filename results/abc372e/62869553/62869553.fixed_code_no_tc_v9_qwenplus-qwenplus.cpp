#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200005;
const int TOP_K = 10;

int fa[MAXN];
set<int, greater<int>> groups[MAXN]; // Store top 10 largest nodes in each group

// Find with path compression
int find(int x) {
    if (fa[x] != x)
        fa[x] = find(fa[x]);
    return fa[x];
}

// Merge two disjoint sets maintaining the top 10 elements
void unite(int x, int y) {
    int fx = find(x);
    int fy = find(y);
    if (fx == fy)
        return;

    // Always merge smaller set into larger one
    if (groups[fx].size() < groups[fy].size())
        swap(fx, fy);

    // Move elements from fy to fx and maintain top 10
    for (int val : groups[fy]) {
        if (groups[fx].size() < TOP_K)
            groups[fx].insert(val);
        else if (val > *groups[fx].rbegin()) {
            groups[fx].insert(val);
            if (groups[fx].size() > TOP_K)
                groups[fx].erase(--groups[fx].end());
        }
    }

    // Clear the smaller set
    groups[fy].clear();
    fa[fy] = fx;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int N, Q;
    cin >> N >> Q;

    // Initialize DSU and each group with its own node
    for (int i = 1; i <= N; ++i) {
        fa[i] = i;
        groups[i].insert(i);
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
            int fv = find(v);
            if (groups[fv].size() < k)
                cout << -1 << '\n';
            else {
                auto it = groups[fv].begin();
                advance(it, k - 1);
                cout << *it << '\n';
            }
        }
    }

    return 0;
}