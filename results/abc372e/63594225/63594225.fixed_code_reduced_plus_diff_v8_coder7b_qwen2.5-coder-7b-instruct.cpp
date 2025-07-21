#include "bits/stdc++.h"

using namespace std;

#define ff first
#define ss second
#define ll long long
#define SZ(s) (int)s.size()

const int N = 2e5 + 5;

vector<int> g[N];
int sz[N], parent[N];

int find(int x) {
    if(parent[x] == x) return x;
    return parent[x] = find(parent[x]);
}

void merge(int a, int b) {
    a = find(a), b = find(b);
    if(a != b) {
        if(sz[a] < sz[b]) swap(a, b);
        parent[b] = a;
        sz[a] += sz[b];
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    iota(parent, parent+n+1, 0);
    fill(sz, sz+n+1, 1);

    while(m--) {
        int type, u, v;
        cin >> type >> u >> v;
        if(type == 1) {
            merge(u, v);
        } else {
            u = find(u);
            if(sz[u] < v) cout << "-1\n";
            else cout << *(--sz[u].end()) << "\n";
        }
    }

    return 0;
}