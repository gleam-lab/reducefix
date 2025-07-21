#include "bits/stdc++.h"

using namespace std;

#define ff first
#define ss second
#define ll long long
#define SZ(s) (int)s.size()

int const N = 2e5 + 5;

vector<vector<int>> v;

vector<int> p;

int par(int x) {
    if(p[x] == x) return x;
    return p[x] = par(p[x]);
}

void uni(int a, int b) {
    a = par(a);
    b = par(b);
    if(a == b) return;

    // Always merge smaller into larger for better performance
    if(v[a].size() > v[b].size()) swap(a, b);

    for(auto node : v[a]) {
        v[b].push_back(node);
    }

    // Keep only top 10 largest elements
    sort(v[b].rbegin(), v[b].rend());
    if(v[b].size() > 10) {
        v[b].resize(10);
    }

    p[a] = b;
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    p.resize(n+1);
    v.resize(n+1);

    for(int i = 1; i <= n; ++i) {
        p[i] = i;
        v[i].push_back(i);
    }

    while(q--) {
        int t, a, b;
        cin >> t >> a >> b;
        if(t == 1) {
            uni(a, b);
        } else {
            int root = par(a);
            if(v[root].size() < b) {
                cout << -1 << '\n';
            } else {
                cout << v[root][b-1] << '\n';
            }
        }
    }

    return 0;
}