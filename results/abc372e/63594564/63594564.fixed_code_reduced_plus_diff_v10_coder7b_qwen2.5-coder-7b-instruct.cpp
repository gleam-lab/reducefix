#include <bits/stdc++.h>

using namespace std;

#define ff first
#define ss second
#define ll long long
#define SZ(s) (int)s.size()

int const N = 2e5 + 5;

vector<vector<int>> v;
vector<int> p;
vector<vector<int>> sorted_v;

int par(int x) {
    if(p[x] == x) return x;
    return p[x] = par(p[x]);
}

void uni(int a, int b) {
    a = par(a), b = par(b);
    if(a == b) return;
    if(sorted_v[a].size() > sorted_v[b].size()) swap(a, b);
    for(int x : sorted_v[a]) {
        auto it = upper_bound(sorted_v[b].begin(), sorted_v[b].end(), x);
        sorted_v[b].insert(it, x);
    }
    sorted_v[b].resize(10);
    p[a] = b;
    return;
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int n, q;
    cin >> n >> q;
    p.resize(n + 1);
    v.resize(n + 1);
    sorted_v.resize(n + 1);
    for(int i = 1; i <= n; i++) {
        p[i] = i;
        v[i].push_back(i);
        sorted_v[i].push_back(i);
    }
    while(q--) {
        int t, a, b;
        cin >> t >> a >> b;
        if(t == 1) {
            uni(a, b);
        } else {
            a = par(a);
            if(sorted_v[a].size() < b) {
                cout << -1 << '\n';
            } else {
                cout << sorted_v[a][sorted_v[a].size() - b] << '\n';
            }
        }
    }

    return 0;
}