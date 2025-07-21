#include "bits/stdc++.h"

using namespace std;

#define ff first
#define ss second
#define ll long long
#define SZ(s) (int)s.size()

int const N = 2e5 + 5;

vector <set<int>> v;

int par[N];

int find(int x) {
    if(par[x] == x) return x;
    return par[x] = find(par[x]);
}

void unite(int a, int b) {
    a = find(a), b = find(b);
    if(a == b) return;
    if(v[a].size() < v[b].size()) swap(a, b);
    for(auto it : v[b]) v[a].insert(it);
    while(v[a].size() > 10) v[a].erase(prev(v[a].end()));
    par[b] = a;
    return;
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int n, q;
    cin >> n >> q;
    for(int i = 1; i <= n; i++) {
        par[i] = i;
        v[i].insert(i);
    }
    while(q--) {
        int t, a, b;
        cin >> t >> a >> b;
        if(t == 1) {
            unite(a, b);
        }
        else {
            a = find(a);
            if(SZ(v[a]) < b) cout << "-1\n";
            else {
                auto it = prev(v[a].end());
                advance(it, -(b-1));
                cout << *it << '\n';
            }
        }
    }

    return 0;
}