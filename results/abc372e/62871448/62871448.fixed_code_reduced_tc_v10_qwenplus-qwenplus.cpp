#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 5;

int N, Q;
vector<int> tops[MAXN];
int fa[MAXN];

// Find with path compression
int find(int x) {
    if (fa[x] != x)
        fa[x] = find(fa[x]);
    return fa[x];
}

// Merge two sets, keeping only top 10 elements
void unite(int u, int v) {
    int fu = find(u);
    int fv = find(v);
    if (fu == fv) return;

    // Always merge smaller into larger for efficiency
    if (tops[fu].size() < tops[fv].size())
        swap(fu, fv);

    // Merge the tops
    for (int val : tops[fv])
        tops[fu].push_back(val);

    // Sort descending and keep top 10
    sort(tops[fu].rbegin(), tops[fu].rend());
    if (tops[fu].size() > 10)
        tops[fu].resize(10);

    // Union
    fa[fv] = fu;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> Q;

    // Initialize DSU and tops
    for (int i = 1; i <= N; ++i) {
        fa[i] = i;
        tops[i].push_back(i);
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
            if ((int)tops[root].size() < k)
                cout << -1 << '\n';
            else
                cout << tops[root][k - 1] << '\n';
        }
    }

    return 0;
}