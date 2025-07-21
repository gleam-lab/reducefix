#include <bits/stdc++.h>

using namespace std;

#define ff first
#define ss second
#define ll long long
#define SZ(s) (int)s.size()

const int N = 2e5 + 5;

vector<int> p, sz, rank;
multiset<int> adj[N];

int par(int x) {
    if (p[x] == x) return x;
    return p[x] = par(p[x]);
}

void uni(int a, int b) {
    a = par(a), b = par(b);
    if (a == b) return;
    if (sz[a] < sz[b]) swap(a, b);
    sz[a] += sz[b];
    p[b] = a;
    adj[a].insert(adj[b].begin(), adj[b].end());
    adj[b].clear();
    adj[a].erase(adj[a].find(b));
    adj[a].insert(sz[a]);
    adj[a].insert(sz[b]);
    rank[a] = max(rank[a], rank[b]);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int n, q;
    cin >> n >> q;
    p.resize(n + 1), sz.resize(n + 1, 1), rank.resize(n + 1, 1);
    for (int i = 1; i <= n; i++) p[i] = i;

    while (q--) {
        int t, a, b;
        cin >> t >> a >> b;
        if (t == 1) {
            uni(a, b);
        } else {
            a = par(a);
            auto it = adj[a].rbegin();
            if (it != adj[a].rend() && *it >= b) {
                cout << *prev(it) << '\n';
            } else {
                cout << -1 << '\n';
            }
        }
    }

    return 0;
}