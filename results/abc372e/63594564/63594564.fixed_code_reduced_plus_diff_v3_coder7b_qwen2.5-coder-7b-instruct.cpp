#include "bits/stdc++.h"

using namespace std;

#define ff first
#define ss second
#define ll long long
#define SZ(s) (int)s.size()

int const N = 2e5 + 5;

vector<vector<int>> v;
vector<int> sz, parent;

int find(int x) {
    if (parent[x] != x) {
        parent[x] = find(parent[x]);
    }
    return parent[x];
}

void unite(int a, int b) {
    a = find(a);
    b = find(b);
    if (a == b) return;
    
    if (sz[a] < sz[b]) swap(a, b);
    
    v[a].insert(v[a].end(), v[b].begin(), v[b].end());
    sort(v[a].begin(), v[a].end());
    v[a].resize(10);
    
    sz[a] += sz[b];
    parent[b] = a;
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int n, q;
    cin >> n >> q;
    parent.resize(n + 1);
    sz.resize(n + 1, 1);
    iota(parent.begin(), parent.end(), 0);
    v.resize(n + 1);
    
    for (int i = 1; i <= n; i++) {
        v[i].push_back(i);
    }
    
    while (q--) {
        int t, a, b;
        cin >> t >> a >> b;
        
        if (t == 1) {
            unite(a, b);
        } else {
            a = find(a);
            if (v[a].size() < b) {
                cout << "-1\n";
            } else {
                cout << v[a][v[a].size() - b] << "\n";
            }
        }
    }

    return 0;
}