#include "bits/stdc++.h"

using namespace std;

#define ff first
#define ss second
#define ll long long
#define SZ(s) (int)s.size()

int const N = 2e5 + 5;

vector<vector<int>> v;
vector<int> p, sz, pos;

int par(int x) {
    if (p[x] != x) p[x] = par(p[x]);
    return p[x];
}

void uni(int a, int b) {
    a = par(a), b = par(b);
    if (a == b) return;
    if (sz[a] < sz[b]) swap(a, b);
    for (auto &x : v[b]) {
        auto it = upper_bound(begin(v[a]), end(v[a]), x);
        v[a].insert(it, x);
    }
    sz[a] += sz[b];
    pos.erase(pos.begin() + pos[b]);
    pos[b] = -1;
    v[b].clear();
    p[b] = a;
}

int kthLargest(vector<int>& arr, int k) {
    if (k > arr.size()) return -1;
    return arr[k - 1];
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int n, q;
    cin >> n >> q;
    p.resize(n + 1);
    sz.resize(n + 1, 1);
    v.resize(n + 1);
    pos.resize(n + 1);
    
    iota(begin(p), end(p), 0);
    iota(begin(pos), end(pos), 0);
    
    while (q--) {
        int t, a, b;
        cin >> t >> a >> b;
        if (t == 1) {
            uni(a, b);
        } else {
            a = par(a);
            cout << kthLargest(v[a], b) << '\n';
        }
    }

    return 0;
}