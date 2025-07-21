#include<bits/stdc++.h>
using namespace std;
vector<int> par(200005); // Parent array
vector<int> size(200005, 1); // Size of the set
vector< vector<int> > group(200005); // Group of nodes

int root(int x) {
    if (x != par[x]) par[x] = root(par[x]);
    return par[x];
}

void unite(int x, int y) {
    int rx = root(x);
    int ry = root(y);
    if (rx != ry) {
        if (size[rx] < size[ry]) {
            swap(rx, ry);
        }
        par[ry] = rx;
        size[rx] += size[ry];
        merge(group[rx], group[ry]);
        sort(group[rx].begin(), group[rx].end(), greater<int>());
    }
}

bool is_same_group(int x, int y) {
    return root(x) == root(y);
}

int main() {
    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        par[i] = i;
        group[i].push_back(i);
    }
    int u, v, op, k;
    while (q--) {
        cin >> op;
        if (op == 1) {
            cin >> u >> v;
            unite(u, v);
        } else {
            cin >> v >> k;
            if (group[root(v)].size() < k) {
                cout << -1 << "\n";
            } else {
                cout << group[root(v)][k - 1] << "\n";
            }
        }
    }
    return 0;
}