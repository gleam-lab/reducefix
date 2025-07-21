#include "bits/stdc++.h"

using namespace std;

#define ff first
#define ss second
#define ll long long
#define SZ(s) (int)s.size()

int const N = 2e5 + 5;

vector <vector <int>> v(N);

int par[N];

int find(int x) {
    if(par[x] == x) return x;
    return par[x] = find(par[x]);
}

void merge(int a, int b) {
    a = find(a), b = find(b);
    if(a == b) return;
    v[a].insert(end(v[a]), begin(v[b]), end(v[b]));
    sort(begin(v[a]), end(v[a]));
    v[a].resize(min(10, (int)v[a].size()));
    par[b] = a;
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int n, q;
    cin >> n >> q;
    iota(par, par+n+1, 0);
    while(q--) {
        int t, a, b;
        cin >> t >> a >> b;
        if(t == 1) {
            merge(a, b);
        }
        else {
            a = find(a);
            if((int)v[a].size() < b) {
                cout << -1 << '\n';
            } else {
                cout << v[a][b-1] << '\n';
            }
        }
    }

    return 0;
}