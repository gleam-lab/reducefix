#include "bits/stdc++.h"
using namespace std;

#define ff first
#define ss second
#define ll long long
#define SZ(s) (int)s.size()

const int N = 2e5 + 5;

vector<int> parent(N), rank(N);
vector<vector<int>> adj(N);

int find(int x) {
    if (parent[x] != x) 
        parent[x] = find(parent[x]);
    return parent[x];
}

void unite(int x, int y) {
    int px = find(x), py = find(y);
    if (px == py) return;
    if (rank[px] < rank[py]) swap(px, py);
    adj[px].insert(adj[px].end(), adj[py].begin(), adj[py].end());
    sort(adj[px].begin(), adj[px].end());
    if (adj[px].size() > 100) {
        adj[px].resize(100);
        adj[px].pop_back();
    }
    parent[py] = px;
    if (rank[px] == rank[py]) rank[px]++;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        parent[i] = i;
        rank[i] = 1;
        adj[i].push_back(i);
    }
    
    while (q--) {
        int t, a, b;
        cin >> t >> a >> b;
        if (t == 1) {
            unite(a, b);
        } else {
            int pa = find(a);
            if (adj[pa].size() < b) {
                cout << -1 << '\n';
            } else {
                cout << adj[pa][adj[pa].size() - b] << '\n';
            }
        }
    }

    return 0;
}