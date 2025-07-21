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
    a = par(a), b = par(b);
    if(a == b) return;
    if(SZ(v[a]) < SZ(v[b])) swap(a, b);
    vector<int> merged;
    int i = 0, j = 0;
    while((i < SZ(v[a]) || j < SZ(v[b])) && merged.size() < 10) {
        if(j >= SZ(v[b]) || (i < SZ(v[a]) && v[a][i] > v[b][j])) {
            merged.push_back(v[a][i]);
            i++;
        } else {
            merged.push_back(v[b][j]);
            j++;
        }
    }
    v[a] = merged;
    p[b] = a;
    return;
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int n, q;
    cin >> n >> q;
    p.resize(n+1);
    v.resize(n+1);
    for(int i = 1; i <= n; i++) {
        p[i] = i;
        v[i].push_back(i);
    }
    while(q--) {
        int t, a, b;
        cin >> t >> a >> b;
        if(t == 1) {
            uni(a, b);
        }
        else {
            a = par(a);
            cout << (SZ(v[a]) < b ? -1 : v[a][b-1]) << '\n';
        }
    }

    return 0;
}