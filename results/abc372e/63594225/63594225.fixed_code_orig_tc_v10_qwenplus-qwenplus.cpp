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
    if(v[a].size() < v[b].size()) swap(a, b);

    // Merge the two sorted lists
    vector<int> merged;
    int i = 0, j = 0;
    while(i < (int)v[a].size() && j < (int)v[b].size()) {
        if(v[a][i] > v[b][j]) {
            merged.push_back(v[b][j++]);
        } else {
            merged.push_back(v[a][i++]);
        }
    }
    while(j < (int)v[b].size()) merged.push_back(v[b][j++]);
    while(i < (int)v[a].size()) merged.push_back(v[a][i++]);

    // Keep only top 100 largest elements
    if(merged.size() > 100)
        merged.resize(100);

    v[a] = merged;
    p[b] = a;
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
        } else {
            a = par(a);
            if(v[a].size() < b) {
                cout << -1 << '\n';
            } else {
                cout << v[a][b-1] << '\n';
            }
        }
    }

    return 0;
}