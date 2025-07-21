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
    // Always merge smaller into larger for efficiency
    if(v[a].size() > v[b].size()) swap(a, b);
    for(int x : v[a]) {
        v[b].push_back(x);
    }
    // Maintain sorted list with top-k largest values
    if(v[b].size() > 100) {
        nth_element(v[b].begin(), v[b].end() - 10, v[b].end());
        v[b].resize(10);
    }
    p[a] = b;
}

int main() {
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
            a = par(a);
            if((int)v[a].size() < b) {
                cout << "-1\n";
            } else {
                cout << v[a][v[a].size() - b] << "\n";
            }
        }
    }

    return 0;
}