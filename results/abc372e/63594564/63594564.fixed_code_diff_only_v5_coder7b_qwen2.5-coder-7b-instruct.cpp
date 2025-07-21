#include "bits/stdc++.h"

using namespace std;

#define ff first
#define ss second
#define ll long long
#define SZ(s) (int)s.size()

int const N = 2e5 + 5;

vector<vector<int>> v(N);
vector<int> p(N);

int par(int x) {
    if(p[x] == x) return x;
    return p[x] = par(p[x]);
}

void uni(int a, int b) {
    a = par(a), b = par(b);
    if(a == b) return;
    if(SZ(v[a]) > SZ(v[b])) swap(a, b);
    for(auto it : v[a]) {
        v[b].insert(lower_bound(v[b].begin(), v[b].end(), it), it);
    }
    v[a].clear();
    while(SZ(v[b]) > 10) {
        v[b].erase(prev(v[b].end()));
    }
    p[a] = b;
    return;
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int n, q;
    cin >> n >> q;
    for(int i = 1; i <= n; i++) {
        p[i] = i;
        v[i].push_back(i);
    }
    while(q--) {
        int t, a, b;
        cin >> t >> a >> b;
        if(t == 1) {
            uni(a, b);
        } else {
            a = par(a);
            if(SZ(v[a]) < b) cout << -1 << '\n';
            else cout << v[a][b-1] << '\n';
        }
    }

    return 0;
}