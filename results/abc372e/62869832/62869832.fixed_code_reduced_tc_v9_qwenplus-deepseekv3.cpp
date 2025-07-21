#include<bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 5;
vector<int> adj[MAXN];
int fa[MAXN];
int n, q;

int find(int x) {
    return fa[x] == x ? x : fa[x] = find(fa[x]);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        fa[i] = i;
        adj[i].push_back(i);
    }

    while (q--) {
        int op, u, v, k;
        cin >> op;
        if (op == 1) {
            cin >> u >> v;
            int fu = find(u), fv = find(v);
            if (fu != fv) {
                if (adj[fu].size() < adj[fv].size()) {
                    swap(fu, fv);
                }
                fa[fv] = fu;
                adj[fu].insert(adj[fu].end(), adj[fv].begin(), adj[fv].end());
                adj[fv].clear();
                sort(adj[fu].rbegin(), adj[fu].rend());
                if (adj[fu].size() > 10) {
                    adj[fu].resize(10);
                }
            }
        } else {
            cin >> v >> k;
            int fv = find(v);
            if (adj[fv].size() < k) {
                cout << "-1\n";
            } else {
                cout << adj[fv][k-1] << "\n";
            }
        }
    }

    return 0;
}