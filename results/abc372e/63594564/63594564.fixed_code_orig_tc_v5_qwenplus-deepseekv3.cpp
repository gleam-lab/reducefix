#include "bits/stdc++.h"

using namespace std;

#define ff first
#define ss second
#define ll long long
#define SZ(s) (int)s.size()

int const N = 2e5 + 5;

vector<multiset<int>> v;
vector<int> p;
vector<int> sz;

int par(int x) {
    if (p[x] == x) return x;
    return p[x] = par(p[x]);
}

void uni(int a, int b) {
    a = par(a), b = par(b);
    if (a == b) return;
    if (sz[a] < sz[b]) swap(a, b);
    
    // Merge smaller into larger
    v[a].insert(v[b].begin(), v[b].end());
    while (v[a].size() > 10) {
        v[a].erase(v[a].begin());
    }
    
    p[b] = a;
    sz[a] += sz[b];
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int n, q;
    cin >> n >> q;
    p.resize(n + 1);
    sz.resize(n + 1, 1);
    v.resize(n + 1);
    
    for (int i = 1; i <= n; i++) {
        p[i] = i;
        v[i].insert(i);
    }
    
    while (q--) {
        int t, a, b;
        cin >> t >> a >> b;
        if (t == 1) {
            uni(a, b);
        } else {
            a = par(a);
            if (v[a].size() < b) {
                cout << -1 << '\n';
            } else {
                auto it = v[a].end();
                advance(it, -b);
                cout << *it << '\n';
            }
        }
    }

    return 0;
}