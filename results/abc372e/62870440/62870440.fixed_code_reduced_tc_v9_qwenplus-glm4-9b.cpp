#include<bits/stdc++.h>
using namespace std;
int fa[200005];
int n, q;
vector<int> g[200005];

int gtf(int x) {
    if (fa[x] != x) {
        fa[x] = gtf(fa[x]); // Path compression
    }
    return fa[x];
}

void unite(int x, int y) {
    int fx = gtf(x);
    int fy = gtf(y);
    if (fx != fy) {
        fa[fy] = fx; // Union operation
        merge(g[fx].begin(), g[fx].end(), g[fy].begin(), g[fy].end());
        sort(g[fx].begin(), g[fx].end()); // Sort the merged list of vertices
    }
}

int main() {
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        g[i].push_back(i); // Initialize each vertex with itself
        fa[i] = i;
    }
    for (int i = 0; i < q; i++) {
        int op, u, v, k;
        cin >> op >> u >> v;
        if (op == 1) {
            unite(u, v);
        } else {
            if (gtf(u) != gtf(v)) {
                cout << -1 << endl;
            } else {
                if (k > g[gtf(u)].size()) {
                    cout << -1 << endl;
                } else {
                    cout << g[gtf(u)][k - 1] << endl;
                }
            }
        }
    }
    return 0;
}